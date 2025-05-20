//Falcon-180B DATASET v1.0 Category: Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void print_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

void play_game(char board[ROWS][COLS]) {
    int player = 1;
    int choice;

    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = (char)('0' + rand() % 2);
        }
    }

    while (!check_win(board)) {
        print_board(board);
        printf("Player %d's turn\n", player);
        printf("Enter your move (row, column): ");
        scanf("%d%d", &choice, &choice);

        if (board[choice][0] == 'X' || board[0][choice] == 'O') {
            printf("Invalid move. Try again.\n");
        } else if (player == 1) {
            board[choice][0] = 'X';
            player = 2;
        } else if (player == 2) {
            board[0][choice] = 'O';
            player = 1;
        }
    }

    printf("Game over!\n");
    if (check_win(board) == 1) {
        printf("Player %d wins!\n", player);
    } else {
        printf("It's a tie!\n");
    }
}

int main() {
    char board[ROWS][COLS];
    play_game(board);

    return 0;
}