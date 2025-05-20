//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// size of the board
#define ROWS 5
#define COLS 5

// function prototypes
void fillBoard();
void printBoard();
void generateNumber();
int checkForBingo();

// global variables
int board[ROWS][COLS];
int numbersCalled[75];
int numCalls = 0;

// main function
int main()
{
    printf("\nWelcome to Bingo Simulator!\n");
    printf("Generating the board...\n\n");
    fillBoard();
    printBoard();
    
    printf("Game starting now!\n");
    srand(time(0));
    int bingo = 0;
    while(!bingo)
    {
        generateNumber();
        printf("Number Called: %d\n", numbersCalled[numCalls-1]);
        bingo = checkForBingo();
        numCalls++;
    }
    
    printf("Bingo! Congratulations!\n");
    
    return 0;
}


// function definitions
void fillBoard()
{
    // fill board with random numbers from 1-75
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            int num = rand() % 15 + 1 + j * 15;
            board[i][j] = num;
        }
    }
    
    // mark center square as FREE
    board[2][2] = -1;
}

void printBoard()
{
    // print the board with column and row labels
    printf("B\tI\tN\tG\tO\n");
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(board[i][j] == -1)
            {
                printf("FREE\t");
            }
            else
            {
                printf("%d\t", board[i][j]);
            }
        }
        printf("\n");
    }
}

void generateNumber()
{
    // generate random number from 1-75 that hasn't been called yet
    int num;
    do
    {
        num = rand() % 75 + 1;
    } while(numbersCalled[num-1] != 0);
    
    // add number to list of called numbers
    numbersCalled[num-1] = num;
}

int checkForBingo()
{
    // check for horizontal bingo
    for(int i = 0; i < ROWS; i++)
    {
        int count = 0;
        for(int j = 0; j < COLS; j++)
        {
            if(board[i][j] == -1)
            {
                count++;
            }
        }
        if(count == COLS)
        {
            return 1;
        }
    }
    
    // check for vertical bingo
    for(int j = 0; j < COLS; j++)
    {
        int count = 0;
        for(int i = 0; i < ROWS; i++)
        {
            if(board[i][j] == -1)
            {
                count++;
            }
        }
        if(count == ROWS)
        {
            return 1;
        }
    }
    
    // check for diagonal bingo
    if(board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1)
    {
        return 1;
    }
    if(board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1)
    {
        return 1;
    }
    
    return 0;
}