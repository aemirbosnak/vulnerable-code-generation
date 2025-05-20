//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: optimized
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
    int numCandidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    for (int i = 0; i < numCandidates; i++)
    {
        candidates[i].name[0] = '\0';
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
    }

    int numVotes;
    printf("Enter the number of votes: ");
    scanf("%d", &numVotes);

    for (int i = 0; i < numVotes; i++)
    {
        char candidate;
        printf("Enter the name of the candidate you voted for: ");
        scanf("%s", &candidate);
        vote(candidate);
    }

    int winner = -1;
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        if (candidates[i].votes > winner)
        {
            winner = i;
        }
    }

    if (winner != -1)
    {
        printf("The winner is: %s", candidates[winner].name);
    }
    else
    {
        printf("There has not been a winner.");
    }

    return 0;
}