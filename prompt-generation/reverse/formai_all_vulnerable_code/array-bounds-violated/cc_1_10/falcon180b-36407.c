//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_board(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(char board[3][3]) {
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
    char board[3][3];
    init_board(board);
    int player = 1;
    while (1) {
        print_board(board);
        int x, y;
        if (player % 2 == 1) {
            printf("Player 1's turn. Enter your move (row and column): ");
            scanf("%d%d", &x, &y);
            board[x][y] = 'X';
            if (check_win(board)) {
                printf("Player 1 wins!\n");
                break;
            }
        } else {
            printf("Player 2's turn. Enter your move (row and column): ");
            scanf("%d%d", &x, &y);
            board[x][y] = 'O';
            if (check_win(board)) {
                printf("Player 2 wins!\n");
                break;
            }
        }
        player++;
        if (player > 9) {
            printf("It's a draw.\n");
            break;
        }
    }
    return 0;
}