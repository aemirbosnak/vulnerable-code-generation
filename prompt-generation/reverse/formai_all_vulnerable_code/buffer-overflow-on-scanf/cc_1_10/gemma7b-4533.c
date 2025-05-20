//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: statistical
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

Candidate candidates[MAX_CANDIDATES];

void initializeCandidates()
{
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }
}

void addVote(char candidateName)
{
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        if (strcmp(candidates[i].name, candidateName) == 0)
        {
            candidates[i].votes++;
            return;
        }
    }

    // Candidate not found, error
    printf("Error: Invalid candidate name.\n");
}

void printResults()
{
    int totalVotes = 0;
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        totalVotes += candidates[i].votes;
    }

    printf("Total votes: %d\n", totalVotes);
}

int main()
{
    initializeCandidates();

    // Voting loop
    for (int i = 0; i < MAX_VOTES; i++)
    {
        char candidateName[20];
        printf("Enter candidate name: ");
        scanf("%s", candidateName);

        addVote(candidateName);
    }

    printResults();

    return 0;
}