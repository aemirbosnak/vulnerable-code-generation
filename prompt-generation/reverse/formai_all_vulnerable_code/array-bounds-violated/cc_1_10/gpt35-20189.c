//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10

int grid[N][N];
int sz[N*N];
bool open[N][N];

int root(int i) {
    while (i != sz[i]) {
        sz[i] = sz[sz[i]];
        i = sz[i];
    }
    return i;
}

bool connected(int p, int q) {
    return root(p) == root(q);
}

void union_items(int p, int q) {
    int i = root(p);
    int j = root(q);
    if (i == j) return;
    if (sz[i] < sz[j]) {
        sz[i] += sz[j];
        sz[j] = i;
    }
    else {
        sz[j] += sz[i];
        sz[i] = j;
    }
}

void percolate() {
    for (int i = 0; i < N*N; i++) sz[i] = i;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (open[i][j]) {
                int p = i*N + j;
                if (i == 0) union_items(p, N*N);
                if (i == N-1) union_items(p, N*N + 1);
                if (j > 0 && open[i][j-1]) union_items(p, p-1);
                if (j < N-1 && open[i][j+1]) union_items(p, p+1);
                if (i > 0 && open[i-1][j]) union_items(p, (i-1)*N + j);
                if (i < N-1 && open[i+1][j]) union_items(p, (i+1)*N + j);
            }
        }
    }
}

void initialize() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = 0;
            open[i][j] = false;
        }
    }
}

void print_grid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == -1) {
                printf("X ");
            }
            else if (open[i][j]) {
                printf("0 ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void simulate() {
    initialize();
    srand(time(NULL));
    int p, q;
    while (!connected(N*N, N*N+1)) {
        p = rand() % N;
        q = rand() % N;
        if (!open[p][q]) {
            open[p][q] = true;
            grid[p][q] = -1;
            percolate();
            print_grid();
        }
    }
}

int main() {
    simulate();
    return 0;
}