//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct candidate {
  char name[100];
  int votes;
} candidate_t;

int main() {
  int num_candidates, num_voters;
  candidate_t *candidates;
  int *votes;

  // Get the number of candidates and voters
  printf("Enter the number of candidates: ");
  scanf("%d", &num_candidates);
  printf("Enter the number of voters: ");
  scanf("%d", &num_voters);

  // Allocate memory for the candidates and votes
  candidates = malloc(sizeof(candidate_t) * num_candidates);
  votes = malloc(sizeof(int) * num_candidates);

  // Get the candidate names and initialize the votes to 0
  for (int i = 0; i < num_candidates; i++) {
    printf("Enter the name of candidate %d: ", i + 1);
    scanf("%s", candidates[i].name);
    votes[i] = 0;
  }

  // Get the votes
  for (int i = 0; i < num_voters; i++) {
    int vote;
    printf("Enter the vote for voter %d: ", i + 1);
    scanf("%d", &vote);
    votes[vote - 1]++;
  }

  // Find the winner
  int max_votes = 0;
  int winner_index = 0;
  for (int i = 0; i < num_candidates; i++) {
    if (votes[i] > max_votes) {
      max_votes = votes[i];
      winner_index = i;
    }
  }

  // Print the winner
  printf("The winner is: %s\n", candidates[winner_index].name);

  // Free the memory
  free(candidates);
  free(votes);

  return 0;
}