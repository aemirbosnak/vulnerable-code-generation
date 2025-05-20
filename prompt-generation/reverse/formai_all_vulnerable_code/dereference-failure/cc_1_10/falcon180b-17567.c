//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

typedef struct {
    int size;
    int *arr;
} Tower;

Tower *createTower(int size) {
    Tower *tower = (Tower *)malloc(sizeof(Tower));
    tower->size = size;
    tower->arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        tower->arr[i] = rand() % 100;
    }
    return tower;
}

void destroyTower(Tower *tower) {
    free(tower->arr);
    free(tower);
}

void printTower(Tower *tower) {
    for (int i = 0; i < tower->size; i++) {
        printf("%d ", tower->arr[i]);
    }
    printf("\n");
}

void moveDisk(Tower *srcTower, Tower *destTower, int n) {
    if (n == 1) {
        destTower->arr[destTower->size - 1] = srcTower->arr[srcTower->size - 1];
        srcTower->arr[srcTower->size - 1] = 0;
    } else {
        Tower *auxTower = createTower(n);
        moveDisk(srcTower, auxTower, n - 1);
        moveDisk(auxTower, destTower, 1);
        destroyTower(auxTower);
    }
}

int main() {
    srand(time(NULL));
    Tower *towerA = createTower(5);
    Tower *towerB = createTower(5);
    printTower(towerA);
    printTower(towerB);
    moveDisk(towerA, towerB, 5);
    printTower(towerA);
    printTower(towerB);
    destroyTower(towerA);
    destroyTower(towerB);
    return 0;
}