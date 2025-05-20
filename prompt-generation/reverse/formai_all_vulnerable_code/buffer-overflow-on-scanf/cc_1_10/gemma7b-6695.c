//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5

typedef struct Candidate
{
    char name[20];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(char *candidate)
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
    int i;
    char vote_choice[20];

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        candidates[i].votes = 0;
    }

    // Get candidate's name
    printf("Enter the candidate's name: ");
    scanf("%s", vote_choice);

    // Vote
    vote(vote_choice);

    // Display results
    printf("Results:\n");
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}