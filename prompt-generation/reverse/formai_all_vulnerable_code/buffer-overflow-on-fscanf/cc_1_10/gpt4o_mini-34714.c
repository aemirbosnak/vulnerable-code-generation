//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPERATIONS 10
#define MAX_INPUT_SIZE 100

typedef struct {
    char operation[10];
    int operand1;
    int operand2;
} ArithmeticOperation;

void load_config(const char *filename, ArithmeticOperation operations[], int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open config file");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while (fscanf(file, "%s %d %d", operations[*count].operation, &operations[*count].operand1,
                  &operations[*count].operand2) != EOF && *count < MAX_OPERATIONS) {
        (*count)++;
    }

    fclose(file);
}

void perform_operation(const ArithmeticOperation *operation) {
    int result;
    if (strcmp(operation->operation, "add") == 0) {
        result = operation->operand1 + operation->operand2;
        printf("%d + %d = %d\n", operation->operand1, operation->operand2, result);
    } else if (strcmp(operation->operation, "subtract") == 0) {
        result = operation->operand1 - operation->operand2;
        printf("%d - %d = %d\n", operation->operand1, operation->operand2, result);
    } else if (strcmp(operation->operation, "multiply") == 0) {
        result = operation->operand1 * operation->operand2;
        printf("%d * %d = %d\n", operation->operand1, operation->operand2, result);
    } else if (strcmp(operation->operation, "divide") == 0) {
        if (operation->operand2 == 0) {
            printf("Error: Division by zero\n");
        } else {
            result = operation->operand1 / operation->operand2;
            printf("%d / %d = %d\n", operation->operand1, operation->operand2, result);
        }
    } else {
        printf("Unknown operation: %s\n", operation->operation);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <config_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *config_file = argv[1];
    ArithmeticOperation operations[MAX_OPERATIONS];
    int operation_count = 0;

    load_config(config_file, operations, &operation_count);

    printf("Performing arithmetic operations from config file: %s\n", config_file);
    for (int i = 0; i < operation_count; i++) {
        perform_operation(&operations[i]);
    }

    return EXIT_SUCCESS;
}