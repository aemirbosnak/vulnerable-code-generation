//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

void initBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

void drawBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4]) {
            return 1;
        }
    }

    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] == board[3][j] && board[3][j] == board[4][j]) {
            return 1;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4]) {
        return 1;
    }

    if (board[0][4] == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[3][1] == board[4][0]) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));

    char board[SIZE][SIZE];
    initBoard(board);

    int player = 1;
    int choice;
    int flag = 0;

    while (!flag) {
        drawBoard(board);
        printf("Player %d's turn\n", player);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > SIZE * SIZE) {
            printf("Invalid choice. Try again.\n");
            continue;
        }

        if (board[choice / SIZE][choice % SIZE]!= '-') {
            printf("Invalid choice. Try again.\n");
            continue;
        }

        board[choice / SIZE][choice % SIZE] = (player == 1)? 'X' : 'O';

        flag = checkWin(board);

        if (flag) {
            printf("Player %d wins!\n", player);
            break;
        }

        player = (player == 1)? 2 : 1;
    }

    return 0;
}