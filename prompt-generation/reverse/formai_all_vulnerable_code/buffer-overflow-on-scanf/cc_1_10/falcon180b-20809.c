//Falcon-180B DATASET v1.0 Category: Recursive ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int top = -1;
char stack[MAX];

void push(char c) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        exit(0);
    }
    stack[++top] = c;
}

char pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        exit(0);
    }
    return stack[top--];
}

int is_empty() {
    return (top == -1);
}

int is_full() {
    return (top >= MAX - 1);
}

void reverse(char s[]) {
    int i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main() {
    char s[MAX];
    printf("Enter a string: ");
    scanf("%s", s);
    int i;
    for (i = 0; s[i]!= '\0'; i++) {
        if (isalpha(s[i])) {
            push(tolower(s[i]));
        }
    }
    printf("The reversed string is: ");
    while (!is_empty()) {
        printf("%c", pop());
    }
    printf("\n");
    return 0;
}