//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int votes;
} Candidate;

int main() {
  // Initialize the candidates
  Candidate candidates[] = {
    {"Alice", 0},
    {"Bob", 0},
    {"Charlie", 0}
  };

  // Get the number of voters
  int num_voters;
  printf("Enter the number of voters: ");
  scanf("%d", &num_voters);

  // Get the votes
  for (int i = 0; i < num_voters; i++) {
    // Get the voter's choice
    char choice[256];
    printf("Enter your choice (Alice, Bob, or Charlie): ");
    scanf("%s", choice);

    // Find the candidate with the given name
    Candidate *candidate = NULL;
    for (int j = 0; j < sizeof(candidates) / sizeof(Candidate); j++) {
      if (strcmp(candidates[j].name, choice) == 0) {
        candidate = &candidates[j];
        break;
      }
    }

    // If the candidate was not found, print an error message
    if (candidate == NULL) {
      printf("Invalid choice\n");
      continue;
    }

    // Increment the candidate's vote count
    candidate->votes++;
  }

  // Find the winner
  Candidate *winner = NULL;
  int max_votes = 0;
  for (int i = 0; i < sizeof(candidates) / sizeof(Candidate); i++) {
    if (candidates[i].votes > max_votes) {
      winner = &candidates[i];
      max_votes = candidates[i].votes;
    }
  }

  // Print the results
  printf("The winner is %s with %d votes\n", winner->name, winner->votes);

  return 0;
}