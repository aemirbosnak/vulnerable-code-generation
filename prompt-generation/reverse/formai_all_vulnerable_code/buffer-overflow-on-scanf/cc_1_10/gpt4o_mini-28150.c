//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define EMPTY ' '
#define TREASURE 'T'
#define TRAP 'X'
#define PLAYER 'P'

typedef struct {
    int x, y;
} Player;

void initialize_grid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = EMPTY;
        }
    }
}

void place_treasure_and_traps(char grid[GRID_SIZE][GRID_SIZE]) {
    int treasure_x = rand() % GRID_SIZE;
    int treasure_y = rand() % GRID_SIZE;
    grid[treasure_x][treasure_y] = TREASURE;

    int num_traps = 3;
    for (int i = 0; i < num_traps; i++) {
        int trap_x, trap_y;
        do {
            trap_x = rand() % GRID_SIZE;
            trap_y = rand() % GRID_SIZE;
        } while (grid[trap_x][trap_y] != EMPTY);
        grid[trap_x][trap_y] = TRAP;
    }
}

void print_grid(char grid[GRID_SIZE][GRID_SIZE], Player player) {
    printf("\nCurrent Grid:\n");
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

int move_player(char grid[GRID_SIZE][GRID_SIZE], Player *player, char direction) {
    int new_x = player->x;
    int new_y = player->y;

    switch (direction) {
        case 'w': new_x--; break; // Up
        case 's': new_x++; break; // Down
        case 'a': new_y--; break; // Left
        case 'd': new_y++; break; // Right
        default: printf("Invalid move! Use 'w', 'a', 's', or 'd'.\n"); return 0;
    }

    if (new_x < 0 || new_x >= GRID_SIZE || new_y < 0 || new_y >= GRID_SIZE) {
        printf("You hit the wall! Try a different direction.\n");
        return 0;
    }

    player->x = new_x;
    player->y = new_y;

    switch (grid[player->x][player->y]) {
        case TREASURE:
            printf("Congratulations! You've found the treasure!\n");
            return 1; // Treasure found
        case TRAP:
            printf("Oh no! You stepped on a trap!\n");
            return -1; // Game over
        default:
            return 0; // Continue game
    }
}

int main() {
    srand(time(NULL));
    char grid[GRID_SIZE][GRID_SIZE];
    Player player = {0, 0}; // Starting position

    initialize_grid(grid);
    place_treasure_and_traps(grid);

    int game_status = 0;
    while (game_status == 0) {
        print_grid(grid, player);
        char move;
        printf("Enter your move (w/a/s/d): ");
        scanf(" %c", &move);
        game_status = move_player(grid, &player, move);
    }

    if (game_status == 1) {
        printf("You win! The game is over.\n");
    } else {
        printf("Game over! Better luck next time.\n");
    }

    return 0;
}