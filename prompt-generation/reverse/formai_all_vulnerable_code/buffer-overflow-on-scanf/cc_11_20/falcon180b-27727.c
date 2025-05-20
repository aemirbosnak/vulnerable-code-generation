//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double num1, num2, result;
    char operator;

    //initialize variables
    num1 = 0;
    num2 = 0;
    operator = '\0';

    //welcome message
    printf("Welcome to the Scientific Calculator!\n");

    //main loop
    while(operator!= 'q') {
        //display current values of variables
        printf("num1 = %lf\n", num1);
        printf("num2 = %lf\n", num2);
        printf("operator = %c\n", operator);

        //ask user for input
        printf("Enter a number or operator (+, -, *, /, sin, cos, tan): ");
        scanf("%c", &operator);

        //check if input is a number
        if(operator >= '0' && operator <= '9') {
            if(operator == '0') {
                num1 = 0;
            } else {
                num1 = num1 * 10 + operator - '0';
            }
        } else if(operator == '+') {
            num2 = num1;
            num1 = 0;
        } else if(operator == '-') {
            num2 = num1;
            num1 = 0;
        } else if(operator == '*') {
            result = num1 * num2;
            printf("Result: %lf\n", result);
            num1 = 0;
            num2 = 0;
        } else if(operator == '/') {
            if(num2 == 0) {
                printf("Error: Division by zero.\n");
            } else {
                result = num1 / num2;
                printf("Result: %lf\n", result);
                num1 = 0;
                num2 = 0;
            }
        } else if(operator =='s') {
            result = sin(num1);
            printf("Result: %lf\n", result);
            num1 = 0;
        } else if(operator == 'c') {
            result = cos(num1);
            printf("Result: %lf\n", result);
            num1 = 0;
        } else if(operator == 't') {
            result = tan(num1);
            printf("Result: %lf\n", result);
            num1 = 0;
        } else if(operator == 'q') {
            printf("Exiting program...\n");
        } else {
            printf("Error: Invalid input.\n");
        }
    }

    return 0;
}