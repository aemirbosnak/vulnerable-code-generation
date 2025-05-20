//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: realistic
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

void vote(char candidate)
{
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        if (candidates[i].name[0] == candidate)
        {
            candidates[i].votes++;
        }
    }
}

int main()
{
    int i, j;
    char vote_choice;

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        candidates[i].votes = 0;
    }

    // Register voters
    printf("Enter the number of voters: ");
    scanf("%d", &j);

    // Vote for candidates
    for (i = 0; i < j; i++)
    {
        printf("Enter the candidate's name: ");
        scanf(" %c", &vote_choice);

        vote(vote_choice);
    }

    // Print results
    printf("\nResults:");
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("Candidate: %s, Votes: %d\n", candidates[i].name, candidates[i].votes);
    }

    // Determine winner
    int winner = 0;
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        if (candidates[i].votes > candidates[winner].votes)
        {
            winner = i;
        }
    }

    // Print winner
    printf("\nWinner: %s\n", candidates[winner].name);

    return 0;
}