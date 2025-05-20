//Falcon-180B DATASET v1.0 Category: Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void draw_board(char board[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(char board[ROW][COL]) {
    int i;

    // check rows
    for (i = 0; i < ROW; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // check columns
    for (i = 0; i < COL; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int main() {
    char board[ROW][COL];
    int i, j, player = 1;

    // initialize board with empty spaces
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            board[i][j] = '-';
        }
    }

    while (1) {
        system("clear");
        draw_board(board);
        printf("\nPlayer %d's turn\n", player);

        int choice;
        scanf("%d", &choice);
        if (choice < 1 || choice > 9) {
            printf("Invalid move!\n");
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col]!= '-') {
            printf("Invalid move!\n");
            continue;
        }

        board[row][col] = (player == 1)? 'X' : 'O';

        if (check_win(board)) {
            printf("\nPlayer %d wins!\n", player);
            break;
        }

        player = (player == 1)? 2 : 1;
    }

    return 0;
}