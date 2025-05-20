//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Claude Shannon
/*
    Author: Claude Shannon
    Purpose: To simulate a game of Bingo
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Macro to define the number of players
#define NUM_PLAYERS 5

int main()
{
    int bingo_board[5][5], num_called[NUM_PLAYERS][75], player_card[NUM_PLAYERS][5][5];
    int i, j, k, num, row, col, call_count, winner=0;
    char player_names[NUM_PLAYERS][20];
    srand(time(NULL));      // Initialize random number generator with current system time

    // Get the names of the players
    for(i=0; i<NUM_PLAYERS; i++)
    {
        printf("Enter the name of player %d: ", i+1);
        scanf("%s", player_names[i]);
    }

    // Generate the Bingo Board
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            // Middle space is always free
            if(i==2 && j==2)
            {
                bingo_board[i][j] = 0;  // 0 indicates the middle space is free
                continue;
            }

            // Generate a random number for the space
            do
            {
                num = rand() % 15 + 1 + (j*15);   // Calculate the range of numbers for each column of the board
            } while( num_called[0][num] );  // Check if the number has been called before

            // Add the number to the Bingo Board
            bingo_board[i][j] = num;
            num_called[0][num] = 1;  // Update the called numbers array
        }
    }

    // Generate unique player cards
    for(k=0; k<NUM_PLAYERS; k++)
    {
        for(i=0; i<5; i++)
        {
            for(j=0; j<5; j++)
            {
                // Check if the number has been called before
                do
                {
                    num = rand() % 15 + 1 + (j*15);   // Calculate the range of numbers for each column of the card
                } while( num_called[k][num] );

                // Add the number to the player's card
                player_card[k][i][j] = num;
                num_called[k][num] = 1;  // Update the called numbers array
            }
        }
    }

    // Print the Bingo Board
    printf("\nBINGO BOARD:\n");
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            printf("%d\t", bingo_board[i][j]);
        }
        printf("\n");
    }

    // Play the game
    call_count = 0;  // Initialize the call count to 0
    while(!winner)
    {
        // Call a random number
        do
        {
            num = rand() % 75 + 1;
        } while( num_called[0][num] );  // Check if the number has been called before

        num_called[0][num] = 1;  // Update the called numbers array
        call_count++;  // Update the call count

        // Check each player's card for the called number
        for(k=0; k<NUM_PLAYERS; k++)
        {
            for(i=0; i<5; i++)
            {
                for(j=0; j<5; j++)
                {
                    if(player_card[k][i][j] == num)
                    {
                        player_card[k][i][j] = 0;  // Mark the number as called on the player's card

                        // Check if the player has won
                        if( player_card[k][i][0]==0 && player_card[k][i][1]==0 && player_card[k][i][2]==0 && player_card[k][i][3]==0 && player_card[k][i][4]==0 )
                        {
                            winner = 1;
                            printf("\n%s has won the game after %d calls!\n", player_names[k], call_count);
                            break;
                        }
                        else if( player_card[k][0][j]==0 && player_card[k][1][j]==0 && player_card[k][2][j]==0 && player_card[k][3][j]==0 && player_card[k][4][j]==0 )
                        {
                            winner = 1;
                            printf("\n%s has won the game after %d calls!\n", player_names[k], call_count);
                            break;
                        }
                        else if( player_card[k][0][0]==0 && player_card[k][1][1]==0 && player_card[k][3][3]==0 && player_card[k][4][4]==0 )
                        {
                            winner = 1;
                            printf("\n%s has won the game after %d calls!\n", player_names[k], call_count);
                            break;
                        }
                        else if( player_card[k][0][4]==0 && player_card[k][1][3]==0 && player_card[k][3][1]==0 && player_card[k][4][0]==0 )
                        {
                            winner = 1;
                            printf("\n%s has won the game after %d calls!\n", player_names[k], call_count);
                            break;
                        }
                    }
                }
                if(winner)
                    break;
            }
            if(winner)
                break;
        }
    }

    return 0;
}