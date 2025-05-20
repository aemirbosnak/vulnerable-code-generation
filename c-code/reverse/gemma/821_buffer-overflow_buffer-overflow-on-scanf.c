#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  // Define an array of candidates
  char candidates[10][20];
  int numCandidates = 0;

  // Loop to add candidates
  while (1) {
    printf("Enter candidate name: ");
    scanf("%s", candidates[numCandidates]);

    // Check if the candidate name is valid
    if (strlen(candidates[numCandidates]) > 19) {
      printf("Error: candidate name too long.\n");
    } else {
      numCandidates++;
      break;
    }
  }

  // Get the number of voters
  int numVoters;
  printf("Enter number of voters: ");
  scanf("%d", &numVoters);

  // Create an array of voter details
  char voterDetails[numVoters][20];
  int voterVotes[numVoters];

  // Loop to get voter details and votes
  for (int i = 0; i < numVoters; i++) {
    printf("Enter voter name: ");
    scanf("%s", voterDetails[i]);

    // Check if the voter name is valid
    if (strlen(voterDetails[i]) > 19) {
      printf("Error: voter name too long.\n");
    } else {
      printf("Enter voter vote: ");
      scanf("%d", &voterVotes[i]);
    }
  }

  // Calculate the results
  int totalVotes = 0;
  for (int i = 0; i < numCandidates; i++) {
    totalVotes = 0;
    for (int j = 0; j < numVoters; j++) {
      if (strcmp(candidates[i], voterDetails[j]) == 0) {
        totalVotes++;
      }
    }
    printf("Candidate: %s, Total Votes: %d\n", candidates[i], totalVotes);
  }

  return 0;
}
