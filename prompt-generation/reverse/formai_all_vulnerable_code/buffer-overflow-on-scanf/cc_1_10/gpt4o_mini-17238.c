//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISK 10

typedef struct {
    int disks[MAX_DISK];
    int top;
} Tower;

void initTower(Tower *t) {
    t->top = -1; // Initialize tower as empty
}

int isFull(Tower *t) {
    return t->top == MAX_DISK - 1;
}

int isEmpty(Tower *t) {
    return t->top == -1;
}

void push(Tower *t, int disk) {
    if (!isFull(t)) {
        t->disks[++t->top] = disk;
    }
}

int pop(Tower *t) {
    if (!isEmpty(t)) {
        return t->disks[t->top--];
    }
    return -1; // Error code for empty tower
}

void printTowers(Tower *source, Tower *aux, Tower *destination, int diskCount) {
    printf("\nCurrent state of towers:\n");
    for (int i = diskCount - 1; i >= 0; i--) {
        printf("Disk %d: ", i + 1);
        if (i <= source->top) printf("[X] ");
        else printf("[ ] ");
        if (i <= aux->top) printf("[Y] ");
        else printf("[ ] ");
        if (i <= destination->top) printf("[Z] ");
        else printf("[ ] ");
        printf("\n");
    }
    printf("\n");
}

void moveDisk(Tower *source, Tower *destination) {
    int disk = pop(source);
    push(destination, disk);
    printf("Moved disk %d from %p to %p\n", disk, (void *)source, (void *)destination);
}

void hanoi(int n, Tower *source, Tower *aux, Tower *destination) {
    if (n == 1) {
        moveDisk(source, destination);
        printTowers(source, aux, destination, n);
        return;
    }
    
    hanoi(n - 1, source, destination, aux);
    moveDisk(source, destination);
    printTowers(source, aux, destination, n);
    hanoi(n - 1, aux, source, destination);
}

int main() {
    int n;
    printf("Enter the number of disks (1-%d): ", MAX_DISK);
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISK) {
        printf("Invalid number of disks. Please enter between 1 and %d.\n", MAX_DISK);
        return EXIT_FAILURE;
    }

    Tower source, aux, destination;
    initTower(&source);
    initTower(&aux);
    initTower(&destination);

    // Initialize the source tower with disks
    for (int i = n; i >= 1; i--) {
        push(&source, i);
    }

    printf("Initial state of towers:\n");
    printTowers(&source, &aux, &destination, n);

    hanoi(n, &source, &aux, &destination);

    printf("All disks have been successfully moved to the destination tower!\n");
    return EXIT_SUCCESS;
}