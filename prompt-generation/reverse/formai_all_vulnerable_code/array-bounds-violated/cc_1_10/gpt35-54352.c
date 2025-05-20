//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

#define MAX_SIZE 100

// Function to check if the given character is an operator or not
int is_operator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return 1;
    }
    return 0;
}

// Function to evaluate the given infix expression
double evaluate(char *exp) {
    char stack[MAX_SIZE];
    int top = -1;
    int i;
    double num, num1, num2, result;
    for(i = 0; i < strlen(exp); i++) {
        if(isdigit(exp[i])) {
            // If the character is a digit, then push it onto the stack
            num = 0;
            while(isdigit(exp[i])) {
                num = num * 10 + (double)(exp[i] - '0');
                i++;
            }
            i--;
            stack[++top] = num;
        }
        else if(is_operator(exp[i])) {
            // If the character is an operator, then pop two values from the stack and evaluate
            num2 = stack[top--];
            num1 = stack[top--];
            switch(exp[i]) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    result = num1 / num2;
                    break;
                case '^':
                    result = pow(num1, num2);
                    break;
            }
            // Push the result back onto the stack
            stack[++top] = result;
        }
    }
    return stack[top--];
}

int main() {
    char exp[MAX_SIZE];
    printf("Enter an infix expression: ");
    fgets(exp, sizeof(exp), stdin);
    printf("The result is: %.2lf", evaluate(exp));
    return 0;
}