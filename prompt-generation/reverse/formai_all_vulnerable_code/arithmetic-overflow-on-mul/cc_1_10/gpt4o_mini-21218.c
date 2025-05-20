//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLOCKED 0
#define OPEN 1
#define FULL 2

typedef struct {
    int width;
    int height;
    int *grid;
} Percolation;

Percolation *createPercolation(int width, int height) {
    Percolation *p = (Percolation *)malloc(sizeof(Percolation));
    p->width = width;
    p->height = height;
    p->grid = (int *)malloc(width * height * sizeof(int));

    for (int i = 0; i < width * height; i++) {
        p->grid[i] = BLOCKED;
    }

    return p;
}

void freePercolation(Percolation *p) {
    free(p->grid);
    free(p);
}

void openSite(Percolation *p, int x, int y) {
    if (x < 0 || x >= p->width || y < 0 || y >= p->height) {
        fprintf(stderr, "Invalid site coordinates.\n");
        return;
    }
    p->grid[y * p->width + x] = OPEN;
}

int isOpen(Percolation *p, int x, int y) {
    if (x < 0 || x >= p->width || y < 0 || y >= p->height) {
        return 0;
    }
    return p->grid[y * p->width + x] == OPEN;
}

int isFull(Percolation *p, int x, int y) {
    if (x < 0 || x >= p->width || y < 0 || y >= p->height) {
        return 0;
    }
    return p->grid[y * p->width + x] == FULL;
}

void printGrid(Percolation *p) {
    for (int j = 0; j < p->height; j++) {
        for (int i = 0; i < p->width; i++) {
            if (isFull(p, i, j)) {
                printf(" F ");
            } else if (isOpen(p, i, j)) {
                printf(" O ");
            } else {
                printf(" # ");
            }
        }
        printf("\n");
    }
}

void fill(Percolation *p, int x, int y) {
    if (!isOpen(p, x, y) || isFull(p, x, y)) {
        return;
    }

    p->grid[y * p->width + x] = FULL;

    fill(p, x - 1, y);
    fill(p, x + 1, y);
    fill(p, x, y - 1);
    fill(p, x, y + 1);
}

int percolates(Percolation *p) {
    for (int x = 0; x < p->width; x++) {
        if (isOpen(p, x, 0)) {
            fill(p, x, 0);
        }
    }
    for (int x = 0; x < p->width; x++) {
        if (isFull(p, x, p->height - 1)) {
            return 1; // percolates
        }
    }
    return 0; // does not percolate
}

void randomSites(Percolation *p, float probability) {
    for (int j = 0; j < p->height; j++) {
        for (int i = 0; i < p->width; i++) {
            if ((rand() / (float)RAND_MAX) < probability) {
                openSite(p, i, j);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int width, height;
    float prob;

    printf("Enter the width of the grid: ");
    scanf("%d", &width);
    printf("Enter the height of the grid: ");
    scanf("%d", &height);
    printf("Enter the open site probability (0.0 - 1.0): ");
    scanf("%f", &prob);

    Percolation *p = createPercolation(width, height);
    randomSites(p, prob);

    printf("Initial grid:\n");
    printGrid(p);

    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    printf("Final grid after checking for full sites:\n");
    printGrid(p);

    freePercolation(p);
    return 0;
}