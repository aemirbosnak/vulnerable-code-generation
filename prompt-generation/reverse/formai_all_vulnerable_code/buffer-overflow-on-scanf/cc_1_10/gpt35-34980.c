//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: distributed
#include<stdio.h>
#include<stdlib.h>

int rows, columns;

void print_maze(char **maze) {
    printf("\nMaze:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int is_valid(char **maze, int row, int col) {
    if(row>=0 && row<rows && col>=0 && col<columns && maze[row][col] == ' ') {
        return 1;
    }
    return 0;
}

int solve_maze(char **maze, int row, int col) {
    if(row==0 || col==0 || row==rows-1 || col==columns-1) {
        maze[row][col] = '*';
        return 1;
    }

    if(is_valid(maze, row, col) == 1) {
        maze[row][col] = '*';

        if(solve_maze(maze, row, col+1) == 1) {	//try right
            return 1;
        }
        if(solve_maze(maze, row+1, col) == 1) {	//try down
            return 1;
        }
        if(solve_maze(maze, row, col-1) == 1) {	//try left
            return 1;
        }
        if(solve_maze(maze, row-1, col) == 1) {	//try up
            return 1;
        }

        maze[row][col] = ' '; //backtracking
    }

    return 0;
}

int main() {
    int start_row, start_col;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &columns);

    char **maze = malloc(rows * sizeof(char*));	//allocating memory for the maze

    for(int i=0; i<rows; i++) {
        maze[i] = malloc(columns * sizeof(char));
        for(int j=0; j<columns; j++) {
            maze[i][j] = ' ';
        }
    }

    printf("Enter the maze:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            scanf(" %c", &maze[i][j]);
        }
    }

    printf("Enter the starting position (row and column): ");
    scanf("%d %d", &start_row, &start_col);

    print_maze(maze);
    solve_maze(maze, start_row, start_col);
    print_maze(maze);

    for(int i=0; i<rows; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}