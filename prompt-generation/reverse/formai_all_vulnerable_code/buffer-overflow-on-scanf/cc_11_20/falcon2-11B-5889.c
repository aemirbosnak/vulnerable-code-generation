//Falcon2-11B DATASET v1.0 Category: Space Invaders Game Clone ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Random Seed
    srand(time(0));

    // Initialise the board
    int board[5][5] = {0};

    // Print the board
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(board[i][j] == 1)
            {
                printf("O");
            }
            else
            {
                printf("_");
            }
        }
        printf("\n");
    }

    // User input
    int player_choice;
    printf("Player Choice: ");
    scanf("%d", &player_choice);

    // Check the user input
    if(player_choice == 1 || player_choice == 2)
    {
        printf("You choose: %d\n", player_choice);
    }
    else
    {
        printf("Invalid Input!\n");
        exit(1);
    }

    // Game loop
    int i, j, k;
    while(1)
    {
        // Randomize the board
        for(i=0; i<5; i++)
        {
            for(j=0; j<5; j++)
            {
                k = rand() % 2;
                if(k == 0)
                {
                    board[i][j] = 1;
                }
                else
                {
                    board[i][j] = 0;
                }
            }
        }

        // Print the board
        for(i=0; i<5; i++)
        {
            for(j=0; j<5; j++)
            {
                if(board[i][j] == 1)
                {
                    printf("O");
                }
                else
                {
                    printf("_");
                }
            }
            printf("\n");
        }

        // Check for game over
        if(player_choice == 1)
        {
            for(i=0; i<5; i++)
            {
                for(j=0; j<5; j++)
                {
                    if(board[i][j] == 1)
                    {
                        printf("You Lost!\n");
                        exit(1);
                    }
                }
            }
        }
        else
        {
            for(i=0; i<5; i++)
            {
                for(j=0; j<5; j++)
                {
                    if(board[i][j] == 0)
                    {
                        printf("You Won!\n");
                        exit(1);
                    }
                }
            }
        }
    }
}