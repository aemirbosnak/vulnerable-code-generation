//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

typedef struct {
    int num1;
    int num2;
    int result;
} arithmetic_op;

arithmetic_op ops[MAX];

void generate_random_numbers(arithmetic_op* op) {
    op->num1 = rand() % 10 + 1;
    op->num2 = rand() % 10 + 1;
}

void add(arithmetic_op* op) {
    op->result = op->num1 + op->num2;
}

void subtract(arithmetic_op* op) {
    op->result = op->num1 - op->num2;
}

void multiply(arithmetic_op* op) {
    op->result = op->num1 * op->num2;
}

void divide(arithmetic_op* op) {
    if (op->num2 != 0)
        op->result = op->num1 / op->num2;
    else {
        printf("Error: Division by zero is not allowed.\n");
        op->result = -1;
    }
}

int main() {
    int choice, i;
    arithmetic_op op;

    srand(time(NULL));

    for (i = 0; i < MAX; i++) {
        generate_random_numbers(&ops[i]);
        printf("Performing operation %d:\n", i + 1);
        printf("Number 1: %d\n", ops[i].num1);
        printf("Number 2: %d\n", ops[i].num2);

        printf("Enter the operation number:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add(&ops[i]);
                printf("Result: %d\n", ops[i].result);
                break;
            case 2:
                subtract(&ops[i]);
                printf("Result: %d\n", ops[i].result);
                break;
            case 3:
                multiply(&ops[i]);
                printf("Result: %d\n", ops[i].result);
                break;
            case 4:
                divide(&ops[i]);
                if (ops[i].result != -1)
                    printf("Result: %d\n", ops[i].result);
                break;
            default:
                printf("Invalid operation number.\n");
                break;
        }
    }

    return 0;
}