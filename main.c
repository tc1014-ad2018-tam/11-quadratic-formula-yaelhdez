//Carlos Yael Hernandez Alcala
//A01412016
//A01412016@ITESM.MX


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>

//------------------------------------QADRATIC FORMULA FUNCTION--------------------------------------------------------------

void Qadratic_formula(double a, double b, double c, int discriminant){
    double x[2];
//depending of the "return" of the function "discriminant", this function will take a path
    if (discriminant==0){
        printf("The operation doesnt have real results"); //if the discriminant is equals to 0
    }
    else if (discriminant==1){
        printf("The operation has only one result\n"); //if the discriminant is equals to 1
        x[0]=(0-b)/(2*a); //the formula without the discriminant
        printf("x1 and x2 = %lf",x[0]);
    }
    else if (discriminant==2){ //if the discriminant is equals to 2
        x[0]= (0-b-sqrt((pow(b,2)-(4*a*c))))/(2*a); //all the formula for x1
        x[1]= (0-b+sqrt((pow(b,2)-(4*a*c))))/(2*a); //all the formula for x2
        printf("x1= %lf\n",x[0]); //output
        printf("x2= %lf",x[1]); //output
    }
}
//------------------------------------ DISCRIMINANT FUNCTION --------------------------------------------------------------

int Discriminant(double a, double b, double c){
    double dis= (pow(b,2))-(4*a*c);
    if (dis==0){ //if the discriminant is equals to 0, the operation only has one result and this path returns a one
        return 1;
    }
    else if (dis>0){ //if the discriminant is greater than 0, the operation has 2 results and this path returns a two
        return 2;
    }
    else if (dis<0){ //if the discriminant is lower than 0, the operation has not results and this path returns a zero
        return 0;
    }
}

//------------------------------------ VALIDATE NUMBER --------------------------------------------------------------

int Validate_number(char number[]){
//this "for" analize all the string
    for(int i=0;i<strlen(number);i++){
//validation using the ascci code. The program will take this path if the user enter another thing that not is a number,
// a point or a negative symbol
        if((number[i]<48 || number[i]>57) && number[i]!=46 && number[i]!=45){

            printf("enter only numbers (press enter to continue)");
            getch(); //getting a void
            printf("\n\n");
            return  0;

        }
    }
}

//------------------------------------MAIN FUNCTION--------------------------------------------------------------

int main() {
    char a[15],b[15],c[15]; //string variables
    int validate; //int variable
    double reala,realb,realc; //real value of the string variables


    do {
        printf("Gimme the value of 'a'\n");
        gets(a); //value request of the string
        validate=Validate_number(a); //Validate_number(); call
        if (!strcmp(a,"0")){printf("The value of 'a' cant be a zero\n");} //if the user enter a 0, the program will show this
    }while(validate==0 || !strcmp(a,"0")); //the loop continues if the user introduce a character or a zero
    reala=atof(a); //conversion of the string to a double

    do {
        printf("Gimme the value of 'b'\n");
        gets(b); //value request  of the string
        validate=Validate_number(b); //Validate_number(); call
    }while(validate==0); //the loop continues if the user introduce a character
    realb=atof(b); //conversion of the string to a double

    do {
        printf("Gimme the value of 'c'\n");
        gets(c); //value request  of the string
        validate=Validate_number(c); //Validate_number(); call
    }while(validate==0); //the loop continues if the user introduce a character
    realc=atof(c); //conversion of the string to a double

    Qadratic_formula(reala,realb,realc,Discriminant(reala,realb,realc)); //Qadratic_formula(); call

    return 0;
}