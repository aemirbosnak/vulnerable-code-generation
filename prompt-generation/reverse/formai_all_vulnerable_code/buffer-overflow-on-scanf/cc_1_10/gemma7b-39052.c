//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5

typedef struct Candidate
{
    char name[20];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(char *candidate)
{
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++)
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
    int i, j;

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        candidates[i].votes = 0;
    }

    // Register voters
    printf("Enter the number of voters: ");
    int numVoters;
    scanf("%d", &numVoters);

    // Vote
    for (i = 0; i < numVoters; i++)
    {
        printf("Enter the name of the voter: ");
        char voterName[20];
        scanf("%s", voterName);

        printf("Enter the name of the candidate you want to vote for: ");
        char candidateName[20];
        scanf("%s", candidateName);

        vote(candidateName);
    }

    // Print results
    printf("Results:\n");
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Calculate winner
    int winner = -1;
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        if (winner == -1 || candidates[i].votes > candidates[winner].votes)
        {
            winner = i;
        }
    }

    // Print winner
    printf("The winner is: %s\n", candidates[winner].name);

    return 0;
}