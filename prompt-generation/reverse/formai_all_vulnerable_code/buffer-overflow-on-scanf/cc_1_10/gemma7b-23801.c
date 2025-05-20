//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: immersive
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
    char vote_choice;

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        candidates[i].votes = 0;
    }

    // Create a virtual ballot box
    printf("Welcome to the Electronic Voting System!\n");
    printf("Please select a candidate: ");

    // Get the voter's choice
    scanf("%c", &vote_choice);

    // Cast the vote
    vote(&vote_choice);

    // Display the results
    printf("The results are:");
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        printf(" %s: %d votes", candidates[i].name, candidates[i].votes);
    }

    return 0;
}