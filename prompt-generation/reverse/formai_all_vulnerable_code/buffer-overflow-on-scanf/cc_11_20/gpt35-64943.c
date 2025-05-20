//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player);

int main()
{
    int i, j, move;
    char player = 'X';
    char board[BOARD_SIZE][BOARD_SIZE] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};

    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1 is X and Player 2 is O.\n\n");

    print_board(board);

    for (i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
    {
        printf("Player %c's turn. Enter move: ", player);
        scanf("%d", &move);

        if (move < 1 || move > 9)
        {
            printf("Invalid move.\n");
            i--;
            continue;
        }

        if (board[(move - 1) / BOARD_SIZE][(move - 1) % BOARD_SIZE] == 'X' || board[(move - 1) / BOARD_SIZE][(move - 1) % BOARD_SIZE] == 'O')
        {
            printf("Position already taken. Try again.\n");
            i--;
            continue;
        }

        board[(move - 1) / BOARD_SIZE][(move - 1) % BOARD_SIZE] = player;
        print_board(board);

        if (check_win(board, player))
        {
            printf("Player %c wins!\n", player);
            return 0;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    printf("It's a tie!\n");
    return 0;
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player)
{
    // Check rows
    if (board[0][0] == player && board[0][1] == player && board[0][2] == player)
        return 1;
    if (board[1][0] == player && board[1][1] == player && board[1][2] == player)
        return 1;
    if (board[2][0] == player && board[2][1] == player && board[2][2] == player)
        return 1;

    // Check columns
    if (board[0][0] == player && board[1][0] == player && board[2][0] == player)
        return 1;
    if (board[0][1] == player && board[1][1] == player && board[2][1] == player)
        return 1;
    if (board[0][2] == player && board[1][2] == player && board[2][2] == player)
        return 1;

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;

    return 0;
}