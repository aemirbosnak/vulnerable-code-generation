//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Define the number of candidates and voters
#define NUM_CANDIDATES 5
#define NUM_VOTERS 100

// Define the data structure for a candidate
struct candidate {
  char name[100];
  int votes;
};

// Define the data structure for a voter
struct voter {
  int id;
  int voted_for;
};

// Create an array of candidates
struct candidate candidates[NUM_CANDIDATES];

// Create an array of voters
struct voter voters[NUM_VOTERS];

// Get the input data
void get_input() {
  // Get the names of the candidates
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    printf("Enter the name of candidate %d: ", i + 1);
    scanf("%s", candidates[i].name);
    candidates[i].votes = 0;
  }

  // Get the IDs of the voters
  for (int i = 0; i < NUM_VOTERS; i++) {
    printf("Enter the ID of voter %d: ", i + 1);
    scanf("%d", &voters[i].id);
    voters[i].voted_for = -1;
  }
}

// Simulate the voting process
void simulate_voting() {
  // Randomly generate the votes for each voter
  for (int i = 0; i < NUM_VOTERS; i++) {
    int candidate_index = rand() % NUM_CANDIDATES;
    voters[i].voted_for = candidate_index;
    candidates[candidate_index].votes++;
  }
}

// Count the votes
void count_votes() {
  // Initialize the vote count for each candidate to 0
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    candidates[i].votes = 0;
  }

  // Count the votes for each candidate
  for (int i = 0; i < NUM_VOTERS; i++) {
    int candidate_index = voters[i].voted_for;
    candidates[candidate_index].votes++;
  }
}

// Print the results
void print_results() {
  // Find the winner
  int winner_index = -1;
  int max_votes = -1;
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    if (candidates[i].votes > max_votes) {
      winner_index = i;
      max_votes = candidates[i].votes;
    }
  }

  // Print the name of the winner
  printf("The winner is: %s\n", candidates[winner_index].name);

  // Print the vote count for each candidate
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
  }
}

// Main function
int main() {
  // Get the input data
  get_input();

  // Simulate the voting process
  simulate_voting();

  // Count the votes
  count_votes();

  // Print the results
  print_results();

  return 0;
}