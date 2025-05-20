//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int playerChoice, ghostPos, doorPos, turnsLeft = 5, scared = 0;
    srand(time(NULL)); //seed for random numbers
    ghostPos = rand() % 10 + 1; //ghost position randomized
    doorPos = rand() % 10 + 1; //door position randomized
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Your objective is to find the exit without encountering the ghost.\n");
    printf("You have 5 turns and if you get scared, you lose.\n");
    printf("Enter a number between 1 and 10 to start moving: ");
    scanf("%d", &playerChoice); //player's first move
    while(turnsLeft > 0) //while turns remain
    {
        if(playerChoice == ghostPos) //if player encounters ghost
        {
            printf("Oh no! You have encountered the ghost and lost the game.\n");
            return 0;
        }
        else if(playerChoice == doorPos && scared == 0) //if player reaches door without being scared
        {
            printf("Congratulations! You have found the exit and won the game.\n");
            return 0;
        }
        else if(playerChoice == doorPos && scared == 1) //if player reaches door but was previously scared
        {
            printf("You cannot leave without conquering your fear. Try again.\n");
            return 0;
        }
        else //if player neither encounters the ghost nor reaches the door
        {
            turnsLeft--; //decrement turns left
            if(turnsLeft == 0) //if all turns used up
            {
                printf("You have used all your turns. Game over.\n");
                return 0;
            }
            printf("You have %d turns left. Enter a number between 1 and 10 to move: ", turnsLeft);
            scanf("%d", &playerChoice); //next move by player
            if(rand() % 2 == 0) //50% chance of ghost appearing
            {
                printf("BOO! You have encountered the ghost and been scared.\n");
                scared = 1;
            }
        }
    }
    return 0;
}