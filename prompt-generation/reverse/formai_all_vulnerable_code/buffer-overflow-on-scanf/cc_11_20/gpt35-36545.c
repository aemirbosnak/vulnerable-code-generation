//FormAI DATASET v1.0 Category: Table Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

void print_board(int board[BOARD_SIZE][BOARD_SIZE], int player_row, int player_col) {
    int i, j;
    printf("  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (i == player_row && j == player_col) {
                printf("P ");
            }
            else if (board[i][j] == 1) {
                printf("* ");
            }
            else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int player_row, player_col, bomb_row, bomb_col;
    int i, j;
    int has_bomb = 0;
    char move;

    srand(time(NULL));
    player_row = rand() % BOARD_SIZE;
    player_col = rand() % BOARD_SIZE;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    // Add 5 bombs randomly to the board
    for (i = 0; i < 5; i++) {
        bomb_row = rand() % BOARD_SIZE;
        bomb_col = rand() % BOARD_SIZE;
        board[bomb_row][bomb_col] = 1;
    }

    printf("Welcome to the Paranoid Table Game!\n");
    printf("The objective of this game is to avoid the bombs on the board.\n");
    printf("Enter 'w' to move up, 'a' to move left, 's' to move down, and 'd' to move right.\n");

    while (1) {
        print_board(board, player_row, player_col);

        if (board[player_row][player_col] == 1) {
            printf("You hit a bomb and lost!\n");
            return 0;
        }

        if (player_row == 0 && player_col == 0) {
            printf("You made it to the other side and survived. Good job!\n");
            return 0;
        }

        printf("Enter a move: ");
        scanf(" %c", &move);
        switch (move) {
            case 'w':
                if (player_row > 0) {
                    player_row--;
                }
                break;
            case 'a':
                if (player_col > 0) {
                    player_col--;
                }
                break;
            case 's':
                if (player_row < BOARD_SIZE - 1) {
                    player_row++;
                }
                break;
            case 'd':
                if (player_col < BOARD_SIZE - 1) {
                    player_col++;
                }
                break;
            default:
                printf("Invalid move. Try again.\n");
                break;
        }
    }

    return 0;
}