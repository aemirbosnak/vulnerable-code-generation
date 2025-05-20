//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: genius
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

void vote(char candidate) {
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    if (strcmp(candidates[i].name, candidate) == 0) {
      candidates[i].votes++;
      break;
    }
  }
}

int main() {
  // Initialize candidates
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    candidates[i].name[0] = '\0';
    candidates[i].votes = 0;
  }

  // Voting loop
  for (int i = 0; i < MAX_VOTES; i++) {
    printf("Enter candidate's name: ");
    char candidate;
    scanf("%c", &candidate);

    vote(candidate);
  }

  // Print results
  printf("Results:\n");
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    if (candidates[i].votes > 0) {
      printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
  }

  return 0;
}