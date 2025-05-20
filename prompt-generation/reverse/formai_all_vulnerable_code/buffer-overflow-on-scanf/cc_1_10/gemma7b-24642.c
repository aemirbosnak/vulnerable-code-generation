//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: calm
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

void vote(char candidate)
{
    for (int i = 0; i < MAX_CANDIDATES; i++)
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
    // Initialize candidates
    candidates[0].name[0] = 'A';
    candidates[0].votes = 0;
    candidates[1].name[0] = 'B';
    candidates[1].votes = 0;
    candidates[2].name[0] = 'C';
    candidates[2].votes = 0;
    candidates[3].name[0] = 'D';
    candidates[3].votes = 0;
    candidates[4].name[0] = 'E';
    candidates[4].votes = 0;

    // Voting loop
    char vote_choice;
    printf("Enter the letter of the candidate you want to vote for: ");
    scanf("%c", &vote_choice);

    vote(vote_choice);

    // Print results
    printf("The results of the election are:");
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        printf(" %s: %d votes", candidates[i].name, candidates[i].votes);
    }

    return 0;
}