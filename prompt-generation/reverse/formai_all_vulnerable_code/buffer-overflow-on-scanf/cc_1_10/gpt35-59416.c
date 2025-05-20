//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // size of the grid

int grid[SIZE][SIZE];
int visited[SIZE][SIZE];

void initialize_grid() { // sets all values to 0
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

void fill_grid(int probability) { // randomly fills the grid
    int i, j, random_num;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            random_num = rand() % 100;
            if (random_num < probability) {
                grid[i][j] = 1;
            }
        }
    }
}

void print_grid() { // prints the grid
    int i, j;
    printf("\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

void percolate(int x, int y) { // recursive function to check if grid percolates
    visited[x][y] = 1;
    if (x == SIZE-1) {
        grid[x][y] = 2;
        return;
    }
    if (x < SIZE-1 && grid[x+1][y] == 1 && !visited[x+1][y]) {
        percolate(x+1, y);
    }
    if (y < SIZE-1 && grid[x][y+1] == 1 && !visited[x][y+1]) {
        percolate(x, y+1);
    }
    if (x > 0 && grid[x-1][y] == 1 && !visited[x-1][y]) {
        percolate(x-1, y);
    }
    if (y > 0 && grid[x][y-1] == 1 && !visited[x][y-1]) {
        percolate(x, y-1);
    }
    grid[x][y] = 2;
}

int check_percolation() { // checks if grid percolates
    int i;
    for (i = 0; i < SIZE; i++) {
        if (grid[0][i] == 1) {
            percolate(0, i);
        }
    }
    for (i = 0; i < SIZE; i++) {
        if (grid[SIZE-1][i] == 2) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int probability;
    printf("O Romeo, how about playing a game tonight?\n");
    printf("Shall we have some fun and simulate some percolation?\n");
    printf("Let's create a grid of size %dx%d. What probability should we use to fill it up?\n", SIZE, SIZE);
    scanf("%d", &probability);
    initialize_grid();
    fill_grid(probability);
    printf("This is how the grid looks like before percolation:\n");
    print_grid();
    if (check_percolation()) {
        printf("And behold! The grid percolates!\n");
    } else {
        printf("Alas, the grid does not percolate.\n");
    }
    printf("Oh sweet Juliet, did you enjoy our little game?\n");
    printf("Let's play again sometime.");
    return 0;
}