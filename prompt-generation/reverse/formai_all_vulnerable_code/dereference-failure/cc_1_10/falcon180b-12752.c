//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

typedef struct {
    int size;
    int top;
    int* stack;
} tower;

void init_tower(tower* t, int size) {
    t->size = size;
    t->top = -1;
    t->stack = (int*) malloc(size * sizeof(int));
}

void push(tower* t, int disk) {
    if (t->top >= t->size - 1) {
        printf("Error: Tower is full.\n");
        return;
    }
    t->top++;
    t->stack[t->top] = disk;
}

int pop(tower* t) {
    if (t->top < 0) {
        printf("Error: Tower is empty.\n");
        return -1;
    }
    int disk = t->stack[t->top];
    t->top--;
    return disk;
}

void print_tower(tower* t) {
    for (int i = t->top; i >= 0; i--) {
        printf("%d ", t->stack[i]);
    }
    printf("\n");
}

void move_disk(tower* from, tower* to, tower* aux) {
    int disk = pop(from);
    printf("Move disk %d from tower %d to tower %d\n", disk, from->top, to->top);
    push(to, disk);
}

void hanoi(int n, tower* from, tower* to, tower* aux) {
    if (n == 1) {
        move_disk(from, to, aux);
        return;
    }
    hanoi(n - 1, from, aux, to);
    move_disk(from, to, aux);
    hanoi(n - 1, aux, to, from);
}

int main() {
    srand(time(NULL));
    int n = rand() % MAX_DISKS + 3;
    tower from, to, aux;
    init_tower(&from, n);
    init_tower(&to, n);
    init_tower(&aux, n);
    for (int i = n - 1; i >= 0; i--) {
        push(&from, i);
    }
    printf("Initial towers:\n");
    print_tower(&from);
    print_tower(&to);
    print_tower(&aux);
    hanoi(n, &from, &to, &aux);
    printf("Final towers:\n");
    print_tower(&from);
    print_tower(&to);
    print_tower(&aux);
    return 0;
}