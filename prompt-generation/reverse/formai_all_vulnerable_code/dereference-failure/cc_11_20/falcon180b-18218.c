//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    int status;
} Cell;

int main() {
    int n, m, p, q, count = 0;
    Cell **grid;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    grid = (Cell **)malloc(n * sizeof(Cell *));
    for (int i = 0; i < n; i++) {
        grid[i] = (Cell *)malloc(m * sizeof(Cell));
        for (int j = 0; j < m; j++) {
            grid[i][j].x = i;
            grid[i][j].y = j;
            grid[i][j].status = 0;
        }
    }

    printf("Enter the number of obstacles: ");
    scanf("%d", &p);

    for (int i = 0; i < p; i++) {
        printf("Enter the coordinates of obstacle %d: ", i + 1);
        scanf("%d %d", &q, &q);
        grid[q][q].status = 1;
    }

    int x, y;
    printf("Enter the starting point: ");
    scanf("%d %d", &x, &y);
    grid[x][y].status = 2;

    while (count < n * m) {
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for (int k = 0; k < 4; k++) {
            x = grid[x][y].x + dx[k];
            y = grid[x][y].y + dy[k];

            if (x >= 0 && x < n && y >= 0 && y < m) {
                if (grid[x][y].status == 0) {
                    grid[x][y].status = 2;
                    count++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j].status == 2) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}