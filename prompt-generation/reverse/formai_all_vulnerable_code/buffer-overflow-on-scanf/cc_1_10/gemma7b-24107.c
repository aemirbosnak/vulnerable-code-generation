//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CANDIDATES 3

typedef struct Candidate
{
    char name[20];
    int votes;
} Candidate;

Candidate candidates[NUM_CANDIDATES] = {
    {"John Doe", 0},
    {"Jane Doe", 0},
    {"Bob Smith", 0}
};

void vote(char candidate)
{
    for (int i = 0; i < NUM_CANDIDATES; i++)
    {
        if (candidates[i].name[0] == candidate)
        {
            candidates[i].votes++;
        }
    }
}

int main()
{
    char vote_choice;

    // Create a dystopian atmosphere
    printf("Welcome to the Last Election!\n");
    printf("The world is ending, but democracy persists!\n");

    // Get the voter's choice
    printf("Please select a candidate: ");
    scanf("%c", &vote_choice);

    // Validate the vote
    if (vote_choice >= 'a' && vote_choice <= 'c')
    {
        vote(vote_choice);
    }
    else
    {
        printf("Invalid vote.\n");
    }

    // Display the results
    printf("The results are in: \n");
    for (int i = 0; i < NUM_CANDIDATES; i++)
    {
        printf("%s has received %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    // Print a victory message
    printf("Congratulations to the winner! May the future be bright.\n");

    return 0;
}