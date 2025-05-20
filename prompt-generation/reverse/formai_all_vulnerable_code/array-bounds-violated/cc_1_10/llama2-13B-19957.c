//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100000
#define MAX_OPERATIONS 10

typedef struct {
    int num;
    char operation;
} operation_t;

operation_t operations[MAX_OPERATIONS];
int num_operations = 0;

void add_operation(char operation) {
    operations[num_operations].operation = operation;
    operations[num_operations].num = 0;
    num_operations++;
}

void evaluate(void) {
    int result = 0;
    for (int i = 0; i < num_operations; i++) {
        switch (operations[i].operation) {
            case '+':
                result += operations[i].num;
                break;
            case '-':
                result -= operations[i].num;
                break;
            case '*':
                result *= operations[i].num;
                break;
            case '/':
                result /= operations[i].num;
                break;
        }
    }
    printf("Result: %d\n", result);
}

int main(void) {
    srand(time(NULL));
    for (int i = 0; i < MAX_NUM; i++) {
        operations[i].num = rand() % 100;
        add_operation(rand() % 4);
    }
    evaluate();
    return 0;
}