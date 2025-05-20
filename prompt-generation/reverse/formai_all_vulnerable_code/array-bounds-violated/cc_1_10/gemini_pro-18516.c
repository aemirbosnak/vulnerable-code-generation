//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAZE_SIZE 10
#define NUM_PLAYERS 4

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    int id;
    Position position;
    int score;
} Player;

char maze[MAZE_SIZE][MAZE_SIZE];
Player players[NUM_PLAYERS];
pthread_mutex_t maze_lock;

void init_maze() {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = '.';
        }
    }

    // Create walls
    for (int i = 0; i < MAZE_SIZE; i++) {
        maze[i][0] = '#';
        maze[i][MAZE_SIZE - 1] = '#';
    }
    for (int j = 0; j < MAZE_SIZE; j++) {
        maze[0][j] = '#';
        maze[MAZE_SIZE - 1][j] = '#';
    }

    // Create a random path through the maze
    int x = 1;
    int y = 1;
    while (x != MAZE_SIZE - 2 || y != MAZE_SIZE - 2) {
        int directions[4];
        int num_directions = 0;
        if (maze[x + 1][y] == '.') {
            directions[num_directions++] = 0;
        }
        if (maze[x - 1][y] == '.') {
            directions[num_directions++] = 1;
        }
        if (maze[x][y + 1] == '.') {
            directions[num_directions++] = 2;
        }
        if (maze[x][y - 1] == '.') {
            directions[num_directions++] = 3;
        }
        int direction = directions[rand() % num_directions];
        switch (direction) {
            case 0:
                x++;
                break;
            case 1:
                x--;
                break;
            case 2:
                y++;
                break;
            case 3:
                y--;
                break;
        }
        maze[x][y] = ' ';
    }
}

void init_players() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i].id = i;
        players[i].position.x = 1;
        players[i].position.y = 1;
        players[i].score = 0;
    }
}

void print_maze() {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void *player_thread(void *arg) {
    Player *player = (Player *)arg;

    while (1) {
        // Get player input
        char input;
        printf("Player %d, enter a move (w, a, s, d): ", player->id);
        scanf(" %c", &input);

        // Update player position
        pthread_mutex_lock(&maze_lock);
        switch (input) {
            case 'w':
                if (maze[player->position.x - 1][player->position.y] == ' ') {
                    player->position.x--;
                }
                break;
            case 'a':
                if (maze[player->position.x][player->position.y - 1] == ' ') {
                    player->position.y--;
                }
                break;
            case 's':
                if (maze[player->position.x + 1][player->position.y] == ' ') {
                    player->position.x++;
                }
                break;
            case 'd':
                if (maze[player->position.x][player->position.y + 1] == ' ') {
                    player->position.y++;
                }
                break;
        }
        pthread_mutex_unlock(&maze_lock);

        // Check if player has reached the exit
        if (player->position.x == MAZE_SIZE - 2 && player->position.y == MAZE_SIZE - 2) {
            printf("Player %d has reached the exit!\n", player->id);
            break;
        }
    }

    return NULL;
}

int main() {
    // Initialize the maze
    init_maze();

    // Initialize the players
    init_players();

    // Create a mutex to protect the maze
    pthread_mutex_init(&maze_lock, NULL);

    // Create a thread for each player
    pthread_t threads[NUM_PLAYERS];
    for (int i = 0; i < NUM_PLAYERS; i++) {
        pthread_create(&threads[i], NULL, player_thread, &players[i]);
    }

    // Join all threads
    for (int i = 0; i < NUM_PLAYERS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&maze_lock);

    // Print the final maze
    print_maze();

    return 0;
}