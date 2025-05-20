//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int i, n, vote, total = 0;
    char name[20];

    printf("Welcome to the Electronic Voting System!\n");

    // Get the number of voters
    printf("Please enter the number of voters: ");
    scanf("%d", &n);

    // Create an array of voters
    struct voter
    {
        char name[20];
        int vote;
    } voters[n];

    // Get the voters' information
    for (i = 0; i < n; i++)
    {
        printf("Please enter the voter's name: ");
        scanf("%s", voters[i].name);

        printf("Please enter the voter's vote: ");
        scanf("%d", &voters[i].vote);
    }

    // Calculate the total number of votes
    for (i = 0; i < n; i++)
    {
        total += voters[i].vote;
    }

    // Print the results
    printf("The total number of votes is: %d\n", total);

    // Calculate the winner
    int winner = voters[0].vote;
    for (i = 1; i < n; i++)
    {
        if (voters[i].vote > winner)
        {
            winner = voters[i].vote;
        }
    }

    // Print the winner
    printf("The winner is: %s\n", voters[i].name);
}