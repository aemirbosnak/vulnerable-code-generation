//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10

typedef struct Candidate
{
    char name[20];
    int votes;
} Candidate;

void vote(Candidate *candidates, int numCandidates)
{
    char voteChoice[20];
    int i;

    printf("Please enter the name of the candidate you want to vote for:");
    scanf("%s", voteChoice);

    for (i = 0; i < numCandidates; i++)
    {
        if (strcmp(candidates[i].name, voteChoice) == 0)
        {
            candidates[i].votes++;
            printf("Thank you for voting for %s!", candidates[i].name);
            break;
        }
    }

    if (i == numCandidates)
    {
        printf("Error: Invalid candidate name");
    }
}

int main()
{
    Candidate candidates[MAX_CANDIDATES];
    int numCandidates = 0;

    printf("Welcome to the Electronic Voting System!\n");

    while (1)
    {
        char choice;

        printf("Would you like to vote (Y/N)? ");
        scanf("%c", &choice);

        if (choice == 'Y' || choice == 'y')
        {
            vote(candidates, numCandidates);
            numCandidates++;
        }
        else if (choice == 'N' || choice == 'n')
        {
            break;
        }
        else
        {
            printf("Invalid input. Please try again.");
        }
    }

    printf("Thank you for voting. The results are:");

    for (int i = 0; i < numCandidates; i++)
    {
        printf("\n%s: %d votes", candidates[i].name, candidates[i].votes);
    }

    return 0;
}