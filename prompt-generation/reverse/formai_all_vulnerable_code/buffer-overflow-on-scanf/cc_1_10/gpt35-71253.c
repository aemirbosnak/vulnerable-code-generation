//FormAI DATASET v1.0 Category: Weather simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));  // initialize random seed
    
    int players;
    printf("How many players are there?\n");
    scanf("%d", &players);
    
    // initialize array of player scores
    int scores[players];
    for (int i = 0; i < players; i++)
    {
        scores[i] = 0;
    }
    
    // game loop
    int round = 1;
    while (round <= 10)  // play 10 rounds of weather simulation
    {
        printf("Round %d:\n", round);
        for (int i = 0; i < players; i++)
        {
            int forecast;
            printf("Player %d, what is your weather forecast for today? (0 for sunny, 1 for rainy, 2 for snowy)\n", i+1);
            scanf("%d", &forecast);
            
            int weather = rand() % 3;  // generate random weather condition
            if (forecast == weather)  // if player's forecast matches actual weather, they get 5 points
            {
                printf("Player %d is correct and gets 5 points!\n", i+1);
                scores[i] += 5;
            }
            else  // if player's forecast does not match actual weather, they lose 1 point for each degree of difference
            {
                int difference = abs(forecast - weather);
                printf("Player %d is incorrect and loses %d points.\n", i+1, difference);
                scores[i] -= difference;
            }
        }
        round++;
    }
    
    // show final scores
    printf("Final scores:\n");
    for (int i = 0; i < players; i++)
    {
        printf("Player %d: %d\n", i+1, scores[i]);
    }
    
    return 0;
}