//Code Llama-13B DATASET v1.0 Category: Procedurally Generated Maze ; Style: introspective
/*
 * Maze Generation using Recursive Backtracking
 *
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10
#define MAX_STEPS 100

// Maze structure
struct maze {
    int width;
    int height;
    int** grid;
};

// Maze generation function
void generate_maze(struct maze* m) {
    // Initialize random seed
    srand(time(NULL));

    // Initialize maze grid
    m->grid = (int**)malloc(m->width * sizeof(int*));
    for (int i = 0; i < m->width; i++) {
        m->grid[i] = (int*)malloc(m->height * sizeof(int));
    }

    // Initialize maze boundaries
    for (int i = 0; i < m->width; i++) {
        m->grid[i][0] = 1;
        m->grid[i][m->height - 1] = 1;
    }
    for (int j = 0; j < m->height; j++) {
        m->grid[0][j] = 1;
        m->grid[m->width - 1][j] = 1;
    }

    // Generate maze
    int x = 1, y = 1;
    int steps = 0;
    while (steps < MAX_STEPS) {
        // Generate random direction
        int dir = rand() % 4;

        // Check if valid move
        if (dir == 0 && y > 1 && m->grid[x][y - 1] == 0) {
            y--;
            m->grid[x][y] = 1;
            steps++;
        } else if (dir == 1 && x < m->width - 1 && m->grid[x + 1][y] == 0) {
            x++;
            m->grid[x][y] = 1;
            steps++;
        } else if (dir == 2 && y < m->height - 1 && m->grid[x][y + 1] == 0) {
            y++;
            m->grid[x][y] = 1;
            steps++;
        } else if (dir == 3 && x > 1 && m->grid[x - 1][y] == 0) {
            x--;
            m->grid[x][y] = 1;
            steps++;
        }
    }
}

// Maze printing function
void print_maze(struct maze* m) {
    for (int i = 0; i < m->width; i++) {
        for (int j = 0; j < m->height; j++) {
            if (m->grid[i][j] == 1) {
                printf("  ");
            } else {
                printf("##");
            }
        }
        printf("\n");
    }
}

int main() {
    // Initialize maze
    struct maze m;
    m.width = WIDTH;
    m.height = HEIGHT;

    // Generate maze
    generate_maze(&m);

    // Print maze
    print_maze(&m);

    return 0;
}