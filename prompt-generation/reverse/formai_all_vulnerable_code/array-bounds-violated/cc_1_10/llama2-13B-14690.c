//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100
#define MAX_OPERATIONS 5

typedef struct {
    int num;
    char operation;
} operation_t;

operation_t operations[MAX_OPERATIONS];
int current_operation = 0;

void parse_expression(char *expression) {
    char *token;
    int i = 0;

    while ((token = strtok(expression, " +- x")) != NULL) {
        if (i >= MAX_NUM) {
            printf("Error: Too many numbers in expression\n");
            return;
        }

        if (token[0] == 'x') {
            operations[i].operation = token[1];
        } else {
            operations[i].num = atoi(token);
        }

        i++;
    }
}

int evaluate_expression() {
    int result = 0;
    int i = 0;

    while (i < current_operation) {
        switch (operations[i].operation) {
            case '+':
                result += operations[i].num;
                break;
            case '-':
                result -= operations[i].num;
                break;
            case 'x':
                result *= operations[i].num;
                break;
        }
        i++;
    }

    return result;
}

int main() {
    srand(time(NULL));

    char expression[100];
    printf("Enter an expression: ");
    fgets(expression, 100, stdin);

    parse_expression(expression);

    int random_operation = rand() % MAX_OPERATIONS;
    operations[current_operation].operation = random_operation + '0';

    printf("Evaluating expression... ");
    int result = evaluate_expression();
    printf("Result: %d\n", result);

    return 0;
}