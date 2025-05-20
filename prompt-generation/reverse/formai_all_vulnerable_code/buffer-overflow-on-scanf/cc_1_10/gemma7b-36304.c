//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

typedef struct Candidate
{
    char name[20];
    int votes;
} Candidate;

void vote(Candidate *candidates, int numCandidates)
{
    char voteChoice[20];
    int i;

    printf("Please enter the name of the candidate you want to vote for: ");
    scanf("%s", voteChoice);

    for (i = 0; i < numCandidates; i++)
    {
        if (strcmp(voteChoice, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            printf("Your vote has been cast for %s.\n", candidates[i].name);
            break;
        }
    }

    if (i == numCandidates)
    {
        printf("Error: invalid vote.\n");
    }
}

int main()
{
    Candidate candidates[MAX_CANDIDATES];
    int numCandidates = 0;
    int i;

    time_t t = time(NULL);
    srand(t);

    // Create candidates
    while (numCandidates < MAX_CANDIDATES)
    {
        printf("Enter the name of a candidate: ");
        scanf("%s", candidates[numCandidates].name);
        candidates[numCandidates].votes = 0;
        numCandidates++;
    }

    // Vote
    vote(candidates, numCandidates);

    // Print results
    printf("The results of the election:\n");
    for (i = 0; i < numCandidates; i++)
    {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}