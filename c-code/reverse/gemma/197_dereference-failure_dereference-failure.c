#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int numCandidates, numVoters, i, vote, candidateVotes[10] = {0};
  printf("Enter the number of candidates:");
  scanf("%d", &numCandidates);

  printf("Enter the number of voters:");
  scanf("%d", &numVoters);

  for (i = 0; i < numVoters; i++) {
    printf("Enter the vote for voter %d:", i + 1);
    scanf("%d", &vote);

    if (vote > numCandidates || vote < 1) {
      printf("Invalid vote.\n");
    } else {
      candidateVotes[vote - 1]++;
    }
  }

  for (i = 0; i < numCandidates; i++) {
    printf("Candidate %d received %d votes.\n", i + 1, candidateVotes[i]);
  }

  return 0;
}
