//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate
{
    char name[50];
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

    // Register voters
    for (i = 0; i < MAX_VOTES; i++)
    {
        printf("Enter the candidate you want to vote for: ");
        scanf(" %c", &vote_choice);
        vote(vote_choice);
    }

    // Print results
    printf("Results:\n");
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Find the winner
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        if (candidates[i].votes > candidates[0].votes)
        {
            printf("The winner is: %s\n", candidates[i].name);
            break;
        }
    }

    return 0;
}