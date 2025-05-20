//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define TRUE 1
#define FALSE 0
#define DELAY 100000 // 100ms

typedef struct {
    int top;
    int *stack;
} Stack;

void push(Stack *s, int x) {
    if (s->top == MAX) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
    s->stack[++(s->top)] = x;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    return s->stack[s->top--];
}

int is_empty(Stack *s) {
    return (s->top == -1);
}

int main() {
    int n, i, j, k, choice;
    Stack A, B, C;
    char ch;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    A.top = -1;
    B.top = -1;
    C.top = -1;
    printf("Do you want to play the game? (y/n): ");
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y') {
        printf("Romeo's turn:\n");
        for (i = n; i >= 1; i--) {
            push(&A, i);
            printf("%d moved from Juliet to Romeo\n", i);
            printf("Press any key to continue...");
            fflush(stdin);
            getchar();
        }
        printf("\nJuliet's turn:\n");
        for (i = n; i >= 1; i--) {
            pop(&A);
            printf("%d moved from Romeo to Juliet\n", i);
            printf("Press any key to continue...");
            fflush(stdin);
            getchar();
        }
    } else {
        printf("Sorry, the game cannot be played.\n");
    }
    return 0;
}