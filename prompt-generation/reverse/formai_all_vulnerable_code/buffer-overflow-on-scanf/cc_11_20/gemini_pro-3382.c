//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Maze dimensions
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// Maze data
int maze[MAZE_HEIGHT][MAZE_WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Player positions
int player1_x = 1;
int player1_y = 1;
int player2_x = MAZE_WIDTH - 2;
int player2_y = MAZE_HEIGHT - 2;

// Player movement directions
enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

// Player input
char player1_input;
char player2_input;

// Mutex for synchronizing player movement
pthread_mutex_t mutex;

// Thread function for player 1
void* player1_thread(void* arg) {
    while (1) {
        // Get player input
        scanf(" %c", &player1_input);

        // Lock the mutex
        pthread_mutex_lock(&mutex);

        // Move player 1
        switch (player1_input) {
            case 'w':
                if (maze[player1_y - 1][player1_x] == 0) {
                    player1_y--;
                }
                break;
            case 's':
                if (maze[player1_y + 1][player1_x] == 0) {
                    player1_y++;
                }
                break;
            case 'a':
                if (maze[player1_y][player1_x - 1] == 0) {
                    player1_x--;
                }
                break;
            case 'd':
                if (maze[player1_y][player1_x + 1] == 0) {
                    player1_x++;
                }
                break;
        }

        // Unlock the mutex
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

// Thread function for player 2
void* player2_thread(void* arg) {
    while (1) {
        // Get player input
        scanf(" %c", &player2_input);

        // Lock the mutex
        pthread_mutex_lock(&mutex);

        // Move player 2
        switch (player2_input) {
            case 'w':
                if (maze[player2_y - 1][player2_x] == 0) {
                    player2_y--;
                }
                break;
            case 's':
                if (maze[player2_y + 1][player2_x] == 0) {
                    player2_y++;
                }
                break;
            case 'a':
                if (maze[player2_y][player2_x - 1] == 0) {
                    player2_x--;
                }
                break;
            case 'd':
                if (maze[player2_y][player2_x + 1] == 0) {
                    player2_x++;
                }
                break;
        }

        // Unlock the mutex
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main() {
    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create the player threads
    pthread_t player1_thread_id;
    pthread_t player2_thread_id;
    pthread_create(&player1_thread_id, NULL, player1_thread, NULL);
    pthread_create(&player2_thread_id, NULL, player2_thread, NULL);

    // Main game loop
    while (1) {
        // Clear the screen
        system("clear");

        // Print the maze
        for (int y = 0; y < MAZE_HEIGHT; y++) {
            for (int x = 0; x < MAZE_WIDTH; x++) {
                if (x == player1_x && y == player1_y) {
                    printf("1");
                } else if (x == player2_x && y == player2_y) {
                    printf("2");
                } else if (maze[y][x] == 1) {
                    printf("#");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Check if either player has reached the goal
        if (player1_x == MAZE_WIDTH - 2 && player1_y == MAZE_HEIGHT - 2) {
            printf("Player 1 wins!\n");
            break;
        } else if (player2_x == MAZE_WIDTH - 2 && player2_y == MAZE_HEIGHT - 2) {
            printf("Player 2 wins!\n");
            break;
        }
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}