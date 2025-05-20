//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: ephemeral
/*
 * Percolation Simulator in C
 * 
 * This program simulates the percolation process in a 2D lattice.
 * The user can specify the size of the lattice and the probability
 * of each site being open or blocked. The program then calculates
 * the percolation threshold and displays the final state of the lattice.
 * 
 * Author: Your Name
 * Date: Today's Date
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define OPEN 1
#define BLOCKED 0

int lattice[MAX_SIZE][MAX_SIZE];
int size;
int threshold;

void init_lattice(int s) {
    srand(time(NULL));
    size = s;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            lattice[i][j] = (rand() % 2 == 0)? BLOCKED : OPEN;
        }
    }
}

void display_lattice() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (lattice[i][j] == OPEN) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int i, int j) {
    int count = 0;
    if (i > 0 && lattice[i-1][j] == OPEN) count++;
    if (i < size-1 && lattice[i+1][j] == OPEN) count++;
    if (j > 0 && lattice[i][j-1] == OPEN) count++;
    if (j < size-1 && lattice[i][j+1] == OPEN) count++;
    return count;
}

void percolate() {
    int open_sites = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (lattice[i][j] == BLOCKED) {
                int neighbors = count_neighbors(i, j);
                if (neighbors >= threshold) {
                    lattice[i][j] = OPEN;
                    open_sites++;
                }
            }
        }
    }
}

int main() {
    int s;
    printf("Enter the size of the lattice: ");
    scanf("%d", &s);
    init_lattice(s);
    printf("Enter the probability threshold (0-1): ");
    scanf("%f", &threshold);
    percolate();
    display_lattice();
    return 0;
}