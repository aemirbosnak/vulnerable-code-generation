//FormAI DATASET v1.0 Category: Table Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

// Function to display the Tic Tac Toe board
void display_board(char board[][COLS])
{
    printf("\n\t\t\t  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t\t\t----+---+----\n");
    printf("\t\t\t  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t\t\t----+---+----\n");
    printf("\t\t\t  %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);
}

// Function to check if the game has been won
int check_win(char board[][COLS], char player)
{
    int i, j;

    // check diagonal
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) 
        || (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return 1;
    }

    // check rows
    for (i = 0; i < ROWS; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return 1;
        }
    }

    // check columns
    for (j = 0; j < COLS; j++)
    {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
        {
            return 1;
        }
    }

    return 0;
}

// Function to check if the game ended in a tie
int check_tie(char board[][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }

    return 1;
}

int main()
{
    char board[ROWS][COLS];
    int row, col, player = 1, winner = 0, choice, num_turns = 0;

    srand(time(NULL)); // for randomly selecting player turn
    
    // Initialize the board with empty spaces
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            board[row][col] = ' ';
        }
    }

    printf("\n\t\t\t TIC TAC TOE \n\n");
    printf("\t\t\t Player 1 (X) - Player 2 (O) \n\n");

    display_board(board);

    while (num_turns < ROWS * COLS)
    {
        player = rand() % 2 + 1; // randomly select player turn
        printf("Player %d, enter a number between 1 and 9 to make your move: ", player);
        scanf("%d", &choice);

        row = (choice - 1) / ROWS;
        col = (choice - 1) % COLS;

        if (board[row][col] != ' ')
        {
            printf("That cell is already taken.\n");
            continue; // go back to while loop
        }

        if (player == 1)
        {
            board[row][col] = 'X';
        }
        else
        {
            board[row][col] = 'O';
        }

        display_board(board);

        winner = check_win(board, board[row][col]);

        if (winner)
        {
            printf("Congratulations! Player %d wins!\n", player);
            break; // exit while loop
        }

        num_turns++;

        if (check_tie(board))
        {
            printf("Game ended in a tie.\n");
            break; // exit while loop
        }
    }

    return 0;
}