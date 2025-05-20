//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100000
#define MAX_OPERATIONS 10

typedef struct {
    int num1;
    int num2;
    char operation;
} operation_t;

operation_t operations[MAX_OPERATIONS];
int current_operation = 0;

void add_operation(char operation) {
    operations[current_operation].operation = operation;
    current_operation++;
}

void execute_operation() {
    int result;
    switch (operations[current_operation - 1].operation) {
        case '+':
            result = operations[current_operation - 2].num1 + operations[current_operation - 2].num2;
            break;
        case '-':
            result = operations[current_operation - 2].num1 - operations[current_operation - 2].num2;
            break;
        case '*':
            result = operations[current_operation - 2].num1 * operations[current_operation - 2].num2;
            break;
        case '/':
            result = operations[current_operation - 2].num1 / operations[current_operation - 2].num2;
            break;
        default:
            result = -1;
    }
    printf("Result of operation %c is %d\n", operations[current_operation - 1].operation, result);
    current_operation--;
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < MAX_NUM; i++) {
        operations[i].num1 = rand() % 100;
        operations[i].num2 = rand() % 100;
        add_operation(rand() % 4 + '+');
    }

    while (current_operation > 0) {
        execute_operation();
    }

    return 0;
}