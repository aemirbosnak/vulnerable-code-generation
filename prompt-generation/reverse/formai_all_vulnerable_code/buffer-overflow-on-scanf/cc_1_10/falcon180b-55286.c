//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 100

int n;
int **a;

void init(int h) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < h; i++) {
        a[i] = (int *)malloc(MAX * sizeof(int));
        for (j = 0; j < MAX; j++) {
            a[i][j] = rand() % 100;
        }
    }
}

void print(int h) {
    int i, j;
    for (i = 0; i < h; i++) {
        for (j = 0; j < MAX; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void move(int from, int to, int aux, int n) {
    int i;
    for (i = 0; i < n; i++) {
        a[to][i] = a[from][i];
    }
}

void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        move(from, to, aux, 1);
        printf("Move disk 1 from %d to %d\n", from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    move(from, to, aux, n);
    printf("Move disk %d from %d to %d\n", n, from, to);
    hanoi(n - 1, aux, to, from);
}

int main() {
    int h;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Enter the number of towers: ");
    scanf("%d", &h);
    a = (int **)malloc(h * sizeof(int *));
    init(h);
    printf("Initial configuration:\n");
    print(h);
    hanoi(n, 0, h - 1, 2 * h - 1);
    printf("Final configuration:\n");
    print(h);
    return 0;
}