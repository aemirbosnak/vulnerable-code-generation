//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate {
  char name[20];
  int votes;
} Candidate;

void vote(Candidate *candidates, int candidateIndex) {
  candidates[candidateIndex].votes++;
}

int main() {
  Candidate candidates[MAX_CANDIDATES];
  int i, votes, candidateIndex;

  // Initialize candidates
  for (i = 0; i < MAX_CANDIDATES; i++) {
    candidates[i].name[0] = '\0';
    candidates[i].votes = 0;
  }

  // Get votes
  printf("Enter the number of votes: ");
  scanf("%d", &votes);

  // Validate votes
  if (votes < 1 || votes > MAX_VOTES) {
    printf("Invalid number of votes.\n");
    return 1;
  }

  // Get candidate index
  printf("Enter the index of the candidate you want to vote for: ");
  scanf("%d", &candidateIndex);

  // Validate candidate index
  if (candidateIndex < 0 || candidateIndex >= MAX_CANDIDATES) {
    printf("Invalid candidate index.\n");
    return 1;
  }

  // Vote
  vote(candidates, candidateIndex);

  // Display results
  printf("The results of the election:\n");
  for (i = 0; i < MAX_CANDIDATES; i++) {
    printf("%s has received %d votes.\n", candidates[i].name, candidates[i].votes);
  }

  return 0;
}