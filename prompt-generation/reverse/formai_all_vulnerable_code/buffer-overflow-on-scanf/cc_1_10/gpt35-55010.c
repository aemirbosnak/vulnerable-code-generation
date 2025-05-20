//FormAI DATASET v1.0 Category: Table Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
void drawBoard(char *board);
int checkWin(char *board, char player);
void playerMove(char *board, char player);
void computerMove(char *board, char player);
int getComputerMove(char *board);
int checkSpace(char *board, int move);

int main()
{
    // Variables
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int turn, move, playing = 1;

    printf("\nWelcome to Tic Tac Toe!\n\n");

    // Main Game Loop
    while (playing)
    {
        drawBoard(board);
        turn = 1;
        while (!checkWin(board, 'X') && !checkWin(board, 'O') && turn <= 9)
        {
            // Player Turn
            if (turn % 2 == 1)
            {
                playerMove(board, 'X');
            }
            // Computer Turn
            else
            {
                computerMove(board, 'O');
            }
            turn++;
        }

        drawBoard(board);

        // Game Over
        if (checkWin(board, 'X'))
        {
            printf("\nCongratulations! You win!\n");
        }
        else if (checkWin(board, 'O'))
        {
            printf("\nSorry, the computer wins.\n");
        }
        else
        {
            printf("\nNo winner. It's a tie.\n");
        }

        // Play Again?
        printf("\nWould you like to play again? (1 for yes, 0 for no): ");
        scanf("%d", &playing);
        if (playing)
        {
            // Reset Board
            for (int i = 0; i < 9; i++)
            {
                board[i] = '1' + i;
            }
        }
    }

    printf("\nThanks for playing Tic Tac Toe!\n");

    return 0;
}

// Draws tic tac toe board
void drawBoard(char *board)
{
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
}

// Checks for win
int checkWin(char *board, char player)
{
    // Row wins
    if ((board[0] == player && board[1] == player && board[2] == player) ||
        (board[3] == player && board[4] == player && board[5] == player) ||
        (board[6] == player && board[7] == player && board[8] == player))
    {
        return 1;
    }

    // Column wins
    if ((board[0] == player && board[3] == player && board[6] == player) ||
        (board[1] == player && board[4] == player && board[7] == player) ||
        (board[2] == player && board[5] == player && board[8] == player))
    {
        return 1;
    }

    // Diagonal wins
    if ((board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player))
    {
        return 1;
    }

    // No win
    return 0;
}

// Gets player move
void playerMove(char *board, char player)
{
    int move;
    printf("\n%s's turn.\nEnter a number from 1-9: ", (player == 'X' ? "Player" : "Computer"));
    scanf("%d", &move);
    move--;

    if (checkSpace(board, move))
    {
        board[move] = player;
    }
    else
    {
        printf("\n%s that space is already taken. Please try again.\n", (player == 'X' ? "Player," : "Computer,"));
        playerMove(board, player);
    }
}

// Gets computer move
void computerMove(char *board, char player)
{
    int move = getComputerMove(board);
    board[move] = player;
}

// Gets computer's move choice
int getComputerMove(char *board)
{
    int corners[] = {0, 2, 6, 8};
    int sides[] = {1, 3, 5, 7};
    int i, move;

    // Check for win
    for (i = 0; i < 9; i++)
    {
        if (checkSpace(board, i))
        {
            board[i] = 'O';
            if (checkWin(board, 'O'))
            {
                return i;
            }
            else
            {
                board[i] = '1' + i;
            }
        }
    }

    // Check for blocking player win
    for (i = 0; i < 9; i++)
    {
        if (checkSpace(board, i))
        {
            board[i] = 'X';
            if (checkWin(board, 'X'))
            {
                return i;
            }
            else
            {
                board[i] = '1' + i;
            }
        }
    }

    // Choose random corner
    srand(time(NULL));
    for (i = 0; i < 4; i++)
    {
        move = corners[rand() % 4];
        if (checkSpace(board, move))
        {
            return move;
        }
    }

    // Choose random side
    for (i = 0; i < 4; i++)
    {
        move = sides[rand() % 4];
        if (checkSpace(board, move))
        {
            return move;
        }
    }

    // Computer cannot move
    return -1;
}

// Checks if space is open
int checkSpace(char *board, int move)
{
    if (board[move] == 'X' || board[move] == 'O')
    {
        return 0;
    }

    return 1;
}