//Falcon-180B DATASET v1.0 Category: Table Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

int check_win(char board[BOARD_SIZE][BOARD_SIZE], char symbol) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
            return 1;
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)
            return 1;
    }
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
        return 1;
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
        return 1;

    return 0;
}

int main() {
    srand(time(NULL));

    char board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);

    int player = 1;
    while (1) {
        system("clear");
        print_board(board);
        printf("Player %d's turn\n", player);

        int x, y;
        scanf("%d %d", &x, &y);

        if (board[x - 1][y - 1]!= '-') {
            printf("Invalid move\n");
            continue;
        }

        board[x - 1][y - 1] = (player % 2 == 0)? 'X' : 'O';

        if (check_win(board, (player % 2 == 0)? 'X' : 'O')) {
            printf("Player %d wins!\n", player);
            break;
        }

        player++;
        if (player > 2)
            player = 1;
    }

    return 0;
}