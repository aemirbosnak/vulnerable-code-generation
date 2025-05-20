//Falcon-180B DATASET v1.0 Category: Chess engine ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8
#define EMPTY '.'
#define BLACK 'B'
#define WHITE 'W'
#define FULL '*'
#define MOVE_LEFT 'L'
#define MOVE_RIGHT 'R'
#define MOVE_UP 'U'
#define MOVE_DOWN 'D'

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, char direction) {
    int newRow = row;
    int newCol = col;

    switch(direction) {
        case MOVE_LEFT:
            newCol--;
            break;
        case MOVE_RIGHT:
            newCol++;
            break;
        case MOVE_UP:
            newRow--;
            break;
        case MOVE_DOWN:
            newRow++;
            break;
    }

    if(newRow >= 0 && newRow < BOARD_SIZE && newCol >= 0 && newCol < BOARD_SIZE && board[newRow][newCol] == EMPTY) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));

    char board[BOARD_SIZE][BOARD_SIZE];
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }

    board[0][0] = BLACK;
    board[0][7] = WHITE;
    board[7][0] = WHITE;
    board[7][7] = BLACK;

    printBoard(board);

    int player = 1;
    while(1) {
        system("clear");
        printBoard(board);

        if(player == 1) {
            printf("Black's turn\n");
        } else {
            printf("White's turn\n");
        }

        char input[3];
        scanf("%s", input);

        int row = input[0] - '0';
        int col = input[1] - '0';
        char direction = input[2];

        if(isValidMove(board, row, col, direction)) {
            if(player == 1) {
                board[row][col] = BLACK;
                player = 2;
            } else {
                board[row][col] = WHITE;
                player = 1;
            }
        } else {
            printf("Invalid move\n");
        }
    }

    return 0;
}