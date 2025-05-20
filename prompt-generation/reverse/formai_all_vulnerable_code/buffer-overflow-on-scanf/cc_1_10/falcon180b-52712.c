//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

char board[SIZE][SIZE]; //The game board
char player; //The current player

void initBoard() { //Initializes the game board to empty spaces
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard() { //Prints the current state of the game board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin() { //Checks if there is a winner
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int checkDraw() { //Checks if the game is a draw
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == '-') {
                return 0;
            }
        }
    }
    return 1;
}

void changePlayer() { //Changes the current player
    if (player == 'X') {
        player = 'O';
    }
    else {
        player = 'X';
    }
}

int main() {
    srand(time(NULL));
    initBoard();
    int choice;
    while (1) {
        system("clear");
        printBoard();
        printf("\nPlayer %c's turn\n", player);
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > SIZE * SIZE) {
            printf("Invalid move, try again.\n");
            continue;
        }
        int row = (choice - 1) / SIZE;
        int col = (choice - 1) % SIZE;
        if (board[row][col]!= '-') {
            printf("Invalid move, try again.\n");
            continue;
        }
        board[row][col] = player;
        if (checkWin()) {
            printf("\n%c wins!\n", player);
            break;
        }
        else if (checkDraw()) {
            printf("\nIt's a draw.\n");
            break;
        }
        changePlayer();
    }
    return 0;
}