//FormAI DATASET v1.0 Category: Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define NUM_ENEMIES 5
#define NUM_HEALTH_PACKS 3

struct Player {
    int x_pos;
    int y_pos;
    int health;
} player;

struct Enemy {
    int x_pos;
    int y_pos;
} enemies[NUM_ENEMIES];

struct Health {
    int x_pos;
    int y_pos;
} health_packs[NUM_HEALTH_PACKS];

void initialize_board(char board[][BOARD_SIZE]) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

void generate_enemies(char board[][BOARD_SIZE]) {
    int i;

    for (i = 0; i < NUM_ENEMIES; i++) {
        int x_pos = rand() % BOARD_SIZE;
        int y_pos = rand() % BOARD_SIZE;

        enemies[i] = (struct Enemy) { x_pos, y_pos };
        board[y_pos][x_pos] = 'E';
    }
}

void generate_health_packs(char board[][BOARD_SIZE]) {
    int i;

    for (i = 0; i < NUM_HEALTH_PACKS; i++) {
        int x_pos = rand() % BOARD_SIZE;
        int y_pos = rand() % BOARD_SIZE;

        health_packs[i] = (struct Health) { x_pos, y_pos };
        board[y_pos][x_pos] = 'H';
    }
}

void print_board(char board[][BOARD_SIZE]) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void move_player(char board[][BOARD_SIZE], char move) {
    int new_x_pos = player.x_pos, new_y_pos = player.y_pos;

    switch(move) {
        case 'w':
            new_y_pos = player.y_pos - 1;
            break;
        case 'a':
            new_x_pos = player.x_pos - 1;
            break;
        case 's':
            new_y_pos = player.y_pos + 1;
            break;
        case 'd':
            new_x_pos = player.x_pos + 1;
            break;
        default:
            printf("Invalid move.");
            return;
    }

    if (new_x_pos < 0 || new_x_pos >= BOARD_SIZE ||
        new_y_pos < 0 || new_y_pos >= BOARD_SIZE) {
        printf("Invalid move.");
        return;
    }

    if (board[new_y_pos][new_x_pos] == 'E') {
        player.health--;
        printf("You got attacked by an enemy! Your health is now %d.\n", player.health);

        if (player.health == 0) {
            printf("Game over!");
            exit(0);
        }
    } else if (board[new_y_pos][new_x_pos] == 'H') {
        player.health++;

        if (player.health > 10) {
            player.health = 10;
        }

        printf("You found a health pack! Your health is now %d.\n", player.health);
    }

    board[player.y_pos][player.x_pos] = '-';
    player.x_pos = new_x_pos;
    player.y_pos = new_y_pos;
    board[player.y_pos][player.x_pos] = 'P';
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    char move;

    srand(time(NULL));

    initialize_board(board);
    generate_enemies(board);
    generate_health_packs(board);

    player.x_pos = rand() % BOARD_SIZE;
    player.y_pos = rand() % BOARD_SIZE;
    player.health = 10;

    board[player.y_pos][player.x_pos] = 'P';

    printf("Welcome to the Cyberpunk game!\n");
    printf("You are the player (P) and your goal is to collect all the health packs (H) without getting attacked by enemies (E).\n");
    printf("Use w, a, s, d keys to move up, left, down, right respectively.\n");

    while (1) {
        printf("\nHealth: %d\n", player.health);
        print_board(board);

        printf("\nEnter your move: ");
        scanf(" %c", &move);

        move_player(board, move);
    }

    return 0;
}