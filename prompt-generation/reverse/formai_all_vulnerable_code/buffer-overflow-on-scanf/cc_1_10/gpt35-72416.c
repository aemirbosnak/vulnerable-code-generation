//FormAI DATASET v1.0 Category: Error handling ; Style: Alan Touring
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int main(){

    int num1, num2, result, choice;
    char operator;

    printf("Please enter two numbers: ");
    scanf("%d%d", &num1, &num2);

    printf("\nPlease enter the operation you want to perform (+, -, *, /): ");
    scanf(" %c", &operator);

    if(!isdigit(operator)){ //Error handling for invalid input of operator
        printf("\nInvalid input for operator, program terminated.");
        exit(0);
    }

    switch(operator){
        case '+':
            result = num1 + num2;
            printf("\n%d + %d = %d", num1, num2, result);
            break;
        
        case '-':
            result = num1 - num2;
            printf("\n%d - %d = %d", num1, num2, result);
            break;
        
        case '*':
            result = num1 * num2;
            printf("\n%d * %d = %d", num1, num2, result);
            break;
        
        case '/':
            if(num2 == 0){ //Error handling for division by zero
                printf("\nDivision by Zero Error, program terminated.");
                exit(0);
            }
            
            result = num1 / num2;
            printf("\n%d / %d = %d", num1, num2, result);
            break;

        default: //Error handling for invalid input of operator
            printf("\nInvalid input for operator, program terminated.");
            exit(0);
    }

    printf("\n\nDo you want to perform another operation? (1 for Yes, 0 for No): ");
    scanf("%d", &choice);

    if(choice != 1 && choice != 0){ //Error handling for invalid input of choice
        printf("\nInvalid input for choice, program terminated.");
        exit(0);
    }

    if(choice == 1){ //Recursion for performing multiple operations
        main();
    }
    else{
        printf("\nProgram terminated.");
        exit(0);
    }

    return 0;
}