//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: Claude Shannon
// Claude Shannon Electronic Voting System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of candidates
#define NUM_CANDIDATES 5

// Define the number of voters
#define NUM_VOTERS 100

// Define the maximum length of a candidate's name
#define MAX_NAME_LENGTH 20

// Declare the array of candidates
char candidates[NUM_CANDIDATES][MAX_NAME_LENGTH];

// Declare the array of votes
int votes[NUM_CANDIDATES];

// Get the candidate's names from the user
void get_candidates() {
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    printf("Enter the name of candidate %d: ", i + 1);
    scanf("%s", candidates[i]);
  }
}

// Get the votes from the users
void get_votes() {
  for (int i = 0; i < NUM_VOTERS; i++) {
    int vote;
    printf("Enter your vote (1-%d): ", NUM_CANDIDATES);
    scanf("%d", &vote);
    votes[vote - 1]++;
  }
}

// Print the results of the election
void print_results() {
  printf("Election Results:\n");
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    printf("%s: %d votes\n", candidates[i], votes[i]);
  }
}

// Find the winner of the election
int find_winner() {
  int max_votes = 0;
  int winner = -1;
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    if (votes[i] > max_votes) {
      max_votes = votes[i];
      winner = i;
    }
  }
  return winner;
}

int main() {
  // Get the candidate's names
  get_candidates();

  // Get the votes
  get_votes();

  // Print the results
  print_results();

  // Find the winner
  int winner = find_winner();

  // Print the winner
  printf("The winner is: %s\n", candidates[winner]);

  return 0;
}