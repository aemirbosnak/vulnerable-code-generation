//FormAI DATASET v1.0 Category: Dice Roller ; Style: medieval
#include <stdio.h> // for standard input output operations
#include <stdlib.h> // for using random function

int main()
{
    int dice, players, i, j, total, maxTotal, maxPlayer;
    // Variables for dice, number of players, loop iterations, total score, max score and max player 
    
    printf("Welcome to Medieval Dice Roller game!\n");
    printf("Enter the number of players: ");
    scanf("%d",&players);
    printf("\n");
    printf("Let's Begin!\n");
    printf("-----------------\n");

    for(i=1;i<=players;i++) 
    {
        printf("Player %d's turn. Press 1 to roll the dice: ",i);
        scanf("%d",&dice);
        if(dice==1)  // if player chooses to roll dice, then only proceed
        {
            printf("Rolling Dice...\n");
            dice = (rand() % 6) + 1; // generating random number between 1 and 6 (inclusive)
            printf("\nYou rolled a %d!\n\n", dice);
            total=total+dice; // update the total score of the player

            if(total>=30) // if total score of player reaches 30, game ends
            {
                maxTotal = total;
                maxPlayer = i;
                printf("Congratulations Player %d, you won the game with a score of %d!", maxPlayer, maxTotal);
                return 0;
            }
        }
        else // if player does not select 1, skip their turn
        {
            printf("%d! You missed the turn.\n",dice);
        }
    }

    // at the end of all turns, calculate and display the winner with max score
    printf("\n\nAll players have finished their turn.\n");

    for(i=1;i<=players;i++) 
    {
        printf("Player %d's Total Score: ",i);
        printf("%d\n",total);
        if(total>maxTotal) 
        {
            maxTotal=total;
            maxPlayer=i;
        }

    }
    printf("-----------------\n");
    printf("Congratulations Player %d, you won the game with a score of %d!\n",maxPlayer,maxTotal);
    printf("-----------------\n");

    return 0;
}