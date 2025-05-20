//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 4

// function to initialize the board with random numbers
void initBoard(int board[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            board[i][j] = rand() % 10;
        }
    }
}

// function to print the board
void printBoard(int board[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// function to check if two cards match
int checkMatch(int card1, int card2) {
    return card1 == card2;
}

// function to check if all cards have been matched
int checkWin(int board[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (board[i][j]!= 0) {
                return 0;
            }
        }
    }
    return 1;
}

// function to handle user input
int handleInput(int board[ROW][COL]) {
    int row1, col1, row2, col2;
    printf("Enter the first card (row and column): ");
    scanf("%d %d", &row1, &col1);
    printf("Enter the second card (row and column): ");
    scanf("%d %d", &row2, &col2);
    if (row1 >= 0 && row1 < ROW && col1 >= 0 && col1 < COL && row2 >= 0 && row2 < ROW && col2 >= 0 && col2 < COL && checkMatch(board[row1][col1], board[row2][col2])) {
        board[row1][col1] = 0;
        board[row2][col2] = 0;
        return 1;
    } else {
        printf("Invalid input. Try again.\n");
        return 0;
    }
}

int main() {
    srand(time(NULL));
    int board[ROW][COL];
    initBoard(board);
    int gameWon = 0;
    while (!gameWon) {
        printBoard(board);
        int input = handleInput(board);
        if (checkWin(board)) {
            printf("Congratulations! You have won the game.\n");
            gameWon = 1;
        }
    }
    return 0;
}