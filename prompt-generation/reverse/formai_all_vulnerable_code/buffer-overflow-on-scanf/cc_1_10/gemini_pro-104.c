//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// The main function
int main() {
  // Declare the variables
  int num_candidates;
  int num_voters;
  int votes[100][100];
  char candidate_names[100][100];
  char voter_names[100][100];

  // Get the number of candidates
  printf("Enter the number of candidates: ");
  scanf("%d", &num_candidates);

  // Get the names of the candidates
  for (int i = 0; i < num_candidates; i++) {
    printf("Enter the name of candidate %d: ", i + 1);
    scanf("%s", candidate_names[i]);
  }

  // Get the number of voters
  printf("Enter the number of voters: ");
  scanf("%d", &num_voters);

  // Get the names of the voters
  for (int i = 0; i < num_voters; i++) {
    printf("Enter the name of voter %d: ", i + 1);
    scanf("%s", voter_names[i]);
  }

  // Get the votes
  for (int i = 0; i < num_voters; i++) {
    for (int j = 0; j < num_candidates; j++) {
      printf("Enter the vote of voter %s for candidate %s: ", voter_names[i], candidate_names[j]);
      scanf("%d", &votes[i][j]);
    }
  }

  // Print the results
  for (int i = 0; i < num_candidates; i++) {
    int total_votes = 0;
    for (int j = 0; j < num_voters; j++) {
      total_votes += votes[j][i];
    }
    printf("Candidate %s received %d votes.\n", candidate_names[i], total_votes);
  }

  return 0;
}