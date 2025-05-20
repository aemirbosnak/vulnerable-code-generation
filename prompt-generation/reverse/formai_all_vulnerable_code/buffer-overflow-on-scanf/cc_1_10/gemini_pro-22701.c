//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define the number of candidates
#define NUM_CANDIDATES 5

// Define the maximum number of votes per candidate
#define MAX_VOTES 1000

// Create an array to store the number of votes for each candidate
int votes[NUM_CANDIDATES];

// Create an array to store the names of the candidates
char *candidates[NUM_CANDIDATES] = {"Alice", "Bob", "Carol", "Dave", "Eve"};

// Create a function to print the results of the election
void print_results() {
  // Find the winner of the election
  int winner = 0;
  for (int i = 1; i < NUM_CANDIDATES; i++) {
    if (votes[i] > votes[winner]) {
      winner = i;
    }
  }

  // Print the name of the winner
  printf("The winner of the election is %s!\n", candidates[winner]);

  // Print the number of votes for each candidate
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    printf("%s received %d votes.\n", candidates[i], votes[i]);
  }
}

// Create a function to allow the user to vote
void vote() {
  // Get the user's input
  int candidate;
  printf("Which candidate do you want to vote for? (Enter a number from 1 to %d)\n", NUM_CANDIDATES);
  scanf("%d", &candidate);

  // Validate the user's input
  if (candidate < 1 || candidate > NUM_CANDIDATES) {
    printf("Invalid candidate number. Please enter a number from 1 to %d\n", NUM_CANDIDATES);
    return;
  }

  // Increment the number of votes for the selected candidate
  votes[candidate - 1]++;

  // Thank the user for voting
  printf("Thank you for voting!\n");
}

// Create a function to start the election
void start_election() {
  // Initialize the number of votes for each candidate to 0
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    votes[i] = 0;
  }

  // Allow the user to vote
  for (int i = 0; i < MAX_VOTES; i++) {
    vote();
  }

  // Print the results of the election
  print_results();
}

int main() {
  // Start the election
  start_election();

  return 0;
}