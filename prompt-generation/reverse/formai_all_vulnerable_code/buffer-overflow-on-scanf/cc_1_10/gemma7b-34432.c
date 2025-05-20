//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
    int i, vote_count, total_votes = 0;
    char candidate;

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        candidates[i].votes = 0;
    }

    // Get the number of votes
    printf("Enter the number of votes: ");
    scanf("%d", &vote_count);

    // Cast votes
    for (i = 0; i < vote_count; i++)
    {
        printf("Enter the candidate's name: ");
        scanf("%c", &candidate);

        vote(&candidate);
    }

    // Print the results
    printf("\n");
    printf("The results are: ");
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        total_votes += candidates[i].votes;
    }

    printf("\nTotal votes cast: %d", total_votes);

    return 0;
}