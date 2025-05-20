//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[3][3] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };

int isWinner(int x) {
    if (board[0][0] == x && board[0][1] == x && board[0][2] == x)
        return 1;
    if (board[1][0] == x && board[1][1] == x && board[1][2] == x)
        return 1;
    if (board[2][0] == x && board[2][1] == x && board[2][2] == x)
        return 1;

    if (board[0][0] == x && board[1][0] == x && board[2][0] == x)
        return 1;
    if (board[0][1] == x && board[1][1] == x && board[2][1] == x)
        return 1;
    if (board[0][2] == x && board[1][2] == x && board[2][2] == x)
        return 1;

    if (board[0][0] == x && board[1][1] == x && board[2][2] == x)
        return 1;
    if (board[2][0] == x && board[1][1] == x && board[0][2] == x)
        return 1;

    return 0;
}

int isBoardFull(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0)
                return 0;
        }
    }
    return 1;
}

void printBoard(int board[3][3]) {
    printf(" | ");
    for (int i = 0; i < 3; i++) {
        printf("%c ", (i + 1) % 2 == 0? 'X' : 'O');
        for (int j = 0; j < 3; j++) {
            printf(" %d ", board[i][j]);
        }
        printf(" | \n");
    }
}

int main() {
    int player = 1;
    int move, x, y;
    int computer = 2;
    int computerMove = 0;
    int computerX = 0;
    int computerY = 0;

    while (1) {
        printBoard(board);
        printf("Player %d's Turn\n", player);
        scanf("%d %d", &move, &x);
        if (isWinner(player)) {
            printf("Player %d is the winner!\n", player);
            break;
        }
        if (isBoardFull(board)) {
            printf("It's a draw!\n");
            break;
        }
        board[x - 1][y - 1] = player;
        if (player == 1) {
            player = 2;
        } else {
            player = 1;
        }
    }

    srand(time(NULL));
    while (1) {
        printBoard(board);
        printf("Computer's Turn\n");
        int randMove = rand() % 3;
        if (randMove == 0) {
            computerMove = 0;
            computerX = 0;
            computerY = 0;
        } else if (randMove == 1) {
            computerMove = 1;
            computerX = 1;
            computerY = 0;
        } else {
            computerMove = 2;
            computerX = 2;
            computerY = 0;
        }
        if (isWinner(computer)) {
            printf("Computer is the winner!\n");
            break;
        }
        if (isBoardFull(board)) {
            printf("It's a draw!\n");
            break;
        }
        board[computerX - 1][computerY - 1] = computer;
        if (computer == 1) {
            computer = 2;
        } else {
            computer = 1;
        }
    }

    return 0;
}