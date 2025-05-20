//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int team1 = 0, team2 = 0, score1 = 0, score2 = 0;
    char team_name1[20], team_name2[20];

    printf("Enter the name of team 1: ");
    scanf("%s", team_name1);

    printf("Enter the name of team 2: ");
    scanf("%s", team_name2);

    printf("Welcome to the Battle of %s vs. %s!\n", team_name1, team_name2);

    // Game loop
    while (team1 < 5 && team2 < 5)
    {
        // Team 1 turn
        printf("%s, enter your move (1-3): ", team_name1);
        int move1 = getchar() - 48;

        // Team 2 turn
        printf("%s, enter your move (1-3): ", team_name2);
        int move2 = getchar() - 48;

        // Scoring
        if (move1 == move2)
        {
            score1++;
            score2++;
        }
        else if (move1 > move2)
        {
            score1++;
        }
        else
        {
            score2++;
        }

        // Team scores
        printf("Team 1 score: %d\n", score1);
        printf("Team 2 score: %d\n", score2);

        // Increment team scores
        if (score1 >= 3)
        {
            team1++;
        }
        if (score2 >= 3)
        {
            team2++;
        }
    }

    // Game over
    printf("The Battle of %s vs. %s has ended!\n", team_name1, team_name2);
    printf("The winner is: ");
    if (score1 > score2)
    {
        printf("%s!\n", team_name1);
    }
    else
    {
        printf("%s!\n", team_name2);
    }

    return 0;
}