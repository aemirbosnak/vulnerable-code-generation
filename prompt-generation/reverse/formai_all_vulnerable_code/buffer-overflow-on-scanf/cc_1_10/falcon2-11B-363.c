//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PIECE_SIZE 10
#define ROWS 8
#define COLUMNS 8
#define MAX_MOVES 100

int board[ROWS][COLUMNS] = {0};
int current_player = 1;
int moves_left = MAX_MOVES;

void print_board(int board[][COLUMNS], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%s ", (board[i][j] == current_player)? "X" : "O");
        }
        printf("\n");
    }
    printf("\n");
}

void move_piece(int row, int column, int new_row, int new_column) {
    if (board[new_row][new_column]!= 0) {
        return;
    }
    board[row][column] = 0;
    board[new_row][new_column] = current_player;

    int jump_count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == current_player) {
                jump_count++;
            }
        }
    }

    if (jump_count > 0) {
        print_board(board, ROWS, COLUMNS);
        printf("You jumped %d pieces!\n", jump_count);
    }
}

int main() {
    srand(time(NULL));

    while (moves_left > 0) {
        printf("Player %d, your move:\n", current_player == 1? "red" : "blue");

        int row, column;
        scanf("%d %d", &row, &column);

        if (row < 0 || row >= ROWS || column < 0 || column >= COLUMNS) {
            printf("Invalid move!\n");
            continue;
        }

        if (board[row][column]!= 0) {
            printf("That space is already taken!\n");
            continue;
        }

        int new_row, new_column;
        do {
            new_row = row + 1;
            new_column = column + 1;
        } while (new_row >= ROWS || new_column >= COLUMNS || board[new_row][new_column]!= 0);

        move_piece(row, column, new_row, new_column);

        moves_left--;
        if (moves_left == 0) {
            printf("Game over!\n");
            break;
        }

        current_player = 1 - current_player;
    }

    return 0;
}