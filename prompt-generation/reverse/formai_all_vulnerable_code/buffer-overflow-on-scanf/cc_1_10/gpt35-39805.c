//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: inquisitive
#include <stdio.h>

int main() {
  int total_voters = 1000;
  int candidate1_votes = 0;
  int candidate2_votes = 0;
  int candidate3_votes = 0;

  printf("Welcome to the Electronic Voting System\n");
  printf("There are %d registered voters\n", total_voters);

  for (int i = 1; i <= total_voters; i++) {
    printf("Voter %d, please enter your vote (1, 2, or 3): ", i);

    int vote;
    scanf("%d", &vote);

    switch(vote) {
      case 1:
        candidate1_votes++;
        printf("You have voted for candidate 1\n");
        break;

      case 2:
        candidate2_votes++;
        printf("You have voted for candidate 2\n");
        break;

      case 3:
        candidate3_votes++;
        printf("You have voted for candidate 3\n");
        break;

      default:
        printf("Invalid vote!\n");
    }
  }

  printf("\nVoting has ended!\n");
  printf("Candidate 1 received %d votes\n", candidate1_votes);
  printf("Candidate 2 received %d votes\n", candidate2_votes);
  printf("Candidate 3 received %d votes\n", candidate3_votes);

  int max_votes = candidate1_votes;
  int winning_candidate = 1;

  if (candidate2_votes > max_votes) {
    max_votes = candidate2_votes;
    winning_candidate = 2;
  }

  if (candidate3_votes > max_votes) {
    max_votes = candidate3_votes;
    winning_candidate = 3;
  }

  printf("The winning candidate is candidate %d with %d votes!\n", winning_candidate, max_votes);

  return 0;
}