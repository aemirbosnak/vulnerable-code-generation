//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate
{
    char name[50];
    int votes;
} Candidate;

void vote(Candidate *candidates, int *votes)
{
    char vote_choice[50];
    printf("Enter your vote choice: ");
    scanf("%s", vote_choice);

    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        if (strcmp(vote_choice, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            *votes++;
            break;
        }
    }

    printf("Thank you for voting!\n");
}

int main()
{
    Candidate candidates[MAX_CANDIDATES] = {"John Doe", "Jane Doe", "Peter Pan", "Mary Poppins", "Captain America"};
    int votes = 0;

    while (votes < MAX_VOTES)
    {
        vote(candidates, &votes);
    }

    printf("Election Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    printf("The winner is: %s\n", candidates[0].name);

    return 0;
}