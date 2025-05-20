//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: portable
#include <stdio.h>

int win_check(char board[3][3], char player)
{
    // Check rows for a win
    int i, j, row_win, col_win, diag_win1 = 1, diag_win2 = 1;
    for(i = 0; i < 3; i++)
    {
        row_win = 1; col_win = 1;
        for(j = 0; j < 3; j++)
        {
            if(board[i][j] != player) row_win = 0;
            if(board[j][i] != player) col_win = 0;
        }
        if(row_win || col_win) return 1;
        if(board[i][i] != player) diag_win1 = 0;
        if(board[i][2-i] != player) diag_win2 = 0;
    }
    if(diag_win1 || diag_win2) return 1;
    return 0;
}

void print_board(char board[3][3])
{
    printf("\n");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
            if(j < 2) printf("|");
        }
        if(i < 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

void tictactoe()
{
    char board[3][3];
    char player1 = 'X';
    char player2 = 'O';
    int turn = 0; // Even turns -> player 1, odd turns -> player 2
    int row, col, valid_move;
    // Initialize board with empty spaces
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
    printf("Let's play!\n");
    print_board(board);
    while(turn < 9)
    {
        valid_move = 0;
        while(!valid_move)
        {
            printf("Player %d's turn (%c):\n", turn%2+1, turn%2 ? player2 : player1);
            printf("Enter a row (1-3): ");
            scanf("%d", &row);
            printf("Enter a column (1-3): ");
            scanf("%d", &col);
            // Check if coordinates are valid
            if(row < 1 || row > 3 || col < 1 || col > 3)
            {
                printf("Invalid coordinates. Try again.\n");
            }
            else if(board[row-1][col-1] != ' ')
            {
                printf("That space is already taken. Try again.\n");
            }
            else
            {
                valid_move = 1;
            }
        }
        // Update board
        board[row-1][col-1] = turn%2 ? player2 : player1;
        print_board(board);
        // Check for win
        if(win_check(board, turn%2 ? player2 : player1))
        {
            printf("Player %d wins!\n", turn%2+1);
            return;
        }
        turn++;
    }
    printf("It's a tie!\n");
}

int main()
{
    tictactoe();
    return 0;
}