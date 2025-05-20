//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Candidate names
char *candidates[] = {"Alice", "Bob", "Carol", "Dave", "Eve"};

// Number of candidates
int num_candidates = 5;

// Number of voters
int num_voters = 100;

// Votes for each candidate
int votes[5];

// Main function
int main() {
  // Initialize votes to 0
  for (int i = 0; i < num_candidates; i++) {
    votes[i] = 0;
  }

  // Get votes from voters
  for (int i = 0; i < num_voters; i++) {
    // Print candidate names
    printf("Candidate names:\n");
    for (int j = 0; j < num_candidates; j++) {
      printf("%d. %s\n", j + 1, candidates[j]);
    }

    // Get vote
    int vote;
    printf("Enter your vote (1-%d): ", num_candidates);
    scanf("%d", &vote);

    // Check if vote is valid
    if (vote < 1 || vote > num_candidates) {
      printf("Invalid vote. Please try again.\n");
      i--;
      continue;
    }

    // Increment vote count for candidate
    votes[vote - 1]++;
  }

  // Print results
  printf("Election results:\n");
  for (int i = 0; i < num_candidates; i++) {
    printf("%s: %d votes\n", candidates[i], votes[i]);
  }

  // Find the winner
  int winner = 0;
  for (int i = 1; i < num_candidates; i++) {
    if (votes[i] > votes[winner]) {
      winner = i;
    }
  }

  // Print the winner
  printf("The winner is: %s\n", candidates[winner]);

  return 0;
}