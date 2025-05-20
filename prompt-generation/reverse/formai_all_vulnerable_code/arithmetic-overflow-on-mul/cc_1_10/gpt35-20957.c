//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ROWS 50
#define MAX_COLS 50

// This struct will hold the maze information: the maze itself and its dimensions
typedef struct Maze {
    char grid[MAX_ROWS][MAX_COLS];
    int rows;
    int cols;
} Maze;

// This struct will hold the information about each coordinate in the maze
typedef struct Coord {
    int row;
    int col;
} Coord;

// Helper function to read the maze from file
Maze read_maze_from_file(char* filename) {
    Maze maze;
    FILE* file = fopen(filename, "r");

    if (file) {
        fread(&maze.rows, sizeof(int), 1, file);
        fread(&maze.cols, sizeof(int), 1, file);
        fread(&maze.grid, sizeof(char), maze.rows*maze.cols, file);
        fclose(file);
    }

    return maze;
}

// Helper function to check if a coordinate is within the maze boundaries
bool is_within_bounds(Maze* maze, Coord* coord) {
    return (coord->row >= 0 && coord->row < maze->rows && coord->col >= 0 && coord->col < maze->cols);
}

// This function will recursively solve the maze until the end is reached or it's determined to be unsolvable
bool solve_maze_recursively(Maze* maze, Coord* current_pos, Coord* end_pos) {
    // If we reached the end, we solved the maze
    if (current_pos->row == end_pos->row && current_pos->col == end_pos->col) {
        return true;
    }

    // If the current position is blocked or outside the maze boundaries, return false
    if ((!is_within_bounds(maze, current_pos)) || (maze->grid[current_pos->row][current_pos->col] == '@') || (maze->grid[current_pos->row][current_pos->col] == '#')) {
        return false;
    }

    // Mark the current position as part of the solution
    maze->grid[current_pos->row][current_pos->col] = '#';

    // Check all four directions recursively
    Coord up = { current_pos->row-1, current_pos->col };
    if (solve_maze_recursively(maze, &up, end_pos))
        return true;

    Coord down = { current_pos->row+1, current_pos->col };
    if (solve_maze_recursively(maze, &down, end_pos))
        return true;

    Coord left = { current_pos->row, current_pos->col-1 };
    if (solve_maze_recursively(maze, &left, end_pos))
        return true;

    Coord right = { current_pos->row, current_pos->col+1 };
    if (solve_maze_recursively(maze, &right, end_pos))
        return true;

    // If none of the directions lead to a solution, mark the current position as not part of the solution
    maze->grid[current_pos->row][current_pos->col] = '.';

    return false;
}

// This function starts the recursive maze solving process and returns the solved maze
Maze solve_maze(Maze* maze, Coord* start_pos, Coord* end_pos) {
    Maze solved_maze = *maze;
    solve_maze_recursively(&solved_maze, start_pos, end_pos);
    return solved_maze;
}

// This function prints the maze to stdout
void print_maze(Maze* maze) {
    for (int row=0; row<maze->rows; row++) {
        for (int col=0; col<maze->cols; col++) {
            printf("%c", maze->grid[row][col]);
        }
        printf("\n");
    }
}

int main() {
    // Read the maze from file
    Maze maze = read_maze_from_file("maze.txt");

    // Define the start and end positions
    Coord start_pos = { 1, 0 };
    Coord end_pos = { 6, 5 };

    // Solve the maze
    Maze solved_maze = solve_maze(&maze, &start_pos, &end_pos);

    // Print the solved maze to stdout
    print_maze(&solved_maze);

    return 0;
}