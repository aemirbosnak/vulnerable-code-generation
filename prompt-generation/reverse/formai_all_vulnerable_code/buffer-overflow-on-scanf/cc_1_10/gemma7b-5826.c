//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate
{
    char name[20];
    int votes;
} Candidate;

void vote(Candidate *candidates, int *votes)
{
    char vote_choice;
    printf("Enter your vote choice (a-e): ");
    scanf(" %c", &vote_choice);

    switch (vote_choice)
    {
        case 'a':
            candidates[0].votes++;
            break;
        case 'b':
            candidates[1].votes++;
            break;
        case 'c':
            candidates[2].votes++;
            break;
        case 'd':
            candidates[3].votes++;
            break;
        case 'e':
            candidates[4].votes++;
            break;
        default:
            printf("Invalid vote choice.\n");
    }

    (*votes)++;
}

int main()
{
    Candidate candidates[MAX_CANDIDATES] = {
        {"John Doe", 0},
        {"Jane Doe", 0},
        {"Peter Pan", 0},
        {"Mary Poppins", 0},
        {"Captain Hook", 0}
    };

    int votes = 0;

    while (votes < MAX_VOTES)
    {
        vote(candidates, &votes);
    }

    printf("Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}