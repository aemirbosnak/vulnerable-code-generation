//Falcon-180B DATASET v1.0 Category: Table Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

int checkWin(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
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

int checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-')
                return 0;
        }
    }
    return 1;
}

void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char board[3][3];
    initBoard(board);

    int player = 1;
    while (1) {
        system("clear");
        printBoard(board);
        printf("\nPlayer %d's turn\n", player);
        int x, y;
        scanf("%d %d", &x, &y);
        if (board[x][y]!= '-') {
            printf("Invalid move\n");
            continue;
        }
        board[x][y] = (player == 1)? 'X' : 'O';
        if (checkWin(board)) {
            printf("Player %d wins!\n", player);
            break;
        } else if (checkDraw(board)) {
            printf("It's a draw.\n");
            break;
        }
        player = (player == 1)? 2 : 1;
    }

    return 0;
}