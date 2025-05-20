//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate {
  char name[20];
  int votes;
} Candidate;

void displayCandidates(Candidate candidates[]) {
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
  }
}

void vote(Candidate candidates[], int voter_id) {
  printf("Enter the candidate's name: ");
  char candidate_name[20];
  scanf("%s", candidate_name);

  for (int i = 0; i < MAX_CANDIDATES; i++) {
    if (strcmp(candidates[i].name, candidate_name) == 0) {
      candidates[i].votes++;
      printf("Your vote has been cast.\n");
      break;
    }
  }

  if (strcmp(candidate_name, "") == 0) {
    printf("Error: Invalid candidate name.\n");
  }
}

int main() {
  Candidate candidates[MAX_CANDIDATES];
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    candidates[i].name[0] = '\0';
    candidates[i].votes = 0;
  }

  int voter_id = 0;
  printf("Enter your voter ID: ");
  scanf("%d", &voter_id);

  vote(candidates, voter_id);

  displayCandidates(candidates);

  return 0;
}