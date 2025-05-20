//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate {
  char name[20];
  int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(char candidate) {
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    if (strcmp(candidates[i].name, candidate) == 0) {
      candidates[i].votes++;
    }
  }
}

int main() {
  // Initialize candidates
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    candidates[i].votes = 0;
  }

  // Get the number of votes
  int numVotes = 0;
  printf("Enter the number of votes: ");
  scanf("%d", &numVotes);

  // Vote
  for (int i = 0; i < numVotes; i++) {
    char candidate;
    printf("Enter the candidate's name: ");
    scanf("%s", candidate);

    vote(candidate);
  }

  // Print the results
  printf("The results are:\n");
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
  }

  return 0;
}