//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_NUMBERS 1000
#define MAX_OPERATIONS 1000

int numbers[MAX_NUMBERS];
int operations[MAX_OPERATIONS];
int num_numbers;
int num_operations;

void generate_random_number(int *number) {
    *number = rand() % 100;
}

void generate_random_operation(int *operation) {
    *operation = rand() % 4;
}

void generate_random_operands(int *operand1, int *operand2) {
    int i;
    for (i = 0; i < num_numbers; i++) {
        if (rand() % 2 == 0) {
            *operand1 = numbers[i];
        } else {
            *operand2 = numbers[i];
        }
    }
}

int main() {
    srand(time(NULL));

    printf("Enter the number of numbers: ");
    scanf("%d", &num_numbers);

    printf("Enter the numbers:\n");
    int i;
    for (i = 0; i < num_numbers; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("Enter the number of operations: ");
    scanf("%d", &num_operations);

    printf("Enter the operations:\n");
    int j;
    for (j = 0; j < num_operations; j++) {
        int operation;
        generate_random_operation(&operation);
        operations[j] = operation;
    }

    int result;
    int operand1, operand2;
    for (j = 0; j < num_operations; j++) {
        generate_random_operands(&operand1, &operand2);
        switch (operations[j]) {
            case 0:
                result = operand1 + operand2;
                break;
            case 1:
                result = operand1 - operand2;
                break;
            case 2:
                result = operand1 * operand2;
                break;
            case 3:
                result = operand1 / operand2;
                break;
            default:
                result = 0;
                break;
        }
        printf("Operation %d: %d %c %d = %d\n", j + 1, operand1, operations[j] + '0', operand2, result);
    }

    return 0;
}