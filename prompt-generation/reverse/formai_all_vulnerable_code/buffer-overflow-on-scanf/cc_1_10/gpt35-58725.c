//FormAI DATASET v1.0 Category: Memory Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void initializeBoard(int board[MAX_SIZE][MAX_SIZE], int size);
void printBoard(int board[MAX_SIZE][MAX_SIZE], int size);
void shuffleBoard(int board[MAX_SIZE][MAX_SIZE], int size);
void copyBoard(int boardA[MAX_SIZE][MAX_SIZE], int boardB[MAX_SIZE][MAX_SIZE], int size);
int checkIfWon(int board[MAX_SIZE][MAX_SIZE], int size);

int main()
{
    // initialize the board game
    int size;
    int board[MAX_SIZE][MAX_SIZE];
    printf("Enter the size of the board game: ");
    scanf("%d", &size);
    initializeBoard(board, size);

    // shuffle the board game
    srand(time(NULL));
    shuffleBoard(board, size);

    // game loop
    int gameOver = 0;
    int numMoves = 0;
    int prevMoveRow = -1;
    int prevMoveCol = -1;
    int row, col;
    while (!gameOver)
    {
        printBoard(board, size);
        printf("Enter row and col to flip (separated by a space): ");
        scanf("%d %d", &row, &col);

        // validate input
        if (row < 0 || row >= size || col < 0 || col >= size)
        {
            printf("Invalid input. Please try again.\n");
            continue;
        }
        if (row == prevMoveRow && col == prevMoveCol)
        {
            printf("This card was already flipped. Please try again.\n");
            continue;
        }
        prevMoveRow = row;
        prevMoveCol = col;

        // flip the card and check for a match
        numMoves++;
        board[row][col] *= -1;
        printBoard(board, size);
        if (numMoves % 2 == 0)
        {
            if (board[row][col] == board[prevMoveRow][prevMoveCol])
            {
                printf("You found a match!\n");
            }
            else
            {
                printf("No match. Flipping cards back over.\n");
                board[row][col] *= -1;
                board[prevMoveRow][prevMoveCol] *= -1;
                printBoard(board, size);
            }
        }

        // check if the game is won
        gameOver = checkIfWon(board, size);
    }
    printf("Congratulations! You won in %d moves!\n", numMoves);

    return 0;
}

// initializes the board game with random numbers from 1 to size^2
void initializeBoard(int board[MAX_SIZE][MAX_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = (i * size + j + 1) / 2;
        }
    }
}

// prints the board game
void printBoard(int board[MAX_SIZE][MAX_SIZE], int size)
{
    printf("  ");
    for (int j = 0; j < size; j++)
    {
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] < 0)
            {
                printf("X ");
            }
            else
            {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

// shuffles the board game by swapping random pairs of cards
void shuffleBoard(int board[MAX_SIZE][MAX_SIZE], int size)
{
    for (int i = 0; i < size * size; i++)
    {
        int row1 = rand() % size;
        int col1 = rand() % size;
        int row2 = rand() % size;
        int col2 = rand() % size;

        int temp = board[row1][col1];
        board[row1][col1] = board[row2][col2];
        board[row2][col2] = temp;
    }
}

// copies the contents of boardA to boardB
void copyBoard(int boardA[MAX_SIZE][MAX_SIZE], int boardB[MAX_SIZE][MAX_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            boardB[i][j] = boardA[i][j];
        }
    }
}

// checks if the game is won (i.e. all cards are flipped over)
int checkIfWon(int board[MAX_SIZE][MAX_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] > 0)
            {
                return 0;
            }
        }
    }
    return 1;
}