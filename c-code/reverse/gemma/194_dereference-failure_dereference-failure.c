#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int numCandidates, numVoters, vote, i, voteArray[100], candidateArray[100];

  printf("Enter the number of candidates: ");
  scanf("%d", &numCandidates);

  printf("Enter the number of voters: ");
  scanf("%d", &numVoters);

  for (i = 0; i < numCandidates; i++) {
    candidateArray[i] = 0;
  }

  for (i = 0; i < numVoters; i++) {
    printf("Enter the vote for candidate %d: ", i + 1);
    scanf("%d", &vote);

    if (vote > numCandidates || vote <= 0) {
      printf("Invalid vote.\n");
    } else {
      voteArray[vote - 1] = 1;
    }
  }

  for (i = 0; i < numCandidates; i++) {
    printf("Candidate %d received %d votes.\n", i + 1, voteArray[i]);
  }

  return 0;
}
