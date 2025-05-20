//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>   

#define ROWS    5   
#define COLS    5   
#define MAX_NUM 75  

int main()
{
    int row, col, number, num_calls = 0, winner = 0;
    int bingo[ROWS][COLS] = {0};
    int selected[MAX_NUM] = {0};

    srand(time(NULL));  

    printf("Welcome to the Bingo Simulator!\n\n");

    while(!winner)
    {
        number = rand() % MAX_NUM + 1;
        num_calls++;

        if(selected[number])
        {
            printf("%d is already selected!\n", number);
            continue;
        }

        selected[number] = 1;
        printf("Number Called: %d\n", number);

        for(row = 0; row < ROWS; row++)
        {
            for(col = 0; col < COLS; col++)
            {
                if(bingo[row][col] == number)
                {
                    bingo[row][col] = -1;   
                }
                if(row == 2 && col == 2)
                {
                    printf("FREE ");
                }
                else if(bingo[row][col] == -1)
                {
                    printf("X ");
                }
                else
                {
                    printf("%d ", bingo[row][col]);
                }
            }
            printf("\n");
        }

        for(row = 0; row < ROWS; row++)
        {
            int sum = 0;
            for(col = 0; col < COLS; col++)
            {
                sum += bingo[row][col];
            }
            if(sum == -5)
            {
                printf("BINGO on row %d!\n", row+1);
                winner = 1;
            }
        }

        for(col = 0; col < COLS; col++)
        {
            int sum = 0;
            for(row = 0; row < ROWS; row++)
            {
                sum += bingo[row][col];
            }
            if(sum == -5)
            {
                printf("BINGO on column %d!\n", col+1);
                winner = 1;
            }
        }

        int sum = 0;
        for(row = 0; row < ROWS; row++)
        {
            sum += bingo[row][row];
        }
        if(sum == -5)
        {
            printf("BINGO on the diagonal!\n");
            winner = 1;
        }

        sum = 0;
        for(row = 0; row < ROWS; row++)
        {
            sum += bingo[row][COLS-1-row];
        }
        if(sum == -5)
        {
            printf("BINGO on the reverse diagonal!\n");
            winner = 1;
        }

        printf("\n");
    }

    printf("BINGO! It took %d calls to get here.\n", num_calls);

    return 0;
}