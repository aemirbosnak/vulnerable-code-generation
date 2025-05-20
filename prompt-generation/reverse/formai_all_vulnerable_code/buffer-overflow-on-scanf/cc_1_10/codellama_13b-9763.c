//Code Llama-13B DATASET v1.0 Category: Electronic Voting System ; Style: happy
/*
 * A simple C Electronic Voting System example program
 *
 * By Happy Learning
 */

#include <stdio.h>
#include <stdlib.h>

// Structure to store the voting data
struct VotingData {
  char *name;
  char *candidate;
  int vote_count;
};

// Function to display the voting results
void display_results(struct VotingData *data, int num_candidates) {
  printf("Voting Results:\n");
  for (int i = 0; i < num_candidates; i++) {
    printf("%s: %d votes\n", data[i].candidate, data[i].vote_count);
  }
}

// Function to increment the vote count for a given candidate
void increment_vote(struct VotingData *data, int num_candidates, char *candidate) {
  for (int i = 0; i < num_candidates; i++) {
    if (strcmp(data[i].candidate, candidate) == 0) {
      data[i].vote_count++;
      break;
    }
  }
}

// Function to add a new candidate to the voting data
void add_candidate(struct VotingData *data, int num_candidates, char *candidate) {
  data[num_candidates].candidate = candidate;
  data[num_candidates].vote_count = 0;
}

int main() {
  // Initialize the voting data
  struct VotingData data[5];
  int num_candidates = 0;
  add_candidate(data, num_candidates++, "Alice");
  add_candidate(data, num_candidates++, "Bob");
  add_candidate(data, num_candidates++, "Charlie");
  add_candidate(data, num_candidates++, "David");

  // Get the user's input
  char input[100];
  while (1) {
    printf("Enter your vote: ");
    scanf("%s", input);
    if (strcmp(input, "exit") == 0) {
      break;
    }
    increment_vote(data, num_candidates, input);
  }

  // Display the results
  display_results(data, num_candidates);

  return 0;
}