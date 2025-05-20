//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ENTRIES 100
#define FILENAME "math_operations.txt"

// Struct to store mathematical operations
typedef struct {
    char operation[10];
    double operand1;
    double operand2;
    double result;
} MathOperation;

// Function prototypes
void add_operation(MathOperation *op);
void save_operations(const MathOperation *operations, int count);
void load_operations(MathOperation *operations, int *count);
void display_operations(const MathOperation *operations, int count);
void clear_operations(MathOperation *operations, int *count);

// Main function
int main() {
    MathOperation operations[MAX_ENTRIES];
    int count = 0;
    int choice;

    load_operations(operations, &count);

    do {
        printf("\nMath Operations Menu:\n");
        printf("1. Add Operation\n");
        printf("2. Display Operations\n");
        printf("3. Clear Operations\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_operation(&operations[count]);
                count++;
                break;
            case 2:
                display_operations(operations, count);
                break;
            case 3:
                clear_operations(operations, &count);
                break;
            case 4:
                printf("Exiting... Saving operations to file.\n");
                save_operations(operations, count);
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Function to add a mathematical operation
void add_operation(MathOperation *op) {
    printf("Enter operation (add, subtract, multiply, divide): ");
    scanf("%s", op->operation);
    printf("Enter first operand: ");
    scanf("%lf", &op->operand1);
    printf("Enter second operand: ");
    scanf("%lf", &op->operand2);

    if (strcmp(op->operation, "add") == 0) {
        op->result = op->operand1 + op->operand2;
    } else if (strcmp(op->operation, "subtract") == 0) {
        op->result = op->operand1 - op->operand2;
    } else if (strcmp(op->operation, "multiply") == 0) {
        op->result = op->operand1 * op->operand2;
    } else if (strcmp(op->operation, "divide") == 0) {
        if (op->operand2 != 0) {
            op->result = op->operand1 / op->operand2;
        } else {
            printf("Error: Division by zero!\n");
            op->result = NAN;
        }
    } else {
        printf("Invalid operation!\n");
        strcpy(op->operation, "invalid");
        op->result = NAN;
    }
}

// Function to save operations to a file
void save_operations(const MathOperation *operations, int count) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (strcmp(operations[i].operation, "invalid") != 0) {
            fprintf(file, "%s %.2f %.2f = %.2f\n",
                    operations[i].operation,
                    operations[i].operand1,
                    operations[i].operand2,
                    operations[i].result);
        }
    }

    fclose(file);
}

// Function to load operations from a file
void load_operations(MathOperation *operations, int *count) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No previous operations found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, "%s %lf %lf = %lf",
                  operations[*count].operation,
                  &operations[*count].operand1,
                  &operations[*count].operand2,
                  &operations[*count].result) == 4) {
        (*count)++;
        if (*count >= MAX_ENTRIES) {
            break;
        }
    }

    fclose(file);
}

// Function to display operations
void display_operations(const MathOperation *operations, int count) {
    if (count == 0) {
        printf("No operations to display.\n");
        return;
    }

    printf("\nOperations performed:\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(operations[i].operation, "invalid") != 0) {
            printf("%s %.2f %.2f = %.2f\n",
                   operations[i].operation,
                   operations[i].operand1,
                   operations[i].operand2,
                   operations[i].result);
        }
    }
}

// Function to clear operations
void clear_operations(MathOperation *operations, int *count) {
    *count = 0;
    printf("All operations cleared.\n");
}