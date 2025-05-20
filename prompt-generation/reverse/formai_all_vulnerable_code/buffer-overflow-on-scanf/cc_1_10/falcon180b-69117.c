//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawBoard(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(int board[3][3]) {
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
    int board[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int player = 1;
    int choice;

    while (1) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn.\n", player);
        printf("Enter your move (1-9): ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid move.\n");
            continue;
        }

        if (board[choice / 3][choice % 3]!= 0) {
            printf("Spot taken. Try again.\n");
            continue;
        }

        board[choice / 3][choice % 3] = player;

        if (checkWin(board)) {
            printf("\nPlayer %d wins!\n", player);
            break;
        }

        player = (player == 1)? 2 : 1;
    }

    return 0;
}