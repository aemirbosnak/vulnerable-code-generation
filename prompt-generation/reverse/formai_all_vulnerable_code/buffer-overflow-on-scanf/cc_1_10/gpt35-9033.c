//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: complete
#include <stdio.h>
#include <stdlib.h>

int main() {
  int voterID;
  int vote;
  int numCandidates = 3;  // replace with number of candidates in the election
  int candidates[numCandidates][2];
  int i, j;

  // initialize candidates array
  for (i = 0; i < numCandidates; i++) {
    candidates[i][0] = i + 1;
    candidates[i][1] = 0;
  }

  // prompt user for voter ID
  printf("Please enter your voter ID: ");
  scanf("%d", &voterID);

  // check if voter ID is valid
  if (voterID < 1000 || voterID > 9999) {
    printf("Invalid voter ID.\n");
    exit(0);
  }

  // prompt user to enter their vote
  printf("Please enter your vote (1-%d): ", numCandidates);
  scanf("%d", &vote);

  // check if vote is valid
  if (vote < 1 || vote > numCandidates) {
    printf("Invalid vote.\n");
    exit(0);
  }

  // record the vote
  for (i = 0; i < numCandidates; i++) {
    if (candidates[i][0] == vote) {
      candidates[i][1]++;
      break;
    }
  }

  // display vote summary
  printf("Thank you for voting!\n");
  printf("Voter ID: %d\n", voterID);
  printf("Your vote: %d\n", vote);

  printf("Vote summary:\n");
  for (i = 0; i < numCandidates; i++) {
    printf("Candidate %d: %d\n", candidates[i][0], candidates[i][1]);
  }

  return 0;
}