//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

char board[SIZE][SIZE] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' } };

void printBoard() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin() {
    int i;

    for (i = 0; i < SIZE; i++) {
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

int main() {
    int i, j, player = 1, choice;
    char mark;

    srand(time(NULL));

    do {
        system("clear");
        printBoard();

        printf("\nPlayer %d's turn:", player);
        scanf("%d", &choice);
        if (choice < 1 || choice > SIZE * SIZE) {
            printf("Invalid move, try again.\n");
            continue;
        }

        if (board[choice / SIZE][choice % SIZE]!= 'X' && board[choice / SIZE][choice % SIZE]!= 'O') {
            if (player % 2 == 0)
                mark = 'X';
            else
                mark = 'O';

            board[choice / SIZE][choice % SIZE] = mark;
            player++;
        } else {
            printf("Invalid move, try again.\n");
        }

        if (checkWin()) {
            printf("\n%s wins!\n", (player % 2 == 0)? "Player 1" : "Player 2");
            break;
        }

        if (player % 2 == 0)
            player++;
        else
            player--;

    } while (1);

    return 0;
}