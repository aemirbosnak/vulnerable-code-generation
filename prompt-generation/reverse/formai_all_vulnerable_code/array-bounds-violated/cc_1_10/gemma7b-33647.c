//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Cell {
    int x, y;
    char value;
} Cell;

Cell cells[BOARD_SIZE][BOARD_SIZE];

void initBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cells[i][j].x = i;
            cells[i][j].y = j;
            cells[i][j].value = ' ';
        }
    }
}

void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", cells[i][j].value);
        }
        printf("\n");
    }
}

int isBoardFull() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (cells[i][j].value == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    initBoard();

    // Play until the board is full or one player wins
    while (!isBoardFull()) {
        // Get the player's move
        int x, y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &x, &y);

        // Check if the move is valid
        if (cells[x][y].value != ' ') {
            printf("Invalid move.\n");
            continue;
        }

        // Make the move
        cells[x][y].value = 'X';

        // Print the board
        printBoard();
    }

    // Print the winner or a draw
    if (isBoardFull()) {
        printf("It's a draw!\n");
    } else {
        printf("Congratulations! You won!\n");
    }

    return 0;
}