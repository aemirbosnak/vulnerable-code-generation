//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int is_win(int board[3][3], int player) {
    if (board[0][0] == player && board[0][1] == player && board[0][2] == player ||
        board[1][0] == player && board[1][1] == player && board[1][2] == player ||
        board[2][0] == player && board[2][1] == player && board[2][2] == player ||
        board[0][0] == player && board[1][0] == player && board[2][0] == player ||
        board[0][1] == player && board[1][1] == player && board[2][1] == player ||
        board[0][2] == player && board[1][2] == player && board[2][2] == player ||
        board[0][0] == player && board[1][1] == player && board[2][2] == player ||
        board[2][0] == player && board[1][1] == player && board[0][2] == player) {
        return 1;
    }
    return 0;
}

int is_board_full(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int ai_move(int board[3][3], int player) {
    if (is_board_full(board)) {
        return 0;
    }

    int move;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                move = i * 3 + j;
                board[i][j] = player;

                if (is_win(board, player)) {
                    board[i][j] = 0;
                    return move;
                }
            }
        }
    }

    move = -1;
    board[0][0] = player;
    if (is_win(board, player)) {
        return move;
    }

    board[0][1] = player;
    if (is_win(board, player)) {
        return move;
    }

    board[0][2] = player;
    if (is_win(board, player)) {
        return move;
    }

    board[1][0] = player;
    if (is_win(board, player)) {
        return move;
    }

    board[1][1] = player;
    if (is_win(board, player)) {
        return move;
    }

    board[1][2] = player;
    if (is_win(board, player)) {
        return move;
    }

    board[2][0] = player;
    if (is_win(board, player)) {
        return move;
    }

    board[2][1] = player;
    if (is_win(board, player)) {
        return move;
    }

    board[2][2] = player;
    if (is_win(board, player)) {
        return move;
    }

    board[0][0] = 0;
    board[0][1] = 0;
    board[0][2] = 0;
    board[1][0] = 0;
    board[1][1] = 0;
    board[1][2] = 0;
    board[2][0] = 0;
    board[2][1] = 0;
    board[2][2] = 0;

    move = -1;
    return move;
}

int main() {
    int board[3][3] = {
        { 0, 0, 0 },
        { 0, 0, 0 },
        { 0, 0, 0 }
    };
    int player = 1;
    int move;

    printf("Tic Tac Toe\n");

    while (1) {
        printf("Player %d's turn. Choose a number from 0 to 2: ", player);
        scanf("%d", &move);
        move--;
        board[move / 3][move % 3] = player;

        if (is_win(board, player)) {
            printf("Player %d wins!\n", player);
            break;
        }
        else if (is_board_full(board)) {
            printf("It's a draw!\n");
            break;
        }

        player = 3 - player;
        move = ai_move(board, player);

        if (move == -1) {
            printf("It's a draw!\n");
            break;
        }

        board[move / 3][move % 3] = player;

        if (is_win(board, player)) {
            printf("Player %d wins!\n", player);
            break;
        }
        else if (is_board_full(board)) {
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}