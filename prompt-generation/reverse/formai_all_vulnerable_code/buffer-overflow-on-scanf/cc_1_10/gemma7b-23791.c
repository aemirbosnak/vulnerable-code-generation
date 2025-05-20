//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5

typedef struct Candidate {
  char name[20];
  int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES] = {
  {"John Doe", 0},
  {"Jane Doe", 0},
  {"Peter Pan", 0},
  {"Mary Poppins", 0},
  {"Captain America", 0}
};

void vote(char *candidate) {
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    if (strcmp(candidates[i].name, candidate) == 0) {
      candidates[i].votes++;
      break;
    }
  }
}

int main() {
  // Voting booth setup
  printf("Welcome to the Electronic Voting Booth!\n");

  // Candidate selection
  printf("Please select a candidate:\n");
  char candidate[20];
  scanf("%s", candidate);

  // Voting
  vote(candidate);

  // Results
  printf("The results are in:\n");
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    printf("%s has received %d votes.\n", candidates[i].name, candidates[i].votes);
  }

  // Thank you
  printf("Thank you for voting!\n");

  return 0;
}