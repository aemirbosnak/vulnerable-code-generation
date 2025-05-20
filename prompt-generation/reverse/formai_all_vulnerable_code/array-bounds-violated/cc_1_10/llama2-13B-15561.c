//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NUM 100000
#define MAX_OPERATIONS 10

typedef struct {
    int num;
    char operation;
} operation_t;

operation_t operations[MAX_OPERATIONS];
int current_operation = 0;

void init_operations() {
    int i;
    for (i = 0; i < MAX_OPERATIONS; i++) {
        operations[i].num = 0;
        operations[i].operation = '+';
    }
}

void add_operation(char operation) {
    if (current_operation < MAX_OPERATIONS) {
        operations[current_operation].operation = operation;
        current_operation++;
    }
}

void execute_operations() {
    int i;
    for (i = 0; i < current_operation; i++) {
        switch (operations[i].operation) {
            case '+':
                printf("Adding %d and %d...\n", operations[i - 1].num, operations[i].num);
                operations[i - 1].num += operations[i].num;
                break;
            case '-':
                printf("Subtracting %d from %d...\n", operations[i].num, operations[i - 1].num);
                operations[i - 1].num -= operations[i].num;
                break;
            case '*':
                printf("Multiplying %d by %d...\n", operations[i - 1].num, operations[i].num);
                operations[i - 1].num *= operations[i].num;
                break;
            case '/':
                printf("Dividing %d by %d...\n", operations[i - 1].num, operations[i].num);
                if (operations[i].num == 0) {
                    printf("Error: cannot divide by zero!\n");
                    return;
                }
                operations[i - 1].num /= operations[i].num;
                break;
            default:
                printf("Invalid operation %c\n", operations[i].operation);
                break;
        }
    }
}

int main() {
    srand(time(NULL));
    init_operations();

    while (1) {
        char operation;
        printf("Enter an operation (+, -, *, /): ");
        scanf("%c", &operation);

        add_operation(operation);

        execute_operations();

        if (current_operation == MAX_OPERATIONS) {
            printf("Too many operations! Ending program.\n");
            break;
        }
    }

    return 0;
}