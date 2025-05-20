#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int numCandidates;
  printf("Enter the number of candidates: ");
  scanf("%d", &numCandidates);

  int votes[numCandidates];
  for (int i = 0; i < numCandidates; i++) {
    votes[i] = 0;
  }

  printf("Enter the votes for each candidate (separated by commas): ");
  char input[100];
  scanf("%s", input);

  char* token = strtok(input, ",");
  while (token) {
    int candidateIndex = atoi(token) - 1;
    if (candidateIndex >= 0 && candidateIndex < numCandidates) {
      votes[candidateIndex]++;
    }
    token = strtok(NULL, ",");
  }

  printf("The results of the election:\n");
  for (int i = 0; i < numCandidates; i++) {
    printf("Candidate %d: %d votes\n", i + 1, votes[i]);
  }

  return 0;
}
