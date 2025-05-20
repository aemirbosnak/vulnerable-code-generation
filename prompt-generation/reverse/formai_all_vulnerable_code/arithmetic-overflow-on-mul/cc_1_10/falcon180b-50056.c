//Falcon-180B DATASET v1.0 Category: Error handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to print error message and exit program */
void error(char *message) {
    fprintf(stderr, "ERROR: %s\n", message);
    exit(EXIT_FAILURE);
}

/* Function to check if a string is a valid integer */
int is_int(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

/* Function to get an integer input from user */
int get_int(char *prompt) {
    char input[100];
    printf("%s", prompt);
    fgets(input, 100, stdin);
    int num = atoi(input);
    if (is_int(input)) {
        return num;
    } else {
        error("Invalid input");
    }
}

/* Recursive function to calculate factorial */
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

/* Main function */
int main() {
    int num;
    char input[100];
    printf("Enter a non-negative integer:\n");
    if (fgets(input, 100, stdin)!= NULL && is_int(input)) {
        num = atoi(input);
        if (num < 0) {
            error("Input must be non-negative");
        } else {
            printf("Factorial of %d is %d\n", num, factorial(num));
        }
    } else {
        error("Invalid input");
    }
    return 0;
}