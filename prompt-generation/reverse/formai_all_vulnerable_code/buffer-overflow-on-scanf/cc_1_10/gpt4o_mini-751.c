//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int width;
    int height;
    int grid[MAX_SIZE][MAX_SIZE];
    bool visited[MAX_SIZE][MAX_SIZE];
} Percolation;

void initialize(Percolation* p, int width, int height) {
    p->width = width;
    p->height = height;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            p->grid[i][j] = (rand() % 2); // Randomly assign 0 or 1
            p->visited[i][j] = false; // Initialize visited array
        }
    }
}

void printGrid(Percolation* p) {
    for (int i = 0; i < p->height; i++) {
        for (int j = 0; j < p->width; j++) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
}

bool isValid(int x, int y, Percolation* p) {
    return x >= 0 && x < p->height && y >= 0 && y < p->width;
}

bool percolates(int x, int y, Percolation* p) {
    if (x == p->height - 1) return true; // Reached the bottom
    if (!isValid(x, y, p) || p->grid[x][y] == 0 || p->visited[x][y]) return false;

    p->visited[x][y] = true; // Mark as visited

    // Check the four possible directions
    bool down = percolates(x + 1, y, p);
    bool right = percolates(x, y + 1, p);
    bool left = percolates(x, y - 1, p);
    bool up = percolates(x - 1, y, p);

    return down || right || left || up;
}

int main() {
    srand(time(NULL));
    Percolation p;
    int width, height;

    printf("Enter width and height for the percolation grid (max %d): ", MAX_SIZE);
    scanf("%d %d", &width, &height);

    if (width > MAX_SIZE || height > MAX_SIZE || width <= 0 || height <= 0) {
        printf("Invalid dimensions! Please use values up to %d.\n", MAX_SIZE);
        return 1;
    }

    initialize(&p, width, height);
    printf("Generated Percolation Grid (0: Blocked, 1: Open):\n");
    printGrid(&p);

    bool doesPercolate = false;
    for (int j = 0; j < width; j++) {
        if (percolates(0, j, &p)) {
            doesPercolate = true;
            break;
        }
    }

    if (doesPercolate) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    return 0;
}