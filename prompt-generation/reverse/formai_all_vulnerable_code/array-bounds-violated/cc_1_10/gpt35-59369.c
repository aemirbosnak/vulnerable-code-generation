//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int playerCount = 0, playerTurn = 0;
    char name[100];

    //Initialize random seed
    srand(time(NULL));

    //Get the number of players
    printf("Enter the number of players (2-4): ");
    scanf("%d", &playerCount);

    //Create the player array
    int players[playerCount];

    //Initialize each player's score to 0
    for(int i=0; i<playerCount; i++)
    {
        players[i] = 0;
    }

    //Get the name of each player and store it in an array
    char playerNames[playerCount][100];
    for(int i=0; i<playerCount; i++)
    {
        printf("Enter the name of player %d: ", i+1);
        scanf("%s", name);
        strcpy(playerNames[i], name);
    }

    //Print the player names
    printf("\nPlayer Names:\n");
    for(int i=0; i<playerCount; i++)
    {
        printf("%s\n", playerNames[i]);
    }

    //Loop through turns until one player reaches the end
    while(players[playerTurn] < 10)
    {
        //Print the current player's name and score
        printf("\n%s's turn. Score: %d\n", playerNames[playerTurn], players[playerTurn]);

        //Roll the dice
        int roll = rand() % 6 + 1;
        printf("You rolled a %d\n", roll);

        //Update the player's score
        players[playerTurn] += roll;

        //Check if the player has landed on a haunted house
        switch(players[playerTurn])
        {
            case 2:
                printf("You have landed on the Haunted House of Doom!\n");
                printf("You have been cursed and must miss your next turn.\n");
                playerTurn++;
                break;
            case 5:
                printf("You have landed on the Haunted House of Terror!\n");
                printf("You have been frightened and must roll again.\n");
                roll = rand() % 6 + 1;
                printf("You roll a %d and move forward.\n", roll);
                players[playerTurn] += roll;
                break;
            case 7:
                printf("You have landed on the Haunted House of Horrors!\n");
                printf("You have been ambushed by ghosts and have been moved back two spaces.\n");
                players[playerTurn] -= 2;
                if (players[playerTurn] < 0)
                {
                    players[playerTurn] = 0;
                }
                break;
        }

        //Switch to the next player's turn
        playerTurn++;
        if(playerTurn >= playerCount)
        {
            playerTurn = 0;
        }
    }

    //Print the winner's name and score
    printf("\nCongratulations %s! You have won with a score of %d.\n", playerNames[playerTurn], players[playerTurn]);

    return 0;
}