//FormAI DATASET v1.0 Category: Error handling ; Style: optimized
// Custom error handling example program in C

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void handle_error(int err_num);

int main() {
    int num1, num2;
    float result;
    char op;

    printf("Enter an arithmetic expression in the form 'num op num':\n");
    scanf("%d %c %d", &num1, &op, &num2);

    switch (op) {
        case '+':
            result = num1 + num2;
            printf("Result: %.2f", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %.2f", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %.2f", result);
            break;
        case '/':
            if (num2 == 0) {
                handle_error(EINVAL);
            } else {
                result = (float) num1 / num2;
                printf("Result: %.2f", result);
            }
            break;
        default:
            handle_error(EINVAL);
    }

    return 0;
}

void handle_error(int err_num) {
    switch (err_num) {
        case EINVAL:
            fprintf(stderr, "Invalid argument passed to function.\n");
            break;
        case ENOMEM:
            fprintf(stderr, "Insufficient memory to perform operation.\n");
            break;
        case EIO:
            fprintf(stderr, "Error occurred while performing an I/O operation.\n");
            break;
        default:
            fprintf(stderr, "Unknown error occurred.\n");
    }
    exit(EXIT_FAILURE);
}