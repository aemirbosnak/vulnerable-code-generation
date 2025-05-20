//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Function declaration
void print_board(char board[3][3]);
int make_move(char board[3][3], char player);
int check_win(char board[3][3], char player);

// Main function
int main()
{
    // Initializing variables
    char player = 'X';
    char board[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
    int moves = 0;

    // Game loop
    while (moves < 9)
    {
        // Printing board
        printf("Player %c's turn\n", player);
        print_board(board);

        // Getting player move
        int move = make_move(board, player);

        // Checking for win
        if (check_win(board, player))
        {
            printf("Player %c wins!\n", player);
            return 0;
        }

        // Switching player and incrementing moves
        player = player == 'X' ? 'O' : 'X';
        moves++;
    }

    // Tie game
    printf("Tie game!\n");
    return 0;
}

// Function to print the game board
void print_board(char board[3][3])
{
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

// Function to make a move
int make_move(char board[3][3], char player)
{
    // Initializing variables
    int row, col;

    // Getting player move
    printf("Enter row and column (e.g. 1 2): ");
    scanf("%d %d", &row, &col);

    // Checking for valid move
    if (row < 1 || row > 3 || col < 1 || col > 3)
    {
        printf("Invalid move! Try again.\n");
        return make_move(board, player);
    }
    else if (board[row-1][col-1] != '-')
    {
        printf("Invalid move! Try again.\n");
        return make_move(board, player);
    }
    else
    {
        board[row-1][col-1] = player;
        return 1;
    }
}

// Function to check for win
int check_win(char board[3][3], char player)
{
    // Checking rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return 1;
        }
    }

    // Checking columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
        {
            return 1;
        }
    }

    // Checking diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return 1;
    }
    else if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return 1;
    }

    // No win
    return 0;
}