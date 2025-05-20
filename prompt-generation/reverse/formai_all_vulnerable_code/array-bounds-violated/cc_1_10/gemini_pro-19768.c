//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The number of candidates
#define NUM_CANDIDATES 5

// The number of voters
#define NUM_VOTERS 100

// The name of each candidate
char *candidates[NUM_CANDIDATES] = {"Alice", "Bob", "Carol", "Dave", "Eve"};

// The number of votes for each candidate
int votes[NUM_CANDIDATES];

// The main function
int main() {
  // Initialize the votes to 0
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    votes[i] = 0;
  }

  // Get the votes from the voters
  for (int i = 0; i < NUM_VOTERS; i++) {
    // Get the voter's name
    char name[256];
    printf("What is your name? ");
    scanf("%s", name);

    // Get the voter's vote
    int vote;
    printf("Who do you want to vote for? ");
    scanf("%d", &vote);

    // Increment the vote count for the voter's candidate
    votes[vote]++;
  }

  // Find the winner
  int max_votes = 0;
  int winner = -1;
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    if (votes[i] > max_votes) {
      max_votes = votes[i];
      winner = i;
    }
  }

  // Print the winner
  printf("The winner is %s with %d votes.\n", candidates[winner], max_votes);

  return 0;
}