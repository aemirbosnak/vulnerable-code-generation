//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter
{
    char name[20];
    int vote;
    struct Voter* next;
} Voter;

typedef struct Poll
{
    char candidate[MAX_CANDIDATES][20];
    int votes[MAX_CANDIDATES];
    struct Poll* next;
} Poll;

void addVoter(Voter** head)
{
    Voter* newVoter = malloc(sizeof(Voter));
    printf("Enter your name: ");
    scanf("%s", newVoter->name);
    printf("Enter your vote: ");
    scanf("%d", &newVoter->vote);
    *head = newVoter;
}

void addPoll(Poll** head)
{
    Poll* newPoll = malloc(sizeof(Poll));
    printf("Enter the name of candidate 1: ");
    scanf("%s", newPoll->candidate[0]);
    printf("Enter the number of votes for candidate 1: ");
    scanf("%d", &newPoll->votes[0]);
    printf("Enter the name of candidate 2: ");
    scanf("%s", newPoll->candidate[1]);
    printf("Enter the number of votes for candidate 2: ");
    scanf("%d", &newPoll->votes[1]);
    *head = newPoll;
}

void vote(Poll* poll, Voter* voter)
{
    int i = 0;
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        if (strcmp(voter->name, poll->candidate[i]) == 0)
        {
            poll->votes[i]++;
            printf("Your vote has been cast for %s.\n", poll->candidate[i]);
            break;
        }
    }
    if (i == MAX_CANDIDATES)
    {
        printf("Error: Invalid vote.\n");
    }
}

int main()
{
    Voter* head = NULL;
    Poll* poll = NULL;

    addVoter(&head);
    addVoter(&head);
    addPoll(&poll);
    addPoll(&poll);

    vote(poll, head);
    vote(poll, head);

    return 0;
}