//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5

typedef struct Candidate
{
    char name[20];
    int votes;
} Candidate;

void vote(Candidate *candidates, int numCandidates)
{
    int i;
    char vote;

    printf("Please select a candidate: ");
    scanf(" %c", &vote);

    for (i = 0; i < numCandidates; i++)
    {
        if (candidates[i].name[0] == vote)
        {
            candidates[i].votes++;
            break;
        }
    }

    printf("Thank you for voting!\n");
}

int main()
{
    Candidate candidates[MAX_CANDIDATES] = {
        {"John Doe", 0},
        {"Jane Doe", 0},
        {"Bill Smith", 0},
        {"Mary Jones", 0},
        {"Bob Green", 0}
    };

    int numCandidates = MAX_CANDIDATES;

    while (1)
    {
        vote(candidates, numCandidates);

        printf("Would you like to vote again? (Y/N): ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'N')
        {
            break;
        }
    }

    int i;
    for (i = 0; i < numCandidates; i++)
    {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}