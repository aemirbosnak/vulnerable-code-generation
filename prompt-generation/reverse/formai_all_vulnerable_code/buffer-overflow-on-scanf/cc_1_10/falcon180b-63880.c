//Falcon-180B DATASET v1.0 Category: System administration ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0
#define OK      0
#define ERROR   1

typedef struct {
    char data[100];
    int top;
}stack;

void init_stack(stack *s) {
    s->top = -1;
}

int push(stack *s, char c) {
    if (s->top >= 99) {
        printf("Stack Overflow\n");
        return ERROR;
    }
    s->top++;
    s->data[++s->top] = c;
    return OK;
}

int pop(stack *s) {
    if (s->top < 0) {
        printf("Stack Underflow\n");
        return ERROR;
    }
    printf("%c", s->data[s->top--]);
    return OK;
}

int main() {
    stack s;
    init_stack(&s);

    char expression[100];
    printf("Enter an expression: ");
    scanf("%s", expression);

    int i = 0;
    while (expression[i]!= '\0') {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(&s, expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            while (s.top!= -1 && (s.data[s.top]!= '(' && s.data[s.top]!= '[' && s.data[s.top]!= '{')) {
                pop(&s);
            }
            if (s.top == -1) {
                printf("Mismatched parentheses\n");
                return ERROR;
            }
            pop(&s);
        }
        i++;
    }

    if (s.top!= -1) {
        printf("Mismatched parentheses\n");
        return ERROR;
    }

    printf("Expression is valid\n");
    return OK;
}