//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: retro
#include <stdio.h>

int main() {
    int board[3][3];
    int player, opponent;
    int turn = 1;
    int game_over = 0;

    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1 is 'X', Player 2 is 'O'\n");

    while (!game_over) {
        printf("\nPlayer %d's turn:\n", turn % 2 + 1);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf(" %d |", board[i][j]);
            }
            printf("\n");
        }
        printf("Enter your position (0-2, 0-2):\n");
        scanf("%d", &player);
        if (player < 0 || player > 2 || board[player / 3][player % 3]!= 0) {
            printf("Invalid move, try again.\n");
            continue;
        }
        board[player / 3][player % 3] = turn;
        if (turn == 1) {
            opponent = 2;
        } else {
            opponent = 1;
        }
        turn = (turn % 2) + 1;
        if (check_win(board, turn)) {
            printf("%c wins!\n", turn == 1? 'X' : 'O');
            game_over = 1;
        } else if (check_tie(board)) {
            printf("It's a tie!\n");
            game_over = 1;
        }
    }

    return 0;
}

int check_win(int board[3][3], int player) {
    int i, j;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
                return 1;
            }
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[2][0] == player && board[1][1] == player && board[0][2] == player) {
        return 1;
    }
    return 0;
}

int check_tie(int board[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}