//FormAI DATASET v1.0 Category: Memory Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h> // required for rand() and srand()
#include <time.h>   // required for time()

#define BOARD_SIZE 4
#define MAX_MOVES BOARD_SIZE * BOARD_SIZE

// Function to initialise the game board with random numbers
void initialiseGameBoard(int gameBoard[BOARD_SIZE][BOARD_SIZE])
{
    srand(time(NULL));  // initialise random number generator with system clock
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++)
        for (j = 0; j < BOARD_SIZE; j++)
            gameBoard[i][j] = rand() % 100 + 1;  // assign a random number between 1 and 100
}

// Function to display the game board
void displayGameBoard(int gameBoard[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
            printf("%3d ", gameBoard[i][j]);
        printf("\n");
    }
}

// Function to check if the moves are valid and to swap the values
int makeMove(int gameBoard[BOARD_SIZE][BOARD_SIZE], int move1Row, int move1Col, int move2Row, int move2Col)
{
    // Check if the moves are adjacent and within the game board boundaries
    if (((abs(move1Row - move2Row) == 1) && (move1Col == move2Col)) || ((abs(move1Col - move2Col) == 1) && (move1Row == move2Row)))
    {
        // Swap the values at the two moves' positions
        int temp = gameBoard[move1Row][move1Col];
        gameBoard[move1Row][move1Col] = gameBoard[move2Row][move2Col];
        gameBoard[move2Row][move2Col] = temp;
        return 1; // Move successful
    }
    else
        return 0; // Invalid move
}

int main()
{
    int gameBoard[BOARD_SIZE][BOARD_SIZE];
    initialiseGameBoard(gameBoard);
    displayGameBoard(gameBoard);
    int movesMade = 0;
    while (movesMade < MAX_MOVES)
    {
        int move1Row, move1Col, move2Row, move2Col;
        printf("Enter the Row and Column of the first move (separated by spaces): ");
        scanf("%d %d", &move1Row, &move1Col);
        printf("Enter the Row and Column of the second move (separated by spaces): ");
        scanf("%d %d", &move2Row, &move2Col);
        if (makeMove(gameBoard, move1Row, move1Col, move2Row, move2Col))
        {
            printf("Move successful.\n");
            displayGameBoard(gameBoard);
            movesMade++;
        }
        else
            printf("Invalid move. Please enter valid moves.\n");
    }
    printf("Game over. All moves made.\n");
    displayGameBoard(gameBoard);
    return 0;
}