//FormAI DATASET v1.0 Category: Arithmetic ; Style: Dennis Ritchie
/*
This program demonstrates the use of C variables, operators, and control statements.
It prompts the user to enter two numbers and performs arithmetic operations on them.
The program also displays the results and offers to repeat the process.
*/

#include<stdio.h>

int main(){
    int num1, num2, choice, result;
    char repeat;

    printf("Welcome to the Arithmetic Program!\n");

    do{
        printf("\nEnter two numbers: ");
        scanf("%d %d", &num1, &num2);

        printf("\nSelect an arithmetic operation:\n");
        printf("1. Addition (+)\n2. Subtraction (-)\n3. Multiplication (*)\n4. Division (/)\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                result = num1 + num2;
                printf("\nThe sum of %d and %d is %d", num1, num2, result);
                break;
            case 2:
                result = num1 - num2;
                printf("\nThe difference between %d and %d is %d", num1, num2, result);
                break;
            case 3:
                result = num1 * num2;
                printf("\nThe product of %d and %d is %d", num1, num2, result);
                break;
            case 4:
                if(num2 != 0){
                    result = num1 / num2;
                    printf("\nThe quotient of %d and %d is %d", num1, num2, result);
                }
                else{
                    printf("\nCannot divide by zero.");
                }
                break;
            default:
                printf("\nInvalid choice.");
                break;
        }

        printf("\nWould you like to perform another operation? (Y/N): ");
        scanf(" %c", &repeat);

    }while(repeat == 'Y' || repeat == 'y');

    printf("\nProgram terminated. Thank you for using our service!\n");

    return 0;
}