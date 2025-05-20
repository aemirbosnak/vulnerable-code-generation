//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 30
#define NUM_NEIGHBORS 8
#define DENSITY_THRESHOLD 0.5

typedef struct {
    int x, y;
} Point;

typedef struct {
    int state;
    struct Site *neighbors[NUM_NEIGHBORS];
} Site;

typedef struct {
    int num_sites;
    Site **sites;
} Grid;

void init_grid(Grid *grid, int num_sites) {
    grid->num_sites = num_sites;
    grid->sites = malloc(num_sites * sizeof(Site));
    for (int i = 0; i < num_sites; i++) {
        grid->sites[i] = malloc(sizeof(Site));
        grid->sites[i]->state = 0;
        for (int j = 0; j < NUM_NEIGHBORS; j++) {
            grid->sites[i]->neighbors[j] = NULL;
        }
    }
}

void init_random(Grid *grid) {
    srand(time(NULL));
    for (int i = 0; i < grid->num_sites; i++) {
        if (rand() % 2 == 0) {
            grid->sites[i]->state = 1;
        }
    }
}

void percolate(Grid *grid) {
    int num_percolated = 0;
    for (int i = 0; i < grid->num_sites; i++) {
        if (grid->sites[i]->state == 1) {
            num_percolated++;
        }
    }
    if (num_percolated >= (grid->num_sites * DENSITY_THRESHOLD)) {
        puts("Percolation occurred!");
    }
}

void print_grid(Grid *grid) {
    for (int i = 0; i < grid->num_sites; i++) {
        printf("%d ", grid->sites[i]->state);
    }
    printf("\n");
}

int main() {
    Grid grid;
    int num_rows, num_cols;

    printf("Enter the number of rows: ");
    scanf("%d", &num_rows);
    printf("Enter the number of columns: ");
    scanf("%d", &num_cols);

    if (num_rows > MAX_ROWS || num_cols > MAX_COLS) {
        printf("Error: Grid dimensions too large.\n");
        return 1;
    }

    init_grid(&grid, num_rows * num_cols);
    init_random(&grid);

    while (1) {
        print_grid(&grid);
        percolate(&grid);
        printf("Press enter to continue...\n");
        getchar();
    }

    return 0;
}