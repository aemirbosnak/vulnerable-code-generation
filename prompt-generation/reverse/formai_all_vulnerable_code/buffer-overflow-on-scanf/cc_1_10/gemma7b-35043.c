//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 5

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
            break;
        }
    }
}

int main()
{
    int i, num_votes;

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }

    // Get number of votes
    printf("Enter the number of votes: ");
    scanf("%d", &num_votes);

    // Vote for candidates
    for (i = 0; i < num_votes; i++)
    {
        char candidate;
        printf("Enter the candidate's name: ");
        scanf(" %c", &candidate);

        vote(candidate);
    }

    // Print results
    printf("Results:\n");
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        if (candidates[i].name[0] != '\0')
        {
            printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        }
    }

    return 0;
}