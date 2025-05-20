//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY_SPOT -1

void display_board(int **board);
void place_piece(int **board, int player);
int check_win(int **board, int player);
int main()
{
    int **board = (int **)malloc(BOARD_SIZE * sizeof(int *));
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board[i] = (int *)malloc(BOARD_SIZE * sizeof(int));
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = EMPTY_SPOT;
        }
    }

    int player = 1;
    int game_over = 0;

    while (!game_over)
    {
        place_piece(board, player);
        display_board(board);

        if (check_win(board, player) || board[0][0] == board[0][1] && board[0][0] == board[0][2])
        {
            game_over = 1;
            printf("Player %d won!", player);
        }
        else if (board[1][0] == board[1][1] && board[1][0] == board[1][2] || board[2][0] == board[2][1] && board[2][0] == board[2][2])
        {
            game_over = 1;
            printf("Player %d won!", player);
        }
        else if (board[0][0] == board[1][0] && board[0][0] == board[2][0] || board[0][1] == board[1][1] && board[0][1] == board[2][1] || board[0][2] == board[1][2] && board[0][2] == board[2][2])
        {
            game_over = 1;
            printf("Player %d won!", player);
        }
        else if (board[0][0] == EMPTY_SPOT && board[0][1] == EMPTY_SPOT && board[0][2] == EMPTY_SPOT && board[1][0] == EMPTY_SPOT && board[1][1] == EMPTY_SPOT && board[1][2] == EMPTY_SPOT && board[2][0] == EMPTY_SPOT && board[2][1] == EMPTY_SPOT && board[2][2] == EMPTY_SPOT)
        {
            game_over = 1;
            printf("It's a draw!");
        }
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}

void display_board(int **board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void place_piece(int **board, int player)
{
    int row, col;

    printf("Enter row (1-3): ");
    scanf("%d", &row);

    printf("Enter column (1-3): ");
    scanf("%d", &col);

    if (board[row][col] != EMPTY_SPOT)
    {
        printf("Error: spot already taken.\n");
        return;
    }

    board[row][col] = player;
}

int check_win(int **board, int player)
{
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++)
    {
        if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == player)
    {
        return 1;
    }

    // Check if board is full
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == EMPTY_SPOT)
            {
                return 0;
            }
        }
    }

    return 0;
}