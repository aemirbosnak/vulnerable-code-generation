//FormAI DATASET v1.0 Category: Dice Roller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int numDice, int numSides)
{
    int roll = 0;
    for(int i = 0; i < numDice; i++)
    {
        roll += rand() % numSides + 1;
    }
    return roll;
}

int main()
{
    srand(time(NULL)); // seed the random number generator with current time
    
    int numPlayers;
    do
    {
        printf("How many players? (Max 6): ");
        scanf("%d", &numPlayers);
    } while(numPlayers < 1 || numPlayers > 6); // ensure number of players is between 1 and 6
    
    int numRounds;
    do
    {
        printf("How many rounds? (Max 10): ");
        scanf("%d", &numRounds);
    } while(numRounds < 1 || numRounds > 10); // ensure number of rounds is between 1 and 10
    
    int scores[numPlayers]; // array to store scores of each player
    for(int i = 0; i < numPlayers; i++)
    {
        scores[i] = 0; // initialize all scores to 0
    }
    
    printf("Let's play!\n");
    for(int r = 1; r <= numRounds; r++)
    {
        printf("Round %d:\n", r);
        for(int p = 0; p < numPlayers; p++)
        {
            printf("Player %d, roll the dice! (Enter number of dice and number of sides): ", p+1);
            int numDice, numSides;
            scanf("%d %d", &numDice, &numSides);
            int roll = rollDice(numDice, numSides); // roll the dice
            scores[p] += roll; // add roll to player's score
            printf("You rolled a total of %d\n", roll);
        }
        printf("\n");
    }
    
    printf("Final scores:\n");
    for(int i = 0; i < numPlayers; i++)
    {
        printf("Player %d: %d\n", i+1, scores[i]); // print final scores of each player
    }
    
    int highestScore = 0;
    int highestScorePlayer = -1;
    for(int i = 0; i < numPlayers; i++)
    {
        if(scores[i] > highestScore)
        {
            highestScore = scores[i];
            highestScorePlayer = i;
        }
    }
    printf("Player %d wins with a score of %d!\n", highestScorePlayer+1, highestScore); // print winner
    
    return 0;
}