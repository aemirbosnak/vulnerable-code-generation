//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SITE_CLOSED 0
#define SITE_OPEN 1

typedef struct {
    int **grid;
    int size;
} Percolation;

Percolation* initialize_percolation(int n);
void open_site(Percolation *p, int row, int col);
int is_open(Percolation *p, int row, int col);
void print_grid(Percolation *p);
int is_full(Percolation *p, int row, int col);
void free_percolation(Percolation *p);
int percolates(Percolation *p);
void random_site_opening(Percolation *p);
void validate_indices(Percolation *p, int row, int col);

int main() {
    srand(time(NULL));
    
    int grid_size;
    printf("Enter the dimension of the grid (N for NxN): ");
    scanf("%d", &grid_size);

    Percolation *simulation = initialize_percolation(grid_size);
    
    if (simulation == NULL) {
        fprintf(stderr, "Failed to initialize the Percolation grid.\n");
        exit(EXIT_FAILURE);
    }

    int num_iterations = 10; // Number of iterations to run
    for (int i = 0; i < num_iterations; ++i) {
        random_site_opening(simulation);
        printf("After opening random sites (iteration %d):\n", i + 1);
        print_grid(simulation);
        
        if (percolates(simulation)) {
            printf("Percolation occurred!\n");
            break;
        }
    }
    
    free_percolation(simulation);
    return 0;
}

Percolation* initialize_percolation(int n) {
    Percolation *p = (Percolation *)malloc(sizeof(Percolation));
    p->size = n;
    p->grid = (int **)malloc(n * sizeof(int *));
    
    for (int i = 0; i < n; ++i) {
        p->grid[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; ++j) {
            p->grid[i][j] = SITE_CLOSED;
        }
    }
    
    return p;
}

void open_site(Percolation *p, int row, int col) {
    validate_indices(p, row, col);
    p->grid[row][col] = SITE_OPEN;
}

int is_open(Percolation *p, int row, int col) {
    validate_indices(p, row, col);
    return p->grid[row][col] == SITE_OPEN;
}

void print_grid(Percolation *p) {
    for (int i = 0; i < p->size; ++i) {
        for (int j = 0; j < p->size; ++j) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
}

int is_full(Percolation *p, int row, int col) {
    return is_open(p, row, col);
}

void free_percolation(Percolation *p) {
    for (int i = 0; i < p->size; ++i) {
        free(p->grid[i]);
    }
    free(p->grid);
    free(p);
}

void random_site_opening(Percolation *p) {
    int row = rand() % p->size;
    int col = rand() % p->size;
    open_site(p, row, col);
}

void validate_indices(Percolation *p, int row, int col) {
    if (row < 0 || row >= p->size || col < 0 || col >= p->size) {
        fprintf(stderr, "Index out of bounds: (%d, %d)\n", row, col);
        exit(EXIT_FAILURE);
    }
}

int percolates(Percolation *p) {
    // Simplified percolation check (to be implemented)
    for (int j = 0; j < p->size; ++j) {
        if (is_open(p, p->size - 1, j)) {
            return 1;
        }
    }
    return 0;
}