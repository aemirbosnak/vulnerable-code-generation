//Falcon-180B DATASET v1.0 Category: Educational ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Define the size of the board
#define EMPTY 0 // Define a value to represent an empty cell
#define PLAYER1 1 // Define a value to represent player 1
#define PLAYER2 2 // Define a value to represent player 2
#define WIN 3 // Define a value to represent a winning position

void print_board(int board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(int board[SIZE][SIZE], int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return 0; // Move is out of bounds
    } else if (board[row][col]!= EMPTY) {
        return 0; // Move is not to an empty cell
    }
    return 1; // Move is valid
}

int check_win(int board[SIZE][SIZE]) {
    int i;
    for (i = 0; i < SIZE; i++) {
        if (board[i][0] == PLAYER1 && board[i][1] == PLAYER1 && board[i][2] == PLAYER1) {
            return WIN;
        } else if (board[0][i] == PLAYER2 && board[1][i] == PLAYER2 && board[2][i] == PLAYER2) {
            return WIN;
        }
    }
    if (board[0][0] == PLAYER1 && board[1][1] == PLAYER1 && board[2][2] == PLAYER1) {
        return WIN;
    } else if (board[0][2] == PLAYER2 && board[1][1] == PLAYER2 && board[2][0] == PLAYER2) {
        return WIN;
    }
    return 0; // No winner yet
}

int main() {
    int board[SIZE][SIZE] = {{EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}};
    int player = PLAYER1;
    int choice;
    int x, y;
    int valid_move = 0;

    srand(time(NULL)); // Seed the random number generator

    while (1) {
        system("clear"); // Clear the console
        print_board(board);
        printf("\nPlayer %d's turn. Enter your move (row and column): ", player + 1);
        scanf("%d %d", &x, &y);
        if (is_valid_move(board, x, y)) {
            board[x][y] = player;
            valid_move = 1;
            if (check_win(board) == WIN) {
                printf("\nPlayer %d wins!\n", player + 1);
                break;
            } else if (!valid_move) {
                printf("\nInvalid move. Try again.\n");
            } else {
                player = (player == PLAYER1)? PLAYER2 : PLAYER1; // Switch to the other player
            }
        } else {
            printf("\nInvalid move. Try again.\n");
        }
    }

    return 0;
}