//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5

typedef struct Candidate {
  char name[20];
  int votes;
} Candidate;

void display_candidates(Candidate candidates[]) {
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
  }
}

void vote(Candidate candidates[]) {
  char voter_name[20];
  printf("Enter your name: ");
  scanf("%s", voter_name);

  char candidate_name[20];
  printf("Enter the candidate's name: ");
  scanf("%s", candidate_name);

  for (int i = 0; i < MAX_CANDIDATES; i++) {
    if (strcmp(candidates[i].name, candidate_name) == 0) {
      candidates[i].votes++;
      break;
    }
  }

  printf("Thank you for voting, %s!\n", voter_name);
}

int main() {
  Candidate candidates[MAX_CANDIDATES] = {
    {"John Doe", 0},
    {"Jane Doe", 0},
    {"Peter Pan", 0},
    {"Mary Poppins", 0},
    {"Captain Hook", 0}
  };

  display_candidates(candidates);

  vote(candidates);

  display_candidates(candidates);

  return 0;
}