//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
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
    int numCandidates = 0;
    char voteChoice;

    // Create candidates
    while (numCandidates < MAX_CANDIDATES && scanf("Enter candidate name: ", candidates[numCandidates].name) != EOF)
    {
        candidates[numCandidates].votes = 0;
        numCandidates++;
    }

    // Vote
    printf("Please vote for a candidate: ");
    scanf(" %c", &voteChoice);

    vote(voteChoice);

    // Print results
    printf("Results:");
    for (int i = 0; i < numCandidates; i++)
    {
        printf(" %s: %d votes", candidates[i].name, candidates[i].votes);
    }

    return 0;
}