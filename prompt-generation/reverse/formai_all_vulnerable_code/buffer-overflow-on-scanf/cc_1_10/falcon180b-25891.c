//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#define ROW 3
#define COL 3

void drawBoard(int board[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(int board[ROW][COL]) {
    int i, j;

    // check rows
    for (i = 0; i < ROW; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // check columns
    for (j = 0; j < COL; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int main() {
    int board[ROW][COL] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int choice;
    int flag = 0;

    srand(time(NULL));
    int comp_choice = rand() % 9; // computer's initial choice

    while (!flag) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn\n", player);

        if (player == 1) {
            printf("Enter your choice (1-9): ");
            scanf("%d", &choice);
            if (choice < 1 || choice > 9) {
                printf("Invalid move. Try again.\n");
                continue;
            }
        } else {
            choice = comp_choice;
        }

        if (board[choice / 3][choice % 3] == 0) {
            board[choice / 3][choice % 3] = player;
            player = (player == 1)? 2 : 1; // switch player
            if (checkWin(board)) {
                flag = 1;
                printf("\nPlayer %d wins!\n", player);
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}