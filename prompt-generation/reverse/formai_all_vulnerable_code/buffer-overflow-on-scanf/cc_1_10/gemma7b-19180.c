//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
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
    char vote_choice;

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        candidates[i].votes = 0;
    }

    // Get votes
    printf("Please vote for a candidate: ");
    scanf(" %c", &vote_choice);

    // Validate vote
    if (vote_choice >= 'a' && vote_choice <= 'a' + MAX_CANDIDATES - 1)
    {
        vote(vote_choice);
    }
    else
    {
        printf("Invalid vote.");
    }

    // Print results
    printf("\nResults:");
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("  %s: %d votes", candidates[i].name, candidates[i].votes);
    }

    return 0;
}