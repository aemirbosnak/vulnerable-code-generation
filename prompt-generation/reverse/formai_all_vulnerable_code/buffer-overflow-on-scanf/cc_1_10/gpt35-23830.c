//FormAI DATASET v1.0 Category: Table Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Function prototypes*/
void printBoard(char board[][3]);
int checkWinner(char board[][3]);
void playerTurn(char board[][3], int player);
void computerTurn(char board[][3], int player);

int main()
{
    char board[3][3] = {{'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'}};
    int player = 1;
    int winner = 0;
    int again = 1;

    printf("Welcome to the C Table Game!\n");
    printf("You will be playing against the computer.\n");
    printf("You are X, and the computer is O.\n");
    
    while(again == 1)
    {
        player = 1;
        winner = 0;

        /*Print starting board*/
        printBoard(board);

        while(winner == 0)
        {
            /*Player's turn*/
            if(player == 1)
            {
                playerTurn(board, player);
                winner = checkWinner(board);
                if(winner != 0)
                {
                    break;
                }
                player = 2;
                printf("Computer's turn:\n");
            }

            /*Computer's turn*/
            if(player == 2)
            {
                computerTurn(board, player);
                winner = checkWinner(board);
                if(winner != 0)
                {
                    break;
                }
                player = 1;
                printf("Your turn:\n");
            }

            /*Print current board*/
            printBoard(board);
        }

        /*Print end of game message*/
        if(winner == 1)
        {
            printf("Congratulations! You win!\n");
        }
        else if(winner == 2)
        {
            printf("Sorry, the computer wins.\n");
        }
        else
        {
            printf("It's a tie!\n");
        }

        printf("Play again? (1 = yes, 0 = no): ");
        scanf("%d", &again);
    }

    printf("Thanks for playing!\n");
    return 0;
}

/*Print the tic-tac-toe board*/
void printBoard(char board[][3])
{
    printf("\n");
    printf("   1   2   3\n");
    printf("1  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("  ---|---|---\n");
    printf("2  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("  ---|---|---\n");
    printf("3  %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

/*Check if there is a winner*/
int checkWinner(char board[][3])
{
    int i, j;

    /*Check rows*/
    for(i = 0; i < 3; i++)
    {
        if((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))
        {
            if(board[i][0] == 'X')
            {
                return 1;
            }
            else if(board[i][0] == 'O')
            {
                return 2;
            }
        }
    }

    /*Check columns*/
    for(j = 0; j < 3; j++)
    {
        if((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]))
        {
            if(board[0][j] == 'X')
            {
                return 1;
            }
            else if(board[0][j] == 'O')
            {
                return 2;
            }
        }
    }

    /*Check diagonals*/
    if((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
    {
        if(board[0][0] == 'X')
        {
            return 1;
        }
        else if(board[0][0] == 'O')
        {
            return 2;
        }
    }

    if((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))
    {
        if(board[0][2] == 'X')
        {
            return 1;
        }
        else if(board[0][2] == 'O')
        {
            return 2;
        }
    }

    /*Check for tie*/
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(board[i][j] == '_')
            {
                return 0; /*Game is not over yet*/
            }
        }
    }
    return 3; /*Tie game*/
}

/*Get the player's move*/
void playerTurn(char board[][3], int player)
{
    int row, col;

    printf("Your turn (enter row and column): ");
    scanf("%d %d", &row, &col);

    if(board[row-1][col-1] != '_')
    {
        printf("Invalid move, try again.\n");
        playerTurn(board, player);
    }
    else
    {
        board[row-1][col-1] = 'X';
    }
}

/*Get the computer's move*/
void computerTurn(char board[][3], int player)
{
    int row, col;

    /*Seed the random number generator*/
    srand(time(NULL));

    /*Find an empty cell*/
    do
    {
        row = rand() % 3;
        col = rand() % 3;
    }
    while(board[row][col] != '_');

    board[row][col] = 'O';
}