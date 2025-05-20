//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the candidate names
#define NUM_CANDIDATES 5
const char *candidates[NUM_CANDIDATES] = {"Alice", "Bob", "Carol", "Dave", "Eve"};

// Define the maximum number of votes
#define MAX_VOTES 100

// Define the data structure for a vote
typedef struct {
  char *candidate;
  int num_votes;
} Vote;

// Define the data structure for the election results
typedef struct {
  Vote votes[NUM_CANDIDATES];
  int num_votes;
} ElectionResults;

// Create a new vote
Vote *create_vote(char *candidate) {
  Vote *vote = malloc(sizeof(Vote));
  vote->candidate = candidate;
  vote->num_votes = 1;
  return vote;
}

// Add a vote to the election results
void add_vote(ElectionResults *results, Vote *vote) {
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    if (strcmp(vote->candidate, candidates[i]) == 0) {
      results->votes[i].num_votes++;
      break;
    }
  }
  results->num_votes++;
}

// Get the winner of the election
char *get_winner(ElectionResults *results) {
  int max_votes = 0;
  char *winner = NULL;
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    if (results->votes[i].num_votes > max_votes) {
      max_votes = results->votes[i].num_votes;
      winner = candidates[i];
    }
  }
  return winner;
}

// Print the election results
void print_results(ElectionResults *results) {
  printf("Election Results:\n");
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    printf("%s: %d votes\n", candidates[i], results->votes[i].num_votes);
  }
  printf("Winner: %s\n", get_winner(results));
}

// Main function
int main() {
  // Create the election results
  ElectionResults results;
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    results.votes[i].candidate = candidates[i];
    results.votes[i].num_votes = 0;
  }
  results.num_votes = 0;

  // Get the votes from the user
  char input[MAX_VOTES][21];
  printf("Enter the candidate names (one per line, up to %d):\n", MAX_VOTES);
  for (int i = 0; i < MAX_VOTES; i++) {
    scanf("%s", input[i]);
  }

  // Add the votes to the election results
  for (int i = 0; i < MAX_VOTES; i++) {
    if (strcmp(input[i], "") == 0) {
      break;
    }
    Vote *vote = create_vote(input[i]);
    add_vote(&results, vote);
  }

  // Print the election results
  print_results(&results);

  return 0;
}