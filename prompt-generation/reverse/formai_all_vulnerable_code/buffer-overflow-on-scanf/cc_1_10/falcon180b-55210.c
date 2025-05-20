//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_OPERATIONS 100

typedef struct {
    char *operand1;
    char *operand2;
    char operation;
    bool completed;
} Operation;

int main() {
    int num_operations = 0;
    Operation operations[MAX_OPERATIONS];

    printf("Enter number of operations (up to %d): ", MAX_OPERATIONS - 1);
    scanf("%d", &num_operations);

    for (int i = 0; i < num_operations; i++) {
        printf("Enter operand 1 for operation %d: ", i + 1);
        char *operand1 = malloc(100 * sizeof(char));
        scanf("%s", operand1);

        printf("Enter operand 2 for operation %d: ", i + 1);
        char *operand2 = malloc(100 * sizeof(char));
        scanf("%s", operand2);

        printf("Enter operation for operation %d (+, -, *, /): ", i + 1);
        char operation;
        scanf(" %c", &operation);

        operations[i].operand1 = operand1;
        operations[i].operand2 = operand2;
        operations[i].operation = operation;
        operations[i].completed = false;
    }

    for (int i = 0; i < num_operations; i++) {
        if (operations[i].operation == '+') {
            int result = atoi(operations[i].operand1) + atoi(operations[i].operand2);
            printf("Result of operation %d: %d\n", i + 1, result);
            operations[i].completed = true;
        } else if (operations[i].operation == '-') {
            int result = atoi(operations[i].operand1) - atoi(operations[i].operand2);
            printf("Result of operation %d: %d\n", i + 1, result);
            operations[i].completed = true;
        } else if (operations[i].operation == '*') {
            int result = atoi(operations[i].operand1) * atoi(operations[i].operand2);
            printf("Result of operation %d: %d\n", i + 1, result);
            operations[i].completed = true;
        } else if (operations[i].operation == '/') {
            double result = atof(operations[i].operand1) / atof(operations[i].operand2);
            printf("Result of operation %d: %.2f\n", i + 1, result);
            operations[i].completed = true;
        }
    }

    return 0;
}