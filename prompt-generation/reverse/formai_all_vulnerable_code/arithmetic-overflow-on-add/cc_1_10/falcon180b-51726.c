//Falcon-180B DATASET v1.0 Category: Error handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the input is a valid integer
int is_integer(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num1, num2, result;
    char operation;

    // Prompt the user for the first number
    printf("Enter the first number: ");
    if (scanf("%d", &num1)!= 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    // Prompt the user for the second number
    printf("Enter the second number: ");
    if (scanf("%d", &num2)!= 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    // Prompt the user for the operation
    printf("Enter the operation (+, -, *, /): ");
    if (scanf(" %c", &operation)!= 1) {
        printf("Invalid input. Please enter a valid operation.\n");
        return 1;
    }

    // Perform the operation and store the result
    switch (operation) {
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
            if (num2 == 0) {
                printf("Error: Division by zero.\n");
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            printf("Invalid operation. Please enter a valid operation.\n");
            return 1;
    }

    // Print the result
    printf("The result is: %d\n", result);

    return 0;
}