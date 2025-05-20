//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate
{
    char name[20];
    int votes;
} Candidate;

void vote(Candidate *candidates, int numCandidates)
{
    char voteStr[20];
    printf("Enter your vote for candidate: ");
    scanf("%s", voteStr);

    for (int i = 0; i < numCandidates; i++)
    {
        if (strcmp(voteStr, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            printf("Your vote has been cast for %s.\n", candidates[i].name);
            return;
        }
    }

    printf("Invalid vote. Please try again.\n");
}

int main()
{
    Candidate candidates[MAX_CANDIDATES] = {
        {"John Doe", 0},
        {"Jane Doe", 0},
        {"Peter Pan", 0},
        {"Mary Poppins", 0},
        {"The Wizard of Oz", 0}
    };

    int numCandidates = MAX_CANDIDATES;

    time_t t = time(NULL);
    srand(t);

    for (int i = 0; i < MAX_VOTES; i++)
    {
        vote(candidates, numCandidates);
    }

    int winner = -1;
    for (int i = 0; i < numCandidates; i++)
    {
        if (candidates[i].votes > winner)
        {
            winner = i;
        }
    }

    if (winner != -1)
    {
        printf("The winner is: %s.\n", candidates[winner].name);
    }
    else
    {
        printf("No winner.\n");
    }

    return 0;
}