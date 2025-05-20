//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// Function prototypes
double get_number(char *input);
int get_operator(char *input);
double perform_operation(double num1, int operator, double num2);

int main() {
    char input[100];
    double num1, num2;
    int operator;

    // Welcome message
    printf("Welcome to the Futuristic Scientific Calculator!\n");

    // Main loop
    while (1) {
        // Prompt user for input
        printf("Enter your calculation (e.g. 5 + 3): ");
        fgets(input, sizeof(input), stdin);

        // Remove newline character
        input[strcspn(input, "\n")] = '\0';

        // Convert input to uppercase
        for (int i = 0; input[i]!= '\0'; i++) {
            input[i] = toupper(input[i]);
        }

        // Parse input
        num1 = get_number(input);
        operator = get_operator(input);
        if (operator!= 0) {
            num2 = get_number(input);
        }

        // Perform calculation
        double result = perform_operation(num1, operator, num2);

        // Print result
        printf("Result: %.2f\n", result);
    }

    return 0;
}

// Function to get a number from input
double get_number(char *input) {
    char *endptr;
    double num = strtod(input, &endptr);

    if (endptr == input) {
        printf("Error: Invalid number.\n");
        exit(1);
    }

    return num;
}

// Function to get an operator from input
int get_operator(char *input) {
    char *endptr;
    int op = strtol(input, &endptr, 10);

    if (endptr == input) {
        return 0;
    } else if (op == '+' || op == '-' || op == '*' || op == '/') {
        return op;
    } else {
        printf("Error: Invalid operator.\n");
        exit(1);
    }
}

// Function to perform an operation
double perform_operation(double num1, int operator, double num2) {
    switch (operator) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero.\n");
                exit(1);
            }
            return num1 / num2;
        default:
            return 0;
    }
}