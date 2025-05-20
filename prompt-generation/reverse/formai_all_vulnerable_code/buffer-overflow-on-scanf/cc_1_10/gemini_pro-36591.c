//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// The board is represented as a 3x3 array of characters.
char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

// The player's symbol is 'X'.
char playerSymbol = 'X';

// The computer's symbol is 'O'.
char computerSymbol = 'O';

// The game is over when one of the following conditions is met:
// - There is a winner.
// - The board is full.
int gameOver = 0;

// The winner is the player who has three of their symbols in a row, column, or diagonal.
char winner = ' ';

// Function to print the board.
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the game is over.
int isGameOver() {
    // Check if there is a winner.
    if (winner != ' ') {
        return 1;
    }

    // Check if the board is full.
    int full = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                full = 0;
                break;
            }
        }
    }

    if (full) {
        return 1;
    }

    // The game is not over.
    return 0;
}

// Function to get the winner.
char getWinner() {
    // Check if there is a winner in a row.
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }

    // Check if there is a winner in a column.
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            return board[0][j];
        }
    }

    // Check if there is a winner in a diagonal.
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }

    // There is no winner yet.
    return ' ';
}

// Function to get the computer's move.
int getComputerMove() {
    // The computer will always try to win if possible.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = computerSymbol;
                if (isGameOver()) {
                    board[i][j] = ' ';
                    return i * 3 + j;
                }
                board[i][j] = ' ';
            }
        }
    }

    // The computer will try to block the player from winning if possible.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = playerSymbol;
                if (isGameOver()) {
                    board[i][j] = ' ';
                    return i * 3 + j;
                }
                board[i][j] = ' ';
            }
        }
    }

    // The computer will randomly choose a move if there is no winning or blocking move available.
    while (1) {
        int move = rand() % 9;
        int row = move / 3;
        int col = move % 3;
        if (board[row][col] == ' ') {
            return move;
        }
    }
}

// Function to get the player's move.
int getPlayerMove() {
    int move;

    // Get the player's move.
    printf("Enter your move (1-9): ");
    scanf("%d", &move);

    // Subtract 1 from the move to convert it to a 0-based index.
    move--;

    // Check if the move is valid.
    if (move < 0 || move > 8 || board[move / 3][move % 3] != ' ') {
        printf("Invalid move. Please try again.\n");
        return -1;
    }

    return move;
}

// Function to play the game.
void playGame() {
    // Print the board.
    printBoard();

    // Get the player's move.
    int move = getPlayerMove();

    // Check if the move is valid.
    if (move == -1) {
        return;
    }

    // Place the player's symbol on the board.
    board[move / 3][move % 3] = playerSymbol;

    // Check if the game is over.
    gameOver = isGameOver();

    // If the game is over, print the winner.
    if (gameOver) {
        winner = getWinner();
        if (winner == playerSymbol) {
            printf("You win!\n");
        } else if (winner == computerSymbol) {
            printf("The computer wins!\n");
        } else {
            printf("It's a draw!\n");
        }
        return;
    }

    // Get the computer's move.
    move = getComputerMove();

    // Place the computer's symbol on the board.
    board[move / 3][move % 3] = computerSymbol;

    // Print the board.
    printBoard();

    // Check if the game is over.
    gameOver = isGameOver();

    // If the game is over, print the winner.
    if (gameOver) {
        winner = getWinner();
        if (winner == playerSymbol) {
            printf("You win!\n");
        } else if (winner == computerSymbol) {
            printf("The computer wins!\n");
        } else {
            printf("It's a draw!\n");
        }
        return;
    }
}

// Main function.
int main() {
    // Seed the random number generator.
    srand(time(NULL));

    // Play the game.
    while (!gameOver) {
        playGame();
    }

    return 0;
}