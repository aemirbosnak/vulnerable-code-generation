//FormAI DATASET v1.0 Category: Math exercise ; Style: interoperable
// This program asks the user to input a mathematical expression in infix notation and
// converts it to postfix notation using the shunting yard algorithm. It then evaluates
// the postfix expression to get the final answer using a stack.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_EXPR_LEN 100

// Stack implementation using a linked list
typedef struct Node {
    double data;
    struct Node* next;
} Node;

Node* create_node(double data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Out of memory!\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

Node* push(Node* top, double data) {
    Node* new_node = create_node(data);
    new_node->next = top;
    return new_node;
}

double pop(Node** top) {
    if (*top == NULL) {
        printf("Stack is empty!\n");
        exit(1);
    }
    double data = (*top)->data;
    (*top) = (*top)->next;
    return data;
}

double peek(Node* top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        exit(1);
    }
    return top->data;
}

int is_operator(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/';
}

int get_precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else {
        return 0;
    }
}

void infix_to_postfix(char* infix, char* postfix) {
    Node* op_stack = NULL;
    int postfix_index = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        if (isdigit(infix[i])) {
            while (isdigit(infix[i])) {
                postfix[postfix_index++] = infix[i++];
            }
            postfix[postfix_index++] = ' ';
            i--;
        } else if (is_operator(infix[i])) {
            while (op_stack != NULL && is_operator(peek(op_stack))
                   && get_precedence(infix[i]) <= get_precedence(peek(op_stack))) {
                postfix[postfix_index++] = pop(&op_stack);
                postfix[postfix_index++] = ' ';
            }
            op_stack = push(op_stack, infix[i]);
        } else if (infix[i] == '(') {
            op_stack = push(op_stack, infix[i]);
        } else if (infix[i] == ')') {
            while (peek(op_stack) != '(') {
                postfix[postfix_index++] = pop(&op_stack);
                postfix[postfix_index++] = ' ';
            }
            pop(&op_stack);
        }
    }

    while (op_stack != NULL) {
        postfix[postfix_index++] = pop(&op_stack);
        postfix[postfix_index++] = ' ';
    }

    postfix[postfix_index] = '\0';
}

double evaluate_postfix(char* postfix) {
    Node* num_stack = NULL;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            int num = atoi(&postfix[i]);
            while (isdigit(postfix[i+1])) {
                i++;
                num = num * 10 + atoi(&postfix[i]);
            }
            num_stack = push(num_stack, num);
        } else if (postfix[i] == ' ') {
            continue;
        } else {
            double num2 = pop(&num_stack);
            double num1 = pop(&num_stack);
            switch (postfix[i]) {
                case '+': num_stack = push(num_stack, num1 + num2); break;
                case '-': num_stack = push(num_stack, num1 - num2); break;
                case '*': num_stack = push(num_stack, num1 * num2); break;
                case '/': num_stack = push(num_stack, num1 / num2); break;
            }
        }
    }

    double result = pop(&num_stack);
    return result;
}

int main() {
    char infix[MAX_EXPR_LEN];
    char postfix[MAX_EXPR_LEN];

    printf("Enter a mathematical expression in infix notation: ");
    fgets(infix, MAX_EXPR_LEN, stdin);
    infix[strlen(infix)-1] = '\0';

    infix_to_postfix(infix, postfix);
    printf("Postfix notation: %s\n", postfix);

    double result = evaluate_postfix(postfix);
    printf("Result: %lf\n", result);

    return 0;
}