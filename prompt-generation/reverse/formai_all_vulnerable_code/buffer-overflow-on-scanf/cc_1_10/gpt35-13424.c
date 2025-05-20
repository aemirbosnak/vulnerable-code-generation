//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board[3][3]; // Tic Tac Toe board
char player = 'X'; // Current player
bool gameOver = false; // Game over flag

// Function to initialize the board with empty spaces
void initBoard() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the board
void printBoard() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);
}

// Function to check if the game is over
void checkGameOver() {
    // Check rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            gameOver = true;
            return;
        }
    }
    // Check columns
    for(int j = 0; j < 3; j++) {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            gameOver = true;
            return;
        }
    }
    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        gameOver = true;
        return;
    }
    if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ') {
        gameOver = true;
        return;
    }
    // Check if board is full
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {
                return;
            }
        }
    }
    gameOver = true;
}

// Function to get input from the player
void getPlayerInput(int *row, int *col) {
    while(true) {
        printf("Enter row (1-3): ");
        scanf("%d", row);
        printf("Enter column (1-3): ");
        scanf("%d", col);
        // Check input validity
        if(*row < 1 || *row > 3 || *col < 1 || *col > 3) {
            printf("Invalid input. Please enter a number between 1 and 3.\n");
            continue;
        }
        if(board[*row-1][*col-1] != ' ') {
            printf("Position already occupied. Please enter a different position.\n");
            continue;
        }
        break;
    }
}

// Function to get input from the AI
void getAIInput(int *row, int *col) {
    // Choose a random position on the board
    do {
        *row = rand() % 3;
        *col = rand() % 3;
    } while(board[*row][*col] != ' ');
}

// Function to make a move on the board
void makeMove(int row, int col) {
    board[row][col] = player;
    if(player == 'X') {
        player = 'O';
    } else {
        player = 'X';
    }
}

int main() {
    initBoard();
    while(!gameOver) {
        printBoard();
        if(player == 'X') {
            int row, col;
            getPlayerInput(&row, &col);
            makeMove(row-1, col-1);
        } else {
            int row, col;
            getAIInput(&row, &col);
            makeMove(row, col);
        }
        checkGameOver();
    }
    printBoard();
    if(player == 'X') {
        printf("AI wins!\n");
    } else {
        printf("Player wins!\n");
    }
    return 0;
}