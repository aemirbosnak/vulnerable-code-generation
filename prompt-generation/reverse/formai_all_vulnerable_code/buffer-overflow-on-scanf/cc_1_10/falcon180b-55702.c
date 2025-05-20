//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

char input[MAX_SIZE];
char postfix[MAX_SIZE];
int top = -1;

void push(char c) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(0);
    }
    postfix[++top] = c;
}

char pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        exit(0);
    }
    return postfix[top--];
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

void infixToPostfix(char infix[]) {
    int i = 0;
    char temp[MAX_SIZE];

    while (infix[i]) {
        if (isalnum(infix[i])) {
            strcat(temp, infix[i]);
            strcat(temp, " ");
        } else {
            while (!isalnum(infix[i]) && infix[i]!= '(' && infix[i]!= ')')
                i++;

            if (infix[i] == '(') {
                push(infix[i]);
                i++;
            } else if (infix[i] == ')') {
                while (postfix[top]!= '(') {
                    strcat(temp, postfix[top]);
                    strcat(temp, " ");
                    pop();
                }
                pop();
            } else {
                while (precedence(infix[i]) <= precedence(postfix[top])) {
                    strcat(temp, postfix[top]);
                    strcat(temp, " ");
                    pop();
                }
                push(infix[i]);
            }
        }
        i++;
    }

    while (top >= 0) {
        strcat(temp, postfix[top]);
        strcat(temp, " ");
        pop();
    }

    strcpy(input, temp);
}

int evaluatePostfix(char postfix[]) {
    int i = 0, j, k, result = 0;
    char temp[MAX_SIZE];

    while (postfix[i]) {
        if (isdigit(postfix[i])) {
            strcat(temp, postfix[i]);
            while (isdigit(postfix[++i]))
                strcat(temp, postfix[i]);
            result += atoi(temp);
            temp[0] = '\0';
        } else {
            switch (postfix[i]) {
                case '+':
                    result += evaluatePostfix(++i);
                    break;
                case '-':
                    result -= evaluatePostfix(++i);
                    break;
                case '*':
                    result *= evaluatePostfix(++i);
                    break;
                case '/':
                    result /= evaluatePostfix(++i);
                    break;
                case '^':
                    result = pow(evaluatePostfix(++i), evaluatePostfix(++i));
                    break;
            }
        }
        i++;
    }

    return result;
}

int main() {
    printf("Enter the expression: ");
    scanf("%s", input);

    infixToPostfix(input);

    printf("Postfix expression: %s\n", input);
    printf("Result: %d\n", evaluatePostfix(input));

    return 0;
}