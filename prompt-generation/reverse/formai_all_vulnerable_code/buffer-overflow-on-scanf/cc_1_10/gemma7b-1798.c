//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CANDIDATES 5

struct Candidate {
  char name[20];
  int votes;
  int is_winner;
};

void vote(struct Candidate *candidates) {
  char voter_choice;
  printf("Please enter your vote:");
  scanf(" %c", &voter_choice);

  switch (voter_choice) {
    case 'a':
      candidates[0].votes++;
      break;
    case 'b':
      candidates[1].votes++;
      break;
    case 'c':
      candidates[2].votes++;
      break;
    case 'd':
      candidates[3].votes++;
      break;
    case 'e':
      candidates[4].votes++;
      break;
    default:
      printf("Invalid vote.");
  }
}

int main() {
  struct Candidate candidates[NUM_CANDIDATES] = {
    {"John Doe", 0, 0},
    {"Jane Doe", 0, 0},
    {"Peter Pan", 0, 0},
    {"Mary Poppins", 0, 0},
    {"Captain Hook", 0, 0}
  };

  vote(candidates);

  for (int i = 0; i < NUM_CANDIDATES; i++) {
    printf("%s has received %d votes.\n", candidates[i].name, candidates[i].votes);
  }

  candidates[0].is_winner = 1;
  printf("The winner is: %s.\n", candidates[0].name);

  return 0;
}