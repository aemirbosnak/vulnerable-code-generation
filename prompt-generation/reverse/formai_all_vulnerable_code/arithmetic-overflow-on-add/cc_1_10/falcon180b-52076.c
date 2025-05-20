//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define N 5
#define M 5

int graph[N][M] = {
    {0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 1, 0, 1},
    {0, 0, 0, 1, 0}
};

void printGraph() {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void move(int x, int y, int dx, int dy) {
    int nx, ny, i;
    nx = x + dx;
    ny = y + dy;
    if (nx >= 0 && nx < N && ny >= 0 && ny < M && graph[nx][ny] == 0) {
        graph[x][y] = 0;
        graph[nx][ny] = 1;
        x = nx;
        y = ny;
    } else {
        printf("Cannot move!\n");
    }
}

int main() {
    int x, y, dx, dy, i;
    printf("Enter starting position (x y): ");
    scanf("%d %d", &x, &y);
    printf("Enter direction (dx dy): ");
    scanf("%d %d", &dx, &dy);
    x = (x + N - 1) % N;
    y = (y + M - 1) % M;
    move(x, y, dx, dy);
    printGraph();
    return 0;
}