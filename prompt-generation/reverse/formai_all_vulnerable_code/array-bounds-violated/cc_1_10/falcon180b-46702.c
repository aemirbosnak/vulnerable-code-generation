//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define MAX_TRIES 5

void generate_board(char board[ROWS][COLS]);
int check_win(char board[ROWS][COLS]);
void print_board(char board[ROWS][COLS]);
int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    generate_board(board);
    int player_row = 0, player_col = 0, tries = 0;
    while (tries < MAX_TRIES) {
        system("clear");
        print_board(board);
        printf("Player %d's turn. Enter row and column: ", tries + 1);
        scanf("%d%d", &player_row, &player_col);
        if (player_row >= ROWS || player_col >= COLS) {
            printf("Invalid input. Try again.\n");
            continue;
        }
        if (board[player_row][player_col]!= 'X' && board[player_row][player_col]!= 'O') {
            board[player_row][player_col] = 'X';
            if (check_win(board)) {
                printf("Player %d wins!\n", tries + 1);
                return 0;
            }
        } else {
            printf("Cell already marked. Try again.\n");
        }
        tries++;
    }
    printf("Tie game.\n");
    return 0;
}

void generate_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2? 'X' : 'O';
        }
    }
}

int check_win(char board[ROWS][COLS]) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

void print_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}