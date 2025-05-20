//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int grid[100][100];
    int n, m;
    int i, j, k;
    int visited[100][100];
    int visited_neighbours[100][100];

    printf("Enter the size of the grid: ");
    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            grid[i][j] = 1;
            visited[i][j] = 0;
            visited_neighbours[i][j] = 0;
        }
    }

    srand(time(NULL));

    for (k = 0; k < n * m; k++) {
        i = rand() % n;
        j = rand() % m;

        if (grid[i][j] == 1) {
            visited[i][j] = 1;
            visited_neighbours[i][j] = 0;

            for (int r = -1; r <= 1; r++) {
                for (int c = -1; c <= 1; c++) {
                    int x = i + r;
                    int y = j + c;

                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && visited[x][y] == 0) {
                        visited_neighbours[i][j]++;
                        break;
                    }
                }
            }

            if (visited_neighbours[i][j] == 1) {
                grid[i][j] = 0;
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }

    return 0;
}