//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max_Size 1000

typedef struct {
    char data[Max_Size];
    int top;
} Stack;

void push(Stack *s, char c) {
    if (s->top >= Max_Size - 1) {
        printf("Stack Overflow\n");
        exit(0);
    }
    s->data[++s->top] = c;
}

char pop(Stack *s) {
    if (s->top <= 0) {
        printf("Stack Underflow\n");
        exit(0);
    }
    return s->data[s->top--];
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int is_full(Stack *s) {
    return s->top == Max_Size - 1;
}

int main() {
    char str[Max_Size];
    Stack s;
    s.top = -1;

    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    printf("Stack: ");

    while (!is_empty(&s)) {
        printf("%c", pop(&s));
    }

    printf("\n");

    return 0;
}