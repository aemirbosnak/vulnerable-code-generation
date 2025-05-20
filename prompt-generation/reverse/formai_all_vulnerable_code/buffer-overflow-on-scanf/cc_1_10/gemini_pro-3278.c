//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Romeo and Juliet candidate names
#define ROMEO "Romeo"
#define JULIET "Juliet"

// Function to get the vote from the user
char* getVote() {
  char* vote = (char*) malloc(sizeof(char) * 20);
  printf("Enter your vote (Romeo or Juliet): ");
  scanf("%s", vote);
  return vote;
}

// Function to count the votes
int countVotes(char** votes, int numVotes) {
  int romeoVotes = 0;
  int julietVotes = 0;

  for (int i = 0; i < numVotes; i++) {
    if (strcmp(votes[i], ROMEO) == 0) {
      romeoVotes++;
    } else if (strcmp(votes[i], JULIET) == 0) {
      julietVotes++;
    }
  }

  return romeoVotes > julietVotes ? 1 : 2;
}

// Main function
int main() {
  // Number of votes
  int numVotes;
  printf("Enter the number of votes: ");
  scanf("%d", &numVotes);

  // Array to store the votes
  char** votes = (char**) malloc(sizeof(char*) * numVotes);

  // Get the votes from the users
  for (int i = 0; i < numVotes; i++) {
    votes[i] = getVote();
  }

  // Count the votes
  int winner = countVotes(votes, numVotes);

  // Print the winner
  if (winner == 1) {
    printf("Romeo wins!\n");
  } else {
    printf("Juliet wins!\n");
  }

  // Free the memory allocated for the votes
  for (int i = 0; i < numVotes; i++) {
    free(votes[i]);
  }
  free(votes);

  return 0;
}