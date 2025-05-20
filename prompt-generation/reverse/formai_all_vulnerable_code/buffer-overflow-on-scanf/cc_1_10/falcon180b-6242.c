//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: puzzling
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 5
#define MATCH 1
#define MISMATCH 0

void init_board(char board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '*';
        }
    }
}

void shuffle_board(char board[][SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int r = rand() % 3;
            if (r == 0) {
                board[i][j] = 'X';
            } else if (r == 1) {
                board[i][j] = 'O';
            }
        }
    }
}

void print_board(char board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char board[SIZE][SIZE];
    init_board(board);
    shuffle_board(board);
    int score = 0;
    int moves = 0;
    while (1) {
        print_board(board);
        int x, y;
        printf("Enter your move (row and column): ");
        scanf("%d%d", &x, &y);
        if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
            if (board[x][y] == 'X' || board[x][y] == 'O') {
                if (board[x][y] == 'X') {
                    board[x][y] = 'O';
                    score++;
                } else {
                    board[x][y] = 'X';
                    score--;
                }
                moves++;
            } else {
                printf("Invalid move.\n");
            }
        } else {
            printf("Invalid move.\n");
        }
        if (score == SIZE * SIZE) {
            printf("You win!\n");
            break;
        } else if (score == -SIZE * SIZE) {
            printf("You lose.\n");
            break;
        }
    }
    return 0;
}