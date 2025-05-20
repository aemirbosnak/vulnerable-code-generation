//FormAI DATASET v1.0 Category: Table Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initializing the randomization 

    int table[3][3]; // declaring a 3x3 table
    int i, j, player = 1, move, row, column, flag = 0;

    for (i=0; i<3; i++) // initializing the table with zeros
    {
        for (j=0; j<3; j++)
        {
            table[i][j] = 0;
        }
    }

    printf("\n");
    printf("******************************\n");
    printf(" Welcome to the Tic-Tac-Toe Game\n");
    printf("******************************\n");

    while(flag != 1) // game loop
    {
        printf("\nTable view:\n\n");

        for (i=0; i<3; i++) // printing the current table
        {
            printf("\t");

            for (j=0; j<3; j++)
            {
                printf("|");

                if (table[i][j] == 0)
                {
                    printf(" ");
                }
                else if (table[i][j] == 1)
                {
                    printf("X");
                }
                else if (table[i][j] == 2)
                {
                    printf("O");
                }
            }

            printf("|\n");
        }

        while(player < 3)
        {
            printf("\nPlayer %d's turn!\n", player);
            printf("Enter a move: ");
            scanf("%d", &move);

            row = (int)((move-1)/3); // calculating the row and column for the selected move
            column = (move-1)%3;

            if (table[row][column] == 0) // checking if the selected position is empty
            {
                table[row][column] = player; // marking the player's move

                if ((table[0][0] == player && table[0][1] == player && table[0][2] == player) || // checking if the player has won
                    (table[1][0] == player && table[1][1] == player && table[1][2] == player) ||
                    (table[2][0] == player && table[2][1] == player && table[2][2] == player) ||
                    (table[0][0] == player && table[1][0] == player && table[2][0] == player) ||
                    (table[0][1] == player && table[1][1] == player && table[2][1] == player) ||
                    (table[0][2] == player && table[1][2] == player && table[2][2] == player) ||
                    (table[0][0] == player && table[1][1] == player && table[2][2] == player) ||
                    (table[0][2] == player && table[1][1] == player && table[2][0] == player))
                {
                    printf("\n");
                    printf("\t********************************\n");
                    printf("\t-Player %d has WON the game!!-\n", player);
                    printf("\t********************************\n");
                    printf("\n");
                    flag = 1;
                    break;
                }

                player++; // changing the turn to the next player

                if (player == 3) // if no more moves can be made, end the game
                {
                    printf("\n");
                    printf("\t********************************\n");
                    printf("\t-The game has ENDED in a DRAW!!-\n");
                    printf("\t********************************\n");
                    printf("\n");
                    flag = 1;
                    break;
                }

                break;
            }
            else
            {
                printf("\n");
                printf("\tInvalid move! Try again\n");
            }
        }
    }

    return 0;
}