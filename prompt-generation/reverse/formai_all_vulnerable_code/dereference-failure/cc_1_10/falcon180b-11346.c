//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define a function to perform arithmetic operations
int arithmetic_operations(int a, int b, char operator) {
    switch(operator) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if(b == 0) {
                printf("Error: Division by zero is not allowed.\n");
                exit(1);
            }
            return a / b;
        default:
            printf("Error: Invalid operator.\n");
            exit(1);
    }
}

int main(int argc, char *argv[]) {
    int a, b;
    char operator;

    // Check if the correct number of arguments are provided
    if(argc!= 4) {
        printf("Error: Invalid number of arguments.\n");
        printf("Usage: %s <operand1> <operator> <operand2>\n", argv[0]);
        exit(1);
    }

    // Convert command line arguments to integers
    a = atoi(argv[1]);
    b = atoi(argv[3]);

    // Convert operator character to integer for switch statement
    if(argv[2][0] == '+') {
        operator = '+';
    } else if(argv[2][0] == '-') {
        operator = '-';
    } else if(argv[2][0] == '*') {
        operator = '*';
    } else if(argv[2][0] == '/') {
        operator = '/';
    } else {
        printf("Error: Invalid operator.\n");
        exit(1);
    }

    // Perform arithmetic operation and print result
    int result = arithmetic_operations(a, b, operator);
    printf("Result: %d\n", result);

    return 0;
}