//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ttt_move(int board[3][3], int player);
void print_board(int board[3][3]);

int main()
{
    srand(time(NULL));
    int board[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    printf("Welcome to Tic Tac Toe!\n");

    print_board(board);

    int player = 1;
    while (ttt_move(board, player)!= 0) {
        print_board(board);
        player = 3 - player;
    }

    if (board[0][0] == player || board[1][1] == player || board[2][2] == player) {
        printf("Player %d wins!\n", player);
    } else if (board[0][1] == player && board[1][0] == player) {
        printf("Player %d wins!\n", player);
    } else if (board[0][2] == player && board[2][0] == player) {
        printf("Player %d wins!\n", player);
    } else if (board[1][0] == player && board[2][1] == player) {
        printf("Player %d wins!\n", player);
    } else if (board[1][2] == player && board[2][1] == player) {
        printf("Player %d wins!\n", player);
    } else if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        printf("Player %d wins!\n", player);
    } else if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        printf("Player %d wins!\n", player);
    } else {
        printf("Game is a draw!\n");
    }

    return 0;
}

int ttt_move(int board[3][3], int player)
{
    int x, y;
    do {
        printf("Player %d, your move: ", player);
        scanf("%d %d", &x, &y);
    } while (x < 0 || y < 0 || x > 2 || y > 2 || board[x][y]!= 0);

    board[x][y] = player;

    return 1;
}

void print_board(int board[3][3])
{
    printf("   |   |   \n");
    printf(" %d | %d | %d \n", board[0][0], board[0][1], board[0][2]);
    printf("   |   |   \n");
    printf("-----------\n");
    printf("   |   |   \n");
    printf(" %d | %d | %d \n", board[1][0], board[1][1], board[1][2]);
    printf("   |   |   \n");
    printf("-----------\n");
    printf("   |   |   \n");
    printf(" %d | %d | %d \n", board[2][0], board[2][1], board[2][2]);
    printf("   |   |   \n");
}