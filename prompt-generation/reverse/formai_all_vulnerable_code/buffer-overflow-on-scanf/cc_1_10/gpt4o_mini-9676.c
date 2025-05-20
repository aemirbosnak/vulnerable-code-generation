//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define EMPTY ' '
#define PLAYER 'X'
#define AI 'O'

char board[3][3];  // The game board
int movesMade = 0; // Number of moves made

// Function prototypes
void initializeBoard();
void printBoard();
int checkWin(char player);
void playerMove();
void aiMove();
int isBoardFull();
void playGame();

int main() {
    printf("Welcome to the Curious C Tic Tac Toe Game!\n");
    printf("You will play as 'X' against a little AI named 'O'.\n");
    playGame();
    return 0;
}

void initializeBoard() {
    // Fill the board with empty spaces
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = EMPTY;    
}

void printBoard() {
    // Print the current state of the board
    printf("Current Board:\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf("-----------\n");
        }
    }
}

int checkWin(char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if (
            (board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        ) {
            return 1; // Player wins
        }
    }
    if (
        (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    ) {
        return 1; // Player wins
    }
    return 0; // No win found
}

void playerMove() {
    int row, col;
    while (1) {
        printf("Your move (row and column 0-2): ");
        scanf("%d %d", &row, &col);
        
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == EMPTY) {
            board[row][col] = PLAYER;
            movesMade++;
            break;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

void aiMove() {
    // A very basic AI that plays in the first available corner or center
    if (board[1][1] == EMPTY) {
        board[1][1] = AI; // Take the center if it's free
    } else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = AI; // Take the first available space
                    movesMade++;
                    return;
                }
            }
        }
    }
}

int isBoardFull() {
    // Check if the board is full
    return movesMade == 9;
}

void playGame() {
    // Game loop
    initializeBoard();
    while (1) {
        printBoard();
        playerMove();
        if (checkWin(PLAYER)) {
            printBoard();
            printf("Congratulations! You won!\n");
            return;
        }
        
        if (isBoardFull()) {
            printBoard();
            printf("It's a draw!\n");
            return;
        }
        
        aiMove();
        if (checkWin(AI)) {
            printBoard();
            printf("Oh no! The AI won! Better luck next time!\n");
            return;
        }
        
        if (isBoardFull()) {
            printBoard();
            printf("It's a draw!\n");
            return;
        }
    }
}