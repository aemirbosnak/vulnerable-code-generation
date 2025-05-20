//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: retro
#include <stdio.h>

// Function to check if a string is a valid integer
int is_integer(char* str) {
    int i = 0;
    while (str[i]) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to perform basic arithmetic operations
int perform_operation(char* operation, int num1, int num2) {
    if (strcmp(operation, "+") == 0) {
        return num1 + num2;
    } else if (strcmp(operation, "-") == 0) {
        return num1 - num2;
    } else if (strcmp(operation, "*") == 0) {
        return num1 * num2;
    } else if (strcmp(operation, "/") == 0) {
        if (num2 == 0) {
            printf("Error: Division by zero\n");
            return 0;
        }
        return num1 / num2;
    }
    printf("Error: Invalid operation\n");
    return 0;
}

int main() {
    char input[100];
    int num1, num2, result;
    char operation;

    // Prompt the user for input
    printf("Enter an integer expression in the format: num1 operator num2\n");
    scanf("%s", input);

    // Extract the two numbers and the operator
    num1 = atoi(input);
    operation = input[strcspn(input, "+-*/")];
    num2 = atoi(input + strcspn(input, "+-*/") + 1);

    // Check if the input is valid
    if (!is_integer(input)) {
        printf("Error: Invalid input\n");
        return 0;
    }

    // Perform the arithmetic operation
    result = perform_operation(&operation, num1, num2);

    // Print the result
    if (result!= 0) {
        printf("Result: %d\n", result);
    }

    return 0;
}