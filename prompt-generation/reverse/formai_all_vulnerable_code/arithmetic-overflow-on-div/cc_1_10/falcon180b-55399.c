//Falcon-180B DATASET v1.0 Category: Error handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // Declare variables
    int choice, num1, num2, result;
    char operation;

    // Initialize variables
    num1 = 0;
    num2 = 0;
    result = 0;

    // Loop until user chooses to quit
    do{
        // Display menu
        printf("\n");
        printf("Please choose an option:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Quit\n");

        // Get user input
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Perform operation based on user choice
        switch(choice){
            case 1:
                // Addition
                printf("\nEnter two numbers to add: ");
                scanf("%d %d", &num1, &num2);
                result = num1 + num2;
                printf("\nResult: %d\n", result);
                break;
            case 2:
                // Subtraction
                printf("\nEnter two numbers to subtract: ");
                scanf("%d %d", &num1, &num2);
                result = num1 - num2;
                printf("\nResult: %d\n", result);
                break;
            case 3:
                // Multiplication
                printf("\nEnter two numbers to multiply: ");
                scanf("%d %d", &num1, &num2);
                result = num1 * num2;
                printf("\nResult: %d\n", result);
                break;
            case 4:
                // Division
                printf("\nEnter two numbers to divide: ");
                scanf("%d %d", &num1, &num2);
                if(num2 == 0){
                    printf("\nError: Division by zero is not allowed.\n");
                }
                else{
                    result = num1 / num2;
                    printf("\nResult: %d\n", result);
                }
                break;
            case 5:
                // Quit
                printf("\nExiting program...\n");
                break;
            default:
                // Invalid choice
                printf("\nError: Invalid choice.\n");
        }

    }while(choice!= 5);

    // Exit program
    return 0;
}