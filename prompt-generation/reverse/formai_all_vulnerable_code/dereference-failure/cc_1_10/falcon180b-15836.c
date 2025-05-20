//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 // number of sites in the lattice
#define P 0.7 // probability of a site being open

int **create_lattice();
void percolate(int **lattice);
int check_neighbors(int i, int j, int **lattice);

int main() {
    srand(time(NULL));
    int **lattice = create_lattice();
    percolate(lattice);
    return 0;
}

int **create_lattice() {
    int **lattice = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        lattice[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            lattice[i][j] = rand() % 2; // randomly assign 0 or 1 to each site
        }
    }
    return lattice;
}

void percolate(int **lattice) {
    int top = 0;
    int bottom = N - 1;
    while (top < bottom) {
        int i = rand() % (bottom - top + 1) + top;
        int j = rand() % N;
        if (check_neighbors(i, j, lattice)) {
            lattice[i][j] = 1;
            if (i > top) {
                top = i;
            }
            if (i < bottom) {
                bottom = i;
            }
        }
    }
}

int check_neighbors(int i, int j, int **lattice) {
    if (i == 0 && lattice[i][j] == 1) {
        return 1;
    }
    if (i == N - 1 && lattice[i][j] == 1) {
        return 1;
    }
    if (j == 0 && lattice[i][j] == 1) {
        return 1;
    }
    if (j == N - 1 && lattice[i][j] == 1) {
        return 1;
    }
    if (lattice[i - 1][j] == 1) {
        return 1;
    }
    if (lattice[i + 1][j] == 1) {
        return 1;
    }
    if (lattice[i][j - 1] == 1) {
        return 1;
    }
    if (lattice[i][j + 1] == 1) {
        return 1;
    }
    return 0;
}