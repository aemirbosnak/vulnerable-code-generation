//Falcon-180B DATASET v1.0 Category: Error handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *message;
    int code;
} Error;

Error *new_error(const char *message, int code) {
    Error *error = malloc(sizeof(Error));
    error->message = strdup(message);
    error->code = code;
    return error;
}

void free_error(Error *error) {
    free(error->message);
    free(error);
}

void print_error(Error *error) {
    printf("Error: %s (code %d)\n", error->message, error->code);
}

int main() {
    int num1, num2;
    char *input;

    if (scanf("%d %d", &num1, &num2)!= 2) {
        Error *error = new_error("Invalid input format", 1);
        print_error(error);
        free_error(error);
        return 1;
    }

    if (num1 == 0 || num2 == 0) {
        Error *error = new_error("Division by zero is not allowed", 2);
        print_error(error);
        free_error(error);
        return 1;
    }

    if (num2 == 1) {
        printf("Result: %d\n", num1);
    } else {
        int result = num1 / num2;
        printf("Result: %.2f\n", (double) result);
    }

    return 0;
}