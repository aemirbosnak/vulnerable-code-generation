//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printBoard(char board[3][3]) {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

void checkWin(char board[3][3]) {
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2]) {
        printf("Player 1 wins!\n");
        exit(0);
    }
    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2]) {
        printf("Player 2 wins!\n");
        exit(0);
    }
    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2]) {
        printf("Player 2 wins!\n");
        exit(0);
    }
    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0]) {
        printf("Player 1 wins!\n");
        exit(0);
    }
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        printf("Player 1 wins!\n");
        exit(0);
    }
    else if (board[0][0] == board[1][2] && board[1][2] == board[2][0]) {
        printf("Player 1 wins!\n");
        exit(0);
    }
    else if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
        printf("Player 2 wins!\n");
        exit(0);
    }
    else if (board[2][2] == board[1][1] && board[1][1] == board[0][0]) {
        printf("Player 2 wins!\n");
        exit(0);
    }
    else if (board[0][2] == board[2][0] && board[2][0] == board[1][1]) {
        printf("Player 2 wins!\n");
        exit(0);
    }
}

void playGame(char board[3][3]) {
    int player = 1;
    int x, y;
    char symbol;

    for (int i = 0; i < 9; i++) {
        do {
            printf("Player %d, enter a move (row and column): ", player);
            scanf("%d%d", &x, &y);
            x--;
            y--;
        } while (board[x][y]!= '\0');

        if (player == 1) {
            symbol = 'X';
            player++;
        }
        else {
            symbol = 'O';
            player--;
        }

        board[x][y] = symbol;
        printBoard(board);
        checkWin(board);
    }
}

int main() {
    srand(time(NULL));
    char board[3][3] = { { '\0', '\0', '\0' }, { '\0', '\0', '\0' }, { '\0', '\0', '\0' } };

    playGame(board);

    return 0;
}