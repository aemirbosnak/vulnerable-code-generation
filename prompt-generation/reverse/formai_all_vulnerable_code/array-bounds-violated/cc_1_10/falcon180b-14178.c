//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAX_NUM_SIZE 1000
#define MAX_OPERATORS 100

char num[MAX_NUM_SIZE];
int pos = 0;
int num_size = 0;

char operators[MAX_OPERATORS][4];
int num_operators = 0;

void push_operator(char op) {
    if (num_operators == MAX_OPERATORS) {
        printf("Error: Too many operators\n");
        exit(1);
    }
    strcpy(operators[num_operators], op);
    num_operators++;
}

char pop_operator() {
    if (num_operators == 0) {
        printf("Error: No operators to pop\n");
        exit(1);
    }
    char op = operators[--num_operators][0];
    return op;
}

int is_operator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return 1;
    }
    return 0;
}

int is_digit(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

void clear() {
    pos = 0;
    num_size = 0;
    num[0] = '\0';
    num_operators = 0;
}

void append_number(char c) {
    if (num_size == MAX_NUM_SIZE) {
        printf("Error: Number too large\n");
        exit(1);
    }
    num[num_size++] = c;
    num[num_size] = '\0';
}

int evaluate_expression(char* expression) {
    int result = 0;
    int i = 0;
    while (expression[i]) {
        if (is_digit(expression[i])) {
            result = result * 10 + (expression[i] - '0');
        } else if (is_operator(expression[i])) {
            char op = expression[i];
            int num2 = result;
            result = 0;
            while (operators[num_operators - 1][0]!= op) {
                result = result * 10 + pop_operator();
            }
            result = result * 10 + num2;
        }
        i++;
    }
    return result;
}

int main() {
    clear();
    printf("Enter an expression: ");
    fgets(num, MAX_NUM_SIZE, stdin);
    int pos = 0;
    while (num[pos]) {
        if (is_digit(num[pos])) {
            push_operator(num[pos]);
        } else if (is_operator(num[pos])) {
            push_operator(num[pos]);
        }
        pos++;
    }
    int result = evaluate_expression(num);
    printf("Result: %d\n", result);
    return 0;
}