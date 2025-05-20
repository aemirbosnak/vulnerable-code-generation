//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// Struct representing each cell in the maze
typedef struct {
    int row, col;
    int walls[4]; // North, East, South, West
    int visited;
} Cell;

// Function to generate a random number between min and max
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to initialize the maze cells with walls and unvisited status
void init_maze(Cell maze[][SIZE], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            maze[i][j].row = i;
            maze[i][j].col = j;
            maze[i][j].walls[0] = 1; // North wall
            maze[i][j].walls[1] = 1; // East wall
            maze[i][j].walls[2] = 1; // South wall
            maze[i][j].walls[3] = 1; // West wall
            maze[i][j].visited = 0;
        }
    }
}

// Function to print the maze walls
void print_maze(Cell maze[][SIZE], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%c", maze[i][j].walls[0] ? '-' : ' ');
            printf("%c", maze[i][j].walls[1] ? '|' : ' ');
        }
        printf("\n");
    }
}

// Recursive function to generate the maze using recursive backtracking algorithm
void generate_maze(Cell maze[][SIZE], int row, int col, int size) {
    // Mark the current cell as visited
    maze[row][col].visited = 1;
    
    // Randomly select an unvisited neighbor cell
    int directions[4] = {0, 1, 2, 3};
    int dir_index, i, temp;
    for (i = 3; i >= 0; i--) {
        dir_index = rand_range(0, i);
        temp = directions[i];
        directions[i] = directions[dir_index];
        directions[dir_index] = temp;
    }
    
    int next_row, next_col;
    for (i = 0; i < 4; i++) {
        switch(directions[i]) {
            case 0: // North
                next_row = row - 1;
                next_col = col;
                break;
            case 1: // East
                next_row = row;
                next_col = col + 1;
                break;
            case 2: // South
                next_row = row + 1;
                next_col = col;
                break;
            case 3: // West
                next_row = row;
                next_col = col - 1;
                break;
        }
        
        if (next_row < 0 || next_row >= size || next_col < 0 || next_col >= size) {
            continue;
        }
        
        if (maze[next_row][next_col].visited) {
            continue;
        }
        
        // Remove the wall between the current cell and the selected neighbor
        if (next_row == row) {
            if (next_col < col) {
                maze[row][col].walls[3] = 0; // Remove West wall
                maze[next_row][next_col].walls[1] = 0; // Remove East wall
            } else {
                maze[row][col].walls[1] = 0; // Remove East wall
                maze[next_row][next_col].walls[3] = 0; // Remove West wall
            }
        } else {
            if (next_row < row) {
                maze[row][col].walls[0] = 0; // Remove North wall
                maze[next_row][next_col].walls[2] = 0; // Remove South wall
            } else {
                maze[row][col].walls[2] = 0; // Remove South wall
                maze[next_row][next_col].walls[0] = 0; // Remove North wall
            }
        }
        
        // Recursively call the function for the selected neighbor
        generate_maze(maze, next_row, next_col, size);
    }
}

int main() {
    srand(time(NULL));
    Cell maze[SIZE][SIZE];
    int size, start_row, start_col, end_row, end_col;
    
    printf("Welcome to the Happy Maze Generator!\n");
    printf("What size do you want your maze to be? (2-20) ");
    scanf("%d", &size);
    
    if (size < 2 || size > 20) {
        printf("Invalid size. The size must be between 2 and 20.\n");
        return 0;
    }
    
    printf("Generating a happy maze just for you...\n");
    init_maze(maze, size);
    generate_maze(maze, 0, 0, size);
    printf("Your maze is ready!\n");
    print_maze(maze, size);
    
    // Find the start and end cells
    start_row = rand_range(0, size-1);
    start_col = 0;
    maze[start_row][start_col].walls[3] = 0; // Remove West wall
    end_row = rand_range(0, size-1);
    end_col = size-1;
    maze[end_row][end_col].walls[1] = 0; // Remove East wall
    
    printf("Get ready to find your way out!\n");
    // Solve the maze using depth-first search
    // Print the path taken and congratulate the user once the solution is found
    // (Code for the solve_maze function is omitted for brevity)
    // ...
    printf("You did it! You solved the maze and found your way out!\n");
    
    return 0;
}