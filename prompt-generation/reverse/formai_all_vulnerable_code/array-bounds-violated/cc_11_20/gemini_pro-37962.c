//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} point;

int main(void) {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Create a maze of size 10x10
    int maze[10][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    // Create a stack to store the path
    point stack[100];
    int top = -1;

    // Create a visited array to keep track of which cells have been visited
    int visited[10][10] = {0};

    // Start at the top-left corner of the maze
    point current = {0, 0};

    // While the current cell is not the bottom-right corner of the maze
    while (current.x != 9 || current.y != 9) {
        // If the current cell has not been visited
        if (!visited[current.x][current.y]) {
            // Push the current cell onto the stack
            stack[++top] = current;

            // Mark the current cell as visited
            visited[current.x][current.y] = 1;

            // Get a list of possible moves from the current cell
            point moves[] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
            int num_moves = sizeof(moves) / sizeof(moves[0]);

            // Shuffle the list of possible moves
            for (int i = 0; i < num_moves; i++) {
                int j = rand() % num_moves;
                point temp = moves[i];
                moves[i] = moves[j];
                moves[j] = temp;
            }

            // Try each possible move until one is found that is valid
            int found = 0;
            for (int i = 0; i < num_moves && !found; i++) {
                point next = {current.x + moves[i].x, current.y + moves[i].y};

                // If the next cell is within the bounds of the maze and has not been visited
                if (next.x >= 0 && next.x < 10 && next.y >= 0 && next.y < 10 && !visited[next.x][next.y] && maze[next.x][next.y] == 0) {
                    // Set the current cell to the next cell
                    current = next;

                    // Set the found flag to true
                    found = 1;
                }
            }

            // If no valid move was found, pop the current cell from the stack
            if (!found) {
                top--;
                current = stack[top];
            }
        } else {
            // Pop the current cell from the stack
            top--;
            current = stack[top];
        }
    }

    // Print the path from the top-left corner to the bottom-right corner of the maze
    for (int i = 0; i <= top; i++) {
        printf("(%d, %d)\n", stack[i].x, stack[i].y);
    }

    return 0;
}