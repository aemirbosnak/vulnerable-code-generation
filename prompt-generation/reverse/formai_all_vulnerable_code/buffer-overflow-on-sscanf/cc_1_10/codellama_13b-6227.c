//Code Llama-13B DATASET v1.0 Category: Error handling ; Style: Donald Knuth
/*
 * A program to demonstrate error handling in C, inspired by Donald Knuth's programming style.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

/*
 * A function to read a line from the user, and check if it is a valid integer.
 * Returns the integer if successful, or -1 if the line is invalid.
 */
int read_integer(void) {
    char line[MAX_LINE_LENGTH];
    int result;

    printf("Enter an integer: ");
    fgets(line, MAX_LINE_LENGTH, stdin);

    if (sscanf(line, "%d", &result) != 1) {
        printf("Invalid input, please try again.\n");
        return -1;
    }

    return result;
}

/*
 * A function to handle an error by printing an error message and exiting the program.
 */
void error_handler(int error_code) {
    switch (error_code) {
        case 1:
            printf("Division by zero!\n");
            break;
        case 2:
            printf("Invalid input!\n");
            break;
        default:
            printf("Unknown error!\n");
            break;
    }

    printf("Exiting program...\n");
    exit(1);
}

int main(void) {
    int a, b, result;

    printf("Enter two integers: ");
    a = read_integer();
    b = read_integer();

    if (a == -1 || b == -1) {
        error_handler(2);
    }

    if (b == 0) {
        error_handler(1);
    }

    result = a / b;
    printf("Result: %d\n", result);

    return 0;
}