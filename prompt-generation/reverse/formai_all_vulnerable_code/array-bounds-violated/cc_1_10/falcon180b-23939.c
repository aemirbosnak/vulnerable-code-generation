//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int grid[SIZE][SIZE];
int count = 0;

void init(int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }
}

void print_grid(int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void add_water(int size, int x, int y) {
    grid[x][y] = 1;
    count++;
}

int check_neighbors(int size, int x, int y) {
    int i, j, neighbors = 0;
    for (i = 0; i < size; i++) {
        if (grid[x][i] == 1) {
            neighbors++;
        }
        if (grid[i][y] == 1) {
            neighbors++;
        }
    }
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if ((i + j == x + y) && grid[i][j] == 1) {
                neighbors++;
            }
        }
    }
    return neighbors;
}

void percolate(int size) {
    int i, j, x, y, neighbors;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (grid[i][j] == 0) {
                x = i;
                y = j;
                neighbors = check_neighbors(size, x, y);
                if (neighbors == 3) {
                    add_water(size, x, y);
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int size, x, y;
    srand(time(NULL));
    printf("Enter the size of the grid: ");
    scanf("%d", &size);
    init(size);
    while (count < size * size) {
        printf("Enter the coordinates of the next cell to add water to (x y): ");
        scanf("%d %d", &x, &y);
        add_water(size, x, y);
    }
    print_grid(size);
    percolate(size);
    printf("After percolation:\n");
    print_grid(size);
    return 0;
}