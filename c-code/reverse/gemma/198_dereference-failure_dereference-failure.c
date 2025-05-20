#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int numCandidates, numVoters, i, voteCount[100], candidateName[100][20];
  printf("Enter the number of candidates: ");
  scanf("%d", &numCandidates);

  // Allocate memory for candidates and votes
  candidateName[numCandidates][20] = (char *)malloc(numCandidates * 20 * sizeof(char));
  voteCount[numCandidates] = (int *)malloc(numCandidates * sizeof(int));

  // Get candidate names and votes
  for (i = 0; i < numCandidates; i++) {
    printf("Enter the name of candidate %d: ", i + 1);
    scanf("%s", candidateName[i][0]);
    printf("Enter the number of votes for candidate %d: ", i + 1);
    scanf("%d", &voteCount[i]);
  }

  // Process votes
  int totalVotes = 0;
  for (i = 0; i < numCandidates; i++) {
    totalVotes += voteCount[i];
  }

  // Announce the winner
  int winner = 0;
  for (i = 0; i < numCandidates; i++) {
    if (voteCount[i] > voteCount[winner]) {
      winner = i;
    }
  }

  printf("The winner is: %s", candidateName[winner][0]);

  // Free memory
  free(candidateName[numCandidates][20]);
  free(voteCount[numCandidates]);

  return 0;
}
