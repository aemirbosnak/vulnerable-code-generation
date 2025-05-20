//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: portable
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

void vote(char candidate)
{
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        if (candidates[i].name[0] == candidate)
        {
            candidates[i].votes++;
        }
    }
}

int main()
{
    int i, n;
    char candidate;

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }

    // Get the number of voters
    printf("Enter the number of voters: ");
    scanf("%d", &n);

    // Vote
    for (i = 0; i < n; i++)
    {
        printf("Enter the candidate's name: ");
        scanf(" %c", &candidate);
        vote(candidate);
    }

    // Print the results
    printf("\nThe results are:");
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        if (candidates[i].name[0] != '\0')
        {
            printf("\n%s: %d votes", candidates[i].name, candidates[i].votes);
        }
    }

    return 0;
}