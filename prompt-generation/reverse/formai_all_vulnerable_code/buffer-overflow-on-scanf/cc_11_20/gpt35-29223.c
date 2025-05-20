//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20 // Maximum size of the maze

// Function to print the maze
void printMaze(int maze[][MAX_SIZE], int size) {
    printf("+");
    for (int i = 0; i < size; i++) {
        printf("-+");
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("|");
        for (int j = 0; j < size; j++) {
            if (maze[i][j] == 0) printf(" |");
            else printf("#|");
        }
        printf("\n");
        printf("+");
        for (int k = 0; k < size; k++) {
            printf("-+");
        }
        printf("\n");
    }
}

// Function to generate the maze
void generateMaze(int maze[][MAX_SIZE], int size) {
    // Set the seed for the random number generator
    srand(time(NULL));
    
    // Array to keep track of visited cells
    int visited[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            visited[i][j] = 0;
        }
    }
    
    // Starting position of the maze
    int row = rand() % size;
    int col = rand() % size;
    maze[row][col] = 1;
    visited[row][col] = 1;
    
    // Variables to keep track of current cell and next cell
    int curr_row, curr_col, next_row, next_col;
    
    // Loop until all cells have been visited
    while (1) {
        // Flag to check if there are any unvisited cells
        int flag = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (visited[i][j] == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) break;
        }
        if (flag == 0) break;
        
        // Create a list of neighboring cells
        int neighbors[4][2];
        int count = 0;
        if (row > 0 && visited[row-1][col] == 0) {
            neighbors[count][0] = row-1;
            neighbors[count][1] = col;
            count++;
        }
        if (col < size-1 && visited[row][col+1] == 0) {
            neighbors[count][0] = row;
            neighbors[count][1] = col+1;
            count++;
        }
        if (row < size-1 && visited[row+1][col] == 0) {
            neighbors[count][0] = row+1;
            neighbors[count][1] = col;
            count++;
        }
        if (col > 0 && visited[row][col-1] == 0) {
            neighbors[count][0] = row;
            neighbors[count][1] = col-1;
            count++;
        }
        
        // If there are no neighboring cells, backtrack to the previous cell
        if (count == 0) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (visited[i][j] == 1 && maze[i][j] != 2) {
                        curr_row = i;
                        curr_col = j;
                        maze[curr_row][curr_col] = 2;
                        break;
                    }
                }
                if (maze[curr_row][curr_col] == 2) break;
            }
        }
        // If there are neighboring cells, choose one at random
        else {
            int r = rand() % count;
            next_row = neighbors[r][0];
            next_col = neighbors[r][1];
            maze[next_row][next_col] = 1;
            visited[next_row][next_col] = 1;
            curr_row = row;
            curr_col = col;
            row = next_row;
            col = next_col;
        }
    }
}

int main() {
    // Read the size of the maze from user
    int size;
    printf("Enter the size of the maze: ");
    scanf("%d", &size);
    
    // Check if size is within the allowed range
    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid input. Size must be between 1 and %d.\n", MAX_SIZE);
        return 0;
    }
    
    // Create the maze
    int maze[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            maze[i][j] = 0;
        }
    }
    generateMaze(maze, size);
    
    // Print the maze
    printMaze(maze, size);
    
    return 0;
}