//Falcon-180B DATASET v1.0 Category: Table Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define WINNING_COMBINATION ((1 << ROWS) - 1)

int board[ROWS][COLS] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

void drawBoard() {
    printf("  %d  %d  %d\n", board[0][0], board[0][1], board[0][2]);
    printf("  %d  %d  %d\n", board[1][0], board[1][1], board[1][2]);
    printf("  %d  %d  %d\n", board[2][0], board[2][1], board[2][2]);
}

int playGame() {
    int player = 1;
    int choice;
    int i, j;

    while (1) {
        drawBoard();
        printf("\nPlayer %d's turn.\n", player);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid choice.\n");
            continue;
        }

        i = choice / 3;
        j = choice % 3;

        if (board[i][j]!= 0) {
            printf("Spot taken.\n");
            continue;
        }

        board[i][j] = player;

        if (checkWin(player)) {
            printf("Player %d wins!\n", player);
            return player;
        }

        player =!player;
    }
}

int checkWin(int player) {
    int i, j;
    int winningCombinations[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
    int k;

    for (k = 0; k < 8; k++) {
        i = winningCombinations[k][0];
        j = winningCombinations[k][1];

        if (board[i][j] == player &&
            board[i][j + 1] == player &&
            board[i + 1][j + 1] == player) {
            return 1;
        }
    }

    return 0;
}

int main() {
    srand(time(NULL));
    int player = rand() % 2 + 1;

    drawBoard();
    printf("\nPlayer %d starts.\n", player);

    playGame();

    return 0;
}