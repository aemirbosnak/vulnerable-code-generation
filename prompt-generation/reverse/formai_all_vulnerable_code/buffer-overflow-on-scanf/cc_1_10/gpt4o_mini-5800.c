//GPT-4o-mini DATASET v1.0 Category: Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 5
#define TREASURES 3
#define TRAPS 2

typedef struct {
    int x;
    int y;
    int treasures_collected;
} Player;

char maze[MAZE_SIZE][MAZE_SIZE];
Player player;

void initialize_maze() {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = '.';
        }
    }
}

void place_treasures() {
    for (int i = 0; i < TREASURES; i++) {
        int x = rand() % MAZE_SIZE;
        int y = rand() % MAZE_SIZE;
        while (maze[x][y] != '.') {
            x = rand() % MAZE_SIZE;
            y = rand() % MAZE_SIZE;
        }
        maze[x][y] = 'T'; // T for treasure
    }
}

void place_traps() {
    for (int i = 0; i < TRAPS; i++) {
        int x = rand() % MAZE_SIZE;
        int y = rand() % MAZE_SIZE;
        while (maze[x][y] != '.' ) {
            x = rand() % MAZE_SIZE;
            y = rand() % MAZE_SIZE;
        }
        maze[x][y] = 'X'; // X for trap
    }
}

void print_maze() {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (i == player.x && j == player.y)
                printf("P "); // P for player
            else
                printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("Treasures collected: %d\n", player.treasures_collected);
}

void move_player(char direction) {
    int new_x = player.x;
    int new_y = player.y;

    switch (direction) {
        case 'w': new_x--; break; // Up
        case 's': new_x++; break; // Down
        case 'a': new_y--; break; // Left
        case 'd': new_y++; break; // Right
        default: break;
    }

    if (new_x >= 0 && new_x < MAZE_SIZE && new_y >= 0 && new_y < MAZE_SIZE) {
        player.x = new_x;
        player.y = new_y;

        char current_cell = maze[player.x][player.y];
        if (current_cell == 'T') {
            player.treasures_collected++;
            maze[player.x][player.y] = '.'; // Remove treasure after collecting
            printf("You found a treasure!\n");
        }
        else if (current_cell == 'X') {
            printf("You stepped on a trap! Game over.\n");
            exit(0);
        }
    } else {
        printf("You can't go that way!\n");
    }
}

int main() {
    srand(time(NULL));
    initialize_maze();
    place_treasures();
    place_traps();

    player.x = 0;
    player.y = 0;
    player.treasures_collected = 0;

    printf("Welcome to the Maze Adventure!\n");
    printf("Collect treasures while avoiding traps.\n");
    printf("Move using W (up), A (left), S (down), D (right).\n");

    while (1) {
        print_maze();
        printf("Enter your move: ");
        char move;
        scanf(" %c", &move);
        move_player(move);
    }

    return 0;
}