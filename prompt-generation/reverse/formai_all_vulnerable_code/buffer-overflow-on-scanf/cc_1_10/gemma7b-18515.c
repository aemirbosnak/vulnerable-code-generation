//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10

typedef struct Candidate
{
    char name[20];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void initializeCandidates()
{
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        candidates[i].votes = 0;
    }
}

void addVote(char candidateName)
{
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        if (strcmp(candidates[i].name, candidateName) == 0)
        {
            candidates[i].votes++;
            break;
        }
    }
}

int main()
{
    initializeCandidates();

    // Voting process
    printf("Enter candidate name: ");
    char candidateName[20];
    scanf("%s", candidateName);

    addVote(candidateName);

    // Results
    printf("Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}