//FormAI DATASET v1.0 Category: Table Game ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void draw_board(char board[][3]);
int check_win(char board[][3], char player, int row, int col);

int main()
{
    char board[3][3] = {' ',' ',' ',
                        ' ',' ',' ',
                        ' ',' ',' '};
    int row, col, count = 0, player = 1, win = 0;
    draw_board(board);

    while(count < 9 && !win)
    {
        if(player%2 != 0)
        {
            printf("Player 1's turn: ");
        }
        else
        {
            printf("Player 2's turn: ");
        }

        scanf("%d %d", &row, &col);

        while(board[row][col] != ' ')
        {
            printf("That spot is taken. Choose again: ");
            scanf("%d %d", &row, &col);
        }

        if(player%2 != 0)
        {
            board[row][col] = 'X';
            if(check_win(board, 'X', row, col))
            {
                printf("Player 1 wins!\n");
                win = 1;
            }
        }
        else
        {
            board[row][col] = 'O';
            if(check_win(board, 'O', row, col))
            {
                printf("Player 2 wins!\n");
                win = 1;
            }
        }

        draw_board(board);
        player++;
        count++;
    }

    if(!win)
    {
        printf("It's a tie game! \n");
    }
    return 0;
}

void draw_board(char board[][3])
{
    printf("-------------\n");
    printf("| %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
    printf("-------------\n");
    printf("| %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
    printf("-------------\n");
    printf("| %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
    printf("-------------\n");
}

int check_win(char board[][3], char player, int row, int col)
{
    int row_count = 0, col_count = 0, diag1_count = 0, diag2_count = 0;

    //checks rows
    for(int i = 0; i < 3; i++)
    {
        if(board[row][i] == player)
        {
            row_count++;
        }
    }

    if(row_count == 3)
    {
        return 1;
    }

    //checks cols
    for(int i = 0; i < 3; i++)
    {
        if(board[i][col] == player)
        {
            col_count++;
        }
    }

    if(col_count == 3)
    {
        return 1;
    }

    //checks diagonal from top left to bottom right
    if(row == col)
    {
        for(int i = 0; i < 3; i++)
        {
            if(board[i][i] == player)
            {
                diag1_count++;
            }
        }

        if(diag1_count == 3)
        {
            return 1;
        }
    }

    //checks diagonal from top right to bottom left
    if(row + col == 2)
    {
        for(int i = 0; i < 3; i++)
        {
            if(board[i][2-i] == player)
            {
                diag2_count++;
            }
        }

        if(diag2_count == 3)
        {
            return 1;
        }
    }
    return 0;
}