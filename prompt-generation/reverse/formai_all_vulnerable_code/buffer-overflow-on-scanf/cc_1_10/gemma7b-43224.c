//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vote_cast(char candidate);

int main()
{
    char candidate;
    int i;
    char *candidates[] = {"John Doe", "Jane Doe", "Peter Pan", "Mary Poppins"};
    int votes[3] = {0};

    printf("Welcome to the Electronic Voting System!\n");

    // Loop to get the number of votes
    for (i = 0; i < 100; i++)
    {
        printf("Please vote for a candidate: ");
        scanf("%c", &candidate);

        // Validate the vote
        if (candidate < 'a' || candidate > 'c')
        {
            printf("Invalid vote. Please try again.\n");
            continue;
        }

        // Cast the vote
        vote_cast(candidate);

        // Increment the vote count
        votes[candidate - 'a']++;
    }

    // Print the results
    printf("The results of the election:\n");
    for (i = 0; i < 3; i++)
    {
        printf("%s received %d votes.\n", candidates[i], votes[i]);
    }

    return 0;
}

void vote_cast(char candidate)
{
    switch (candidate)
    {
        case 'a':
            printf("You have voted for John Doe.\n");
            break;
        case 'b':
            printf("You have voted for Jane Doe.\n");
            break;
        case 'c':
            printf("You have voted for Peter Pan.\n");
            break;
    }
}