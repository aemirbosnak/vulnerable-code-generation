//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 5

typedef struct Candidate
{
    char name[20];
    int votes;
} Candidate;

void vote(Candidate *candidates, int numCandidates)
{
    char vote;
    printf("Enter your vote (a-e): ");
    scanf(" %c", &vote);

    for (int i = 0; i < numCandidates; i++)
    {
        if (vote == candidates[i].name[0])
        {
            candidates[i].votes++;
            break;
        }
    }

    printf("Thank you for voting!\n");
}

int main()
{
    Candidate candidates[MAX_CANDIDATES] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Charlie", 0},
        {"Dave", 0},
        {"Eve", 0}
    };

    int numCandidates = MAX_CANDIDATES;

    vote(candidates, numCandidates);

    for (int i = 0; i < numCandidates; i++)
    {
        printf("%s has received %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}