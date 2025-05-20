//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: standalone
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
    int i;
    char vote_choice;

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        candidates[i].votes = 0;
    }

    // Get candidate's name
    printf("Enter the name of the candidate you want to vote for: ");
    scanf("%s", candidates[0].name);

    // Validate vote
    vote_choice = getchar();
    while (vote_choice < 'a' || vote_choice > 'z')
    {
        printf("Invalid vote. Please try again: ");
        scanf("%c", &vote_choice);
    }

    // Cast vote
    vote(vote_choice);

    // Print results
    printf("The results of the election are:\n");
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}