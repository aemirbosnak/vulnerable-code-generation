//FormAI DATASET v1.0 Category: Table Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare constants
#define ROWS 3
#define COLS 3

// Declare functions
void initializeBoard(char board[ROWS][COLS]);
void printBoard(char board[ROWS][COLS]);
int checkWin(char board[ROWS][COLS], char symbol);

// Main function
int main()
{
    char board[ROWS][COLS];     // Declare the board
    char playerSymbol = 'X';    // Set player symbol to X
    char computerSymbol = 'O';  // Set computer symbol to O
    int turn = 0;               // Keep track of whose turn it is
    int row, col;               // Keep track of user input

    srand(time(0));             // Set seed for random number generator

    initializeBoard(board);     // Initialize the board with empty cells

    // Loop until someone wins or the board is full
    while (!checkWin(board, playerSymbol) && !checkWin(board, computerSymbol) && turn < 9)
    {
        system("clear");        // Clear the console

        // Print out the board
        printf("Here is the current board:\n\n");
        printBoard(board);
        printf("\n");

        // Player's turn
        if (turn % 2 == 0)
        {
            printf("It is your turn. Please enter the row and column numbers of your move.\n");
            printf("Row (1-3): ");
            scanf("%d", &row);
            printf("Column (1-3): ");
            scanf("%d", &col);

            // Convert user input from 1-indexed to 0-indexed
            row--;
            col--;

            // Check if cell is empty
            if (board[row][col] != ' ')
            {
                printf("That cell is already occupied. Please try again.\n");
                continue;
            }

            // Make the move
            board[row][col] = playerSymbol;
        }
        // Computer's turn
        else
        {
            printf("It is the computer's turn.\n");

            // Generate random row and column numbers
            row = rand() % ROWS;
            col = rand() % COLS;

            // Check if cell is empty
            while (board[row][col] != ' ')
            {
                row = rand() % ROWS;
                col = rand() % COLS;
            }

            // Make the move
            board[row][col] = computerSymbol;
        }

        turn++;
    }

    system("clear");                // Clear the console

    // Print out the final board
    printf("Here is the final board:\n\n");
    printBoard(board);
    printf("\n");

    // Check who won, if anyone
    if (checkWin(board, playerSymbol))
    {
        printf("Congratulations, you won!\n");
    }
    else if (checkWin(board, computerSymbol))
    {
        printf("Sorry, the computer won. Better luck next time.\n");
    }
    else
    {
        printf("It's a tie!\n");
    }

    return 0;
}

// Initialize the board with empty cells
void initializeBoard(char board[ROWS][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// Print out the board
void printBoard(char board[ROWS][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != ROWS-1)
        {
            printf("\n-----------\n");
        }
    }
}

// Check if someone has won
int checkWin(char board[ROWS][COLS], char symbol)
{
    int i;

    // Check rows
    for (i = 0; i < ROWS; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == symbol)
        {
            return 1;
        }
    }

    // Check columns
    for (i = 0; i < COLS; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == symbol)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == symbol)
    {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] == symbol)
    {
        return 1;
    }

    return 0;
}