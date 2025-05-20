//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10

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
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }

    // Register voters
    char voter_name[20];
    printf("Enter your name: ");
    scanf("%s", voter_name);

    // Vote for a candidate
    char candidate_name[20];
    printf("Enter the name of the candidate you want to vote for: ");
    scanf("%s", candidate_name);

    vote(candidate_name);

    // Display the results
    printf("The results of the election:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s has received %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}