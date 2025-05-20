//Code Llama-13B DATASET v1.0 Category: Percolation Simulator ; Style: configurable
/*
 * percolation_simulator.c
 *
 * A simple percolation simulator program in C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

/* Structure to represent a site in the percolation system */
typedef struct {
    int x;
    int y;
    int status;
} Site;

/* Structure to represent a percolation system */
typedef struct {
    Site** sites;
    int size;
    int num_open;
} PercolationSystem;

/* Function to create a new percolation system */
PercolationSystem* create_percolation_system(int size) {
    PercolationSystem* system = malloc(sizeof(PercolationSystem));
    system->sites = malloc(sizeof(Site*) * size * size);
    system->size = size;
    system->num_open = 0;

    for (int i = 0; i < size * size; i++) {
        system->sites[i] = malloc(sizeof(Site));
        system->sites[i]->x = i % size;
        system->sites[i]->y = i / size;
        system->sites[i]->status = 0;
    }

    return system;
}

/* Function to open a site in the percolation system */
void open_site(PercolationSystem* system, int x, int y) {
    if (x >= 0 && x < system->size && y >= 0 && y < system->size) {
        system->sites[x + y * system->size]->status = 1;
        system->num_open++;
    }
}

/* Function to check if the percolation system is open */
int is_open(PercolationSystem* system, int x, int y) {
    if (x >= 0 && x < system->size && y >= 0 && y < system->size) {
        return system->sites[x + y * system->size]->status;
    } else {
        return 0;
    }
}

/* Function to check if the percolation system is percolated */
int is_percolated(PercolationSystem* system) {
    for (int i = 0; i < system->size * system->size; i++) {
        if (system->sites[i]->status == 1) {
            if (is_open(system, i % system->size, i / system->size - 1) == 1 ||
                is_open(system, i % system->size, i / system->size + 1) == 1 ||
                is_open(system, i % system->size - 1, i / system->size) == 1 ||
                is_open(system, i % system->size + 1, i / system->size) == 1) {
                return 1;
            }
        }
    }
    return 0;
}

/* Function to simulate a percolation process */
void simulate_percolation(PercolationSystem* system, int num_iterations) {
    for (int i = 0; i < num_iterations; i++) {
        int x = rand() % system->size;
        int y = rand() % system->size;
        open_site(system, x, y);
        if (is_percolated(system)) {
            break;
        }
    }
}

int main() {
    srand(time(NULL));

    PercolationSystem* system = create_percolation_system(MAX_SIZE);

    simulate_percolation(system, 1000);

    printf("Percolation simulation completed.\n");

    free(system->sites);
    free(system);

    return 0;
}