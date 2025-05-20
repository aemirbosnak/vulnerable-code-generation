//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int grid[MAX_SIZE][MAX_SIZE];
    int size;
} PercolationGrid;

void initializeGrid(PercolationGrid *pg, int size) {
    pg->size = size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            pg->grid[i][j] = 0; // 0 indicates blocked site
        }
    }
}

void displayGrid(PercolationGrid pg) {
    printf("\nPercolation Grid (%d x %d):\n", pg.size, pg.size);
    for (int i = 0; i < pg.size; i++) {
        for (int j = 0; j < pg.size; j++) {
            printf("%d ", pg.grid[i][j]);
        }
        printf("\n");
    }
}

void openSite(PercolationGrid *pg, int x, int y) {
    if (x >= 0 && x < pg->size && y >= 0 && y < pg->size) {
        pg->grid[x][y] = 1; // 1 indicates open site
    }
}

int isOpen(PercolationGrid pg, int x, int y) {
    return (x >= 0 && x < pg.size && y >= 0 && y < pg.size) ? pg.grid[x][y] : 0;
}

int percolates(PercolationGrid pg) {
    for (int j = 0; j < pg.size; j++) {
        if (pg.grid[0][j] == 1) {
            // Starting DFS from the top row
            int stack[MAX_SIZE * MAX_SIZE][2], top = -1;
            stack[++top][0] = 0;
            stack[top][1] = j;
            int visited[MAX_SIZE][MAX_SIZE] = {0};

            while (top >= 0) {
                int x = stack[top][0];
                int y = stack[top][1];
                top--;

                if (visited[x][y]) continue;
                visited[x][y] = 1;

                // Check if we reach the bottom row
                if (x == pg.size - 1) return 1;

                // Check adjacent cells
                if (isOpen(pg, x + 1, y)) stack[++top][0] = x + 1, stack[top][1] = y; // down
                if (isOpen(pg, x - 1, y)) stack[++top][0] = x - 1, stack[top][1] = y; // up
                if (isOpen(pg, x, y + 1)) stack[++top][0] = x, stack[top][1] = y + 1; // right
                if (isOpen(pg, x, y - 1)) stack[++top][0] = x, stack[top][1] = y - 1; // left
            }
        }
    }
    return 0;
}

void randomOpenSites(PercolationGrid *pg, float probability) {
    for (int i = 0; i < pg->size; i++) {
        for (int j = 0; j < pg->size; j++) {
            if ((float) rand() / RAND_MAX < probability) {
                openSite(pg, i, j);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int size;
    float probability;

    printf("Enter the grid size (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    if (size > MAX_SIZE) {
        fprintf(stderr, "Error: size exceeds maximum allowed size.\n");
        return EXIT_FAILURE;
    }

    printf("Enter the probability to open sites (0.0 to 1.0): ");
    scanf("%f", &probability);
    if (probability < 0.0 || probability > 1.0) {
        fprintf(stderr, "Error: Invalid probability value.\n");
        return EXIT_FAILURE;
    }

    PercolationGrid pg;
    initializeGrid(&pg, size);
    randomOpenSites(&pg, probability);
    displayGrid(pg);

    if (percolates(pg)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    return EXIT_SUCCESS;
}