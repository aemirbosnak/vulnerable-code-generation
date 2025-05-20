//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: optimized
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

// Initializes the board with spaces
void initializeBoard() {
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Displays the current board state
void displayBoard() {
    printf("\n");

    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);

            if (j != BOARD_SIZE - 1) {
                printf("|");
            }
        }

        printf("\n");

        if (i != BOARD_SIZE - 1) {
            printf("-----------\n");
        }
    }

    printf("\n");
}

// Updates the board with the player's move
void updateBoard(int row, int col, char player) {
    board[row][col] = player;
}

// Checks if the game is over
bool isGameOver() {
    // Check rows
    for (int i=0; i<BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return true;
        }
    }

    // Check columns
    for (int i=0; i<BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return true;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return true;
    }

    // Check for tie
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }

    return true;
}

// Returns 1 if the player wins, -1 if the AI wins, and 0 for a tie
int playGame(bool playerGoesFirst) {
    initializeBoard();
    displayBoard();
    char player, ai;

    if (playerGoesFirst) {
        player = 'X';
        ai = 'O';
    } else {
        player = 'O';
        ai = 'X';
    }

    int currentPlayer = player;

    while (!isGameOver()) {
        int row, col;

        if (currentPlayer == player) {
            // Prompt player for move
            printf("Enter row and column to place %c: ", player);
            scanf("%d %d", &row, &col);
        } else {
            // Generate AI move
            bool moveMade = false;
            for (int i=0; i<BOARD_SIZE; i++) {
                for (int j=0; j<BOARD_SIZE; j++) {
                    if (board[i][j] == ' ') {
                        updateBoard(i, j, ai);
                        moveMade = true;
                        break;
                    }
                }

                if (moveMade) {
                    break;
                }
            }

            row = 0;
            col = 0;
        }

        // Update board with move
        updateBoard(row, col, currentPlayer);

        // Switch turns
        if (currentPlayer == player) {
            currentPlayer = ai;
        } else {
            currentPlayer = player;
        }

        displayBoard();
    }

    // Check who won
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == player) {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == player) {
        return 1;
    }

    for (int i=0; i<BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == player) {
            return 1;
        }
    }

    for (int i=0; i<BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == player) {
            return 1;
        }
    }

    if (isGameOver()) {
        return 0;
    }

    return -1;
}

int main() {
    int playerWins = 0, aiWins = 0, ties = 0;

    for (int i=0; i<1000; i++) {
        int result = playGame(i % 2 == 0);
        if (result == 1) {
            playerWins++;
        } else if (result == -1) {
            aiWins++;
        } else {
            ties++;
        }
    }

    printf("Player wins: %d\nAI wins: %d\nTies: %d\n", playerWins, aiWins, ties);
    
    return 0;
}