//Falcon-180B DATASET v1.0 Category: Table Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void print_board(int board[ROWS][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(int board[ROWS][COLS], int row, int col) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(board[i][j] == 1 || board[i][j] == 2) {
                if(i == row && j == col) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main() {
    int board[ROWS][COLS] = {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int choice;
    int row, col;
    int valid_move = 0;
    srand(time(NULL));

    while(1) {
        system("clear");
        print_board(board);
        printf("\nPlayer %d's turn\n", player);
        printf("Enter your move (row and column): ");
        scanf("%d %d", &row, &col);
        if(is_valid_move(board, row, col)) {
            board[row][col] = player;
            valid_move = 1;
            player = (player == 1)? 2 : 1;
        } else {
            printf("Invalid move. Try again.\n");
        }
        if(valid_move) {
            if(check_winner(board)) {
                printf("Player %d wins!\n", player);
                break;
            } else if(check_draw(board)) {
                printf("It's a draw.\n");
                break;
            }
            valid_move = 0;
        }
    }

    return 0;
}

int check_winner(int board[ROWS][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    for(j = 0; j < COLS; j++) {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int check_draw(int board[ROWS][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}