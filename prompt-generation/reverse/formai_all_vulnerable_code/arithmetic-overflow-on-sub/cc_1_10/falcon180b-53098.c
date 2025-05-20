//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISK 10
#define MAX_ROD 30
#define MAX_MOVE 1000

typedef struct {
    int top;
    int size;
    int *data;
} Stack;

void init(Stack *s, int size) {
    s->top = -1;
    s->size = size;
    s->data = (int *) malloc(size * sizeof(int));
}

void push(Stack *s, int x) {
    if (s->top >= s->size - 1) {
        printf("Stack is full\n");
        exit(1);
    }
    s->data[++s->top] = x;
}

int pop(Stack *s) {
    if (s->top < 0) {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->data[s->top--];
}

void print_stack(Stack s) {
    printf("Stack: ");
    for (int i = s.top; i >= 0; i--) {
        printf("%d ", s.data[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    Stack A, B, C;
    init(&A, n);
    init(&B, n);
    init(&C, n);

    printf("Initial configuration:\n");
    for (int i = n - 1; i >= 0; i--) {
        push(&A, i);
    }
    print_stack(A);

    int moves = 0;
    while (moves < MAX_MOVE) {
        if (move_disk(&A, &C, &B, n)) {
            moves++;
            printf("Move disk %d from A to C\n", pop(&A));
            print_stack(A);
            print_stack(B);
            print_stack(C);
        } else {
            printf("No moves left\n");
            break;
        }
    }

    return 0;
}

int move_disk(Stack *A, Stack *C, Stack *B, int n) {
    if (n == 1) {
        push(C, pop(A));
        return 1;
    }

    if (move_disk(A, B, C, n - 1)) {
        push(C, pop(A));
        push(B, pop(C));
        push(A, pop(B));
        return 1;
    }

    return 0;
}