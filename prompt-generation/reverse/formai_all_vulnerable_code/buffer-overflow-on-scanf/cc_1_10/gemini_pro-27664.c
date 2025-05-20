//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Define the number of candidates
#define NUM_CANDIDATES 5

// Define the maximum number of votes per candidate
#define MAX_VOTES_PER_CANDIDATE 10

// Define the structure of a candidate
typedef struct candidate {
  char name[20];
  int votes;
} candidate;

// Define the array of candidates
candidate candidates[NUM_CANDIDATES];

// Initialize the candidates
void initialize_candidates() {
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    sprintf(candidates[i].name, "Candidate %d", i + 1);
    candidates[i].votes = 0;
  }
}

// Get the vote for a candidate
int get_vote() {
  int vote;

  // Get the vote from the user
  printf("Enter your vote (1-%d): ", NUM_CANDIDATES);
  scanf("%d", &vote);

  // Validate the vote
  if (vote < 1 || vote > NUM_CANDIDATES) {
    printf("Invalid vote. Please enter a value between 1 and %d.\n", NUM_CANDIDATES);
    return -1;
  }

  // Return the vote
  return vote - 1;
}

// Cast a vote for a candidate
void cast_vote(int vote) {
  // Increment the vote count for the candidate
  candidates[vote].votes++;
}

// Print the results of the election
void print_results() {
  // Find the winner of the election
  int winner = 0;
  for (int i = 1; i < NUM_CANDIDATES; i++) {
    if (candidates[i].votes > candidates[winner].votes) {
      winner = i;
    }
  }

  // Print the results
  printf("The winner of the election is %s with %d votes.\n", candidates[winner].name, candidates[winner].votes);
}

// Main function
int main() {
  // Initialize the candidates
  initialize_candidates();

  // Get the votes from the users
  int vote;
  while ((vote = get_vote()) != -1) {
    cast_vote(vote);
  }

  // Print the results of the election
  print_results();

  return 0;
}