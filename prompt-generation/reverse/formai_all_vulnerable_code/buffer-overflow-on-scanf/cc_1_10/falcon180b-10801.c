//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DISKS 100

typedef struct {
    int top;
    int capacity;
    int *disks;
} Tower;

void init_tower(Tower *tower, int capacity) {
    tower->top = -1;
    tower->capacity = capacity;
    tower->disks = malloc(capacity * sizeof(int));
    memset(tower->disks, 0, capacity * sizeof(int));
}

void destroy_tower(Tower *tower) {
    free(tower->disks);
}

int is_empty(Tower *tower) {
    return tower->top == -1;
}

int is_full(Tower *tower) {
    return tower->top == tower->capacity - 1;
}

void push(Tower *tower, int disk) {
    if (is_full(tower)) {
        printf("Error: Tower is full\n");
        return;
    }
    tower->disks[++tower->top] = disk;
}

int pop(Tower *tower) {
    if (is_empty(tower)) {
        printf("Error: Tower is empty\n");
        return -1;
    }
    return tower->disks[tower->top--];
}

void move_disk(Tower *from, Tower *to, int n) {
    if (n == 1) {
        push(to, pop(from));
        return;
    }
    move_disk(from, to, n - 1);
    push(to, pop(from));
    push(from, pop(to));
}

void print_tower(Tower *tower) {
    int i;
    for (i = tower->top; i >= 0; i--) {
        printf("%d ", tower->disks[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    Tower from, to, aux;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    init_tower(&from, n);
    init_tower(&to, n);
    init_tower(&aux, n);

    printf("Initial state:\n");
    print_tower(&from);

    move_disk(&from, &to, n);

    printf("Final state:\n");
    print_tower(&to);

    destroy_tower(&from);
    destroy_tower(&to);
    destroy_tower(&aux);

    return 0;
}