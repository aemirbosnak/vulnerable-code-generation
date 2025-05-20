//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: complete
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

void vote(Candidate *candidates, int *votes)
{
    int i;
    printf("Enter the number of the candidate you want to vote for: ");
    scanf("%d", &i);

    if (i < 1 || i > MAX_CANDIDATES)
    {
        printf("Invalid input.\n");
        return;
    }

    candidates[i - 1].votes++;
    *votes++;
}

int main()
{
    Candidate candidates[MAX_CANDIDATES];
    int votes = 0;

    // Initialize candidates
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }

    // Vote
    vote(candidates, &votes);

    // Print results
    printf("Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    printf("Total votes: %d\n", votes);

    return 0;
}