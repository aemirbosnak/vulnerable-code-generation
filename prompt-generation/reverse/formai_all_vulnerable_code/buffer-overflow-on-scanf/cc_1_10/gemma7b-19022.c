//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CANDIDATES 3
#define NUM_VOTES 100

typedef struct Candidate
{
    char name[20];
    int votes;
} Candidate;

Candidate candidates[NUM_CANDIDATES] = {
    {"Romeo", 0},
    {"Juliet", 0},
    {"Benvolio", 0}
};

void vote(char voter_name)
{
    int i;
    for (i = 0; i < NUM_CANDIDATES; i++)
    {
        if (strcmp(candidates[i].name, voter_name) == 0)
        {
            candidates[i].votes++;
            break;
        }
    }
}

int main()
{
    char voter_name[20];
    int i;

    // Register voters
    for (i = 0; i < NUM_VOTES; i++)
    {
        printf("Enter your name: ");
        scanf("%s", voter_name);
        vote(voter_name);
    }

    // Print results
    printf("Results:\n");
    for (i = 0; i < NUM_CANDIDATES; i++)
    {
        printf("%s has %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    // Determine winner
    Candidate winner = candidates[0];
    for (i = 1; i < NUM_CANDIDATES; i++)
    {
        if (candidates[i].votes > winner.votes)
        {
            winner = candidates[i];
        }
    }

    // Announce winner
    printf("The winner is: %s!\n", winner.name);

    return 0;
}