//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5

typedef struct Candidate
{
    char name[20];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES] = {
    {"John Doe", 0},
    {"Jane Doe", 0},
    {"Peter Pan", 0},
    {"Mary Poppins", 0},
    {"Captain America", 0}
};

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
    char vote_choice;

    printf("Welcome to the Electronic Voting System!\n");

    // Print candidates
    printf("Available candidates:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Get the voter's choice
    printf("Please enter the name of the candidate you want to vote for: ");
    scanf(" %c", &vote_choice);

    // Validate the vote
    if (vote_choice >= 'a' && vote_choice <= 'e')
    {
        vote(vote_choice);
        printf("Your vote has been cast.\n");
    }
    else
    {
        printf("Invalid vote. Please try again.\n");
    }

    // Print the final results
    printf("The results of the election:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}