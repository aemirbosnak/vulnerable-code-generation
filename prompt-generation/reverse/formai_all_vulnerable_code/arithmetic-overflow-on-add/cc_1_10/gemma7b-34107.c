//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: thoughtful
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

void vote(Candidate *candidates, int numCandidates)
{
    char vote;
    int i;

    printf("Enter your vote (a-e): ");
    scanf(" %c", &vote);

    for (i = 0; i < numCandidates; i++)
    {
        if (candidates[i].name[0] == vote)
        {
            candidates[i].votes++;
            break;
        }
    }

    if (i == numCandidates)
    {
        printf("Invalid vote.\n");
    }
}

int main()
{
    Candidate candidates[MAX_CANDIDATES] = {"Alice", "Bob", "Charlie", "Dave", "Eve"};
    int numCandidates = MAX_CANDIDATES;

    int i;
    for (i = 0; i < MAX_VOTES; i++)
    {
        vote(candidates, numCandidates);
    }

    for (i = 0; i < numCandidates; i++)
    {
        printf("%s has %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}