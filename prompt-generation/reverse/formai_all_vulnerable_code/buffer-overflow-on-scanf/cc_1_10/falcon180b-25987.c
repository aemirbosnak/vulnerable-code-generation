//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void print_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];

    // Initialize board with random symbols
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 'X' + rand() % 3;
        }
    }

    // Print initial board
    printf("Initial board:\n");
    print_board(board);

    // Game loop
    int moves = 0;
    while (1) {
        system("clear");
        printf("Moves: %d\n", moves);
        print_board(board);

        char move;
        scanf(" %c", &move);

        int row = -1, col = -1;
        switch (move) {
            case 'w':
                row--;
                break;
            case 'a':
                col--;
                break;
            case's':
                row++;
                break;
            case 'd':
                col++;
                break;
            default:
                printf("Invalid move.\n");
                continue;
        }

        if (row >= 0 && row < ROWS && col >= 0 && col < COLS &&
            board[row][col] == 'X') {
            board[row][col] = 'O';
            moves++;
        } else {
            printf("Invalid move.\n");
        }
    }

    return 0;
}