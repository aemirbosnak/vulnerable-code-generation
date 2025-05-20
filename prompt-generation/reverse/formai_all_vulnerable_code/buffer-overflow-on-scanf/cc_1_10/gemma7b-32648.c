//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter
{
    char name[50];
    int vote_count;
    struct Voter* next;
} Voter;

typedef struct Ballot
{
    char candidate_name[50];
    int votes_received;
    struct Ballot* next;
} Ballot;

void add_voter(Voter** head)
{
    Voter* new_voter = (Voter*)malloc(sizeof(Voter));
    printf("Enter your name: ");
    scanf("%s", new_voter->name);
    new_voter->vote_count = 0;
    new_voter->next = *head;
    *head = new_voter;
}

void add_ballot(Ballot** head)
{
    Ballot* new_ballot = (Ballot*)malloc(sizeof(Ballot));
    printf("Enter the candidate's name: ");
    scanf("%s", new_ballot->candidate_name);
    new_ballot->votes_received = 0;
    new_ballot->next = *head;
    *head = new_ballot;
}

void vote(Voter* voter, Ballot* ballot)
{
    int vote_choice;
    printf("Enter your vote choice: ");
    scanf("%d", &vote_choice);
    if (vote_choice > MAX_CANDIDATES || vote_choice < 1)
    {
        printf("Invalid vote choice.\n");
    }
    else
    {
        ballot->votes_received++;
        voter->vote_count++;
    }
}

void print_results(Ballot* head)
{
    Ballot* current_ballot = head;
    while (current_ballot)
    {
        printf("%s received %d votes.\n", current_ballot->candidate_name, current_ballot->votes_received);
        current_ballot = current_ballot->next;
    }
}

int main()
{
    Voter* head_voter = NULL;
    Ballot* head_ballot = NULL;

    // Add voters and ballots
    add_voter(&head_voter);
    add_ballot(&head_ballot);
    add_voter(&head_voter);
    add_ballot(&head_ballot);

    // Vote
    vote(head_voter, head_ballot);

    // Print results
    print_results(head_ballot);

    return 0;
}