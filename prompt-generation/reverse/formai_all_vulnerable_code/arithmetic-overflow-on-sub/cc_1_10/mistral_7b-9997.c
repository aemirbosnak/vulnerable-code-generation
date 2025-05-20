//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

void error_and_exit(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

int atoi_wrapper(const char *str) {
    char *endptr;
    int num = strtol(str, &endptr, 10);

    if (endptr > str && *endptr != '\0') {
        error_and_exit("Invalid number: non-digit characters found.");
    }

    return num;
}

int factorial(int n) {
    if (n < 0) {
        error_and_exit("Invalid number: factorial is not defined for negative numbers.");
    }

    if (n == 0 || n == 1) {
        return 1;
    }

    return n * factorial(n - 1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        error_and_exit("Usage: ./factorial <number>");
    }

    int num;
    if (strlen(argv[1]) > MAX_INPUT_LENGTH) {
        error_and_exit("Error: Input number too long.");
    }

    num = atoi_wrapper(argv[1]);
    int result = factorial(num);

    printf("Factorial of %d is %d\n", num, result);

    return EXIT_SUCCESS;
}