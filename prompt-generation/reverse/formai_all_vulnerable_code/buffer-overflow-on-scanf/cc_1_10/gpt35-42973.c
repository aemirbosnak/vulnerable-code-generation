//FormAI DATASET v1.0 Category: Table Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void initBoard(int board[][3]);
void printBoard(int board[][3]);
int checkWinner(int board[][3]);

int main()
{
    int board[3][3];
    int player = 1, winner = 0;
    int row, col;

    // initialize the board
    initBoard(board);

    // show the initial board
    printBoard(board);

    // play until there's a winner or the board is full
    while (winner == 0)
    {
        // get the row and column input from the player
        printf("Player %d, enter a row (1-3): ", player);
        scanf("%d", &row);
        printf("Player %d, enter a column (1-3): ", player);
        scanf("%d", &col);

        // check if the input is valid
        if (row < 1 || row > 3 || col < 1 || col > 3)
        {
            printf("Invalid input, please try again.\n");
            continue;
        }

        // check if the cell is already taken
        if (board[row-1][col-1] != 0)
        {
            printf("That cell is already taken, please try again.\n");
            continue;
        }

        // mark the cell with the player's symbol
        board[row-1][col-1] = player;

        // show the updated board
        printBoard(board);

        // check for a winner
        winner = checkWinner(board);

        // switch to the other player
        if (player == 1)
            player = 2;
        else
            player = 1;
    }

    // show the winner
    printf("Player %d wins!\n", winner);

    return 0;
}

void initBoard(int board[][3])
{
    int i, j;

    // seed the random number generator
    srand(time(NULL));

    // initialize the board with random values (0 or 1)
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            board[i][j] = rand() % 2;
        }
    }
}

void printBoard(int board[][3])
{
    int i, j;

    // print the board
    printf("\n  1 2 3\n");
    for (i = 0; i < 3; i++)
    {
        printf("%d ", i+1);
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] == 0)
                printf("- ");
            else if (board[i][j] == 1)
                printf("X ");
            else
                printf("O ");
        }
        printf("\n");
    }
}

int checkWinner(int board[][3])
{
    int i, j;

    // check rows
    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
    }

    // check columns
    for (j = 0; j < 3; j++)
    {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return board[0][j];
    }

    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    // no winner yet
    return 0;
}