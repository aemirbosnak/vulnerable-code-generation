//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  int votes;
} Candidate;

int main() {
  // Initialize the candidates
  Candidate candidates[4] = {
    {"Alice", 0},
    {"Bob", 0},
    {"Carol", 0},
    {"Dave", 0}
  };

  // Get the number of voters
  int numVoters;
  printf("Enter the number of voters: ");
  scanf("%d", &numVoters);

  // Get the votes from each voter
  for (int i = 0; i < numVoters; i++) {
    // Get the voter's name
    char voterName[50];
    printf("Enter your name: ");
    scanf("%s", voterName);

    // Get the voter's vote
    int vote;
    printf("Enter your vote (1-4): ");
    scanf("%d", &vote);

    // Increment the vote count for the selected candidate
    candidates[vote - 1].votes++;
  }

  // Find the winner
  int maxVotes = 0;
  int winnerIndex = 0;
  for (int i = 0; i < 4; i++) {
    if (candidates[i].votes > maxVotes) {
      maxVotes = candidates[i].votes;
      winnerIndex = i;
    }
  }

  // Print the winner
  printf("The winner is: %s\n", candidates[winnerIndex].name);

  return 0;
}