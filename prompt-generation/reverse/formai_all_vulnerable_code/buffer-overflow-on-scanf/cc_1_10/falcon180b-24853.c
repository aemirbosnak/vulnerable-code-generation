//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

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
    char board[ROWS][COLS] = { { '0', '1', '2' }, { '3', '4', '5' }, { '6', '7', '8' } };
    int player = 1;
    int choice;
    int flag = 0;

    while (flag == 0) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn\n", player);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col]!= '0' && board[row][col]!= 'X' && board[row][col]!= 'O') {
            board[row][col] = (player == 1)? 'X' : 'O';
            player = (player == 1)? 2 : 1;
        } else {
            printf("Invalid move! Try again.\n");
        }

        flag = checkWin(board);
    }

    return 0;
}

int checkWin(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
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