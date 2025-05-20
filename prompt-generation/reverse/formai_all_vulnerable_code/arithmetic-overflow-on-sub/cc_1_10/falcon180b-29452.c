//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DISKS 10

typedef struct {
    int top;
    int capacity;
    int *tower;
} Tower;

void init_tower(Tower *tower, int capacity) {
    tower->top = -1;
    tower->capacity = capacity;
    tower->tower = (int *)malloc(capacity * sizeof(int));
}

void free_tower(Tower *tower) {
    free(tower->tower);
}

void push(Tower *tower, int disk) {
    if (tower->top >= tower->capacity - 1) {
        printf("Error: Tower is full.\n");
        return;
    }
    tower->tower[++tower->top] = disk;
}

int pop(Tower *tower) {
    if (tower->top < 0) {
        printf("Error: Tower is empty.\n");
        return -1;
    }
    return tower->tower[tower->top--];
}

void display_tower(Tower *tower) {
    if (tower->top < 0) {
        printf("Empty tower\n");
        return;
    }
    printf("Tower: ");
    for (int i = tower->top; i >= 0; i--) {
        printf("%d ", tower->tower[i]);
    }
    printf("\n");
}

void move_disk(Tower *src, Tower *dst, int n) {
    if (n == 1) {
        push(dst, pop(src));
        return;
    }
    move_disk(src, dst, n - 1);
    push(dst, pop(src));
    move_disk(src, dst, n - 1);
}

int main() {
    Tower src, dst, aux;
    int n, disk;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    init_tower(&src, n);
    init_tower(&dst, n);
    init_tower(&aux, n);

    printf("Enter the disks (1-%d): ", n);
    for (int i = n - 1; i >= 0; i--) {
        scanf("%d", &disk);
        push(&src, disk);
    }

    display_tower(&src);

    move_disk(&src, &dst, n);

    display_tower(&dst);

    free_tower(&src);
    free_tower(&dst);
    free_tower(&aux);

    return 0;
}