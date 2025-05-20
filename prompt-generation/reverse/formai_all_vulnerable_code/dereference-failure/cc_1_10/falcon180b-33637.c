//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ERRORS 10
#define ERR_MSG_LEN 100

typedef struct {
    char msg[ERR_MSG_LEN];
    int lineno;
} error_t;

static int num_errors = 0;
static error_t errors[MAX_ERRORS];

void add_error(const char* msg, int lineno) {
    if (num_errors >= MAX_ERRORS) {
        fprintf(stderr, "Error: Too many errors, cannot add more.\n");
        exit(1);
    }
    strncpy(errors[num_errors].msg, msg, ERR_MSG_LEN - 1);
    errors[num_errors].msg[ERR_MSG_LEN - 1] = '\0';
    errors[num_errors].lineno = lineno;
    num_errors++;
}

void print_errors() {
    if (num_errors == 0) {
        printf("No errors found.\n");
        return;
    }
    printf("Found %d errors:\n", num_errors);
    for (int i = 0; i < num_errors; i++) {
        printf("%d: %s\n", errors[i].lineno, errors[i].msg);
    }
}

int main() {
    int i = 5;
    char* msg = (char*)malloc(10);
    strcpy(msg, "Hello");
    printf("%s\n", msg);
    free(msg);

    if (i == 10) {
        add_error("Variable i should be equal to 5", __LINE__);
    }

    print_errors();

    return 0;
}