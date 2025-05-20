//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: synchronous
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

void initializeCandidates() {
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    candidates[i].name[0] = '\0';
    candidates[i].votes = 0;
  }
}

void vote(char* voterName, char* candidateName) {
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    if (strcmp(candidates[i].name, candidateName) == 0) {
      candidates[i].votes++;
    }
  }
}

int main() {
  initializeCandidates();

  // Register voters
  char voterName[20];
  printf("Enter your voter name: ");
  scanf("%s", voterName);

  // Vote for a candidate
  char candidateName[20];
  printf("Enter the candidate name you want to vote for: ");
  scanf("%s", candidateName);

  vote(voterName, candidateName);

  // Print the results
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    printf("%s has received %d votes.\n", candidates[i].name, candidates[i].votes);
  }

  return 0;
}