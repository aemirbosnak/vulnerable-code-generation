//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// maze structure
typedef struct {
    char cells[MAX_ROWS][MAX_COLS];
    int start_row;
    int start_col;
    int end_row;
    int end_col;
} maze;

// function to read maze from file
void read_maze(char* filename, maze* maze_ptr) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s for reading.\n", filename);
        exit(1);
    }
    // read maze dimensions
    int rows, cols;
    fscanf(fp, "%d %d", &rows, &cols);
    if (rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Error: Maze is too big.\n");
        fclose(fp);
        exit(1);
    }
    maze_ptr->start_row = -1;
    maze_ptr->start_col = -1;
    maze_ptr->end_row = -1;
    maze_ptr->end_col = -1;
    // read maze cells and start/end positions
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            char cell;
            fscanf(fp, " %c", &cell);
            maze_ptr->cells[row][col] = cell;
            if (cell == 'S') {
                if (maze_ptr->start_row == -1) {
                    maze_ptr->start_row = row;
                    maze_ptr->start_col = col;
                } else {
                    printf("Error: Maze has multiple start positions.\n");
                    fclose(fp);
                    exit(1);
                }
            } else if (cell == 'E') {
                if (maze_ptr->end_row == -1) {
                    maze_ptr->end_row = row;
                    maze_ptr->end_col = col;
                } else {
                    printf("Error: Maze has multiple end positions.\n");
                    fclose(fp);
                    exit(1);
                }
            }
        }
    }
    if (maze_ptr->start_row == -1) {
        printf("Error: Maze does not have a start position.\n");
        fclose(fp);
        exit(1);
    } else if (maze_ptr->end_row == -1) {
        printf("Error: Maze does not have an end position.\n");
        fclose(fp);
        exit(1);
    }
    fclose(fp);
}

// function to print maze
void print_maze(maze* maze_ptr) {
    for (int row = 0; row < MAX_ROWS; row++) {
        for (int col = 0; col < MAX_COLS; col++) {
            printf("%c ", maze_ptr->cells[row][col]);
        }
        printf("\n");
    }
}

// recursive function to find path
int find_path(int row, int col, maze* maze_ptr) {
    if (row < 0 || row >= MAX_ROWS || col < 0 || col >= MAX_COLS) {
        return 0;   // outside of maze
    } else if (maze_ptr->cells[row][col] == '#') {
        return 0;   // wall
    } else if (maze_ptr->cells[row][col] == 'X') {
        return 0;   // already visited
    } else if (maze_ptr->cells[row][col] == 'E') {
        return 1;   // end position found
    }
    maze_ptr->cells[row][col] = 'X';   // mark position as visited
    if (find_path(row-1, col, maze_ptr) == 1) {   // up
        return 1;
    } else if (find_path(row+1, col, maze_ptr) == 1) {   // down
        return 1;
    } else if (find_path(row, col-1, maze_ptr) == 1) {   // left
        return 1;
    } else if (find_path(row, col+1, maze_ptr) == 1) {   // right
        return 1;
    } else {
        maze_ptr->cells[row][col] = '.';   // unmark position as visited
        return 0;   // dead end
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <maze_file>\n", argv[0]);
        return 1;
    }
    // read maze from file
    maze maze_var;
    read_maze(argv[1], &maze_var);
    // print maze
    printf("Maze:\n");
    print_maze(&maze_var);
    // find path
    printf("Finding path...\n");
    if (find_path(maze_var.start_row, maze_var.start_col, &maze_var) == 1) {
        printf("Path found!\n");
        // print maze with path
        for (int row = 0; row < MAX_ROWS; row++) {
            for (int col = 0; col < MAX_COLS; col++) {
                if (maze_var.cells[row][col] == 'X') {
                    printf("* ");
                } else {
                    printf("%c ", maze_var.cells[row][col]);
                }
            }
            printf("\n");
        }
    } else {
        printf("Path not found.\n");
    }
    return 0;
}