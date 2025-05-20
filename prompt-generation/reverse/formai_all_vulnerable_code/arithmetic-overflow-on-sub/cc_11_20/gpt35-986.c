//FormAI DATASET v1.0 Category: Table Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

// Function to display the board
void display_board(char board[][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf(" %c ", board[i][j]);
            if (j != COLS-1) printf("|");
        }
        printf("\n");
        if (i != ROWS-1) printf("-----------\n");
    }
    printf("\n");
}

// Function to check if the game is over
int game_over(char board[][COLS], char *winner) {
    // Check for a winner
    for(int i = 0; i < ROWS; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            *winner = board[i][0];
            return 1;
        }
    }
    for(int j = 0; j < COLS; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            *winner = board[0][j];
            return 1;
        }
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        *winner = board[0][0];
        return 1;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        *winner = board[0][2];
        return 1;
    }
    // Check for a tie
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    *winner = ' ';
    return 1;
}

int main() {
    char board[ROWS][COLS];
    char player1[20], player2[20];
    char winner = ' ';
    int turn = 0;
    int row, col;
    int valid_move = 0;

    // Initialize board
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }

    // Get player names
    printf("Enter name for Player 1 (X): ");
    scanf("%s", player1);
    printf("Enter name for Player 2 (O): ");
    scanf("%s", player2);

    // Game loop
    while(!game_over(board, &winner)) {
        // Display the board
        display_board(board);

        // Get player's move
        do {
            if (turn == 0) {
                printf("%s's (X) turn. Enter row and column (1-3): ", player1);
            } else {
                printf("%s's (O) turn. Enter row and column (1-3): ", player2);
            }
            scanf("%d %d", &row, &col);
            row--;
            col--;
            if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == ' ') {
                if (turn == 0) {
                    board[row][col] = 'X';
                } else {
                    board[row][col] = 'O';
                }
                valid_move = 1;
            } else {
                printf("Invalid move. Try again.\n");
                valid_move = 0;
            }
        } while (!valid_move);

        // Switch turn
        turn = !turn;
    }

    // Display final board
    display_board(board);

    // Declare winner
    if (winner == 'X') {
        printf("%s wins!\n", player1);
    } else if (winner == 'O') {
        printf("%s wins!\n", player2);
    } else {
        printf("Tie game.\n");
    }

    return 0;
}