//GPT-4o-mini DATASET v1.0 Category: Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BOARD_SIZE 5
#define EMPTY ' '
#define PLAYER 'P'
#define ENEMY 'E'
#define TREASURE 'T'
#define MAX_TREASURES 3
#define MAX_ENEMIES 3

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position position;
    int treasure_count;
} Player;

typedef struct {
    Position position;
} Enemy;

char board[BOARD_SIZE][BOARD_SIZE];
Player player;
Enemy enemies[MAX_ENEMIES];
int treasure_count = 0;

void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void place_player() {
    player.position.x = rand() % BOARD_SIZE;
    player.position.y = rand() % BOARD_SIZE;
    board[player.position.x][player.position.y] = PLAYER;
}

void place_enemies() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        do {
            enemies[i].position.x = rand() % BOARD_SIZE;
            enemies[i].position.y = rand() % BOARD_SIZE;
        } while (board[enemies[i].position.x][enemies[i].position.y] != EMPTY);

        board[enemies[i].position.x][enemies[i].position.y] = ENEMY;
    }
}

void place_treasures() {
    while (treasure_count < MAX_TREASURES) {
        Position treasure_position = {rand() % BOARD_SIZE, rand() % BOARD_SIZE};
        if (board[treasure_position.x][treasure_position.y] == EMPTY) {
            board[treasure_position.x][treasure_position.y] = TREASURE;
            treasure_count++;
        }
    }
}

void display_board() {
    printf("\nBoard:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("Player Treasures: %d\n", player.treasure_count);
}

bool move_player(char direction) {
    Position new_position = player.position;

    switch (direction) {
        case 'w': new_position.x--; break;  // Up
        case 's': new_position.x++; break;  // Down
        case 'a': new_position.y--; break;  // Left
        case 'd': new_position.y++; break;  // Right
        default: return false; // Invalid move
    }

    if (new_position.x < 0 || new_position.x >= BOARD_SIZE || 
        new_position.y < 0 || new_position.y >= BOARD_SIZE) {
        printf("You can't move outside the board!\n");
        return false;
    }

    if (board[new_position.x][new_position.y] == ENEMY) {
        printf("You ran into an enemy! Game Over!\n");
        return false;
    } else if (board[new_position.x][new_position.y] == TREASURE) {
        player.treasure_count++;
        printf("You collected a treasure!\n");
    }

    // Move the player
    board[player.position.x][player.position.y] = EMPTY;
    player.position = new_position;
    board[player.position.x][player.position.y] = PLAYER;

    return true;
}

void enemy_turn() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        int direction = rand() % 4;
        Position new_position = enemies[i].position;

        // Move enemy in a random direction
        switch (direction) {
            case 0: new_position.x--; break; // Up
            case 1: new_position.x++; break; // Down
            case 2: new_position.y--; break; // Left
            case 3: new_position.y++; break; // Right
        }

        // Check for valid move
        if (new_position.x >= 0 && new_position.x < BOARD_SIZE &&
            new_position.y >= 0 && new_position.y < BOARD_SIZE &&
            board[new_position.x][new_position.y] == EMPTY) {
            board[enemies[i].position.x][enemies[i].position.y] = EMPTY;
            enemies[i].position = new_position;
            board[enemies[i].position.x][enemies[i].position.y] = ENEMY;
        }
    }
}

int main() {
    srand(time(NULL));
    initialize_board();
    player.treasure_count = 0;
    place_player();
    place_enemies();
    place_treasures();

    char move;
    bool game_running = true;

    while (game_running) {
        display_board();
        printf("Enter move (w/a/s/d): ");
        scanf(" %c", &move);

        game_running = move_player(move);
        if (game_running) {
            enemy_turn();
        }
    }

    printf("Game Over! You collected %d treasures.\n", player.treasure_count);
    return 0;
}