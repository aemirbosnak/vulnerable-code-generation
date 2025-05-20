//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define the number of candidates
#define NUM_CANDIDATES 4

// Define the names of the candidates
char *candidates[] = {"Alice", "Bob", "Carol", "Dave"};

// Define the number of voters
#define NUM_VOTERS 10

// Define the array of votes
int votes[NUM_VOTERS];

// Get the vote from a voter
int get_vote() {
  int vote;
  printf("Enter your vote (1-%d): ", NUM_CANDIDATES);
  scanf("%d", &vote);
  return vote;
}

// Count the votes
void count_votes() {
  int i;
  for (i = 0; i < NUM_CANDIDATES; i++) {
    votes[i] = 0;
  }
  for (i = 0; i < NUM_VOTERS; i++) {
    votes[votes[i]]++;
  }
}

// Print the results
void print_results() {
  int i;
  for (i = 0; i < NUM_CANDIDATES; i++) {
    printf("%s: %d votes\n", candidates[i], votes[i]);
  }
}

// Main function
int main() {
  int i;

  // Get the votes from the voters
  for (i = 0; i < NUM_VOTERS; i++) {
    votes[i] = get_vote();
  }

  // Count the votes
  count_votes();

  // Print the results
  print_results();

  return 0;
}