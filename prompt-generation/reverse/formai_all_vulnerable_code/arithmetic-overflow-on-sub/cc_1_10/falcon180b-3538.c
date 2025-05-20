//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void rotateTower(int *tower, int n, int from, int to) {
    int temp = tower[from];
    for (int i = from; i <= to; i++) {
        tower[i] = tower[i + 1];
    }
    tower[to] = temp;
}

void printTower(int *tower, int n) {
    for (int i = 0; i <= n; i++) {
        printf("%d ", tower[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    int tower[MAX];
    for (int i = 0; i <= n; i++) {
        tower[i] = i + 1;
    }
    printf("Initial state:\n");
    printTower(tower, n);
    int from = 0;
    int to = n - 1;
    int temp = n - 1;
    int count = 0;
    srand(time(NULL));
    int random = rand() % 3;
    while (random == 0) {
        random = rand() % 3;
    }
    if (random == 1) {
        to = from;
        from = temp;
        temp = to;
    }
    printf("Random state:\n");
    printTower(tower, n);
    while (count < n * 2) {
        if (from == to) {
            if (from == 0) {
                printf("Solved in %d moves!\n", count);
                break;
            }
            else {
                printf("Invalid move!\n");
                exit(0);
            }
        }
        if (from > to) {
            rotateTower(tower, n, from, to + 1);
            from--;
            to++;
        }
        else {
            rotateTower(tower, n, from, to);
            from++;
            to--;
        }
        count++;
        printf("Move %d:\n", count);
        printTower(tower, n);
    }
    return 0;
}