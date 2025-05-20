//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void init_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board(const char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    init_board(board);
    int num_matches = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2? 'X' : 'O';
        }
    }

    while (num_matches < ROWS * COLS) {
        int row, col;
        printf("Enter row and column: ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < ROWS && col >= 0 && col < COLS &&
            board[row][col]!= '-') {
            if (board[row][col] == board[(row + 1) % ROWS][col]) {
                board[(row + 1) % ROWS][col] = '-';
                num_matches++;
            } else if (board[row][col] == board[row][(col + 1) % COLS]) {
                board[row][(col + 1) % COLS] = '-';
                num_matches++;
            }
        } else {
            printf("Invalid input.\n");
        }
    }

    printf("Congratulations! You won in %d turns.\n", num_matches + 2);
    return 0;
}