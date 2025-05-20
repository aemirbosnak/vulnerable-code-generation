//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

void main()
{
    system("clear");

    // Create a list of voters
    struct voter
    {
        char name[50];
        int vote;
    } voters[100];

    // Initialize the number of voters
    int num_voters = 0;

    // Get the number of voters
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Create the voters
    for (int i = 0; i < num_voters; i++)
    {
        printf("Enter the name of the voter: ");
        scanf("%s", voters[i].name);

        printf("Enter the vote of the voter: ");
        scanf("%d", &voters[i].vote);
    }

    // Print the voters
    for (int i = 0; i < num_voters; i++)
    {
        printf("Name: %s, Vote: %d\n", voters[i].name, voters[i].vote);
    }

    // Calculate the winner
    int winner = voters[0].vote;
    for (int i = 1; i < num_voters; i++)
    {
        if (voters[i].vote > winner)
        {
            winner = voters[i].vote;
        }
    }

    // Print the winner
    printf("The winner is: %s with %d votes\n", voters[0].name, winner);
}