//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5
#define EMPTY ' '
#define PLAYER1 'X'
#define PLAYER2 'O'

void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]);
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int check_winner(char board[BOARD_SIZE][BOARD_SIZE], char player);
void player_move(char board[BOARD_SIZE][BOARD_SIZE], char player);
int is_board_full(char board[BOARD_SIZE][BOARD_SIZE]);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    char current_player = PLAYER1;
    int winner = 0;

    initialize_board(board);

    printf("Welcome to the Artistic Tic-Tac-Toe Game!\n");
    printf("Player 1 (X) and Player 2 (O) take turns to place their marks.\n");
    printf("First to get 5 in a row wins!\n");
    print_board(board);

    while (winner == 0 && !is_board_full(board)) {
        player_move(board, current_player);
        print_board(board);
        winner = check_winner(board, current_player);
        current_player = (current_player == PLAYER1) ? PLAYER2 : PLAYER1;
    }

    if (winner) {
        printf("Player %c wins the game!\n", winner);
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}

void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void player_move(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    int row, col;
    while (1) {
        printf("Player %c, enter your move (row and column): ", player);
        scanf("%d %d", &row, &col);

        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == EMPTY) {
            board[row][col] = player;
            break;
        } else {
            printf("Invalid move, please try again.\n");
        }
    }
}

int check_winner(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    // Check rows and columns for winner
    for (int i = 0; i < BOARD_SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player &&
             board[i][3] == player && board[i][4] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player &&
             board[3][i] == player && board[4][i] == player)) {
            return player;
        }
    }

    // Check diagonals for winner
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player &&
         board[3][3] == player && board[4][4] == player) ||
        (board[0][4] == player && board[1][3] == player && board[2][2] == player &&
         board[3][1] == player && board[4][0] == player)) {
        return player;
    }

    return 0;
}

int is_board_full(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return 0; // Found an empty spot
            }
        }
    }
    return 1; // No empty spots left
}