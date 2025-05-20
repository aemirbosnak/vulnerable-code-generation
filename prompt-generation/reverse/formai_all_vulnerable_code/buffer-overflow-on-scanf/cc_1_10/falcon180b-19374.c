//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

typedef struct {
    char *str;
    int len;
} string_t;

typedef struct {
    int top;
    int capacity;
    string_t *stack;
} stack_t;

void init_stack(stack_t *s, int capacity) {
    s->top = -1;
    s->capacity = capacity;
    s->stack = (string_t *)malloc(capacity * sizeof(string_t));
    if (s->stack == NULL) {
        printf("Failed to allocate memory for stack\n");
        exit(1);
    }
}

void push_string(stack_t *s, char *str) {
    if (s->top >= s->capacity - 1) {
        printf("Stack is full\n");
        return;
    }
    s->stack[++s->top].str = strdup(str);
    s->stack[s->top].len = strlen(str);
}

void pop_string(stack_t *s) {
    if (s->top < 0) {
        printf("Stack is empty\n");
        return;
    }
    free(s->stack[s->top].str);
    s->top--;
}

int main() {
    stack_t s;
    int choice, capacity;

    init_stack(&s, MAX_SIZE);

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Push string\n");
        printf("2. Pop string\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter string to push:\n");
            scanf("%s", s.stack[s.top].str);
            s.stack[s.top].len = strlen(s.stack[s.top].str);
            s.top++;
            break;
        case 2:
            pop_string(&s);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}