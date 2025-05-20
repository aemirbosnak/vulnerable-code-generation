//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SITE_OPEN 1
#define SITE_CLOSED 0

typedef struct {
    int size;
    int *grid;
} Percolation;

Percolation* create_percolation(int n) {
    Percolation *p = malloc(sizeof(Percolation));
    p->size = n;
    p->grid = malloc(n * n * sizeof(int));
    
    // Initialize the grid with closed sites
    for (int i = 0; i < n * n; i++) {
        p->grid[i] = SITE_CLOSED;
    }
    
    return p;
}

void destroy_percolation(Percolation *p) {
    free(p->grid);
    free(p);
}

void open_site(Percolation *p, int row, int col) {
    if (row < 0 || col < 0 || row >= p->size || col >= p->size) {
        fprintf(stderr, "Coordinates out of bounds\n");
        return;
    }
    p->grid[row * p->size + col] = SITE_OPEN;
}

int is_open(Percolation *p, int row, int col) {
    if (row < 0 || col < 0 || row >= p->size || col >= p->size) {
        return 0; // out of bounds
    }
    return p->grid[row * p->size + col] == SITE_OPEN;
}

int percolates(Percolation *p) {
    int n = p->size;
    for (int col = 0; col < n; col++) {
        if (is_open(p, 0, col)) {
            int stack[n * n];
            int top = -1;
            stack[++top] = col; // push starting cell
            
            while (top >= 0) {
                int current_col = stack[top--];
                for (int row = 0; row < n; row++) {
                    if (is_open(p, row, current_col)) {
                        if (row == n - 1) {
                            return 1; // found a path to the bottom
                        }
                        // Check neighboring sites
                        if (row > 0 && is_open(p, row - 1, current_col)) {
                            stack[++top] = current_col; // push upward
                        }
                        if (row < n - 1 && is_open(p, row + 1, current_col)) {
                            stack[++top] = current_col; // push downward
                        }
                        if (current_col > 0 && is_open(p, row, current_col - 1)) {
                            stack[++top] = current_col - 1; // push left
                        }
                        if (current_col < n - 1 && is_open(p, row, current_col + 1)) {
                            stack[++top] = current_col + 1; // push right
                        }
                    }
                }
            }
        }
    }
    return 0; // no path found to the bottom
}

void print_grid(Percolation *p) {
    int n = p->size;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", p->grid[i * n + j]);
        }
        printf("\n");
    }
}

void random_open_sites(Percolation *p, double probability) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            if ((double)rand() / RAND_MAX < probability) {
                open_site(p, i, j);
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int n;
    double prob;

    printf("Enter grid size: ");
    scanf("%d", &n);
    
    printf("Enter probability of opening a site (0.0 to 1.0): ");
    scanf("%lf", &prob);

    Percolation *p = create_percolation(n);
    random_open_sites(p, prob);
    
    printf("Grid configuration:\n");
    print_grid(p);
    
    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    destroy_percolation(p);
    return 0;
}