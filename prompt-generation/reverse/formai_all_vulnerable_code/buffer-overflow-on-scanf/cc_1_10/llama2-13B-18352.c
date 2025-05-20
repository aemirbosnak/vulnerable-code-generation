//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER_OF_OPERATIONS 100
#define MAX_NUMBER 1000

typedef struct operation {
    char operator;
    int num1;
    int num2;
} operation;

operation operations[MAX_NUMBER_OF_OPERATIONS];
int num_operations = 0;

void add_operation(char op, int num1, int num2) {
    operations[num_operations].operator = op;
    operations[num_operations].num1 = num1;
    operations[num_operations].num2 = num2;
    num_operations++;
}

void execute_operations() {
    for (int i = 0; i < num_operations; i++) {
        switch (operations[i].operator) {
            case '+':
                printf("%d + %d = %d\n", operations[i].num1, operations[i].num2, operations[i].num1 + operations[i].num2);
                break;
            case '-':
                printf("%d - %d = %d\n", operations[i].num1, operations[i].num2, operations[i].num1 - operations[i].num2);
                break;
            case '*':
                printf("%d * %d = %d\n", operations[i].num1, operations[i].num2, operations[i].num1 * operations[i].num2);
                break;
            case '/':
                printf("%d / %d = %d\n", operations[i].num1, operations[i].num2, operations[i].num1 / operations[i].num2);
                break;
            default:
                printf("Invalid operator %c\n", operations[i].operator);
                break;
        }
    }
}

int main() {
    srand(time(NULL));

    char op;
    int num1, num2;

    for (int i = 0; i < MAX_NUMBER_OF_OPERATIONS; i++) {
        do {
            printf("Enter an operation (+, -, *, /, or a character to quit): ");
            scanf(" %c", &op);
            printf("Enter two numbers: ");
            scanf("%d%d", &num1, &num2);
            add_operation(op, num1, num2);
        } while (op != 'q');
    }

    execute_operations();

    return 0;
}