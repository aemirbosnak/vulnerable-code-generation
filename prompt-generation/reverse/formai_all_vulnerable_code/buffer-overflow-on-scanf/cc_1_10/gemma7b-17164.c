//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: single-threaded
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

Candidate candidates[MAX_CANDIDATES];

void vote(char *candidate)
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
    // Initialize candidates
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        candidates[i].votes = 0;
    }

    // Get candidate's name
    char candidate_name[20];
    printf("Enter candidate's name: ");
    scanf("%s", candidate_name);

    // Vote
    vote(candidate_name);

    // Print results
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s has %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}