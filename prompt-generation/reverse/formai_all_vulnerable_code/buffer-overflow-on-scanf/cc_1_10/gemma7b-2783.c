//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    char vote[2] = {'a', 'b'};
    int i, totalVotes = 0, choice;

    // Create an array of structures to store candidate information
    struct candidate
    {
        char name[20];
        int votes;
    } candidates[5] = {
        {"John Doe", 0},
        {"Jane Doe", 0},
        {"Peter Pan", 0},
        {"Mary Poppins", 0},
        {"Captain Hook", 0}
    };

    // Print the candidates' names
    printf("Candidates:");
    for (i = 0; i < 5; i++)
    {
        printf("\n%s", candidates[i].name);
    }

    // Get the user's vote
    printf("\nEnter your vote (a/b): ");
    scanf("%c", &choice);

    // Validate the vote
    if (choice != vote[0] && choice != vote[1])
    {
        printf("Invalid vote. Please try again.\n");
        return;
    }

    // Increment the candidate's votes
    for (i = 0; i < 5; i++)
    {
        if (strcmp(candidates[i].name, vote) == 0)
        {
            candidates[i].votes++;
            break;
        }
    }

    // Print the results
    printf("\nResults:");
    for (i = 0; i < 5; i++)
    {
        printf("\n%s: %d votes", candidates[i].name, candidates[i].votes);
    }

    // Calculate the total number of votes
    for (i = 0; i < 5; i++)
    {
        totalVotes += candidates[i].votes;
    }

    // Print the total number of votes
    printf("\nTotal Votes: %d", totalVotes);

    return;
}