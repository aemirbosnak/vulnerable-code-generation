//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate {
  char name[20];
  int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void initCandidates() {
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    candidates[i].name[0] = '\0';
    candidates[i].votes = 0;
  }
}

void addVote(char candidate) {
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    if (strcmp(candidates[i].name, candidate) == 0) {
      candidates[i].votes++;
      return;
    }
  }

  // Candidate not found, error
  fprintf(stderr, "Error: Invalid candidate name.\n");
}

int main() {
  initCandidates();

  // Register voters
  printf("Enter your name: ");
  char voterName[20];
  scanf("%s", voterName);

  // Vote
  printf("Enter the candidate's name: ");
  char candidateName[20];
  scanf("%s", candidateName);

  addVote(candidateName);

  // Print results
  printf("Results:\n");
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
  }

  return 0;
}