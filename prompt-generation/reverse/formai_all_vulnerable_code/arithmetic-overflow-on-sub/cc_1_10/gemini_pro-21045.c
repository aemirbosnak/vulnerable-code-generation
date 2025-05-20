//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// The board is represented as a 3x3 grid of characters.
char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

// The player's symbol is 'X' and the AI's symbol is 'O'.
char playerSymbol = 'X';
char aiSymbol = 'O';

// Function to print the board.
void printBoard() {
    printf("  |   |  \n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("  |   |  \n");
}

// Function to check if the game is over.
bool gameOver() {
    // Check if there is a winner.
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }

    // Check if there is a tie.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }

    return true;
}

// Function to get the player's move.
int getPlayerMove() {
    int move;
    printf("Enter your move (1-9): ");
    scanf("%d", &move);
    return move;
}

// Function to get the AI's move.
int getAiMove() {
    // The AI is a master strategist and always knows the best move.
    int move = 5;
    return move;
}

// Function to place a symbol on the board.
void placeSymbol(int move, char symbol) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    board[row][col] = symbol;
}

// Function to run the game.
void runGame() {
    // Print the initial board.
    printBoard();

    // While the game is not over, get the player's move and the AI's move, and place them on the board.
    while (!gameOver()) {
        int playerMove = getPlayerMove();
        placeSymbol(playerMove, playerSymbol);
        printBoard();

        int aiMove = getAiMove();
        placeSymbol(aiMove, aiSymbol);
        printBoard();
    }

    // Check if the player won, the AI won, or there was a tie.
    if (gameOver()) {
        if (board[0][0] == playerSymbol && board[0][1] == playerSymbol && board[0][2] == playerSymbol) {
            printf("You win!");
        } else if (board[0][0] == aiSymbol && board[0][1] == aiSymbol && board[0][2] == aiSymbol) {
            printf("The AI wins!");
        } else if (board[1][0] == playerSymbol && board[1][1] == playerSymbol && board[1][2] == playerSymbol) {
            printf("You win!");
        } else if (board[1][0] == aiSymbol && board[1][1] == aiSymbol && board[1][2] == aiSymbol) {
            printf("The AI wins!");
        } else if (board[2][0] == playerSymbol && board[2][1] == playerSymbol && board[2][2] == playerSymbol) {
            printf("You win!");
        } else if (board[2][0] == aiSymbol && board[2][1] == aiSymbol && board[2][2] == aiSymbol) {
            printf("The AI wins!");
        } else if (board[0][0] == playerSymbol && board[1][1] == playerSymbol && board[2][2] == playerSymbol) {
            printf("You win!");
        } else if (board[0][0] == aiSymbol && board[1][1] == aiSymbol && board[2][2] == aiSymbol) {
            printf("The AI wins!");
        } else if (board[0][2] == playerSymbol && board[1][1] == playerSymbol && board[2][0] == playerSymbol) {
            printf("You win!");
        } else if (board[0][2] == aiSymbol && board[1][1] == aiSymbol && board[2][0] == aiSymbol) {
            printf("The AI wins!");
        } else {
            printf("It's a tie!");
        }
    }
}

// The main function.
int main() {
    // Run the game.
    runGame();

    return 0;
}