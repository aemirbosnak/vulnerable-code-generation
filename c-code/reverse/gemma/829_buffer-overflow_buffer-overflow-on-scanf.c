#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  int numCandidates = 0;
  char **candidates = NULL;
  int votes[100] = {0};

  // Add candidate
  printf("Enter candidate name: ");
  char candidateName[20];
  scanf("%s", candidateName);
  candidates = realloc(candidates, (numCandidates + 1) * sizeof(char *));
  candidates[numCandidates++] = candidateName;

  // Cast vote
  printf("Enter candidate name: ");
  scanf("%s", candidateName);
  for (int i = 0; i < numCandidates; i++) {
    if (strcmp(candidateName, candidates[i]) == 0) {
      votes[i]++;
    }
  }

  // Display results
  printf("Results:\n");
  for (int i = 0; i < numCandidates; i++) {
    printf("%s received %d votes.\n", candidates[i], votes[i]);
  }

  return 0;
}
