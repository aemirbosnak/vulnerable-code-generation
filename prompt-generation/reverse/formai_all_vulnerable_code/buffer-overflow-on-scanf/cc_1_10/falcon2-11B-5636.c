//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
    bool player;
} TicTacToe;

bool isWinner(TicTacToe board, char symbol) {
    if (board.x == 0 && board.y == 0 && board.player == true) {
        return true;
    }
    if (board.x == 1 && board.y == 1 && board.player == true) {
        return true;
    }
    if (board.x == 2 && board.y == 2 && board.player == true) {
        return true;
    }
    if (board.x == 0 && board.y == 1 && board.player == true) {
        return true;
    }
    if (board.x == 2 && board.y == 1 && board.player == true) {
        return true;
    }
    if (board.x == 0 && board.y == 2 && board.player == true) {
        return true;
    }
    if (board.x == 2 && board.y == 0 && board.player == true) {
        return true;
    }
    if (board.x == 1 && board.y == 2 && board.player == true) {
        return true;
    }
    if (board.x == 2 && board.y == 0 && board.player == true) {
        return true;
    }
    if (board.x == 1 && board.y == 0 && board.player == true) {
        return true;
    }
    return false;
}

bool isFull(TicTacToe board) {
    return (board.x == 3 || board.y == 3);
}

TicTacToe getMove(TicTacToe board, int player) {
    TicTacToe move;
    while (true) {
        printf("Player %d, enter your move (x/y): ", player);
        int x, y;
        scanf("%d%d", &x, &y);
        if (x >= 0 && x <= 2 && y >= 0 && y <= 2) {
            move.x = x;
            move.y = y;
            move.player =!player;
            break;
        } else {
            printf("Invalid move.\n");
        }
    }
    return move;
}

TicTacToe play(TicTacToe board) {
    int player = 0;
    while (!isFull(board)) {
        TicTacToe move = getMove(board, player);
        board.x = move.x;
        board.y = move.y;
        board.player = move.player;
        if (isWinner(board, 'X')) {
            printf("Player %d wins!\n", 1);
            break;
        } else if (isWinner(board, 'O')) {
            printf("Player %d wins!\n", 2);
            break;
        }
        player =!player;
    }
    return board;
}

int main() {
    TicTacToe board = {0, 0, false};
    play(board);
    return 0;
}