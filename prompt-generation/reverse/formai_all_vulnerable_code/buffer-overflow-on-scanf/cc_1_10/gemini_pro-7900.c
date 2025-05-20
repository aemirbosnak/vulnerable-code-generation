//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

typedef struct {
  char *name;
  int votes;
} Candidate;

int main() {
  srand(time(NULL));

  // Initialize the candidates
  Candidate candidates[] = {
    {"Alice", 0},
    {"Bob", 0},
    {"Charlie", 0},
    {"Dave", 0},
    {"Eve", 0}
  };
  const int num_candidates = sizeof(candidates) / sizeof(Candidate);

  // Get the number of voters
  int num_voters;
  printf("Enter the number of voters: ");
  scanf("%d", &num_voters);

  // Get the votes from the voters
  for (int i = 0; i < num_voters; i++) {
    // Get the voter's choice
    int choice;
    do {
      printf("Enter your choice (1-%d): ", num_candidates);
      scanf("%d", &choice);
    } while (choice < 1 || choice > num_candidates);

    // Increment the vote count for the chosen candidate
    candidates[choice - 1].votes++;
  }

  // Find the winner
  int max_votes = INT_MIN;
  int winner_index = -1;
  for (int i = 0; i < num_candidates; i++) {
    if (candidates[i].votes > max_votes) {
      max_votes = candidates[i].votes;
      winner_index = i;
    }
  }

  // Print the winner
  printf("The winner is %s with %d votes.\n", candidates[winner_index].name, max_votes);

  return 0;
}