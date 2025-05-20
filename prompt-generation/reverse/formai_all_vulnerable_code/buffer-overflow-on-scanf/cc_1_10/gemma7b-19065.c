//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: medieval
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

void vote(Candidate *candidate)
{
    candidate->votes++;
}

int main()
{
    int i, vote_count;
    char choice;

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }

    // Get candidate names
    for (i = 0; candidates[i].name[0] != '\0'; i++)
    {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
    }

    // Vote
    printf("Please select a candidate: ");
    scanf("%c", &choice);

    // Validate vote
    if (choice > 'a' && choice <= 'A' + MAX_CANDIDATES - 1)
    {
        vote(&candidates[choice - 'a']);
    }
    else
    {
        printf("Invalid vote.\n");
    }

    // Print results
    printf("Results:\n");
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Calculate winner
    vote_count = candidates[0].votes;
    for (i = 1; i < MAX_CANDIDATES; i++)
    {
        if (candidates[i].votes > vote_count)
        {
            vote_count = candidates[i].votes;
            candidates[i].name[0] = 'W';
        }
    }

    // Print winner
    printf("The winner is: %s\n", candidates[0].name);

    return 0;
}