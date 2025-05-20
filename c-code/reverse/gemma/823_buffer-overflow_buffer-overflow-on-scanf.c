#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int numCandidates = 0;
  char **candidates = NULL;
  int votes[100] = {0};

  // Add candidate
  printf("Enter the name of the candidate: ");
  char candidateName[20];
  scanf("%s", candidateName);

  candidates = realloc(candidates, (numCandidates + 1) * sizeof(char *));
  candidates[numCandidates] = malloc(20 * sizeof(char));
  strcpy(candidates[numCandidates], candidateName);
  numCandidates++;

  // Record vote
  printf("Enter the name of the candidate you voted for: ");
  char voteCandidateName[20];
  scanf("%s", voteCandidateName);

  for (int i = 0; i < numCandidates; i++) {
    if (strcmp(voteCandidateName, candidates[i]) == 0) {
      votes[i]++;
    }
  }

  // Display results
  printf("The results of the election are:\n");
  for (int i = 0; i < numCandidates; i++) {
    printf("%s received %d votes.\n", candidates[i], votes[i]);
  }

  return 0;
}
