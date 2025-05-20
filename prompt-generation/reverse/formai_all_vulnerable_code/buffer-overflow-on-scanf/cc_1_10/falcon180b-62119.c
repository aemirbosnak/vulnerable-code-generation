//Falcon-180B DATASET v1.0 Category: Table Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define EMPTY_CELL '.'
#define PLAYER1_CELL 'X'
#define PLAYER2_CELL 'O'
#define WINNING_COMBINATION "XXX"
#define WINNING_COMBINATION_LENGTH 3

void print_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(char board[ROWS][COLS], char player_cell) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == player_cell && board[i][1] == player_cell && board[i][2] == player_cell) {
            return 1;
        }
        if (board[0][i] == player_cell && board[1][i] == player_cell && board[2][i] == player_cell) {
            return 1;
        }
    }
    if (board[0][0] == player_cell && board[1][1] == player_cell && board[2][2] == player_cell) {
        return 1;
    }
    if (board[0][2] == player_cell && board[1][1] == player_cell && board[2][0] == player_cell) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS] = { { EMPTY_CELL, EMPTY_CELL, EMPTY_CELL },
                                { EMPTY_CELL, EMPTY_CELL, EMPTY_CELL },
                                { EMPTY_CELL, EMPTY_CELL, EMPTY_CELL } };
    int player = 1;
    int choice;
    while (1) {
        system("clear");
        print_board(board);
        printf("Player %d's turn\n", player);
        printf("Enter your choice (1-%d): ", ROWS * COLS - 1);
        scanf("%d", &choice);
        if (choice < 1 || choice > ROWS * COLS - 1) {
            printf("Invalid move, try again.\n");
            continue;
        }
        if (board[choice / COLS][choice % COLS]!= EMPTY_CELL) {
            printf("Cell already occupied, try again.\n");
            continue;
        }
        board[choice / COLS][choice % COLS] = (player == 1)? PLAYER1_CELL : PLAYER2_CELL;
        if (check_win(board, (player == 1)? PLAYER1_CELL : PLAYER2_CELL)) {
            printf("Player %d wins!\n", player);
            break;
        }
        player = (player == 1)? 2 : 1;
    }
    return 0;
}