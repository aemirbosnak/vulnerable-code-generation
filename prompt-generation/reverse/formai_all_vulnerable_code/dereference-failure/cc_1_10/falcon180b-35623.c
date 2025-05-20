//Falcon-180B DATASET v1.0 Category: Error handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

// Function to print the error message and exit the program
void error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

// Function to read a line from the standard input
char* read_line() {
    char* line = malloc(MAX_LINE_SIZE);
    if (line == NULL) {
        error("Out of memory");
    }
    fgets(line, MAX_LINE_SIZE, stdin);
    return line;
}

// Function to parse an integer from a string
int parse_int(const char* str) {
    int num = 0;
    int sign = 1;
    if (*str == '-') {
        sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        num = num * 10 + (*str - '0');
        str++;
    }
    return num * sign;
}

int main() {
    char* line;
    int num1, num2, result;

    // Prompt the user to enter the first number
    printf("Enter the first number: ");
    line = read_line();
    num1 = parse_int(line);

    // Prompt the user to enter the second number
    printf("Enter the second number: ");
    line = read_line();
    num2 = parse_int(line);

    // Prompt the user to enter the operation
    printf("Enter the operation (+, -, *, /): ");
    line = read_line();
    char operation = *line;

    // Perform the operation and print the result
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
                error("Division by zero");
            }
            result = num1 / num2;
            break;
        default:
            error("Invalid operation");
    }

    printf("The result is: %d\n", result);

    return 0;
}