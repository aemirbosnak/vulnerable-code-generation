//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: puzzling
/*
 * Tic Tac Toe AI Puzzle
 *
 * This program implements a unique Tic Tac Toe AI that plays in a puzzling style.
 * It uses a combination of random moves and strategic thinking to outsmart the user.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
#define EMPTY ' '
#define PLAYER1 'X'
#define PLAYER2 'O'

// Function prototypes
void print_board(char board[SIZE][SIZE]);
void reset_board(char board[SIZE][SIZE]);
void player_move(char board[SIZE][SIZE], char player);
void ai_move(char board[SIZE][SIZE], char player);
int check_win(char board[SIZE][SIZE], char player);
int check_draw(char board[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE] = {EMPTY, EMPTY, EMPTY,
                            EMPTY, EMPTY, EMPTY,
                            EMPTY, EMPTY, EMPTY};

    int player = PLAYER1;
    int win = 0;

    while (!win && !check_draw(board)) {
        print_board(board);

        if (player == PLAYER1) {
            player_move(board, player);
            win = check_win(board, player);
            player = PLAYER2;
        } else {
            ai_move(board, player);
            win = check_win(board, player);
            player = PLAYER1;
        }
    }

    print_board(board);
    printf("Player %c wins!\n", player);

    return 0;
}

// Function definitions
void print_board(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void reset_board(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void player_move(char board[SIZE][SIZE], char player) {
    int row, col;
    printf("Enter row and column for player %c: ", player);
    scanf("%d %d", &row, &col);
    board[row][col] = player;
}

void ai_move(char board[SIZE][SIZE], char player) {
    int row, col;
    if (player == PLAYER1) {
        // Random move
        row = rand() % SIZE;
        col = rand() % SIZE;
        board[row][col] = player;
    } else {
        // Strategic move
        // Check if the user has played in a corner
        if (board[0][0] == PLAYER1 || board[0][2] == PLAYER1 || board[2][0] == PLAYER1 || board[2][2] == PLAYER1) {
            // Play in the center
            row = 1;
            col = 1;
        } else {
            // Play in a corner
            row = rand() % 2;
            col = rand() % 2;
        }
        board[row][col] = player;
    }
}

int check_win(char board[SIZE][SIZE], char player) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

int check_draw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}