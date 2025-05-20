//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter
{
  char name[20];
  int vote;
  struct Voter *next;
} Voter;

void insertVoter(Voter **head)
{
  Voter *newVoter = (Voter *)malloc(sizeof(Voter));
  printf("Enter your name: ");
  scanf("%s", newVoter->name);
  newVoter->vote = 0;
  newVoter->next = NULL;

  if (*head == NULL)
  {
    *head = newVoter;
  }
  else
  {
    (*head)->next = newVoter;
  }
}

void vote(Voter **head)
{
  printf("Enter the number of the candidate you want to vote for (1-%d): ", MAX_CANDIDATES);
  int candidateNumber;
  scanf("%d", &candidateNumber);

  Voter *currentVoter = *head;
  while (currentVoter)
  {
    if (strcmp(currentVoter->name, (*head)->name) == 0)
    {
      currentVoter->vote = candidateNumber;
      break;
    }
    currentVoter = currentVoter->next;
  }

  if (currentVoter == NULL)
  {
    printf("Error: Voter not found.\n");
  }
}

void displayResults(Voter **head)
{
  int totalVotes = 0;
  for (Voter *currentVoter = *head; currentVoter; currentVoter = currentVoter->next)
  {
    totalVotes++;
  }

  printf("Total number of votes: %d\n", totalVotes);

  int candidateVotes[MAX_CANDIDATES];
  for (int i = 0; i < MAX_CANDIDATES; i++)
  {
    candidateVotes[i] = 0;
  }

  for (Voter *currentVoter = *head; currentVoter; currentVoter = currentVoter->next)
  {
    candidateVotes[currentVoter->vote - 1]++;
  }

  printf("Candidate votes:\n");
  for (int i = 0; i < MAX_CANDIDATES; i++)
  {
    printf("Candidate %d: %d votes\n", i + 1, candidateVotes[i]);
  }
}

int main()
{
  Voter *head = NULL;

  insertVoter(&head);
  insertVoter(&head);
  insertVoter(&head);
  insertVoter(&head);
  insertVoter(&head);

  vote(&head);
  vote(&head);
  vote(&head);

  displayResults(&head);

  return 0;
}