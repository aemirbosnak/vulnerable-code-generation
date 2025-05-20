//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Define the size of the array
#define SIZE 100

// Function to perform arithmetic operations
int arithmetic(int num1, char operator, int num2) {
    int result = 0;

    switch(operator) {
        case '+': // Addition
            result = num1 + num2;
            break;

        case '-': // Subtraction
            result = num1 - num2;
            break;

        case '*': // Multiplication
            result = num1 * num2;
            break;

        case '/': // Division
            if(num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
                exit(1);
            }
            result = num1 / num2;
            break;

        default: // Invalid operator
            printf("Error: Invalid operator.\n");
            exit(1);
    }

    return result;
}

int main() {
    // Initialize the array
    int arr[SIZE];
    int i;

    // Prompt the user to enter the elements of the array
    printf("Enter the elements of the array:\n");
    for(i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform arithmetic operations on the array
    printf("Enter the arithmetic operation (+, -, *, /):\n");
    char operator;
    scanf(" %c", &operator);

    printf("Enter the first number:\n");
    int num1;
    scanf("%d", &num1);

    printf("Enter the second number:\n");
    int num2;
    scanf("%d", &num2);

    // Perform the arithmetic operation on the array
    int result = arithmetic(num1, operator, num2);

    // Display the result
    printf("The result of the arithmetic operation is: %d\n", result);

    return 0;
}