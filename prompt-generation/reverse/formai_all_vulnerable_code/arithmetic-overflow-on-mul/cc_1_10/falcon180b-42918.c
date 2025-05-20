//Falcon-180B DATASET v1.0 Category: Error handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int isInteger(char *str);
int calculate(int num1, int num2, char operation);

int main() {
    char input[100];
    char operation;
    int num1, num2;

    // Prompt user for input
    printf("Enter an arithmetic expression (e.g. 5 + 3): ");
    fgets(input, 100, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Split input into numbers and operator
    sscanf(input, "%d %c %d", &num1, &operation, &num2);

    // Check if input is valid
    if (!isInteger(input)) {
        printf("Error: Invalid input.\n");
        return 1;
    }

    // Calculate result
    int result = calculate(num1, num2, operation);

    // Print result
    printf("Result: %d\n", result);

    return 0;
}

// Function to check if a string is an integer
int isInteger(char *str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to calculate result based on operator
int calculate(int num1, int num2, char operation) {
    int result;
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
                return 0;
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: Invalid operator.\n");
            return 0;
    }
    return result;
}