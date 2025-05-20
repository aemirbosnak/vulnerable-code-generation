//FormAI DATASET v1.0 Category: Memory Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int board[ROWS][COLS] = {0};
int tempBoard[ROWS][COLS] = {0};
int row1 = -1, col1 = -1, row2 = -1, col2 = -1;
int firstInput = 1;
int totalMoves = 0;

//randomize the board with numbers between 1 and 8
void randomize() 
{
    int i, j, randNum;
    srand(time(NULL));
    for(i = 0; i < ROWS; i++) 
    {
        for(j = 0; j < COLS; j++) 
        {
            randNum = (rand() % 8) + 1;
            board[i][j] = randNum;
        }
    }
}

// print board on the screen
void printBoard() 
{
    int i, j;
    printf("\n");
    for(i = 0; i < ROWS; i++) 
    {
        for(j = 0; j < COLS; j++) 
        {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// verify if input is valid
int isValidInput(int row, int col) 
{
    if(row < 0 || row >= ROWS || col < 0 || col >= COLS || tempBoard[row][col] == -1) 
    {
        return 0;
    }
    return 1;
}

// verify if two inputs are matching
int checkIfMatch() 
{
    if(board[row1][col1] == board[row2][col2]) 
    {
        tempBoard[row1][col1] = -1;
        tempBoard[row2][col2] = -1;
        return 1;
    }
    return 0;
}

// verifying the win conditions
int isGameWon() 
{
    int i, j;
    for(i = 0; i < ROWS; i++) 
    {
        for(j = 0; j < COLS; j++) 
        {
            if(tempBoard[i][j] != -1) 
            {
                return 0;
            }
        }
    }
    return 1;
}

//reset the temp board
void resetTempBoard() 
{
    int i, j;
    for(i = 0; i < ROWS; i++) 
    {
        for(j = 0; j < COLS; j++) 
        {
            tempBoard[i][j] = board[i][j];
        }
    }
}

// clear screen
void clearScreen() 
{
    printf("\033[2J\033[1;1H");
    fflush(stdout);
}

// play one round of the game
void play() 
{
    int row, col;
    do 
    {
        if(firstInput) 
        {
            printf("\nEnter row and column of your 1st choice, separated by space (i.e. 0 1): ");
            scanf("%d %d", &row, &col);
            if(isValidInput(row, col)) 
            {
                row1 = row;
                col1 = col;
                firstInput = 0;
                clearScreen();
                printf("Move #:%d\n", ++totalMoves);
                resetTempBoard();
                tempBoard[row][col] = -1;
                printBoard(tempBoard);
            } 
            else 
            {
                printf("\nInvalid input!!");
                fflush(stdin);
            }
        }
        else 
        {
            printf("\nEnter row and column of your 2nd choice, separated by space (i.e. 0 1): ");
            scanf("%d %d", &row, &col);
            if(isValidInput(row, col)) 
            {
                row2 = row;
                col2 = col;
                if(checkIfMatch() == 1) 
                {
                    clearScreen();
                    printf("Move #:%d\n", ++totalMoves);
                    resetTempBoard();
                    tempBoard[row1][col1] = -1;
                    tempBoard[row2][col2] = -1;
                    printBoard(tempBoard);
                    printf("\nIt's a match!");
                    fflush(stdin);
                    firstInput = 1;
                    if(isGameWon() == 1) 
                    {
                        printf("\nCongratulations, you have completed the game in %d moves", totalMoves);
                        exit(0);
                    }
                } 
                else 
                {
                    clearScreen();
                    printf("Move #:%d\n", ++totalMoves);
                    resetTempBoard();
                    tempBoard[row][col] = -1;
                    printBoard(tempBoard);
                    printf("\nNot a match, try again!");
                    fflush(stdin);
                    row2 = -1;
                    col2 = -1;
                    firstInput = 1;
                }
            } 
            else 
            {
                printf("\nInvalid input!!");
                fflush(stdin);
            }
        }
    } while(1);
}

int main() 
{
    randomize();
    play();
    return 0;
}