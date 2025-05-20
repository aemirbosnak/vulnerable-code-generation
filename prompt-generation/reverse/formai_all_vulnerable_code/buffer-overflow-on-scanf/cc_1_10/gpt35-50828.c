//FormAI DATASET v1.0 Category: Table Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void printBoard(char board[ROWS][COLS]);
int checkWin(char board[ROWS][COLS], char symbol);
int playerMove(char board[ROWS][COLS], char symbol);
int computerMove(char board[ROWS][COLS], char symbol);
int generateRandomNumber(int min, int max);

int main() {
    char board[ROWS][COLS] = {
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '}
    };
    char playerSymbol = 'X';
    char computerSymbol = 'O';
    int turn = 0;
    int winner = 0;
    
    printf("Welcome to the C Table Game!\n");
    printf("The board is a %d x %d grid.\n", ROWS, COLS);
    
    // Randomly determine who goes first
    srand(time(NULL));
    turn = generateRandomNumber(0, 1);
    if (turn == 0) {
        printf("You will go first.\n");
    } else {
        printf("The computer will go first.\n");
    }
    
    // Main game loop
    while (1) {
        // Player's turn
        if (turn == 0) {
            winner = playerMove(board, playerSymbol);
        }
        // Computer's turn
        else {
            winner = computerMove(board, computerSymbol);
        }
        // Check for a win
        if (winner == 1) {
            if (turn == 0) {
                printf("Congratulations! You have won.\n");
            } else {
                printf("The computer has won. Better luck next time.\n");
            }
            break;
        }
        // Check for a tie
        if (winner == 2) {
            printf("The game is a tie.\n");
            break;
        }
        // Switch turns
        turn = (turn + 1) % 2;
    }
    return 0;
}

// Print the current state of the board
void printBoard(char board[ROWS][COLS]) {
    printf("|---|---|---|---|---|\n");
    for (int i = 0; i < ROWS; i++) {
        printf("| %c | %c | %c | %c | %c |\n", board[i][0], board[i][1], board[i][2], board[i][3], board[i][4]);
        printf("|---|---|---|---|---|\n");
    }
}

// Check if a given symbol has won the game
int checkWin(char board[ROWS][COLS], char symbol) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol && board[i][3] == symbol && board[i][4] == symbol) {
            return 1;
        }
    }
    // Check columns
    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol && board[3][j] == symbol && board[4][j] == symbol) {
            return 1;
        }
    }
    // Check diagonal
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol && board[3][3] == symbol && board[4][4] == symbol) {
        return 1;
    }
    // Check other diagonal
    if (board[0][4] == symbol && board[1][3] == symbol && board[2][2] == symbol && board[3][1] == symbol && board[4][0] == symbol) {
        return 1;
    }
    // Check for a tie
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == ' ') {
                count++;
            }
        }
    }
    if (count == 0) {
        return 2;
    }
    return 0;
}

// Make a move for the player
int playerMove(char board[ROWS][COLS], char symbol) {
    int row = 0;
    int col = 0;
    int validMove = 0;
    
    printf("Your turn. Enter the row and column to place your %c: ", symbol);
    while (!validMove) {
        scanf("%d %d", &row, &col);
        if (row < 1 || row > ROWS || col < 1 || col > COLS) {
            printf("Invalid move. Please enter a row and column between 1 and %d: ", ROWS);
        } else if (board[row - 1][col - 1] != ' ') {
            printf("Invalid move. That space is already taken. Please enter a different row and column: ");
        } else {
            validMove = 1;
        }
    }
    board[row - 1][col - 1] = symbol;
    printf("You placed your %c at (%d, %d).\n", symbol, row, col);
    printBoard(board);
    return checkWin(board, symbol);
}

// Make a move for the computer
int computerMove(char board[ROWS][COLS], char symbol) {
    int row = 0;
    int col = 0;
    int validMove = 0;
    
    printf("The computer's turn.\n");
    // Check if the computer can win in one move
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = symbol;
                if (checkWin(board, symbol)) {
                    printf("The computer placed its %c at (%d, %d).\n", symbol, i + 1, j + 1);
                    printBoard(board);
                    return 1;
                }
                board[i][j] = ' ';
            }
        }
    }
    // Check if the player can win in one move and block them
    if (symbol == 'O') {
        symbol = 'X';
    } else {
        symbol = 'O';
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = symbol;
                if (checkWin(board, symbol)) {
                    board[i][j] = 'O';
                    printf("The computer placed its %c at (%d, %d).\n", 'O', i + 1, j + 1);
                    printBoard(board);
                    return 0;
                }
                board[i][j] = ' ';
            }
        }
    }
    // Make a random move
    while (!validMove) {
        row = generateRandomNumber(1, ROWS);
        col = generateRandomNumber(1, COLS);
        if (board[row - 1][col - 1] == ' ') {
            validMove = 1;
            board[row - 1][col - 1] = 'O';
            printf("The computer placed its %c at (%d, %d).\n", 'O', row, col);
            printBoard(board);
            return checkWin(board, 'O');
        }
    }
}

// Generate a random number between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}