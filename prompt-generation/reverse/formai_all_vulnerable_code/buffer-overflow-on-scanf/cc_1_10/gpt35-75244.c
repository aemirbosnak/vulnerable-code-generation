//FormAI DATASET v1.0 Category: Table Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

char board[3][3]; // Tic-tac-toe board

void initialize_board()
{
    int i, j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void print_board()
{
    int i, j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
            if(j != 2) printf("|");
        }
        printf("\n");
        if(i != 2) printf("---|---|---\n");
    }
}

int check_winner(char p)
{
    int i, j;

    // Check rows
    for(i = 0; i < 3; i++)
    {
        if(board[i][0] == p && board[i][1] == p && board[i][2] == p)
        {
            return 1;
        }
    }

    // Check columns
    for(i = 0; i < 3; i++)
    {
        if(board[0][i] == p && board[1][i] == p && board[2][i] == p)
        {
            return 1;
        }
    }

    // Check diagonals
    if(board[0][0] == p && board[1][1] == p && board[2][2] == p)
    {
        return 1;
    }

    if(board[2][0] == p && board[1][1] == p && board[0][2] == p)
    {
        return 1;
    }

    return 0;
}

int make_move(int row, int col, char p)
{
    // Check if the move is valid
    if(row < 0 || row > 2 || col < 0 || col > 2)
    {
        printf("\nInvalid move!\n");
        return 0;
    }

    if(board[row][col] != ' ')
    {
        printf("\nPosition already taken!\n");
        return 0;
    }

    board[row][col] = p;
    return 1;
}

int main()
{
    int player, row, col, move_ok, moves = 0;

    printf("Welcome to Tic Tac Toe!\n");

    initialize_board();
    print_board();

    printf("Player 1: X\nPlayer 2: O\n");

    while(moves < 9)
    {
        player = moves % 2 + 1;

        printf("\nPlayer %d, enter row and column: ", player);
        scanf("%d %d", &row, &col);

        move_ok = make_move(row, col, player == 1 ? 'X' : 'O');

        if(!move_ok)
        {
            continue;
        }

        print_board();

        if(check_winner(player == 1 ? 'X' : 'O'))
        {
            printf("Player %d wins!\n", player);
            return 0;
        }

        moves++;
    }

    printf("\nIt's a tie!\n");
    return 0;
}