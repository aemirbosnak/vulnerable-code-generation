//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Ada Lovelace
#include <stdio.h>

 char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void display_board()
{
    printf("\n");
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(j < 2)
            {
                printf(" %c |", board[i][j]);
            }
            else
            {
                printf(" %c ", board[i][j]);
            }
        }
        if(i < 2)
        {
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
}

int check_vertical(char player)
{
    for(int i=0; i<3; i++)
    {
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return 1;
        }
    }
    return 0;
}

int check_horizontal(char player)
{
    for(int i=0; i<3; i++)
    {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return 1;
        }
    }
    return 0;
}

int check_diagonal(char player)
{
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return 1;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return 1;
    }
    return 0;
}

int is_winner(char player)
{
    if(check_vertical(player) || check_horizontal(player) || check_diagonal(player))
    {
        return 1;
    }
    return 0;
}

int is_board_full()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

void play_game()
{
    int row, col, invalid_move;
    char player = 'X';
    printf("Welcome to Tic Tac Toe!\n");
    while(1)
    {
        invalid_move = 0;
        display_board();
        printf("%c's turn. Enter row (1-3) and column (1-3) separated by space: ", player);
        scanf("%d %d", &row, &col);
        row--;
        col--;
        if(board[row][col] == ' ')
        {
            board[row][col] = player;
            if(is_winner(player))
            {
                printf("%c wins!\n", player);
                display_board();
                break;
            }
            if(is_board_full())
            {
                printf("Board is full! The game is drawn.\n");
                display_board();
                break;
            }
            player = (player == 'X') ? 'O' : 'X';
        }
        else
        {
            printf("Invalid move. Try again.\n");
            invalid_move = 1;
        }
    }
}

int main()
{
    play_game();
    return 0;
}