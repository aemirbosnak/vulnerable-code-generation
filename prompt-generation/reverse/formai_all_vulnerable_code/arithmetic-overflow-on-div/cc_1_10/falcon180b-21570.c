//Falcon-180B DATASET v1.0 Category: Error handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <stdarg.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#include <setjmp.h>

#define MAX_NUM_ERRORS 10
#define ERR_CODE_LEN 4

typedef struct {
    char error_code[ERR_CODE_LEN];
    char *error_message;
} error_t;

static error_t errors[MAX_NUM_ERRORS];
static int num_errors = 0;

void init_errors() {
    memset(errors, 0, sizeof(errors));
    num_errors = 0;
}

void add_error(char *error_code, char *error_message) {
    if (num_errors >= MAX_NUM_ERRORS) {
        fprintf(stderr, "Error: Too many errors\n");
        exit(EXIT_FAILURE);
    }

    strncpy(errors[num_errors].error_code, error_code, ERR_CODE_LEN - 1);
    errors[num_errors].error_message = error_message;
    num_errors++;
}

void print_errors() {
    for (int i = 0; i < num_errors; i++) {
        fprintf(stderr, "Error %d: %s - %s\n", i + 1, errors[i].error_code, errors[i].error_message);
    }
}

int main() {
    int num1, num2;

    init_errors();

    if (scanf("%d %d", &num1, &num2)!= 2) {
        add_error("EINVAL", "Invalid input");
        return 1;
    }

    if (num1 == 0) {
        add_error("EDIV", "Division by zero");
        return 1;
    }

    int result = num1 / num2;

    if (result * num2!= num1) {
        add_error("ERANGE", "Result out of range");
        return 1;
    }

    printf("Result: %d\n", result);

    return 0;
}