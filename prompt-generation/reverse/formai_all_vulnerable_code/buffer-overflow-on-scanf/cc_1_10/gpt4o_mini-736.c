//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board[3][3];
char playerSymbol = 'X';
char aiSymbol = 'O';
int moveCount = 0;

void initializeBoard() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    printf("Current Board:\n");
    for(int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if(i < 2) {
            printf("---|---|---\n");
        }
    }
}

bool checkWin(char symbol) {
    for(int i = 0; i < 3; i++) {
        if((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) || 
           (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) {
            return true;
        }
    }
    if((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) || 
       (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return true;
    }
    return false;
}

bool isBoardFull() {
    return moveCount >= 9;
}

void playerMove() {
    int row, col;
    while(true) {
        printf("Enter your move (row and column: 0-2): ");
        scanf("%d %d", &row, &col);
        if(row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Oops! That move is not valid. Try again!\n");
        } else {
            board[row][col] = playerSymbol;
            moveCount++;
            break;
        }
    }
}

void aiMove() {
    // Basic AI logic to fill empty spaces
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = aiSymbol;
                if(checkWin(aiSymbol)) {
                    printf("AI wins! Hooray for the AI!\n");
                    return;
                } else {
                    board[i][j] = ' ';  // undo move
                }
            }
        }
    }

    // If AI can't win, take the first empty slot
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = aiSymbol;
                moveCount++;
                printf("AI places %c at (%d,%d)\n", aiSymbol, i, j);
                return;
            }
        }
    }
}

void playGame() {
    initializeBoard();
    while(true) {
        displayBoard();
        playerMove();
        if(checkWin(playerSymbol)) {
            displayBoard();
            printf("Congratulations! You win! 🎉\n");
            break;
        }
        if(isBoardFull()) {
            displayBoard();
            printf("It's a draw! Everyone wins! 🥳\n");
            break;
        }
        aiMove();
        if(checkWin(aiSymbol)) {
            displayBoard();
            printf("Oh no! The AI wins! Better luck next time! 🤖\n");
            break;
        }
        if(isBoardFull()) {
            displayBoard();
            printf("It's a draw! Everyone wins! 🥳\n");
            break;
        }
    }
}

int main() {
    printf("Welcome to Tic Tac Toe! Let's have some fun! 😄\n");
    playGame();
    return 0;
}