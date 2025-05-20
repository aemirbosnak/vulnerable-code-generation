//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i;

    // Check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
            return 1;
        }
        if ((board[i][2] == board[i][1]) && (board[i][1] == board[i][0])) {
            return 1;
        }
    }

    // Check columns
    for (i = 0; i < BOARD_SIZE; i++) {
        if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
            return 1;
        }
        if ((board[2][i] == board[1][i]) && (board[1][i] == board[0][i])) {
            return 1;
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
        return 1;
    }
    if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0])) {
        return 1;
    }

    return 0;
}

void play_game() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int player = 1;
    int choice;
    int i, j;

    // Initialize board
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }

    // Play game
    while (1) {
        printf("Player %d's turn\n", player);
        printf("Enter row and column: ");
        scanf("%d%d", &i, &j);

        if ((i >= 0) && (i < BOARD_SIZE) && (j >= 0) && (j < BOARD_SIZE)) {
            if (board[i][j] == '-') {
                board[i][j] = (player % 2)? 'X' : 'O';
                player++;
            } else {
                printf("Invalid move\n");
            }
        } else {
            printf("Invalid move\n");
        }

        if (check_win(board)) {
            printf("Player %d wins!\n", (player % 2)? 1 : 2);
            break;
        } else if (player == 9) {
            printf("It's a draw.\n");
            break;
        }

        player++;
        if (player > 2) {
            player = 1;
        }
    }
}

int main() {
    srand(time(NULL));
    play_game();
    return 0;
}