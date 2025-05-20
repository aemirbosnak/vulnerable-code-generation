//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define ROWS 5
#define COLS 5

void generateNumbers(int bingo[][COLS]);
void printBingo(int bingo[][COLS]);
void checkBingo(int bingo[][COLS], int *bingoFlag);

int main()
{
    int bingo[ROWS][COLS] = {0};
    int bingoFlag = 0, randomNumber;
    char answer;

    printf("Welcome to the Bingo Simulator!\n\n");
    printf("Press y to generate Bingo numbers and start playing: ");
    scanf(" %c", &answer);

    if(answer == 'y')
    {
        srand(time(NULL));
        generateNumbers(bingo);
        printBingo(bingo);

        printf("\nPlaying Bingo...\n\n");

        while(!bingoFlag)
        {
            printf("Press y to generate the next number: ");
            scanf(" %c", &answer);

            if(answer == 'y')
            {
                randomNumber = rand() % 75 + 1;
                printf("Calling number: %d\n", randomNumber);

                for(int i = 0; i < ROWS; i++)
                {
                    for(int j = 0; j < COLS; j++)
                    {
                        if(bingo[i][j] == randomNumber)
                        {
                            bingo[i][j] = 0;
                        }
                    }
                }

                printBingo(bingo);
                checkBingo(bingo, &bingoFlag);

                if(bingoFlag)
                {
                    printf("BINGO!!!\n");
                }
            }
            else
            {
                printf("Invalid input.\n");
            }
        }
    }

    printf("\nThanks for playing!\n");

    return 0;
}

void generateNumbers(int bingo[][COLS])
{
    int randomNumber;

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            do
            {
                randomNumber = rand() % 15 + (j * 15) + 1;
            } while(bingo[i][0] == randomNumber || bingo[i][1] == randomNumber || 
                    bingo[i][2] == randomNumber || bingo[i][3] == randomNumber || 
                    bingo[i][4] == randomNumber);

            bingo[i][j] = randomNumber;
        }
    }

    bingo[2][2] = 0;
}

void printBingo(int bingo[][COLS])
{
    printf("\nBingo Board:\n\n");

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%2d ", bingo[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void checkBingo(int bingo[][COLS], int *bingoFlag)
{
    for(int i = 0; i < ROWS; i++)//Checking Rows
    {
        if(bingo[i][0] == 0 && bingo[i][1] == 0 && bingo[i][2] == 0 && 
           bingo[i][3] == 0 && bingo[i][4] == 0)
        {
            *bingoFlag = 1;
            break;
        }
    }

    if(*bingoFlag == 0)//Checking Cols if Rows are not Bingo.
    {
        for(int j = 0; j < COLS; j++)
        {
            if(bingo[0][j] == 0 && bingo[1][j] == 0 && bingo[2][j] == 0 && 
               bingo[3][j] == 0 && bingo[4][j] == 0)
            {
                *bingoFlag = 1;
                break;
            }
        }
    }

    if(*bingoFlag == 0)//Checking Diagonals if Rows and Cols are not Bingo.
    {
        if(bingo[0][0] == 0 && bingo[1][1] == 0 && bingo[2][2] == 0 && 
           bingo[3][3] == 0 && bingo[4][4] == 0)
        {
            *bingoFlag = 1;
        }
        else if(bingo[0][4] == 0 && bingo[1][3] == 0 && bingo[2][2] == 0 && 
                bingo[3][1] == 0 && bingo[4][0] == 0)
        {
            *bingoFlag = 1;
        }
    }
}