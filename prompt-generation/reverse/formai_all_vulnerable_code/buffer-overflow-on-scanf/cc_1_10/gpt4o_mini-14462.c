//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_OPERATIONS 100

typedef enum {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    SQUARE,
    SQUARE_ROOT,
    POWER,
    MODULO
} OperationType;

typedef struct {
    OperationType type;
    double operand1;
    double operand2;
} Operation;

void perform_operation(Operation op, double* result) {
    switch (op.type) {
        case ADDITION:
            *result = op.operand1 + op.operand2;
            break;
        case SUBTRACTION:
            *result = op.operand1 - op.operand2;
            break;
        case MULTIPLICATION:
            *result = op.operand1 * op.operand2;
            break;
        case DIVISION:
            if (op.operand2 != 0) {
                *result = op.operand1 / op.operand2;
            } else {
                printf("Error: Division by zero.\n");
                *result = NAN;
            }
            break;
        case SQUARE:
            *result = op.operand1 * op.operand1;
            break;
        case SQUARE_ROOT:
            if (op.operand1 >= 0) {
                *result = sqrt(op.operand1);
            } else {
                printf("Error: Square root of a negative number.\n");
                *result = NAN;
            }
            break;
        case POWER:
            *result = pow(op.operand1, op.operand2);
            break;
        case MODULO:
            if ((int)op.operand2 != 0) {
                *result = (int)op.operand1 % (int)op.operand2;
            } else {
                printf("Error: Modulo by zero.\n");
                *result = NAN;
            }
            break;
        default:
            printf("Invalid operation.\n");
            *result = NAN;
    }
}

void execute_operations(Operation* operations, int count) {
    for (int i = 0; i < count; i++) {
        double result;
        perform_operation(operations[i], &result);
        if (!isnan(result)) {
            printf("Result of operation %d: ", i + 1);
            switch (operations[i].type) {
                case ADDITION:
                    printf("%.2f + %.2f = %.2f\n", operations[i].operand1, operations[i].operand2, result);
                    break;
                case SUBTRACTION:
                    printf("%.2f - %.2f = %.2f\n", operations[i].operand1, operations[i].operand2, result);
                    break;
                case MULTIPLICATION:
                    printf("%.2f * %.2f = %.2f\n", operations[i].operand1, operations[i].operand2, result);
                    break;
                case DIVISION:
                    printf("%.2f / %.2f = %.2f\n", operations[i].operand1, operations[i].operand2, result);
                    break;
                case SQUARE:
                    printf("Square of %.2f = %.2f\n", operations[i].operand1, result);
                    break;
                case SQUARE_ROOT:
                    printf("Square root of %.2f = %.2f\n", operations[i].operand1, result);
                    break;
                case POWER:
                    printf("%.2f ^ %.2f = %.2f\n", operations[i].operand1, operations[i].operand2, result);
                    break;
                case MODULO:
                    printf("%.0f %% %.0f = %.0f\n", operations[i].operand1, operations[i].operand2, result);
                    break;
            }
        }
    }
}

void input_operations(Operation* operations, int* count) {
    int n, type;
    printf("Enter the number of operations (1 to %d): ", MAX_OPERATIONS);
    scanf("%d", &n);

    if (n > 0 && n <= MAX_OPERATIONS) {
        *count = n;
        for (int i = 0; i < n; i++) {
            printf("Enter operation type (0: +, 1: -, 2: *, 3: /, 4: ^2, 5: sqrt, 6: ^, 7: %%): ");
            scanf("%d", &type);
            operations[i].type = (OperationType)type;

            if (type == SQUARE || type == SQUARE_ROOT) {
                printf("Enter operand: ");
                scanf("%lf", &operations[i].operand1);
                operations[i].operand2 = 0; // Unused for these operations
            } else {
                printf("Enter first operand: ");
                scanf("%lf", &operations[i].operand1);
                printf("Enter second operand: ");
                scanf("%lf", &operations[i].operand2);
            }
        }
    } else {
        printf("Invalid number of operations.\n");
        *count = 0;
    }
}

int main() {
    Operation operations[MAX_OPERATIONS];
    int count;

    input_operations(operations, &count);
    execute_operations(operations, count);

    return 0;
}