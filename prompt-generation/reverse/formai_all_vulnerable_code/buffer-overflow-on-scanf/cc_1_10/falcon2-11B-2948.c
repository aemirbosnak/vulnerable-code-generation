//Falcon2-11B DATASET v1.0 Category: Syntax parsing ; Style: retro
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct Node {
    char* str;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, char* str) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->str = str;
    node->next = stack->top;
    stack->top = node;
}

char* pop(Stack* stack) {
    if (stack->top == NULL) {
        return NULL;
    }
    Node* node = stack->top;
    stack->top = node->next;
    char* str = node->str;
    free(node);
    return str;
}

int main() {
    Stack* stack = createStack();
    char input[100];
    scanf("%[^\n]", input);
    while (input[0]!= '}') {
        char* token = pop(stack);
        printf("%s", token);
        scanf("%[^\n]", input);
    }
    printf("}");
    return 0;
}