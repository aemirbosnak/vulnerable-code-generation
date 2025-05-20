//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 30
#define MAX_COLS 60

char maze[MAX_ROWS][MAX_COLS];  // Maze grid

void generate_maze(int row, int col)
{
    srand(time(NULL));  // Initialize random number generator
    
    // Create maze outer walls
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (i == 0 || i == MAX_ROWS-1 || j == 0 || j == MAX_COLS-1) {
                maze[i][j] = '#';
            }
            else {
                maze[i][j] = '.';
            }
        }
    }
    
    // Create maze inner walls
    for (int i = 2; i < MAX_ROWS-2; i += 2) {
        for (int j = 2; j < MAX_COLS-2; j += 2) {
            maze[i][j] = '#';
            
            // Randomly decide whether to add vertical wall
            if (i < row && rand() % 2 == 0) {
                for (int k = i+1; k < row; k++) {
                    maze[k][j] = '#';
                }
            }
            
            // Randomly decide whether to add horizontal wall
            if (j < col && rand() % 2 == 0) {
                for (int k = j+1; k < col; k++) {
                    maze[i][k] = '#';
                }
            }
        }
    }
    
    // Set start and end points
    maze[1][0] = 'S';
    maze[row-2][col-1] = 'E';
}

void print_maze()
{
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int row, col;
    
    printf("Enter number of rows (odd number between 5 and %d): ", MAX_ROWS);
    scanf("%d", &row);
    
    printf("Enter number of columns (odd number between 5 and %d): ", MAX_COLS);
    scanf("%d", &col);
    
    // Make sure row and col are odd numbers within range
    if (row % 2 == 0) row++;
    if (col % 2 == 0) col++;
    if (row < 5) row = 5;
    if (col < 5) col = 5;
    if (row > MAX_ROWS) row = MAX_ROWS;
    if (col > MAX_COLS) col = MAX_COLS;
    
    generate_maze(row, col);
    print_maze();
    
    return 0;
}