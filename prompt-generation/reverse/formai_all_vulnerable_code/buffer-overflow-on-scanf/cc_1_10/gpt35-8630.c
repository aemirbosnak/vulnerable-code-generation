//FormAI DATASET v1.0 Category: Table Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setup_game(int board[3][3])
{
    // initialize the game board with 0s
    for(int row=0; row<3; row++)
    {
        for(int col=0; col<3; col++)
        {
            board[row][col] = 0;
        }
    }
}

void print_board(int board[3][3])
{
    printf("   1   2   3  \n");   // column numbers
    printf("1  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("  ---+---+--- \n");
    printf("2  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("  ---+---+--- \n");
    printf("3  %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int player_move(int board[3][3], int player)
{
    int row, col;

    // get player's move
    printf("Player %d's move\n", player);
    printf("Enter row number (1-3): ");
    scanf("%d", &row);
    printf("Enter column number (1-3): ");
    scanf("%d", &col);

    // check if move is valid
    if(row < 1 || row > 3 || col < 1 || col > 3)
    {
        printf("Invalid move. Try again.\n");
        return 0;  // move unsuccessful
    }
    if(board[row-1][col-1] != 0)
    {
        printf("That spot is already taken. Try again.\n");
        return 0;  // move unsuccessful
    }

    // update game board
    board[row-1][col-1] = (player == 1) ? 'X' : 'O';

    return 1;   // move successful
}

int check_win(int board[3][3])
{
    // check rows for win
    for(int row=0; row<3; row++)
    {
        if(board[row][0] != 0 && board[row][0] == board[row][1] && board[row][0] == board[row][2])
        {
            return 1;
        }
    }

    // check columns for win
    for(int col=0; col<3; col++)
    {
        if(board[0][col] != 0 && board[0][col] == board[1][col] && board[0][col] == board[2][col])
        {
            return 1;
        }
    }

    // check diagonals for win
    if(board[0][0] != 0 && board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return 1;
    }
    if(board[0][2] != 0 && board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return 1;
    }

    // check for tie game
    for(int row=0; row<3; row++)
    {
        for(int col=0; col<3; col++)
        {
            if(board[row][col] == 0)
            {
                return 0;  // game is not over yet
            }
        }
    }

    return -1;  // tie game
}

int main()
{
    int board[3][3];
    int player = 1;
    int move_successful = 0;
    int game_over = 0;
    int win_player = 0;

    setup_game(board);

    printf("Welcome to the peaceful Tic Tac Toe Game!\n");

    while(!game_over)
    {
        print_board(board);

        // get player's move and update board
        while(!move_successful)
        {
            move_successful = player_move(board, player);
        }

        // check if game is over
        win_player = check_win(board);
        if(win_player)
        {
            game_over = 1;
        }
        else if(win_player == -1)
        {
            printf("The game ends in a tie.\n");
            game_over = 1;
        }
        else  // game continues
        {
            // switch players
            player = (player == 1) ? 2 : 1;
            move_successful = 0;
        }
    }

    print_board(board);

    if(win_player == 1)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }

    return 0;
}