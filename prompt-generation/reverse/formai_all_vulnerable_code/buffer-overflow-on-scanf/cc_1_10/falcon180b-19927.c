//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY_CELL '-'
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'
#define AI_MOVE 'A'

char board[BOARD_SIZE][BOARD_SIZE];
char current_player;

void print_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner() {
    int i;

    // Check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int main() {
    int i, j;
    srand(time(NULL));
    current_player = PLAYER_ONE;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY_CELL;
        }
    }

    while (1) {
        print_board();
        printf("Current player: %c\n", current_player);
        int choice;
        scanf("%d", &choice);

        if (choice < 1 || choice > BOARD_SIZE) {
            printf("Invalid move!\n");
            continue;
        }

        if (board[choice - 1][0]!= EMPTY_CELL) {
            printf("Cell already occupied!\n");
            continue;
        }

        board[choice - 1][0] = current_player;

        if (check_winner()) {
            printf("Player %c wins!\n", current_player);
            break;
        }

        if (current_player == PLAYER_ONE) {
            current_player = PLAYER_TWO;
        } else {
            current_player = PLAYER_ONE;
        }
    }

    return 0;
}