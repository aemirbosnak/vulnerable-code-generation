//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Function to print a game board
void printBoard(int board[3][3]) {
    printf("\n");
    printf("   |   |   \n");
    printf(" %2d | %2d | %2d \n", board[0][0], board[0][1], board[0][2]);
    printf("   |   |   \n");
    printf("   |   |   \n");
    printf("   |   |   \n");
}

// Function to check for a winning combination
int isWinner(int board[3][3], char symbol) {
    if (board[0][0] == symbol && board[0][1] == symbol && board[0][2] == symbol) return 1;
    if (board[1][0] == symbol && board[1][1] == symbol && board[1][2] == symbol) return 1;
    if (board[2][0] == symbol && board[2][1] == symbol && board[2][2] == symbol) return 1;
    if (board[0][0] == symbol && board[1][0] == symbol && board[2][0] == symbol) return 1;
    if (board[0][1] == symbol && board[1][1] == symbol && board[2][1] == symbol) return 1;
    if (board[0][2] == symbol && board[1][2] == symbol && board[2][2] == symbol) return 1;
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) return 1;
    if (board[2][0] == symbol && board[1][1] == symbol && board[0][2] == symbol) return 1;
    return 0;
}

// Function to check for a draw
int isDraw(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) return 0;
        }
    }
    return 1;
}

// Function to check if the board is full
int isFull(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) return 0;
        }
    }
    return 1;
}

// Main function
int main() {
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int symbol;

    printf("Enter a symbol: ");
    scanf("%d", &symbol);

    while (1) {
        printBoard(board);
        printf("Enter a position: ");
        scanf("%d %d", &board[0][0], &board[0][1]);

        if (isWinner(board, symbol)) {
            printf("Player %d wins!\n", symbol);
            break;
        }
        else if (isDraw(board)) {
            printf("It's a draw!\n");
            break;
        }
        else if (isFull(board)) {
            printf("The board is full!\n");
            break;
        }

        board[0][0] = 0;
        board[0][1] = 0;

        printf("Enter a position: ");
        scanf("%d %d", &board[1][0], &board[1][1]);

        if (isWinner(board, symbol)) {
            printf("Player %d wins!\n", symbol);
            break;
        }
        else if (isDraw(board)) {
            printf("It's a draw!\n");
            break;
        }
        else if (isFull(board)) {
            printf("The board is full!\n");
            break;
        }

        board[1][0] = 0;
        board[1][1] = 0;

        printf("Enter a position: ");
        scanf("%d %d", &board[2][0], &board[2][1]);

        if (isWinner(board, symbol)) {
            printf("Player %d wins!\n", symbol);
            break;
        }
        else if (isDraw(board)) {
            printf("It's a draw!\n");
            break;
        }
        else if (isFull(board)) {
            printf("The board is full!\n");
            break;
        }
    }

    return 0;
}