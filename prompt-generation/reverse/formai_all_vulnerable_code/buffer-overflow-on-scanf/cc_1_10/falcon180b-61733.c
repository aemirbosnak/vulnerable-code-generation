//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

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
        // rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        // columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    // diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

int main() {
    srand(time(NULL));
    char board[SIZE][SIZE];

    // initialize board with empty spaces
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = '-';

    int player = 1;
    int choice;
    int flag = 0;

    while (flag == 0) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn\n", player);
        printf("Enter your move (row col): ");
        scanf("%d %d", &choice, &choice);
        int row = choice / SIZE;
        int col = choice % SIZE;

        if (board[row][col]!= '-') {
            printf("Invalid move! Try again.\n");
            continue;
        } else {
            board[row][col] = (player % 2 == 0)? 'X' : 'O';
            flag = checkWin(board);
            player++;
        }
    }

    printf("\nGame over! Player %d wins!\n", (player - 1) % 2 + 1);

    return 0;
}