//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number in the range [0, 1]
double random_double() {
    return (double)rand() / (double)RAND_MAX;
}

// Function to generate a maze using a random walk algorithm
void generate_maze(int rows, int cols) {
    int i, j;
    char maze[rows][cols];
    
    // Fill the maze with walls
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            maze[i][j] = '.';
        }
    }
    
    // Create a starting point and a destination point
    int start_row = rand() % rows;
    int start_col = rand() % cols;
    int dest_row = rand() % rows;
    int dest_col = rand() % cols;
    
    // Create a random path from start to destination
    int steps = 0;
    int x = start_row;
    int y = start_col;
    do {
        int dx = (int)(random_double() * 2 - 1);
        int dy = (int)(random_double() * 2 - 1);
        if (maze[x + dx][y + dy] == '.' && (dx == 0 || dy == 0 || dx == -1 || dy == 1)) {
            maze[x][y] = '*';
            x += dx;
            y += dy;
        } else {
            maze[x][y] = '#';
            break;
        }
        steps++;
    } while (x!= dest_row || y!= dest_col);
    
    // Print the maze
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to get user input for rows and columns
void get_input(int *rows, int *cols) {
    printf("Enter the number of rows: ");
    scanf("%d", rows);
    
    printf("Enter the number of columns: ");
    scanf("%d", cols);
}

// Main function
int main() {
    int rows, cols;
    get_input(&rows, &cols);
    generate_maze(rows, cols);
    return 0;
}