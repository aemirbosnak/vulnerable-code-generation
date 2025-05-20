//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

struct Tower {
    int numDisks;
    int *disks;
    int top;
};

void createTower(struct Tower *tower, int numDisks) {
    tower->numDisks = numDisks;
    tower->disks = malloc(sizeof(int) * numDisks);
    tower->top = -1;
}

void destroyTower(struct Tower *tower) {
    free(tower->disks);
}

int pushDisk(struct Tower *tower, int disk) {
    if (tower->top >= tower->numDisks - 1) {
        return -1;
    }

    tower->disks[++tower->top] = disk;
    return 0;
}

int popDisk(struct Tower *tower, int *disk) {
    if (tower->top < 0) {
        return -1;
    }

    *disk = tower->disks[tower->top--];
    return 0;
}

void moveTower(struct Tower *source, struct Tower *destination, struct Tower *auxiliary, int numDisks) {
    if (numDisks > 0) {
        moveTower(source, auxiliary, destination, numDisks - 1);
        pushDisk(destination, popDisk(source, NULL));
        moveTower(auxiliary, destination, source, numDisks - 1);
    }
}

void printTower(struct Tower *tower) {
    for (int i = tower->numDisks - 1; i >= 0; i--) {
        printf("%d ", tower->disks[i]);
    }
    printf("\n");
}

int main() {
    struct Tower source, destination, auxiliary;
    int numDisks;

    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    createTower(&source, numDisks);
    createTower(&destination, numDisks);
    createTower(&auxiliary, numDisks);

    for (int i = numDisks; i >= 1; i--) {
        pushDisk(&source, i);
    }

    printf("Initial state:\n");
    printTower(&source);
    printTower(&destination);
    printTower(&auxiliary);

    moveTower(&source, &destination, &auxiliary, numDisks);

    printf("\nFinal state:\n");
    printTower(&source);
    printTower(&destination);
    printTower(&auxiliary);

    destroyTower(&source);
    destroyTower(&destination);
    destroyTower(&auxiliary);

    return 0;
}