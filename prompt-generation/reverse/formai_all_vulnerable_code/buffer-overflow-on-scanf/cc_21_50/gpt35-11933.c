//FormAI DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int playerA, playerB;
    char decisionA, decisionB;
    int rounds = 1;
    int scoreA = 0, scoreB = 0;
    srand(time(NULL));

    while(rounds <= 10)
    {
        printf("Round %d\n", rounds);

        playerA = rand() % 3;
        playerB = rand() % 3;

        printf("Player A: Enter your decision (R/P/S): ");
        scanf(" %c", &decisionA);
        printf("Player B: Enter your decision (R/P/S): ");
        scanf(" %c", &decisionB);

        if(decisionA == 'R' || decisionA == 'r')
            playerA = 0;
        else if(decisionA == 'P' || decisionA == 'p')
            playerA = 1;
        else if(decisionA == 'S' || decisionA == 's')
            playerA = 2;

        if(decisionB == 'R' || decisionB == 'r')
            playerB = 0;
        else if(decisionB == 'P' || decisionB == 'p')
            playerB = 1;
        else if(decisionB == 'S' || decisionB == 's')
            playerB = 2;

        if(playerA == playerB)
        {
            printf("Draw!\n");
        }
        else if(playerA == 0 && playerB == 2)
        {
            printf("Player A wins! Rock beats Scissors.\n");
            scoreA++;
        }
        else if(playerA == 1 && playerB == 0)
        {
            printf("Player A wins! Paper beats Rock.\n");
            scoreA++;
        }
        else if(playerA == 2 && playerB == 1)
        {
            printf("Player A wins! Scissors beats Paper.\n");
            scoreA++;
        }
        else
        {
            printf("Player B wins!\n");
            scoreB++;
        }

        rounds++;
    }

    printf("Final Score: Player A - %d, Player B - %d\n", scoreA, scoreB);

    if(scoreA > scoreB)
        printf("Player A wins the game!\n");
    else if(scoreB > scoreA)
        printf("Player B wins the game!\n");
    else
        printf("It's a tie game!\n");

    return 0;
}