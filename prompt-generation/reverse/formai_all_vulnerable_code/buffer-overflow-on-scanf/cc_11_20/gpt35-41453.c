//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MIN_NUM 1
#define MAX_NUM 75

// Function to check the bingo card for a win
int check_bingo(int bingo_card[][COLS])
{
    int i, j, sum;

    // Check rows
    for(i = 0; i < ROWS; i++)
    {
        sum = 0;
        for(j = 0; j < COLS; j++)
        {
            sum += bingo_card[i][j];
        }
        if(sum == 0)
        {
            return 1;
        }
    }

    // Check columns
    for(i = 0; i < COLS; i++)
    {
        sum = 0;
        for(j = 0; j < ROWS; j++)
        {
            sum += bingo_card[j][i];
        }
        if(sum == 0)
        {
            return 1;
        }
    }

    // Check diagonals
    sum = 0;
    for(i = 0; i < ROWS; i++)
    {
        sum += bingo_card[i][i];
    }
    if(sum == 0)
    {
        return 1;
    }

    sum = 0;
    for(i = 0; i < ROWS; i++)
    {
        sum += bingo_card[i][COLS - i - 1];
    }
    if(sum == 0)
    {
        return 1;
    }

    // No winner yet
    return 0;
}

int main()
{
    int bingo_card[ROWS][COLS] = {0};
    int i, j, num, player, win;
    srand(time(NULL));

    printf("Welcome to the Bingo Simulator!\n");
    printf("Enter the number of players: ");
    scanf("%d", &player);

    do
    {
        printf("Generating cards...\n");

        // Generate bingo cards for each player
        for(i = 0; i < player; i++)
        {
            printf("Player %d's card:\n", i + 1);
            for(j = 0; j < ROWS; j++)
            {
                printf("---------------------\n");
                for(int k = 0; k <COLS; k++)
                {
                    if(k == 2 && j == 2){
                        printf("|  FREE  ");
                        bingo_card[j][k] = 0;
                    }
                    else{
                        num = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
                        while(bingo_card[j][k] == num)
                        {
                            num = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
                        }
                        bingo_card[j][k] = num;
                        printf("|   %2d   ", bingo_card[j][k]);
                    }
                }
                printf("|\n");
            }
            printf("---------------------\n\n");
        }

        win = 0;

        while(!win)
        {
            // Generate number
            num = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
            printf("The called number is: %d\n", num);

            // Mark number on all cards
            for(i = 0; i < player; i++)
            {
                for(j = 0; j < ROWS; j++)
                {
                    for(int k = 0; k < COLS; k++)
                    {
                        if(bingo_card[j][k] == num)
                        {
                            bingo_card[j][k] = 0;
                        }
                    }
                }

                // Check for winner
                if(check_bingo(bingo_card))
                {
                    printf("BINGO! Player %d has won!\n", i + 1);
                    win = 1;
                    break;
                }
            }
        }

        // Play again?
        char play_again;
        printf("Would you like to play again? (Y/N)\n");
        scanf(" %c", &play_again);
        if(play_again == 'Y' || play_again == 'y')
        {
            win = 0;
        }
        else
        {
            printf("Thanks for playing!\n");
            return 0;
        }
    } while(win == 0);

    return 0;
}