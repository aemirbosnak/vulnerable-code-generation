//FormAI DATASET v1.0 Category: Checkers Game ; Style: Claude Shannon
// C Checkers Game Program
// Inspired by Claude Shannon, Father of Modern Information Theory

#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void initialize_board(int board[SIZE][SIZE]);
void print_board(int board[SIZE][SIZE]);
void make_move(int board[SIZE][SIZE], int move[4]);
int check_valid_move(int board[SIZE][SIZE], int move[4]);
int check_single_move(int board[SIZE][SIZE], int move[4]);
int check_double_move(int board[SIZE][SIZE], int move[4]);
int check_jump_move(int board[SIZE][SIZE], int move[4]);

int main()
{
    int board[SIZE][SIZE];
    int move[4];
    int turn = 1;

    initialize_board(board);

    while (1)
    {
        printf("\n\n");
        print_board(board);

        if (turn == 1)
            printf("Player 1 (Red) make a move: ");
        else
            printf("Player 2 (Black) make a move: ");

        scanf("%d %d %d %d", &move[0], &move[1], &move[2], &move[3]);

        if (check_valid_move(board, move))
        {
            make_move(board, move);
            turn = (turn == 1) ? 2 : 1;
        }
        else
            printf("Invalid move. Try again.\n");
    }

    return 0;
}

void initialize_board(int board[SIZE][SIZE])
{
    int i, j;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if ((i + j) % 2 == 0)
            {
                if (i < 3)
                    board[i][j] = 1;
                else if (i > 4)
                    board[i][j] = 2;
                else
                    board[i][j] = 0;
            }
            else
                board[i][j] = 0;
        }
    }
}

void print_board(int board[SIZE][SIZE])
{
    int i, j;

    printf("  0 1 2 3 4 5 6 7\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", i);
        for (j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 1)
                printf("R ");
            else if (board[i][j] == 2)
                printf("B ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

void make_move(int board[SIZE][SIZE], int move[4])
{
    int piece = board[move[0]][move[1]];
    board[move[0]][move[1]] = 0;
    board[move[2]][move[3]] = piece;
}

int check_valid_move(int board[SIZE][SIZE], int move[4])
{
    if (move[0] < 0 || move[0] >= SIZE || move[1] < 0 || move[1] >= SIZE || 
        move[2] < 0 || move[2] >= SIZE || move[3] < 0 || move[3] >= SIZE ||
        board[move[0]][move[1]] == 0)
        return 0;

    if (board[move[2]][move[3]] != 0)
        return 0;

    if (board[move[0]][move[1]] == 1 && move[2] >= move[0])
        return 0;

    if (board[move[0]][move[1]] == 2 && move[2] <= move[0])
        return 0;

    if (check_single_move(board, move) || check_double_move(board, move) || check_jump_move(board, move))
        return 1;

    return 0;
}

int check_single_move(int board[SIZE][SIZE], int move[4])
{
    int piece = board[move[0]][move[1]];
    int diff_row = move[2] - move[0];
    int diff_col = move[3] - move[1];

    if (piece == 1)
    {
        if (diff_row == 1 && abs(diff_col) == 1)
            return 1;
    }
    else if (piece == 2)
    {
        if (diff_row == -1 && abs(diff_col) == 1)
            return 1;
    }

    return 0;
}

int check_double_move(int board[SIZE][SIZE], int move[4])
{
    int piece = board[move[0]][move[1]];
    int diff_row = move[2] - move[0];
    int diff_col = move[3] - move[1];
    int middle_row = (move[0] + move[2]) / 2;
    int middle_col = (move[1] + move[3]) / 2;

    if (piece == 1)
    {
        if (diff_row == 2 && abs(diff_col) == 2 && board[middle_row][middle_col] == 2)
            return 1;
    }
    else if (piece == 2)
    {
        if (diff_row == -2 && abs(diff_col) == 2 && board[middle_row][middle_col] == 1)
            return 1;
    }

    return 0;
}

int check_jump_move(int board[SIZE][SIZE], int move[4])
{
    int piece = board[move[0]][move[1]];
    int diff_row = move[2] - move[0];
    int diff_col = move[3] - move[1];
    int middle_row = (move[0] + move[2]) / 2;
    int middle_col = (move[1] + move[3]) / 2;

    if (piece == 1)
    {
        if (diff_row == 2 && abs(diff_col) == 2 && board[middle_row][middle_col] == 2)
            return 1;
    }
    else if (piece == 2)
    {
        if (diff_row == -2 && abs(diff_col) == 2 && board[middle_row][middle_col] == 1)
            return 1;
    }

    return 0;
}