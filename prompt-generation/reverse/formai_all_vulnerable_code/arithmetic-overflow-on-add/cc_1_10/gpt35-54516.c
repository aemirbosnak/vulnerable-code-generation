//FormAI DATASET v1.0 Category: Error handling ; Style: curious
#include<stdio.h>

int main(){
    // Declaring variables
    int num1, num2, result;
    char operation;
    printf("Enter a mathematical operation (+, -, *, /): ");
    scanf("%c", &operation);

    printf("Enter first number: ");
    if(scanf("%d", &num1) != 1){ // Handling scanf error
        printf("ERROR: Invalid input for first number. Please enter a number.\n");
        return 1; // Exiting program 
    }

    printf("Enter second number: ");
    if(scanf("%d", &num2) != 1){ // Handling scanf error
        printf("ERROR: Invalid input for second number. Please enter a number.\n");
        return 1; // Exiting program
    }

    // handling division by zero error
    if(operation == '/' && num2 == 0){
        printf("ERROR: Division by zero is not allowed.\n");
        return 1; // Exiting program
    }

    // Performing mathematical operation based on user input
    switch(operation){
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            printf("ERROR: Invalid mathematical operation entered. Please enter a valid operation.\n");
            return 1; // Exiting program
    }

    printf("%d %c %d = %d\n", num1, operation, num2, result); // Outputting result

    return 0; // Successful program execution
}