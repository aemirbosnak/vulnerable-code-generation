//Falcon-180B DATASET v1.0 Category: Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

// Define the game board
char board[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// Function to print the game board
void printBoard() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the game is won
int checkWin() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        if(board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
            return 1;
        if(board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
            return 1;
    }
    if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
        return 1;
    if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
        return 1;

    return 0;
}

// Function to check if the game is tied
int checkTie() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(board[i][j]!= 'X' && board[i][j]!= 'O')
                return 0;
        }
    }
    return 1;
}

// Function to get a valid input from the user
int getValidInput(int player) {
    int row, col;
    printf("Player %d's turn:\n", player + 1);
    printf("Enter your move (row and column): ");
    scanf("%d%d", &row, &col);
    if(row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col]!= '-') {
        printf("Invalid move. Try again.\n");
        return 0;
    }
    return 1;
}

// Function to play the game
void playGame() {
    int player = 0;
    char mark;
    if(rand() % 2 == 0)
        mark = 'X';
    else
        mark = 'O';

    while(1) {
        system("clear");
        printBoard();
        printf("Player %d's turn (X): ", player + 1);
        if(!getValidInput(player))
            continue;

        board[player][0] = mark;
        player++;
        if(player == 2)
            player = 0;

        if(checkWin()) {
            printf("Player %d wins!\n", player + 1);
            break;
        } else if(checkTie()) {
            printf("It's a tie!\n");
            break;
        }
    }
}

int main() {
    srand(time(0));
    playGame();
    return 0;
}