//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void init_board(char board[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            board[i][j] = '.';
        }
    }
}

void print_board(char board[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    char board[MAX_ROWS][MAX_COLS];
    init_board(board);

    int mines = 10;
    int mines_placed = 0;

    while (mines_placed < mines) {
        int row = rand() % MAX_ROWS;
        int col = rand() % MAX_COLS;

        if (board[row][col] == '.' && mines_placed < mines) {
            board[row][col] = '*';
            mines_placed++;
        }
    }

    char input;
    int row, col;
    int game_over = 0;

    while (!game_over) {
        print_board(board);

        printf("Enter your move (row col): ");
        scanf("%d %d", &row, &col);

        if (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS) {
            if (board[row][col] == '*') {
                game_over = 1;
            } else if (board[row][col] == '.') {
                board[row][col] = 'X';
            }
        } else {
            printf("Invalid move\n");
        }
    }

    if (game_over) {
        printf("You hit a mine! Game over.\n");
    } else {
        printf("Congratulations! You won!\n");
    }

    return 0;
}