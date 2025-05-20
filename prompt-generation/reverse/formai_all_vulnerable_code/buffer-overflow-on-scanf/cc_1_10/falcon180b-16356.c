//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

void drawBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    int row, col;
    for (row = 0; row < BOARD_SIZE; row++) {
        for (col = 0; col < BOARD_SIZE; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

int checkWin(char board[BOARD_SIZE][BOARD_SIZE]) {
    int row, col;

    // Check rows
    for (row = 0; row < BOARD_SIZE; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            return 1;
        }
    }

    // Check columns
    for (col = 0; col < BOARD_SIZE; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

void placeMark(char board[BOARD_SIZE][BOARD_SIZE], char mark) {
    int row, col;

    printf("Enter the row and column to place your mark (0-2): ");
    scanf("%d %d", &row, &col);

    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == '\0') {
        board[row][col] = mark;
    } else {
        printf("Invalid move.\n");
    }
}

int main() {
    srand(time(NULL));
    char board[BOARD_SIZE][BOARD_SIZE];

    // Initialize board
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = '\0';
        }
    }

    // Start game loop
    while (1) {
        system("clear");
        drawBoard(board);

        int player = rand() % 2;
        char mark;
        if (player == 0) {
            mark = 'X';
        } else {
            mark = 'O';
        }

        int won = 0;
        while (!won) {
            placeMark(board, mark);
            won = checkWin(board);
        }

        if (player == 0) {
            printf("Player 1 wins!\n");
        } else {
            printf("Player 2 wins!\n");
        }

        printf("Do you want to play again? (y/n): ");
        char playAgain;
        scanf(" %c", &playAgain);
        if (playAgain!= 'y') {
            break;
        }
    }

    return 0;
}