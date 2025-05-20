//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define candidate names and vote counts
const char *candidates[] = {"Alice", "Bob", "Charlie", "Dave", "Eve"};
int votes[5] = {0};

// Print the welcome message
void print_welcome() {
  printf("\nWelcome to the Electronic Voting System!\n");
  printf("Please cast your vote for one of the following candidates:\n");
  for (int i = 0; i < 5; i++) {
    printf("%d. %s\n", i + 1, candidates[i]);
  }
  printf("Enter the number of your chosen candidate: ");
}

// Get the user's vote
int get_vote() {
  int vote;
  while (1) {
    scanf("%d", &vote);
    if (vote >= 1 && vote <= 5) {
      return vote - 1;
    } else {
      printf("Invalid vote. Please enter a number between 1 and 5: ");
    }
  }
}

// Print the results of the election
void print_results() {
  printf("\nElection results:\n");
  for (int i = 0; i < 5; i++) {
    printf("%s: %d votes\n", candidates[i], votes[i]);
  }
  int max_votes = 0;
  int winner = -1;
  for (int i = 0; i < 5; i++) {
    if (votes[i] > max_votes) {
      max_votes = votes[i];
      winner = i;
    }
  }
  printf("The winner is: %s\n", candidates[winner]);
}

// Main function
int main() {
  // Print the welcome message
  print_welcome();

  // Get the user's vote
  int vote = get_vote();

  // Increment the vote count for the chosen candidate
  votes[vote]++;

  // Print the results of the election
  print_results();

  return 0;
}