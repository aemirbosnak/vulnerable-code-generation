//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define GRID_SIZE 5
#define TREASURES 3
#define TRAPS 2

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position treasures[TREASURES];
    Position traps[TRAPS];
    Position player;
} GameState;

void initialize_game(GameState *game) {
    // Initialize player position
    game->player.x = 0;
    game->player.y = 0;

    // Initialize random seed
    srand(time(NULL));

    // Place treasures
    for (int i = 0; i < TREASURES; i++) {
        int x, y;
        do {
            x = rand() % GRID_SIZE;
            y = rand() % GRID_SIZE;
        } while ((x == game->player.x && y == game->player.y));
        game->treasures[i].x = x;
        game->treasures[i].y = y;
    }

    // Place traps
    for (int i = 0; i < TRAPS; i++) {
        int x, y;
        do {
            x = rand() % GRID_SIZE;
            y = rand() % GRID_SIZE;
        } while ((x == game->player.x && y == game->player.y) ||
                 (x == game->treasures[0].x && y == game->treasures[0].y) ||
                 (x == game->treasures[1].x && y == game->treasures[1].y) ||
                 (x == game->treasures[2].x && y == game->treasures[2].y));
        game->traps[i].x = x;
        game->traps[i].y = y;
    }
}

void display_grid(GameState *game) {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == game->player.x && j == game->player.y) {
                printf(" P ");
            } else if (game->treasures[0].x == i && game->treasures[0].y == j) {
                printf(" T ");
            } else if (game->treasures[1].x == i && game->treasures[1].y == j) {
                printf(" T ");
            } else if (game->treasures[2].x == i && game->treasures[2].y == j) {
                printf(" T ");
            } else if (game->traps[0].x == i && game->traps[0].y == j) {
                printf(" X ");
            } else if (game->traps[1].x == i && game->traps[1].y == j) {
                printf(" X ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

void move_player(GameState *game, char direction) {
    switch (direction) {
        case 'w': // Up
            if (game->player.x > 0) game->player.x--;
            break;
        case 's': // Down
            if (game->player.x < GRID_SIZE - 1) game->player.x++;
            break;
        case 'a': // Left
            if (game->player.y > 0) game->player.y--;
            break;
        case 'd': // Right
            if (game->player.y < GRID_SIZE - 1) game->player.y++;
            break;
        default:
            printf("Invalid move!\n");
            break;
    }
}

int check_game_status(GameState *game) {
    for (int i = 0; i < TREASURES; i++) {
        if (game->player.x == game->treasures[i].x && game->player.y == game->treasures[i].y) {
            return 1; // Found a treasure
        }
    }
    for (int i = 0; i < TRAPS; i++) {
        if (game->player.x == game->traps[i].x && game->player.y == game->traps[i].y) {
            return -1; // Hit a trap
        }
    }
    return 0; // Game continues
}

int main() {
    GameState game;
    int treasure_count = 0;
    int game_status;

    initialize_game(&game);

    printf("Welcome to Treasure Hunt!\n");

    while (treasure_count < TREASURES) {
        display_grid(&game);
        printf("Move (w/a/s/d): ");
        char move;
        scanf(" %c", &move);

        move_player(&game, move);
        game_status = check_game_status(&game);

        if (game_status == 1) {
            printf("You found a treasure!\n");
            treasure_count++;
            system("clear"); // Clear the screen
        } else if (game_status == -1) {
            printf("You fell into a trap! Game Over!\n");
            break;
        }
    }

    if (treasure_count == TREASURES) {
        printf("Congratulations! You found all the treasures!\n");
    }

    return 0;
}