//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

typedef struct Voter
{
    char name[20];
    int vote;
    time_t timestamp;
} Voter;

Voter voters[MAX_VOTES];

void vote(char candidate)
{
    int i;
    for (i = 0; i < MAX_VOTES; i++)
    {
        if (voters[i].vote == candidate)
        {
            return;
        }
    }

    voters[MAX_VOTES - 1].name[0] = candidate;
    voters[MAX_VOTES - 1].vote = candidate;
    voters[MAX_VOTES - 1].timestamp = time(NULL);

    printf("Thank you for voting, %s!\n", voters[MAX_VOTES - 1].name);
}

int main()
{
    int i;
    char candidate;

    // Initialize voters
    for (i = 0; i < MAX_VOTES; i++)
    {
        voters[i].name[0] = '\0';
        voters[i].vote = 0;
        voters[i].timestamp = 0;
    }

    // Get candidate's vote
    printf("Please enter the candidate you want to vote for (1-10): ");
    scanf("%c", &candidate);

    // Validate vote
    if (candidate < 1 || candidate > MAX_CANDIDATES)
    {
        printf("Invalid vote. Please try again.\n");
    }
    else
    {
        vote(candidate);
    }

    return 0;
}