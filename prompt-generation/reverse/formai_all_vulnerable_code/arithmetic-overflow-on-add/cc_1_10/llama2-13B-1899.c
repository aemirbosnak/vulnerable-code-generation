//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to hold the maze data
typedef struct {
    int rows;
    int cols;
    int** grid;
} maze_t;

// Function to generate a random maze
void generate_maze(maze_t* maze) {
    int i, j;
    for (i = 0; i < maze->rows; i++) {
        for (j = 0; j < maze->cols; j++) {
            // 25% chance of a wall
            if (rand() % 4 == 0) {
                maze->grid[i][j] = 1;
            } else {
                maze->grid[i][j] = 0;
            }
        }
    }
}

// Function to move the player through the maze
void move_player(maze_t* maze, int player_x, int player_y) {
    int new_x, new_y;
    // Check for walls
    if (maze->grid[player_y][player_x] == 1) {
        // If we hit a wall, move down
        if (player_y > 0) {
            player_y--;
        } else {
            // If we hit a wall and there's no more down, move right
            player_x++;
        }
    } else {
        // If there's no wall, move right
        player_x++;
    }
    // Update the player position
    new_x = player_x;
    new_y = player_y;
    maze->grid[new_y][new_x] = 2; // Mark the player position
    player_x = new_x;
    player_y = new_y;
}

// Function to check if the player has won
int check_win(maze_t* maze) {
    int i, j;
    for (i = 0; i < maze->rows; i++) {
        for (j = 0; j < maze->cols; j++) {
            if (maze->grid[i][j] == 2) {
                return 1; // Player has won
            }
        }
    }
    return 0; // Player has not won
}

int main() {
    // Initialize the maze
    maze_t* maze = (maze_t*)malloc(sizeof(maze_t));
    generate_maze(maze);

    // Set the player position
    int player_x = 5;
    int player_y = 5;

    // Set the goal position
    int goal_x = 15;
    int goal_y = 15;

    // Game loop
    while (1) {
        // Print the maze
        for (int i = 0; i < maze->rows; i++) {
            for (int j = 0; j < maze->cols; j++) {
                printf("%d ", maze->grid[i][j]);
            }
            printf("\n");
        }

        // Ask the user for a move
        printf("Enter row and column to move (e.g. 3 5): ");
        scanf("%d %d", &player_x, &player_y);

        // Move the player
        move_player(maze, player_x, player_y);

        // Check if the player has won
        if (check_win(maze)) {
            printf("You win! Congratulations!\n");
            break;
        }
    }

    // Free the maze memory
    free(maze);

    return 0;
}