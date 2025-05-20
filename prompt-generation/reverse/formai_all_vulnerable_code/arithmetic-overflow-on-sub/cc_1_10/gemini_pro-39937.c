//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Define the number of candidates and voters
#define NUM_CANDIDATES 5
#define NUM_VOTERS 100

// Define the candidate names
char *candidate_names[] = {"Alice", "Bob", "Carol", "Dave", "Eve"};

// Define the vote counts
int vote_counts[NUM_CANDIDATES] = {0};

// Get a vote from a voter
int get_vote() {
  int vote;
  printf("Enter your vote (1-%d): ", NUM_CANDIDATES);
  scanf("%d", &vote);
  return vote - 1;
}

// Tally the votes
void tally_votes() {
  for (int i = 0; i < NUM_VOTERS; i++) {
    int vote = get_vote();
    vote_counts[vote]++;
  }
}

// Find the winner
int find_winner() {
  int max_votes = 0;
  int winner = -1;
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    if (vote_counts[i] > max_votes) {
      max_votes = vote_counts[i];
      winner = i;
    }
  }
  return winner;
}

// Print the results
void print_results() {
  int winner = find_winner();
  printf("The winner is: %s\n", candidate_names[winner]);
  printf("Vote counts:\n");
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    printf("%s: %d\n", candidate_names[i], vote_counts[i]);
  }
}

// Main function
int main() {
  // Tally the votes
  tally_votes();

  // Find the winner
  print_results();

  return 0;
}