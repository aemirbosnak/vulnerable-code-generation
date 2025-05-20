//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: scalable
#include <stdio.h>

typedef struct {
  char candidate_name[20];
  int votes;
} Candidate;

int main() {
  Candidate candidates[5];
  int num_candidates = 0;
  int num_voters = 0;
  int i, j;

  printf("Enter number of candidates: ");
  scanf("%d", &num_candidates);

  for (i = 0; i < num_candidates; i++) {
    printf("Enter candidate %d's name: ", i+1);
    scanf("%s", candidates[i].candidate_name);
    candidates[i].votes = 0;
  }

  printf("Enter number of voters: ");
  scanf("%d", &num_voters);

  for (i = 0; i < num_voters; i++) {
    printf("Voter %d, please enter your vote (1-%d): ", i+1, num_candidates);
    int vote;
    scanf("%d", &vote);

    // check if vote is valid
    if (vote < 1 || vote > num_candidates) {
      printf("Invalid vote, please enter a number between 1 and %d.\n", num_candidates);
      i--; // redo this iteration
      continue;
    }

    // increment vote count for candidate
    candidates[vote-1].votes++;
  }

  printf("\nElection Results:\n");
  for (i = 0; i < num_candidates; i++) {
    printf("%s: %d votes\n", candidates[i].candidate_name, candidates[i].votes);
  }

  // find winner(s)
  int max_votes = candidates[0].votes;
  for (i = 1; i < num_candidates; i++) {
    if (candidates[i].votes > max_votes) {
      max_votes = candidates[i].votes;
    }
  }
  printf("\nWinner(s):\n");
  for (i = 0; i < num_candidates; i++) {
    if (candidates[i].votes == max_votes) {
      printf("%s\n", candidates[i].candidate_name);
    }
  }

  return 0;
}