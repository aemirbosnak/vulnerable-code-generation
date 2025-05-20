//FormAI DATASET v1.0 Category: Table Game ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// global variables
char table[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; // empty table
int currentPlayer = 1; // player 1 starts
int winner = 0; // no winner yet


// function declarations
void printTable();
int input();
void updateTable(int row, int col);
void checkWinner();
int checkRows();
int checkColumns();
int checkDiagonals();
void changePlayer();


// main function
int main() {

    printf("Welcome to the Table Game!\n");
    printf("Player 1: X\n");
    printf("Player 2: O\n\n");

    printTable();

    while (!winner) {
        int row = input();
        int col = input();

        updateTable(row, col);
        printTable();
        checkWinner();
        changePlayer();
    }

    if (winner == 1) {
        printf("Player 1 (X) wins!\n");
    } else {
        printf("Player 2 (O) wins!\n");
    }

    return 0;
}


// function to print the table
void printTable() {

    printf("   0   1   2\n");
    printf("0  %c | %c | %c \n", table[0][0], table[0][1], table[0][2]);
    printf("  ---|---|---\n");
    printf("1  %c | %c | %c \n", table[1][0], table[1][1], table[1][2]);
    printf("  ---|---|---\n");
    printf("2  %c | %c | %c \n", table[2][0], table[2][1], table[2][2]);

}


// function to get user input
int input() {

    int row, col;

    printf("Player %d, enter the row: ", currentPlayer);
    scanf("%d", &row);

    printf("Player %d, enter the column: ", currentPlayer);
    scanf("%d", &col);

    return row, col;

}


// function to update the table
void updateTable(int row, int col) {

    if (table[row][col] == ' ') {
        if (currentPlayer == 1) {
            table[row][col] = 'X';
        } else {
            table[row][col] = 'O';
        }
    } else {
        printf("This field is already taken, try again.\n");
        input();
    }
}


// function to check if there's a winner
void checkWinner() {

    if (checkRows() || checkColumns() || checkDiagonals()) {
        winner = currentPlayer;
    }
}


// function to check rows for a winner
int checkRows() {

    for (int row = 0; row < 3; row++) {
        if ((table[row][0] == table[row][1]) && (table[row][1] == table[row][2]) && (table[row][0] != ' ')) {
            return 1;
        }
    }

    return 0;
}


// function to check columns for a winner
int checkColumns() {

    for (int col = 0; col < 3; col++) {
        if ((table[0][col] == table[1][col]) && (table[1][col] == table[2][col]) && (table[0][col] != ' ')) {
            return 1;
        }
    }

    return 0;
}


// function to check diagonals for a winner
int checkDiagonals() {

    if (((table[0][0] == table[1][1]) && (table[1][1] == table[2][2]) && (table[0][0] != ' ')) || 
        ((table[0][2] == table[1][1]) && (table[1][1] == table[2][0]) && (table[0][2] != ' '))) {
        return 1;
    } else {
        return 0;
    }
}


// function to change the current player
void changePlayer() {

    if (currentPlayer == 1) {
        currentPlayer = 2;
    } else {
        currentPlayer = 1;
    }
}