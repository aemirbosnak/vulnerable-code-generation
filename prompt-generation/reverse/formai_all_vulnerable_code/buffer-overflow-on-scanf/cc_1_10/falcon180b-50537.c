//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Point;

void init_board(char board[3][3]) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = '-';
}

void print_board(const char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            printf("%c ", board[i][j]);
        printf("\n");
    }
}

int check_win(const char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
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

int main() {
    srand(time(NULL));
    char board[3][3];
    init_board(board);
    int player = 1;
    while (1) {
        print_board(board);
        int x, y;
        printf("Player %d, enter your move: ", player);
        scanf("%d %d", &x, &y);
        if (x < 1 || x > 3 || y < 1 || y > 3 || board[y - 1][x - 1]!= '-') {
            printf("Invalid move, try again.\n");
            continue;
        }
        board[y - 1][x - 1] = (player == 1)? 'X' : 'O';
        if (check_win(board)) {
            printf("Player %d wins!\n", player);
            break;
        }
        player = (player == 1)? 2 : 1;
    }
    return 0;
}