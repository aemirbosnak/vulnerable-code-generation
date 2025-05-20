//Falcon-180B DATASET v1.0 Category: Error handling ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ERRORS 10

typedef struct {
    char *message;
    int line_number;
    time_t timestamp;
} Error;

Error errors[MAX_ERRORS];
int num_errors = 0;

void log_error(int line_number, const char *message) {
    if (num_errors >= MAX_ERRORS) {
        fprintf(stderr, "Too many errors, cannot log anymore\n");
        return;
    }

    errors[num_errors].message = strdup(message);
    errors[num_errors].line_number = line_number;
    errors[num_errors].timestamp = time(NULL);

    num_errors++;
}

void print_errors() {
    if (num_errors == 0) {
        printf("No errors found\n");
        return;
    }

    printf("Found %d errors:\n", num_errors);
    for (int i = 0; i < num_errors; i++) {
        printf("[%d] %s (line %d)\n", i+1, errors[i].message, errors[i].line_number);
    }
}

int main() {
    int x = 10;
    int y = 0;

    if (x == 0) {
        log_error(__LINE__, "x is zero");
    } else if (y == 0) {
        log_error(__LINE__, "y is zero");
    } else {
        int z = x / y;
    }

    print_errors();

    return 0;
}