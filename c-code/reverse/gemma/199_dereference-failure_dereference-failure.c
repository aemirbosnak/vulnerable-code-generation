#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int numCandidates, numVoters, i, vote, validVote = 0;
  char candidateName[20];

  printf("Enter the number of candidates: ");
  scanf("%d", &numCandidates);

  printf("Enter the number of voters: ");
  scanf("%d", &numVoters);

  for (i = 0; i < numVoters; i++) {
    printf("Enter the voter's name: ");
    scanf("%s", candidateName);

    printf("Enter the voter's vote: ");
    scanf("%d", &vote);

    if (vote > numCandidates || vote <= 0) {
      printf("Invalid vote. Please try again.\n");
    } else {
      validVote++;
    }
  }

  printf("Total number of valid votes: %d\n", validVote);

  return 0;
}
