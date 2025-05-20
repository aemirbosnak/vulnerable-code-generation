//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void shiftTower(int *tower, int height, int from, int to, int *spare) {
    if (height == 1) {
        tower[to] = tower[from];
        return;
    }
    int top = tower[from];
    for (int i = from + 1; i < to; i++) {
        tower[i - 1] = tower[i];
    }
    tower[to] = top;
}

void printTower(int tower[], int height) {
    for (int i = 0; i < height; i++) {
        printf("%d ", tower[i]);
    }
    printf("\n");
}

void playGame(int numDisks) {
    int *tower = malloc(numDisks * sizeof(int));
    int *spare = malloc(numDisks * sizeof(int));
    int spareIndex = 0;
    for (int i = numDisks - 1; i >= 0; i--) {
        tower[i] = i + 1;
        spare[spareIndex++] = i + 1;
    }
    int moves = 0;
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    while (spareIndex > 0) {
        int from = rand() % 3;
        int to = (from + 1) % 3;
        while (tower[to] > tower[from]) {
            to = (to + 1) % 3;
        }
        int *temp = tower[from];
        tower[from] = tower[to];
        tower[to] = temp;
        shiftTower(tower, numDisks, from, to, spare);
        printTower(tower, numDisks);
        moves++;
        spareIndex--;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double duration = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("Congratulations! You solved the Tower of Hanoi in %d moves and %.6f seconds.\n", moves, duration);
}

int main() {
    int numDisks;
    printf("Enter the number of disks: ");
    if (scanf("%d", &numDisks)!= 1 || numDisks <= 0) {
        printf("Invalid input.\n");
        return 1;
    }
    srand(time(NULL));
    playGame(numDisks);
    return 0;
}