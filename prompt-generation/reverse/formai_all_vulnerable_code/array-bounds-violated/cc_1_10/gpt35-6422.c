//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE] = {{' ', ' ', ' '},
                                       {' ', ' ', ' '},
                                       {' ', ' ', ' '}};

bool checkRows(char symbol) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        if(board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) 
            return true;
    }
    return false;
}

bool checkColumns(char symbol) {
    for(int j = 0; j < BOARD_SIZE; j++) {
        if(board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol) 
            return true;
    }
    return false;
}

bool checkDiagonals(char symbol) {
    if(board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) 
        return true;
    if(board[2][0] == symbol && board[1][1] == symbol && board[0][2] == symbol) 
        return true;
    return false;
}

bool checkForWin(char symbol) {
    if(checkRows(symbol) || checkColumns(symbol) || checkDiagonals(symbol))
        return true;
    return false;
}

void displayBoard() {
    printf("-------------\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}

bool makeMove(char symbol, int row, int column) {
    if(board[row][column] != ' ')
        return false;
    else {
        board[row][column] = symbol;
        return true;
    }
}

bool isBoardFull() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

bool playGame(char symbol) {
    bool isWin = false;
    int row, column;
    do {
        displayBoard();
        printf("Player %c enter move (row,column): ", symbol);
        scanf("%d,%d", &row, &column);
        if(makeMove(symbol, row, column)) {
            isWin = checkForWin(symbol);
            if(isWin) {
                displayBoard();
                printf("Player %c wins!\n", symbol);
                return true;
            }
            else if(isBoardFull()) {
                displayBoard();
                printf("It's a tie!\n");
                return true;
            }
        }
        else {
            printf("Invalid move. Please try again.\n");
        }
        if(symbol == 'X')
            symbol = 'O';
        else
            symbol = 'X';
    } while(!isWin);
    return false;
}

int main() {
    printf("Welcome to Tic Tac Toe!\n\n");
    bool endGame;
    char playAgain;
    do {
        endGame = playGame('X');
        if(endGame) {
            printf("Do you want to play again? (y/n): ");
            scanf(" %c", &playAgain);
            if(playAgain == 'y' || playAgain == 'Y') {
                for(int i = 0; i < BOARD_SIZE; i++) {
                    for(int j = 0; j < BOARD_SIZE; j++) {
                        board[i][j] = ' ';
                    }
                }
            }
        }
    } while(playAgain == 'y' || playAgain == 'Y');
    printf("Thanks for playing!\n");
    return 0;
}