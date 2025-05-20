//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define EMPTY ' '
#define PLAYER 'P'
#define TARGET 'T'

char board[SIZE][SIZE];
int player_x, player_y;
int target_x, target_y;

void initialize_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
    player_x = rand() % SIZE;
    player_y = rand() % SIZE;
    target_x = rand() % SIZE;
    target_y = rand() % SIZE;

    while (player_x == target_x && player_y == target_y) {
        target_x = rand() % SIZE;
        target_y = rand() % SIZE;
    }

    board[player_x][player_y] = PLAYER;
    board[target_x][target_y] = TARGET;
}

void draw_board() {
    printf("Current Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

void move_player() {
    char move;
    printf("Move player (W/A/S/D): ");
    scanf(" %c", &move);

    int new_x = player_x, new_y = player_y;
    switch (move) {
        case 'W': new_x--; break;
        case 'S': new_x++; break;
        case 'A': new_y--; break;
        case 'D': new_y++; break;
        default: printf("Invalid Move! Use W/A/S/D.\n"); return;
    }

    if (new_x >= 0 && new_x < SIZE && new_y >= 0 && new_y < SIZE) {
        board[player_x][player_y] = EMPTY;
        player_x = new_x;
        player_y = new_y;
        board[player_x][player_y] = PLAYER;
    } else {
        printf("Can't move outside the board!\n");
    }
}

int check_target_reached() {
    return (player_x == target_x && player_y == target_y);
}

void announce_victory() {
    printf("Congratulations! You've reached the target!\n");
    printf("Exiting game...\n");
}

int main() {
    srand(time(NULL));
    initialize_board();
    char play_again;

    do {
        draw_board();
        move_player();
        if (check_target_reached()) {
            announce_victory();
            break;
        }
        printf("Do you want to continue playing? (Y/N): ");
        scanf(" %c", &play_again);
        if (play_again == 'N' || play_again == 'n') {
            printf("Thank you for playing!\n");
            break;
        }
    } while (1);

    return 0;
}