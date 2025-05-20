//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    int top;
    int **stacks;
} tower;

void create_tower(int n, tower *t) {
    t->n = n;
    t->top = -1;
    t->stacks = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        t->stacks[i] = (int *)malloc(100 * sizeof(int)); // assuming max 100 disks
    }
}

void push(int disk, tower *t) {
    if (t->top >= t->n - 1) {
        printf("Cannot push disk %d\n", disk);
        return;
    }
    t->stacks[++t->top][t->n - 1 - t->top] = disk;
}

int pop(tower *t) {
    if (t->top < 0) {
        printf("Cannot pop disk\n");
        return -1;
    }
    return t->stacks[t->top--][t->n - 1 - t->top];
}

void move_tower(int n, int from, int to, int aux, tower *t) {
    if (n == 1) {
        push(pop(t), t);
        return;
    }
    move_tower(n - 1, from, aux, to, t);
    push(pop(t), t);
    move_tower(n - 1, aux, to, from, t);
}

void print_tower(tower *t) {
    for (int i = 0; i <= t->top; i++) {
        for (int j = 0; j < t->n; j++) {
            printf("%d ", t->stacks[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    tower t;
    create_tower(n, &t);
    for (int i = n; i >= 1; i--) {
        push(i, &t);
    }
    printf("Initial tower:\n");
    print_tower(&t);
    move_tower(n, 0, 2, 1, &t);
    printf("\nFinal tower:\n");
    print_tower(&t);
    return 0;
}