//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define MAX 1000000

void push(char *s, int top, char c) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        exit(0);
    }
    s[++top] = c;
}

int is_empty(char *s, int top) {
    if (top == -1)
        return 1;
    else
        return 0;
}

int is_full(char *s, int top) {
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

char pop(char *s, int *top) {
    char c;
    if (is_empty(s, *top)) {
        printf("Stack Underflow\n");
        exit(0);
    }
    c = s[*top--];
    return c;
}

void display(char *s, int top) {
    if (is_empty(s, top))
        printf("Stack is Empty\n");
    else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--)
            printf("%c", s[i]);
        printf("\n");
    }
}

int main() {
    char s[MAX];
    int top = -1;
    char choice;
    int val;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                printf("Enter the value to be pushed into the stack: ");
                scanf("%d", &val);
                push(s, top, val);
                break;
            case '2':
                pop(s, &top);
                break;
            case '3':
                display(s, top);
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}