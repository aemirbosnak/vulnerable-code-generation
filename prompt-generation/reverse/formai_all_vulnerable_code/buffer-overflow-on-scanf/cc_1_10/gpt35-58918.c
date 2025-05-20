//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 3

// This function prints the current state of the Tic Tac Toe board
void print_board(char board[][BOARD_SIZE]) {
    printf("\nCurrent state of the board:\n\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);

            if (j != BOARD_SIZE - 1) {
                printf("|");
            }
        }

        printf("\n");

        if (i != BOARD_SIZE - 1) {
            printf("---+---+---\n");
        }
    }

    printf("\n");
}

// This function checks if the given player has won the game
bool check_win(char board[][BOARD_SIZE], char player_symbol) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player_symbol && board[i][1] == player_symbol && board[i][2] == player_symbol) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == player_symbol && board[1][i] == player_symbol && board[2][i] == player_symbol) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player_symbol && board[1][1] == player_symbol && board[2][2] == player_symbol) {
        return true;
    }

    if (board[0][2] == player_symbol && board[1][1] == player_symbol && board[2][0] == player_symbol) {
        return true;
    }

    return false;
}

// This function checks if there is a tie
bool check_tie(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }

    return true;
}

// This function makes a random move for the AI player
void ai_move(char board[][BOARD_SIZE]) {
    int row, col;

    do {
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
    } while (board[row][col] != ' ');

    board[row][col] = 'O';
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int row, col;

    // This loop represents a single turn of the game
    while (true) {
        // Player's turn
        printf("Enter the row and column (separated by a comma) to make your move (e.g. 1,2): ");
        scanf("%d,%d", &row, &col);

        // Check if the input is valid
        if (row < 1 || row > BOARD_SIZE || col < 1 || col > BOARD_SIZE || board[row - 1][col - 1] != ' ') {
            printf("Invalid input! Try again.\n\n");
            continue;
        }

        board[row - 1][col - 1] = 'X';
        print_board(board);

        // Check if the player has won
        if (check_win(board, 'X')) {
            printf("Congratulations! You won the game.\n");
            break;
        }

        // Check if there is a tie
        if (check_tie(board)) {
            printf("The game is tied.\n");
            break;
        }

        // AI's turn
        printf("The AI is thinking...\n\n");
        ai_move(board);
        print_board(board);

        // Check if the AI has won
        if (check_win(board, 'O')) {
            printf("Sorry, you lost the game. Better luck next time!\n");
            break;
        }

        // Check if there is a tie
        if (check_tie(board)) {
            printf("The game is tied.\n");
            break;
        }
    }

    return 0;
}