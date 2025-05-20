//Falcon-180B DATASET v1.0 Category: Table Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int board[SIZE][SIZE];

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void drawBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void placeMark(int player, int x, int y) {
    if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && board[x][y] == 0) {
        board[x][y] = player;
    }
}

int checkWin(int player) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i] == player && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    if (board[0][0] == player && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == player && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    initializeBoard();
    int player = 1;
    int choice;
    while (1) {
        system("clear");
        drawBoard();
        printf("\nPlayer %d's turn\n", player);
        printf("Enter your move (row and column): ");
        scanf("%d %d", &choice, &choice);
        if (choice >= 0 && choice < SIZE) {
            placeMark(player, choice, 0);
            if (checkWin(player)) {
                printf("\nPlayer %d wins!\n", player);
                break;
            }
            player++;
            if (player > 2) {
                player = 1;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    return 0;
}