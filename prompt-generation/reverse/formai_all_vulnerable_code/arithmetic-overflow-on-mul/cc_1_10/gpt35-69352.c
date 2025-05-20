//FormAI DATASET v1.0 Category: Syntax parsing ; Style: creative
#include <stdio.h>

// Function to check if given character is a digit
int isDigit(char c) {
    if(c >= '0' && c <= '9') {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if given character is an operator
int isOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/') {
        return 1;
    } else {
        return 0;
    }
}

// Function to evaluate postfix expression
int evalPostfix(char postfix[]) {
    int stack[100], top = -1, i;
    int res;
    char c;

    for(i = 0; postfix[i] != '\0'; i++) {
        c = postfix[i];
        if(isDigit(c)) {
            stack[++top] = c - '0';
        } else if(isOperator(c)) {
            int op1 = stack[top--];
            int op2 = stack[top--];
            switch(c) {
                case '+':
                    res = op2 + op1;
                    break;
                case '-':
                    res = op2 - op1;
                    break;
                case '*':
                    res = op2 * op1;
                    break;
                case '/':
                    res = op2 / op1;
                    break;
            }
            stack[++top] = res;
        }
    }

    return stack[top];
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evalPostfix(postfix);
    printf("Result of postfix expression is: %d", result);

    return 0;
}