//Code Llama-13B DATASET v1.0 Category: Percolation Simulator ; Style: Linus Torvalds
// Percolation Simulator
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Grid structure
struct Grid {
    int n_rows;
    int n_cols;
    int **matrix;
};

// Percolation structure
struct Percolation {
    struct Grid *grid;
    int n_open_sites;
    int n_closed_sites;
    int n_connected_sites;
};

// Initialize grid
void init_grid(struct Grid *grid, int n_rows, int n_cols) {
    grid->n_rows = n_rows;
    grid->n_cols = n_cols;
    grid->matrix = (int **)malloc(n_rows * sizeof(int *));
    for (int i = 0; i < n_rows; i++) {
        grid->matrix[i] = (int *)malloc(n_cols * sizeof(int));
        for (int j = 0; j < n_cols; j++) {
            grid->matrix[i][j] = 0;
        }
    }
}

// Initialize percolation
void init_percolation(struct Percolation *percolation, struct Grid *grid) {
    percolation->grid = grid;
    percolation->n_open_sites = grid->n_rows * grid->n_cols;
    percolation->n_closed_sites = 0;
    percolation->n_connected_sites = 0;
}

// Check if the grid is percolated
int is_percolated(struct Percolation *percolation) {
    return (percolation->n_connected_sites == percolation->grid->n_rows * percolation->grid->n_cols);
}

// Open a site
void open_site(struct Percolation *percolation, int row, int col) {
    if (row >= 0 && row < percolation->grid->n_rows && col >= 0 && col < percolation->grid->n_cols) {
        percolation->grid->matrix[row][col] = 1;
        percolation->n_open_sites--;
        if (is_percolated(percolation)) {
            percolation->n_closed_sites++;
        }
    }
}

// Close a site
void close_site(struct Percolation *percolation, int row, int col) {
    if (row >= 0 && row < percolation->grid->n_rows && col >= 0 && col < percolation->grid->n_cols) {
        percolation->grid->matrix[row][col] = 0;
        percolation->n_closed_sites++;
    }
}

// Check if a site is open
int is_open_site(struct Percolation *percolation, int row, int col) {
    if (row >= 0 && row < percolation->grid->n_rows && col >= 0 && col < percolation->grid->n_cols) {
        return percolation->grid->matrix[row][col];
    }
    return 0;
}

// Check if a site is closed
int is_closed_site(struct Percolation *percolation, int row, int col) {
    if (row >= 0 && row < percolation->grid->n_rows && col >= 0 && col < percolation->grid->n_cols) {
        return !percolation->grid->matrix[row][col];
    }
    return 1;
}

// Check if a site is connected
int is_connected_site(struct Percolation *percolation, int row, int col) {
    int n_connected_sites = 0;
    if (is_open_site(percolation, row, col)) {
        n_connected_sites++;
        if (row > 0 && is_open_site(percolation, row - 1, col)) {
            n_connected_sites++;
        }
        if (row < percolation->grid->n_rows - 1 && is_open_site(percolation, row + 1, col)) {
            n_connected_sites++;
        }
        if (col > 0 && is_open_site(percolation, row, col - 1)) {
            n_connected_sites++;
        }
        if (col < percolation->grid->n_cols - 1 && is_open_site(percolation, row, col + 1)) {
            n_connected_sites++;
        }
    }
    return n_connected_sites;
}

// Check if a site is percolated
int is_percolated_site(struct Percolation *percolation, int row, int col) {
    if (is_open_site(percolation, row, col)) {
        return is_connected_site(percolation, row, col) == percolation->grid->n_rows * percolation->grid->n_cols;
    }
    return 0;
}

// Check if a site is isolated
int is_isolated_site(struct Percolation *percolation, int row, int col) {
    if (is_open_site(percolation, row, col)) {
        return is_connected_site(percolation, row, col) == 0;
    }
    return 1;
}

// Simulate percolation
void simulate_percolation(struct Percolation *percolation) {
    while (percolation->n_open_sites > 0) {
        int row = rand() % percolation->grid->n_rows;
        int col = rand() % percolation->grid->n_cols;
        if (is_open_site(percolation, row, col)) {
            close_site(percolation, row, col);
        }
    }
}

// Print grid
void print_grid(struct Grid *grid) {
    for (int i = 0; i < grid->n_rows; i++) {
        for (int j = 0; j < grid->n_cols; j++) {
            printf("%d ", grid->matrix[i][j]);
        }
        printf("\n");
    }
}

// Print percolation
void print_percolation(struct Percolation *percolation) {
    printf("Grid: %dx%d\n", percolation->grid->n_rows, percolation->grid->n_cols);
    printf("Open sites: %d\n", percolation->n_open_sites);
    printf("Closed sites: %d\n", percolation->n_closed_sites);
    printf("Connected sites: %d\n", percolation->n_connected_sites);
    printf("Percolated: %s\n", is_percolated(percolation) ? "Yes" : "No");
    printf("Isolated: %s\n", is_isolated_site(percolation, 0, 0) ? "Yes" : "No");
    printf("Percolated site: %s\n", is_percolated_site(percolation, 0, 0) ? "Yes" : "No");
    printf("Isolated site: %s\n", is_isolated_site(percolation, 0, 0) ? "Yes" : "No");
}

int main() {
    // Initialize grid
    struct Grid grid;
    init_grid(&grid, 10, 10);

    // Initialize percolation
    struct Percolation percolation;
    init_percolation(&percolation, &grid);

    // Simulate percolation
    simulate_percolation(&percolation);

    // Print grid
    print_grid(&grid);

    // Print percolation
    print_percolation(&percolation);

    return 0;
}