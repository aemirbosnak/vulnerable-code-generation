//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CANDIDATES 3
#define NUM_VOTES 20

typedef struct Candidate
{
    char name[20];
    int votes;
} Candidate;

Candidate candidates[NUM_CANDIDATES] = {
    {"Romeo", 0},
    {"Juliet", 0},
    {"Mercutio", 0}
};

void vote(char voter_name, char candidate_name)
{
    int i = 0;
    for (i = 0; i < NUM_CANDIDATES; i++)
    {
        if (strcmp(candidates[i].name, candidate_name) == 0)
        {
            candidates[i].votes++;
            break;
        }
    }
}

int main()
{
    int i = 0;
    for (i = 0; i < NUM_VOTES; i++)
    {
        char voter_name[20];
        char candidate_name[20];

        printf("Enter voter name: ");
        scanf("%s", voter_name);

        printf("Enter candidate name: ");
        scanf("%s", candidate_name);

        vote(voter_name, candidate_name);
    }

    for (i = 0; i < NUM_CANDIDATES; i++)
    {
        printf("%s has %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}