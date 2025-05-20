//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the game board
void print_board(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if there is a winner
int check_winner(int board[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
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

// Function to check if a move is valid
int check_move(int board[3][3], int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == 0) {
        return 1;
    }
    return 0;
}

// Function to play the game
void play_game(int board[3][3]) {
    int player = 1;
    int moves = 0;

    while (moves < 9) {
        system("clear");
        printf("Player %d's turn:\n", player);
        print_board(board);

        int row, col;
        if (player == 1) {
            printf("Enter your move (row and column): ");
            scanf("%d%d", &row, &col);
            row--;
            col--;
        } else {
            int valid_move = 0;
            while (!valid_move) {
                srand(time(NULL));
                row = rand() % 3;
                col = rand() % 3;
                if (check_move(board, row, col)) {
                    valid_move = 1;
                }
            }
        }

        if (check_winner(board)) {
            printf("Player %d wins!\n", player);
            break;
        }

        if (check_move(board, row, col)) {
            board[row][col] = player;
            moves++;
            player = (player == 1)? 2 : 1;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

int main() {
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    play_game(board);

    return 0;
}