//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_OPERANDS 10

typedef struct {
    double value;
    int id;
} operand_t;

operand_t operands[MAX_OPERANDS];
int num_operands = 0;

void push(double value) {
    if (num_operands >= MAX_OPERANDS) {
        printf("Error: too many operands.\n");
        exit(1);
    }
    operands[num_operands].value = value;
    operands[num_operands].id = num_operands;
    num_operands++;
}

double pop() {
    if (num_operands == 0) {
        printf("Error: not enough operands.\n");
        exit(1);
    }
    double value = operands[num_operands - 1].value;
    num_operands--;
    return value;
}

void print_operands() {
    printf("Operands:\n");
    for (int i = 0; i < num_operands; i++) {
        printf("%d: %f\n", operands[i].id, operands[i].value);
    }
}

double evaluate_expression(char* expression) {
    double result = 0;
    int i = 0;
    while (expression[i]!= '\0') {
        if (expression[i] == '+') {
            result += pop();
        } else if (expression[i] == '-') {
            result -= pop();
        } else if (expression[i] == '*') {
            result *= pop();
        } else if (expression[i] == '/') {
            result /= pop();
        } else if (expression[i] >= '0' && expression[i] <= '9') {
            result = expression[i] - '0';
        } else {
            printf("Error: invalid expression.\n");
            exit(1);
        }
        i++;
    }
    push(result);
    return result;
}

int main() {
    char expression[100];
    printf("Enter an expression:\n");
    scanf("%s", expression);
    double result = evaluate_expression(expression);
    printf("Result: %f\n", result);
    print_operands();
    return 0;
}