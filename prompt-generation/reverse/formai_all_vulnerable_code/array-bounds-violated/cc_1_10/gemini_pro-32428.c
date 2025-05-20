//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Candidate names
char *candidates[] = {"The Amazing Mr. Incredible", "The Incredible Elastigirl", "The Superfast Mr. Frozone", "The Strongest Lumpia Man"};

// Number of candidates
int num_candidates = sizeof(candidates) / sizeof(candidates[0]);

// Function to get the winner of the election
char *get_winner(int *votes) {
  // Find the candidate with the most votes
  int max_votes = 0;
  int winner_index = -1;
  for (int i = 0; i < num_candidates; i++) {
    if (votes[i] > max_votes) {
      max_votes = votes[i];
      winner_index = i;
    }
  }

  // Return the name of the winner
  return candidates[winner_index];
}

int main() {
  // Declare the array of votes
  int votes[num_candidates];

  // Initialize the votes to 0
  for (int i = 0; i < num_candidates; i++) {
    votes[i] = 0;
  }

  // Get the votes from the user
  printf("Welcome to the election! Please cast your votes by entering the numbers of the candidates you want to vote for (separated by spaces):\n");
  char input[100];
  fgets(input, sizeof(input), stdin);

  // Parse the input and count the votes
  char *token = strtok(input, " ");
  while (token != NULL) {
    int candidate_index = atoi(token) - 1;
    if (candidate_index >= 0 && candidate_index < num_candidates) {
      votes[candidate_index]++;
    }
    token = strtok(NULL, " ");
  }

  // Get the winner of the election
  char *winner = get_winner(votes);

  // Print the results of the election
  printf("The winner of the election is: %s\n", winner);

  // Congratulate the winner
  printf("Congratulations, %s! You have won the election!\n", winner);

  return 0;
}