//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10
#define START_X 0
#define START_Y 0
#define END_X 9
#define END_Y 9

const char *maze =
"#########"
"#   #   #"
"# ### ###"
"# # # # #"
"# # # # #"
"# ### ###"
"#   #   #"
"# # # # #"
"# # # # #"
"#########"
;

int main()
{
    // Allocate a 2D array to represent the maze
    char **maze_array = (char **)malloc(MAZE_HEIGHT * sizeof(char *));
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        maze_array[i] = (char *)malloc(MAZE_WIDTH * sizeof(char));
    }

    // Copy the maze into the 2D array
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            maze_array[i][j] = maze[i * MAZE_WIDTH + j];
        }
    }

    // Find the starting point
    int x = START_X;
    int y = START_Y;

    // Find the ending point
    int end_x = END_X;
    int end_y = END_Y;

    // Create a stack to store the path
    int *stack = (int *)malloc(MAZE_WIDTH * MAZE_HEIGHT * sizeof(int));
    int stack_top = 0;

    // Push the starting point onto the stack
    stack[stack_top++] = x;
    stack[stack_top++] = y;

    // While the stack is not empty
    while (stack_top > 0) {
        // Pop the top of the stack
        x = stack[--stack_top];
        y = stack[--stack_top];

        // Check if the current position is the ending point
        if (x == end_x && y == end_y) {
            // Print the path
            for (int i = 0; i < stack_top; i += 2) {
                printf("(%d, %d)\n", stack[i], stack[i + 1]);
            }

            // Free the stack
            free(stack);

            // Free the maze array
            for (int i = 0; i < MAZE_HEIGHT; i++) {
                free(maze_array[i]);
            }
            free(maze_array);

            // Return
            return 0;
        }

        // Check if the current position is a valid move
        if (maze_array[y][x] == ' ') {
            // Mark the current position as visited
            maze_array[y][x] = '.';

            // Push the current position's neighbors onto the stack
            if (x > 0 && maze_array[y][x - 1] == ' ') {
                stack[stack_top++] = x - 1;
                stack[stack_top++] = y;
            }
            if (y > 0 && maze_array[y - 1][x] == ' ') {
                stack[stack_top++] = x;
                stack[stack_top++] = y - 1;
            }
            if (x < MAZE_WIDTH - 1 && maze_array[y][x + 1] == ' ') {
                stack[stack_top++] = x + 1;
                stack[stack_top++] = y;
            }
            if (y < MAZE_HEIGHT - 1 && maze_array[y + 1][x] == ' ') {
                stack[stack_top++] = x;
                stack[stack_top++] = y + 1;
            }
        }
    }

    // The maze is unsolvable
    printf("The maze is unsolvable.\n");

    // Free the stack
    free(stack);

    // Free the maze array
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        free(maze_array[i]);
    }
    free(maze_array);

    // Return
    return 0;
}