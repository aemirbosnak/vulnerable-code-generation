//Falcon2-11B DATASET v1.0 Category: Chess AI ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8

typedef struct {
    int value;
    char position[BOARD_SIZE];
} Board;

void initializeBoard(Board* board) {
    int i;
    for (i = 0; i < BOARD_SIZE; i++) {
        board->position[i] = '.';
    }
}

int isMoveValid(Board* board, int row, int col) {
    return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board->position[row] == '.');
}

void makeMove(Board* board, int row, int col) {
    board->position[row] = 'X';
    board->position[col] = 'O';
}

void printBoard(Board* board) {
    int i;
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", board->position[i]);
    }
    printf("\n");
}

void playGame() {
    srand(time(NULL));
    int moves = 0;
    Board board;
    initializeBoard(&board);
    printBoard(&board);

    while (1) {
        int row, col;
        printf("Enter your move (row,col): ");
        scanf("%d%d", &row, &col);

        if (isMoveValid(&board, row, col)) {
            makeMove(&board, row, col);
            if (row == 0 && col == 0) {
                printf("Game Over. You Win!\n");
                break;
            } else if (row == 7 && col == 7) {
                printf("Game Over. You Lose!\n");
                break;
            }
            moves++;
            printBoard(&board);
        } else {
            printf("Invalid move!\n");
        }
    }

    printf("You made %d moves.\n", moves);
}

int main() {
    playGame();
    return 0;
}