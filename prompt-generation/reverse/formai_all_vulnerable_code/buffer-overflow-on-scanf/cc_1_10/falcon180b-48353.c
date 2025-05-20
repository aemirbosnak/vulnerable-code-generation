//Falcon-180B DATASET v1.0 Category: Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void drawBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    char board[ROWS][COLS] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int player = 1;
    int choice;
    int flag = 0;

    while (flag == 0) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn.\n", player);

        printf("Enter your move (row and column): ");
        scanf("%d %d", &choice, &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid move.\n");
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col]!= 'X' && board[row][col]!= 'O') {
            board[row][col] = (player == 1)? 'X' : 'O';
            player++;
            flag = 1;
        } else {
            printf("Invalid move.\n");
        }
    }

    if (player == 2) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }

    return 0;
}