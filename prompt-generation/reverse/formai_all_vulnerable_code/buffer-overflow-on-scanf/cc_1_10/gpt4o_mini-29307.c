//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20
#define OPEN ' '
#define BLOCKED '#'
#define PERCOLATED 'P'

typedef struct {
    char grid[GRID_SIZE][GRID_SIZE];
    int visited[GRID_SIZE][GRID_SIZE];
} Percolation;

void initializeGrid(Percolation *perc);
void randomFillGrid(Percolation *perc, float fillProbability);
void printGrid(Percolation *perc);
int percolate(Percolation *perc);
void dfs(Percolation *perc, int x, int y);

int main() {
    srand(time(NULL));
    Percolation perc;
    float fillProbability;

    printf("Enter the fill probability (0.0 to 1.0): ");
    scanf("%f", &fillProbability);
    
    // Input validation
    if (fillProbability < 0.0 || fillProbability > 1.0) {
        fprintf(stderr, "Invalid probability! It must be between 0.0 and 1.0.\n");
        return EXIT_FAILURE;
    }

    initializeGrid(&perc);
    randomFillGrid(&perc, fillProbability);
    printf("Initial Grid:\n");
    printGrid(&perc);

    if (percolate(&perc)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    return EXIT_SUCCESS;
}

void initializeGrid(Percolation *perc) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            perc->grid[i][j] = BLOCKED;
            perc->visited[i][j] = 0;
        }
    }
}

void randomFillGrid(Percolation *perc, float fillProbability) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if ((float)rand() / RAND_MAX < fillProbability) {
                perc->grid[i][j] = OPEN;
            }
        }
    }
}

void printGrid(Percolation *perc) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", perc->grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int percolate(Percolation *perc) {
    for (int col = 0; col < GRID_SIZE; col++) {
        if (perc->grid[0][col] == OPEN && !perc->visited[0][col]) {
            dfs(perc, 0, col);
        }
    }

    // Check if any of the bottom row is visited
    for (int col = 0; col < GRID_SIZE; col++) {
        if (perc->visited[GRID_SIZE - 1][col]) {
            return 1; // The system percolates
        }
    }
    return 0; // The system does not percolate
}

void dfs(Percolation *perc, int x, int y) {
    // Base cases for DFS
    if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE ||
        perc->visited[x][y] || perc->grid[x][y] == BLOCKED) {
        return;
    }

    // Mark the site as visited
    perc->visited[x][y] = 1;
    perc->grid[x][y] = PERCOLATED;

    // Explore neighbors (right, down, left, up)
    dfs(perc, x + 1, y);
    dfs(perc, x - 1, y);
    dfs(perc, x, y + 1);
    dfs(perc, x, y - 1);
}