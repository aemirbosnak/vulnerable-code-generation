//Falcon-180B DATASET v1.0 Category: Table Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define NUM_SYMBOLS 2

char symbols[NUM_SYMBOLS] = {'X', 'O'};
char board[ROWS][COLS];

void init_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner() {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    init_board();
    int player = 0;
    int choice;
    while (1) {
        print_board();
        printf("Player %d's turn\n", player + 1);
        printf("Enter your choice (1-%d): ", ROWS * COLS - 1);
        scanf("%d", &choice);
        if (choice < 1 || choice > ROWS * COLS - 1) {
            printf("Invalid choice, try again.\n");
            continue;
        }
        int row = choice / COLS;
        int col = choice % COLS;
        if (board[row][col]!= '-') {
            printf("Cell already occupied, try again.\n");
            continue;
        }
        board[row][col] = symbols[player];
        if (check_winner()) {
            print_board();
            printf("Player %d wins!\n", player + 1);
            break;
        }
        player =!player;
    }
    return 0;
}