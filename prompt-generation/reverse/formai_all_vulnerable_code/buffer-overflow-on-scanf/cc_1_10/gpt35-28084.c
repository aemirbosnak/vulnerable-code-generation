//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: scalable
// C Percolation Simulator
// Simulates the percolation process on a square grid
// Uses weighted quick union-find algorithm to determine if the grid percolates
// Scalable code with adjustable grid size and probability of sites being open

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 1000  // maximum size of grid
#define MIN_SIZE 1  // minimum size of grid

// weighted quick union-find data structure
typedef struct {
    int *parent, *size;
    int num_elements;
} uf_t;

void uf_init(uf_t *uf, int num_elements);
int uf_find(uf_t *uf, int p);
void uf_union(uf_t *uf, int p, int q);
void uf_free(uf_t *uf);

int main() {
    int n;  // size of grid
    double p;  // probability of site being open
    do {
        printf("Enter size of grid (between %d and %d): ", MIN_SIZE, MAX_SIZE);
        scanf("%d", &n);
    } while (n < MIN_SIZE || n > MAX_SIZE);
    do {
        printf("Enter probability of site being open (between 0 and 1): ");
        scanf("%lf", &p);
    } while (p < 0 || p > 1);

    // create grid and initialize all elements to closed
    bool grid[MAX_SIZE][MAX_SIZE];
    int i, j;
    srand(time(NULL));  // seed for random number generator
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (((double) rand() / (RAND_MAX)) < p) {
                grid[i][j] = true;  // site is open
            }
            else {
                grid[i][j] = false;  // site is closed
            }
        }
    }

    // initialize union-find data structure for quick percolation check
    uf_t uf;
    uf_init(&uf, n*n);

    // connect all elements in top and bottom rows to virtual top and bottom sites, respectively
    int top_site = n*n, bottom_site = n*n+1;  // virtual sites
    for (i = 0; i < n; i++) {
        if (grid[0][i]) {
            uf_union(&uf, i, top_site);
        }
        if (grid[n-1][i]) {
            uf_union(&uf, n*(n-1)+i, bottom_site);
        }
    }

    // connect adjacent open elements
    int site, adj_site;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            site = i*n + j;  // index in 1D array
            if (grid[i][j]) {  // if site is open
                if (i > 0 && grid[i-1][j]) {  // check above
                    adj_site = site - n;
                    uf_union(&uf, site, adj_site);
                }
                if (j < n-1 && grid[i][j+1]) {  // check right
                    adj_site = site + 1;
                    uf_union(&uf, site, adj_site);
                }
                if (i < n-1 && grid[i+1][j]) {  // check below
                    adj_site = site + n;
                    uf_union(&uf, site, adj_site);
                }
                if (j > 0 && grid[i][j-1]) {  // check left
                    adj_site = site - 1;
                    uf_union(&uf, site, adj_site);
                }
            }
        }
    }

    // check if top and bottom virtual sites are connected
    if (uf_find(&uf, top_site) == uf_find(&uf, bottom_site)) {
        printf("Grid percolates!\n");
    }
    else {
        printf("Grid does not percolate.\n");
    }

    // free memory
    uf_free(&uf);
    return 0;
}

// functions for weighted quick union-find data structure
void uf_init(uf_t *uf, int num_elements) {
    uf->parent = (int *) malloc(num_elements * sizeof(int));
    uf->size = (int *) malloc(num_elements * sizeof(int));
    uf->num_elements = num_elements;
    int i;
    for (i = 0; i < num_elements; i++) {
        uf->parent[i] = i;
        uf->size[i] = 1;
    }
}

int uf_find(uf_t *uf, int p) {
    while (p != uf->parent[p]) {
        uf->parent[p] = uf->parent[uf->parent[p]];  // path compression
        p = uf->parent[p];
    }
    return p;
}

void uf_union(uf_t *uf, int p, int q) {
    int root_p = uf_find(uf, p);
    int root_q = uf_find(uf, q);
    if (root_p == root_q) {
        return;
    }
    if (uf->size[root_p] < uf->size[root_q]) {  // weighted quick union
        uf->parent[root_p] = root_q;
        uf->size[root_q] += uf->size[root_p];
    }
    else {
        uf->parent[root_q] = root_p;
        uf->size[root_p] += uf->size[root_q];
    }
}

void uf_free(uf_t *uf) {
    free(uf->parent);
    free(uf->size);
}