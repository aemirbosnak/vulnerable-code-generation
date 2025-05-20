//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate
{
    char name[20];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(Candidate *candidate)
{
    candidate->votes++;
}

int main()
{
    int i, vote_count, candidate_index;
    char vote_choice;

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }

    // Get vote count
    printf("Enter the number of votes: ");
    scanf("%d", &vote_count);

    // Vote
    for (i = 0; i < vote_count; i++)
    {
        // Get candidate choice
        printf("Enter the candidate's name: ");
        scanf("%s", candidates[candidate_index].name);

        // Vote for candidate
        vote(&candidates[candidate_index]);
    }

    // Print results
    printf("Results:\n");
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        if (candidates[i].name[0] != '\0')
        {
            printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        }
    }

    // Find winner
    candidate_index = 0;
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        if (candidates[i].votes > candidates[candidate_index].votes)
        {
            candidate_index = i;
        }
    }

    // Print winner
    printf("Winner: %s\n", candidates[candidate_index].name);

    return 0;
}