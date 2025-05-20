//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void drawBoard(char board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[SIZE][SIZE]) {
    int i;

    // Check horizontal lines
    for (i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check vertical lines
    for (i = 0; i < SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // Check diagonal lines
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

void getMove(char board[SIZE][SIZE], int player) {
    int i, j;
    char c;

    printf("Player %d's turn:\n", player);
    printf("Enter your move (row and column): ");
    scanf("%d%c", &i, &c);
    j = c - '0';

    if (board[i - 1][j - 1]!= 'X' && board[i - 1][j - 1]!= 'O') {
        board[i - 1][j - 1] = (player == 1)? 'X' : 'O';
    } else {
        printf("Invalid move. Try again.\n");
        getMove(board, player);
    }
}

int main() {
    srand(time(NULL));
    char board[SIZE][SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    int player = rand() % 2 + 1;

    while (1) {
        system("clear");
        drawBoard(board);
        printf("Player %d's turn\n", player);

        getMove(board, player);

        if (checkWin(board)) {
            drawBoard(board);
            printf("Player %d wins!\n", player);
            break;
        } else if (board[0][0]!= '1' && board[0][0]!= '2' && board[0][0]!= '3' &&
                   board[0][1]!= '4' && board[0][1]!= '5' && board[0][1]!= '6' &&
                   board[0][2]!= '7' && board[0][2]!= '8' && board[0][2]!= '9') {
            drawBoard(board);
            printf("It's a draw.\n");
            break;
        }

        player = (player == 1)? 2 : 1;
    }

    return 0;
}