//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED 1
#define BLUE 2
#define GREEN 3
#define YELLOW 4

int main()
{
    int team_red = 0, team_blue = 0, score_red = 0, score_blue = 0;
    char team_name_red[20], team_name_blue[20];

    printf("Enter the name of team red: ");
    scanf("%s", team_name_red);

    printf("Enter the name of team blue: ");
    scanf("%s", team_name_blue);

    printf("Enter the number of players on team red: ");
    scanf("%d", &team_red);

    printf("Enter the number of players on team blue: ");
    scanf("%d", &team_blue);

    printf("Enter the score of team red: ");
    scanf("%d", &score_red);

    printf("Enter the score of team blue: ");
    scanf("%d", &score_blue);

    printf("--------------------------------------------------------------------\n");
    printf("%s vs. %s\n", team_name_red, team_name_blue);
    printf("Score: %d - %d\n", score_red, score_blue);
    printf("--------------------------------------------------------------------\n");

    if (score_red > score_blue)
    {
        printf("The winner is: %s!\n", team_name_red);
    }
    else if (score_red < score_blue)
    {
        printf("The winner is: %s!\n", team_name_blue);
    }
    else
    {
        printf("It's a draw!\n");
    }

    return 0;
}