//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 3

char board[SIZE][SIZE];
char player, computer;
int turn;

void initBoard() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < SIZE - 1)
            printf("---|---|---\n");
    }
    printf("\n");
}

bool isWinner(char ch) {
    // Check rows, columns and diagonals
    for (int i = 0; i < SIZE; i++)
        if ((board[i][0] == ch && board[i][1] == ch && board[i][2] == ch) ||
            (board[0][i] == ch && board[1][i] == ch && board[2][i] == ch))
            return true;
    if ((board[0][0] == ch && board[1][1] == ch && board[2][2] == ch) ||
        (board[0][2] == ch && board[1][1] == ch && board[2][0] == ch))
        return true;
    return false;
}

bool isDraw() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

void playerMove() {
    int x, y;
    while (true) {
        printf("\nPlayer %c, enter your move (row and column): ", player);
        scanf("%d %d", &x, &y);
        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || board[x][y] != ' ') {
            printf("Oops! That spot is either taken or out of bounds! Try again.\n");
        } else {
            board[x][y] = player;
            break;
        }
    }
}

void computerMove() {
    printf("\nComputer %c is pondering...\n", computer);
    srand(time(0));
    int x, y;
    // AI chose a position randomly, full of confidence!
    while (true) {
        x = rand() % SIZE;
        y = rand() % SIZE;
        if (board[x][y] == ' ') {
            board[x][y] = computer;
            printf("Computer played at (%d, %d)! Smarter than the average human!\n", x, y);
            break;
        }
    }
}

void startGame() {
    printf("Welcome to Tic Tac Toe Vs Computer! Are you ready to lose?\n");
    printf("Choose your symbol (X or O): ");
    scanf(" %c", &player);
    // Ensure a valid symbol is chosen
    computer = (player == 'X') ? 'O' : 'X';
   
    printf("\nLet's get this battle started!\n\n");
    while (true) {
        printBoard();
        playerMove();
        if (isWinner(player)) {
            printBoard();
            printf("Congratulations! You win! But, how??\n");
            break;
        }
        if (isDraw()) {
            printBoard();
            printf("It's a draw! Let's call it a tie and grab some pizza instead!\n");
            break;
        }

        computerMove();
        if (isWinner(computer)) {
            printBoard();
            printf("Computer %c wins! Time to reconsider your life choices...\n", computer);
            break;
        }
        if (isDraw()) {
            printBoard();
            printf("It's a draw! Again! You must be out of luck, or just bad.\n");
            break;
        }
    }
}

int main() {
    initBoard();
    startGame();
    return 0;
}