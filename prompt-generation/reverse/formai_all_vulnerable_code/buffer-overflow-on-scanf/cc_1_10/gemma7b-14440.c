//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate
{
    char name[20];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(char candidate)
{
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        if (strcmp(candidates[i].name, candidate) == 0)
        {
            candidates[i].votes++;
            break;
        }
    }
}

int main()
{
    int i, vote_count = 0;

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }

    // Vote loop
    while (vote_count < MAX_VOTES)
    {
        char candidate;

        // Get the candidate's name
        printf("Enter the candidate's name: ");
        scanf("%s", candidates[vote_count].name);

        // Validate the candidate's name
        if (strlen(candidates[vote_count].name) == 0)
        {
            printf("Error: Invalid candidate name.\n");
            continue;
        }

        // Vote
        vote(candidates[vote_count].name);

        // Increment vote count
        vote_count++;
    }

    // Print the results
    printf("Results:\n");
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}