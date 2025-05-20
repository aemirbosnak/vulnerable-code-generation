//Falcon-180B DATASET v1.0 Category: Error handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ERRORS 10
#define MAX_ERROR_MSG_LENGTH 100

typedef struct {
    char *msg;
    int line_number;
} error_t;

error_t errors[MAX_ERRORS];
int num_errors = 0;

void add_error(const char *msg, int line_number) {
    if (num_errors >= MAX_ERRORS) {
        printf("Error: Too many errors.\n");
        exit(1);
    }

    strncpy(errors[num_errors].msg, msg, MAX_ERROR_MSG_LENGTH);
    errors[num_errors].line_number = line_number;
    num_errors++;
}

void print_errors() {
    printf("Errors:\n");
    for (int i = 0; i < num_errors; i++) {
        printf("Line %d: %s\n", errors[i].line_number, errors[i].msg);
    }
}

int main() {
    int x = 0;
    int y = 1;

    // Division by zero
    x = 10 / y;

    // Invalid pointer dereference
    char *ptr = NULL;
    *ptr = 'a';

    // Invalid array index
    char arr[3] = {'a', 'b', 'c'};
    char c = arr[3];

    // Invalid format string
    printf("The value of x is %d.\n", x);

    // Too many errors
    if (num_errors >= MAX_ERRORS) {
        printf("Error: Too many errors.\n");
        exit(1);
    }

    return 0;
}