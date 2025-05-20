//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

void drawBoard(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 1) {
                printf("X ");
            } else if (board[i][j] == 2) {
                printf("O ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

int isBoardFull(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int isThereAWinner(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
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
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    char choice;
    while (1) {
        system("clear");
        printf("Player 1: X, Player 2: O\n");
        printf("Player %d's turn.\n", player);
        Point p;
        p.x = 0;
        p.y = 0;
        do {
            printf("Enter your move (row and column): ");
            scanf("%d%d", &p.x, &p.y);
        } while (p.x < 1 || p.x > 3 || p.y < 1 || p.y > 3 || board[p.x - 1][p.y - 1]!= 0);
        board[p.x - 1][p.y - 1] = player;
        drawBoard(board);
        if (isBoardFull(board)) {
            printf("It's a draw.\n");
            break;
        }
        if (isThereAWinner(board)) {
            printf("Player %d wins!\n", player);
            break;
        }
        player = 3 - player;
    }
    return 0;
}