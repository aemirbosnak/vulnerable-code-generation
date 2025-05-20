//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int size;
    int *grid;
} Percolation;

Percolation* create_percolation(int size);
void destroy_percolation(Percolation *p);
void open_site(Percolation *p, int row, int col);
int is_open(Percolation *p, int row, int col);
int percolates(Percolation *p);
void print_grid(Percolation *p);
void initialize_random_sites(Percolation *p, double probability);
int index(int row, int col, int size);
int check_percolation_rec(Percolation *p, int row, int col, int *visited);

int main() {
    srand(time(NULL));
    int size;
    double probability;

    printf("Enter the size of the grid (N x N): ");
    scanf("%d", &size);
    printf("Enter the probability of opening a site (0.0 to 1.0): ");
    scanf("%lf", &probability);

    Percolation *p = create_percolation(size);
    initialize_random_sites(p, probability);

    printf("Initial grid:\n");
    print_grid(p);

    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate!\n");
    }

    destroy_percolation(p);
    return 0;
}

Percolation* create_percolation(int size) {
    Percolation *p = (Percolation *)malloc(sizeof(Percolation));
    p->size = size;
    p->grid = (int *)calloc(size * size, sizeof(int));
    return p;
}

void destroy_percolation(Percolation *p) {
    free(p->grid);
    free(p);
}

void open_site(Percolation *p, int row, int col) {
    if (row >= 0 && row < p->size && col >= 0 && col < p->size) {
        p->grid[index(row, col, p->size)] = OPEN;
    }
}

int is_open(Percolation *p, int row, int col) {
    return p->grid[index(row, col, p->size)] == OPEN;
}

int percolates(Percolation *p) {
    int *visited = (int *)calloc(p->size * p->size, sizeof(int));
    for (int col = 0; col < p->size; col++) {
        if (is_open(p, 0, col)) {
            if (check_percolation_rec(p, 0, col, visited)) {
                free(visited);
                return 1;
            }
        }
    }
    free(visited);
    return 0;
}

int check_percolation_rec(Percolation *p, int row, int col, int *visited) {
    if (row >= p->size) return 1;
    if (row < 0 || col < 0 || col >= p->size || visited[index(row, col, p->size)] || !is_open(p, row, col)) {
        return 0;
    }
    
    visited[index(row, col, p->size)] = 1;

    return check_percolation_rec(p, row + 1, col, visited) ||  
           check_percolation_rec(p, row, col + 1, visited) || 
           check_percolation_rec(p, row, col - 1, visited) ||
           check_percolation_rec(p, row - 1, col, visited);
}

int index(int row, int col, int size) {
    return row * size + col;
}

void initialize_random_sites(Percolation *p, double probability) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            if ((double)rand() / RAND_MAX < probability) {
                open_site(p, i, j);
            }
        }
    }
}

void print_grid(Percolation *p) {
    for (int row = 0; row < p->size; row++) {
        for (int col = 0; col < p->size; col++) {
            printf("%d ", is_open(p, row, col));
        }
        printf("\n");
    }
}