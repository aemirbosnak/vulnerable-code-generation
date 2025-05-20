//FormAI DATASET v1.0 Category: Memory Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_GUESSES 16

/* Function Prototypes */
void printBoard(char board[][COLS]);
void fillBoard(char board[][COLS]);
void shuffleBoard(char board[][COLS]);
void getPlayerGuess(char board[][COLS], int* row, int* col);
void updateBoard(char board[][COLS], int row1, int col1, int row2, int col2);
int checkForMatch(char board[][COLS], int row1, int col1, int row2, int col2);

int main()
{
    char board[ROWS][COLS];
    int row1, col1, row2, col2, guesses = 0;
    
    srand(time(NULL));
    fillBoard(board);
    shuffleBoard(board);
    
    printf("Welcome to the Memory Game!\n");
    printf("Try to match all the letters in the least amount of guesses.\n\n");
    
    while(guesses < MAX_GUESSES)
    {
        printBoard(board);
        getPlayerGuess(board, &row1, &col1);
        getPlayerGuess(board, &row2, &col2);
        
        if(checkForMatch(board, row1, col1, row2, col2))
        {
            printf("Congratulations! You found a match!\n\n");
            updateBoard(board, row1, col1, row2, col2);
        }
        else
        {
            printf("Sorry, those two cards do not match.\n\n");
        }
        
        guesses++;
    }
    
    printf("Game over! You took %d guesses.\n", guesses);
    
    return 0;
}

void printBoard(char board[][COLS])
{
    printf("\n");
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/* Function to fill the board with random letters */
void fillBoard(char board[][COLS])
{
    char letters[] = {'A','B','C','D','E','F','G','H'};

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            board[i][j] = letters[(i * 4) + j];
        }
    }
}

/* Function to shuffle the board */
void shuffleBoard(char board[][COLS])
{
    for(int i = 0; i < ROWS*COLS; i++)
    {
        int r1 = rand() % ROWS;
        int c1 = rand() % COLS;
        int r2 = rand() % ROWS;
        int c2 = rand() % COLS;
        
        char temp = board[r1][c1];
        board[r1][c1] = board[r2][c2];
        board[r2][c2] = temp;
    }
}

/* Function to get player guess */
void getPlayerGuess(char board[][COLS], int* row, int* col)
{
    do
    {
        printf("Enter row and column of your guess (ex. 1 2): ");
        scanf("%d %d", row, col);
    } while(*row < 1 || *row > ROWS || *col < 1 || *col > COLS || board[*row-1][*col-1] == '*');
    
    *row -= 1;
    *col -= 1;
}

/* Function to update the board with a match */
void updateBoard(char board[][COLS], int row1, int col1, int row2, int col2)
{
    board[row1][col1] = '*';
    board[row2][col2] = '*';
}

/* Function to check for a match */
int checkForMatch(char board[][COLS], int row1, int col1, int row2, int col2)
{
    if(board[row1][col1] == board[row2][col2])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}