//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 100

char input[MAX_SIZE];
int pos = 0;

void push(char c) {
    if (pos >= MAX_SIZE - 1) {
        printf("Error: Input too long\n");
        exit(1);
    }
    input[pos++] = c;
}

char pop() {
    if (pos <= 0) {
        printf("Error: Input too short\n");
        exit(1);
    }
    return input[--pos];
}

int is_operator(char c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
        default:
            return 0;
    }
}

int is_digit(char c) {
    return isdigit(c);
}

int is_space(char c) {
    return isspace(c);
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}

void evaluate() {
    char op;
    while (!is_space(input[pos])) {
        if (is_digit(input[pos])) {
            printf("%c", input[pos]);
        } else if (is_operator(input[pos])) {
            op = input[pos];
            while (precedence(op) <= precedence(input[pos - 1])) {
                printf("%c", pop());
            }
            push(op);
        }
        pos++;
    }
    while (!is_space(input[pos])) {
        if (is_digit(input[pos])) {
            printf("%c", input[pos]);
        } else if (is_operator(input[pos])) {
            op = input[pos];
            while (precedence(op) <= precedence(input[pos - 1])) {
                printf("%c", pop());
            }
            push(op);
        }
        pos++;
    }
}

int main() {
    printf("Enter an expression: ");
    fgets(input, MAX_SIZE, stdin);
    evaluate();
    printf("\n");
    return 0;
}