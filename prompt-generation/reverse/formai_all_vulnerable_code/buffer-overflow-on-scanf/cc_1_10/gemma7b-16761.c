//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

void main()
{
    // Declare variables
    int r_points = 50;
    int j_points = 40;
    char team;

    // Get the team's choice
    printf("Enter R for Red or J for Juliet: ");
    scanf(" %c", &team);

    // Check if the team's choice is valid
    if (team != 'R' && team != 'J')
    {
        printf("Invalid team choice.\n");
        return;
    }

    // Adjust points based on team's choice
    if (team == 'R')
    {
        r_points += 10;
    }
    else if (team == 'J')
    {
        j_points += 10;
    }

    // Print the team's points
    printf("Team points: ");
    printf("%d", r_points);
    printf(" - ");
    printf("%d", j_points);
    printf("\n");

    // Declare winner
    if (r_points > j_points)
    {
        printf("Red wins!");
    }
    else if (j_points > r_points)
    {
        printf("Juliet wins!");
    }
    else
    {
        printf("It's a draw!");
    }

    return;
}