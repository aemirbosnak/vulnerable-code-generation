//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char symbol;
    int priority;
    struct Node* next;
} Node;

Node* stack = NULL;

void push(char symbol, int priority) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->symbol = symbol;
    newNode->priority = priority;
    newNode->next = stack;
    stack = newNode;
}

char pop() {
    if (stack == NULL) {
        printf("Error: Stack is empty.\n");
        exit(1);
    }
    char symbol = stack->symbol;
    Node* temp = stack;
    stack = stack->next;
    free(temp);
    return symbol;
}

int precedence(char op) {
    switch (op) {
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

void translate(char* input) {
    int i = 0;
    while (input[i] != '\0') {
        if (isdigit(input[i])) {
            printf("%c ", input[i]);
            i++;
            continue;
        }

        if (precedence(input[i]) == -1) {
            if (input[i] == '(') {
                push(input[i], 0);
                i++;
                continue;
            } else if (input[i] == ')') {
                while (stack->symbol != '(') {
                    char op = pop();
                    printf("%c ", op);
                }
                pop();
                i++;
                continue;
            }
        }

        while (stack != NULL && precedence(stack->symbol) >= precedence(input[i])) {
            char op = pop();
            printf("%c ", op);
        }

        push(input[i], precedence(input[i]));
        i++;
    }

    while (stack != NULL) {
        char op = pop();
        printf("%c ", op);
    }

    printf("\n");
}

int main() {
    char input[100];
    printf("Enter a C Cat Language expression: ");
    scanf("%s", input);
    translate(input);
    return 0;
}

// The Cats meow of expression trees,
// In elegant code we trust, we truly believe,
// Our C Cat Language Translator will grieve,
// No more syntax errors, no more grief.
//
// Just enter an expression, pure and simple,
// And let our translator work its magic,
// No more frustration, no more huff and puff,
// Our C Cat Language Translator is always enough.