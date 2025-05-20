//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

typedef struct Candidate
{
    char name[20];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(int voter_id)
{
    int candidate_id;

    printf("Enter the candidate ID: ");
    scanf("%d", &candidate_id);

    if (candidate_id < 0 || candidate_id >= MAX_CANDIDATES)
    {
        printf("Invalid candidate ID.\n");
        return;
    }

    candidates[candidate_id].votes++;
}

int main()
{
    int i;
    int num_voters;

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    for (i = 0; i < num_voters; i++)
    {
        vote(i);
    }

    printf("Results:");

    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("Candidate: %s, Votes: %d\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}