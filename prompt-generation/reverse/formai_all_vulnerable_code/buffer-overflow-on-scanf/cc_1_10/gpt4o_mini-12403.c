//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define TREASURE 'T'
#define DANGER 'D'
#define EMPTY '.'
#define PLAYER 'P'

typedef struct {
    int x;
    int y;
} Position;

void initialize_grid(char grid[GRID_SIZE][GRID_SIZE], Position *treasure, Position *danger) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = EMPTY;
        }
    }

    // Randomly place the treasure
    treasure->x = rand() % GRID_SIZE;
    treasure->y = rand() % GRID_SIZE;
    grid[treasure->x][treasure->y] = TREASURE;

    // Randomly place the danger
    do {
        danger->x = rand() % GRID_SIZE;
        danger->y = rand() % GRID_SIZE;
    } while (danger->x == treasure->x && danger->y == treasure->y);
    
    grid[danger->x][danger->y] = DANGER;
}

void print_grid(char grid[GRID_SIZE][GRID_SIZE], Position player) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == player.x && j == player.y) {
                printf("%c ", PLAYER);
            } else {
                printf("%c ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

int move_player(Position *player, char direction) {
    switch (direction) {
        case 'w': // Up
            if (player->x > 0) player->x--;
            break;
        case 's': // Down
            if (player->x < GRID_SIZE - 1) player->x++;
            break;
        case 'a': // Left
            if (player->y > 0) player->y--;
            break;
        case 'd': // Right
            if (player->y < GRID_SIZE - 1) player->y++;
            break;
        default:
            return 0; // Invalid move
    }
    return 1; // Valid move
}

int check_position(Position player, Position treasure, Position danger) {
    if (player.x == treasure.x && player.y == treasure.y) {
        return 1; // Found treasure
    }

    if (player.x == danger.x && player.y == danger.y) {
        return -1; // Encountered danger
    }

    return 0; // Nothing special
}

int main() {
    srand(time(NULL));

    char grid[GRID_SIZE][GRID_SIZE];
    Position player = {0, 0}; // Starting position
    Position treasure, danger;
    int game_status = 0; // 0 = ongoing, 1 = win, -1 = loss

    initialize_grid(grid, &treasure, &danger);

    printf("Welcome to the Treasure Hunt!\n");
    printf("Control your player with 'w', 'a', 's', 'd'. Find the treasure 'T' but avoid the danger 'D'.\n");

    while (game_status == 0) {
        print_grid(grid, player);
        printf("Enter your move (w/a/s/d): ");
        char move;
        scanf(" %c", &move);

        if (move_player(&player, move)) {
            game_status = check_position(player, treasure, danger);
        } else {
            printf("Invalid move! Try again.\n");
        }
    }

    print_grid(grid, player);
    
    if (game_status == 1) {
        printf("Congratulations! You found the treasure!\n");
    } else {
        printf("Oh no! You encountered danger! Game over!\n");
    }

    return 0;
}