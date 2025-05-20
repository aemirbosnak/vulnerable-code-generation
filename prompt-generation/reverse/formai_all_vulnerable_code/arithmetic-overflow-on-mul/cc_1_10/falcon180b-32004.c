//Falcon-180B DATASET v1.0 Category: Educational ; Style: invasive
// This program is a simple calculator that can perform addition, subtraction, multiplication, and division
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int first_num, second_num, result;
    char operation;

    // Get user input for two numbers and an operation
    printf("Enter the first number: ");
    if (!scanf("%d", &first_num)) {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    printf("Enter the second number: ");
    if (!scanf("%d", &second_num)) {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform the operation and display the result
    switch(operation) {
        case '+':
            result = first_num + second_num;
            printf("The result is %d.\n", result);
            break;
        case '-':
            result = first_num - second_num;
            printf("The result is %d.\n", result);
            break;
        case '*':
            result = first_num * second_num;
            printf("The result is %d.\n", result);
            break;
        case '/':
            if (second_num == 0) {
                printf("Division by zero is not allowed.\n");
                return 1;
            }
            result = first_num / second_num;
            printf("The result is %d.\n", result);
            break;
        default:
            printf("Invalid operation. Please enter a valid operation.\n");
            return 1;
    }

    return 0;
}