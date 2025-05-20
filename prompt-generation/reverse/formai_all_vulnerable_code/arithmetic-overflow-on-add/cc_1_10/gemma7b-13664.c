//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CANDIDATES 5
#define NUM_VOTES 100

typedef struct Voter {
  char name[50];
  int vote;
  struct Voter* next;
} Voter;

typedef struct Poll {
  char candidate[NUM_CANDIDATES][50];
  int votes[NUM_CANDIDATES];
  struct Poll* next;
} Poll;

void addVoter(Voter** head) {
  Voter* newVoter = (Voter*)malloc(sizeof(Voter));
  newVoter->next = NULL;

  if (*head == NULL) {
    *head = newVoter;
  } else {
    (*head)->next = newVoter;
  }
}

void addPoll(Poll** head) {
  Poll* newPoll = (Poll*)malloc(sizeof(Poll));
  newPoll->next = NULL;

  if (*head == NULL) {
    *head = newPoll;
  } else {
    (*head)->next = newPoll;
  }
}

void vote(Voter* voter, Poll* poll) {
  int voteChoice = voter->vote;
  poll->votes[voteChoice]++;
}

int main() {
  Voter* head = NULL;
  Poll* poll = NULL;

  // Add voters
  addVoter(&head);
  addVoter(&head);
  addVoter(&head);

  // Add polls
  addPoll(&poll);
  addPoll(&poll);
  addPoll(&poll);

  // Vote
  vote(head, poll);
  vote(head, poll);
  vote(head, poll);

  // Print results
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    printf("%s: %d votes\n", poll->candidate[i], poll->votes[i]);
  }

  return 0;
}