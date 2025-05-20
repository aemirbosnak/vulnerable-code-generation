//Falcon-180B DATASET v1.0 Category: Error handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define custom error codes
#define ERR_INVALID_ARGUMENT 1
#define ERR_OUT_OF_MEMORY 2
#define ERR_FILE_NOT_FOUND 3
#define ERR_INVALID_INPUT 4
#define ERR_INVALID_OPERATION 5

// define function prototypes
void *safe_malloc(size_t size);
int perform_operation(int a, int b, int operation);

int main() {
    int result;

    // allocate memory for variables
    int *a = safe_malloc(sizeof(int));
    int *b = safe_malloc(sizeof(int));
    int *operation = safe_malloc(sizeof(int));

    // prompt user for input
    printf("Enter two numbers and an operation (+, -, *, /): ");
    scanf("%d %d %d", a, b, operation);

    // perform operation and handle errors
    result = perform_operation(*a, *b, *operation);
    if (result!= 0) {
        printf("Error: %s\n", strerror(result));
        return result;
    }

    // print result
    printf("Result: %d\n", *a);

    // free memory
    free(a);
    free(b);
    free(operation);

    return 0;
}

// safe malloc function that checks for out of memory errors
void *safe_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(ERR_OUT_OF_MEMORY);
    }
    return ptr;
}

// perform operation function that checks for invalid arguments and divides by zero
int perform_operation(int a, int b, int operation) {
    switch (operation) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                fprintf(stderr, "Error: Division by zero\n");
                exit(ERR_INVALID_OPERATION);
            }
            return a / b;
        default:
            fprintf(stderr, "Error: Invalid operation\n");
            exit(ERR_INVALID_ARGUMENT);
    }
}