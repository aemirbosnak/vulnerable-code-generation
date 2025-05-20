//FormAI DATASET v1.0 Category: Error handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    ERROR_DIVIDE_BY_ZERO,
    ERROR_MEMORY_ALLOCATION,
    ERROR_INVALID_INPUT
} ErrorType;

void errorHandler(ErrorType type) {
    switch(type) {
        case ERROR_DIVIDE_BY_ZERO:
            printf("ERROR: Cannot divide by zero.\n");
            break;
        case ERROR_MEMORY_ALLOCATION:
            printf("ERROR: Could not allocate memory.\n");
            break;
        case ERROR_INVALID_INPUT:
            printf("ERROR: Invalid input.\n");
            break;
        default:
            printf("UNKNOWN ERROR\n");
            break;
    }
}

int main() {
    int a, b, result;

    // user input
    printf("Enter two numbers:\n");
    scanf("%d%d", &a, &b);

    // check for invalid input
    if(b == 0) {
        errorHandler(ERROR_DIVIDE_BY_ZERO);
        return -1;
    }

    // allocate memory
    int* arr = malloc(sizeof(int) * a);
    if(arr == NULL) {
        errorHandler(ERROR_MEMORY_ALLOCATION);
        return -1;
    }

    // perform division
    result = a / b;

    // check for invalid result
    if(result < 0 || result > 100) {
        errorHandler(ERROR_INVALID_INPUT);
        return -1;
    }

    // print array of results
    printf("Array of Results:\n");
    for(int i = 0; i < a; i++) {
        arr[i] = result;
        printf("%d\n", arr[i]);
    }

    // free memory
    free(arr);

    return 0;
}