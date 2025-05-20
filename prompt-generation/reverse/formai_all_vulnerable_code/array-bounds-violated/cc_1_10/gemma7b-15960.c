//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 5

typedef struct Candidate
{
    char name[20];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(int candidate_index)
{
    candidates[candidate_index].votes++;
}

int main()
{
    int i, candidate_index, vote_count;

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }

    // Get the vote count
    printf("Enter the number of votes: ");
    scanf("%d", &vote_count);

    // Cast votes
    for (i = 0; i < vote_count; i++)
    {
        printf("Enter the candidate index: ");
        scanf("%d", &candidate_index);

        vote(candidate_index);
    }

    // Print the results
    printf("The results are:\n");
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s has received %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    // Find the winner
    Candidate winner = candidates[0];
    for (i = 1; i < MAX_CANDIDATES; i++)
    {
        if (candidates[i].votes > winner.votes)
        {
            winner = candidates[i];
        }
    }

    // Print the winner
    printf("The winner is: %s\n", winner.name);

    return 0;
}