//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CANDIDATES 5

// Candidate names and vote counts
char *candidates[NUM_CANDIDATES] = {"Alice", "Bob", "Carol", "Dave", "Eve"};
int votes[NUM_CANDIDATES] = {0, 0, 0, 0, 0};

// Get the user's vote
int get_vote() {
  int choice;
  printf("Enter your vote (1-%d): ", NUM_CANDIDATES);
  scanf("%d", &choice);
  return choice - 1;  // Adjust for 0-based array
}

// Cast a vote for a candidate
void cast_vote(int candidate) {
  votes[candidate]++;
}

// Find the winning candidate
int find_winner() {
  int winner = 0;
  for (int i = 1; i < NUM_CANDIDATES; i++) {
    if (votes[i] > votes[winner]) {
      winner = i;
    }
  }
  return winner;
}

// Print the election results
void print_results() {
  printf("Election Results:\n");
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    printf("%s: %d votes\n", candidates[i], votes[i]);
  }
  printf("Winner: %s\n", candidates[find_winner()]);
}

int main() {
  // Get the number of voters
  int num_voters;
  printf("Enter the number of voters: ");
  scanf("%d", &num_voters);

  // Get the votes from the voters
  for (int i = 0; i < num_voters; i++) {
    cast_vote(get_vote());
  }

  // Print the election results
  print_results();

  return 0;
}