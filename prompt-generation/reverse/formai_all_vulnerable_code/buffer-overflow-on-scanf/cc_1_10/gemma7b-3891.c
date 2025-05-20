//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void main()
{
    // Define the number of voters
    int num_voters = 10;

    // Create an array of voters
    struct voter
    {
        char name[50];
        int vote_choice;
    } voters[num_voters];

    // Initialize the voters
    for (int i = 0; i < num_voters; i++)
    {
        printf("Enter the name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);

        printf("Enter the vote choice of voter %d: ", i + 1);
        scanf("%d", &voters[i].vote_choice);
    }

    // Print the results
    int winner = -1;
    int max_votes = 0;
    for (int i = 0; i < num_voters; i++)
    {
        // Calculate the number of votes for each candidate
        int votes = 0;
        for (int j = 0; j < num_voters; j++)
        {
            if (voters[j].vote_choice == voters[i].vote_choice)
            {
                votes++;
            }
        }

        // Update the maximum number of votes and the winner
        if (votes > max_votes)
        {
            max_votes = votes;
            winner = i;
        }
    }

    // Print the winner
    if (winner != -1)
    {
        printf("The winner is: %s", voters[winner].name);
    }
    else
    {
        printf("There has not been a winner.");
    }

    return;
}