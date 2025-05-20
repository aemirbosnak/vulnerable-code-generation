#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int numCandidates, numVoters, i, vote, candidateIndex, winner = 0;
  char **candidatesName = NULL;
  int **votes = NULL;

  printf("Enter the number of candidates: ");
  scanf("%d", &numCandidates);

  candidatesName = (char **)malloc(numCandidates * sizeof(char *));
  votes = (int **)malloc(numCandidates * sizeof(int *));

  for (i = 0; i < numCandidates; i++) {
    candidatesName[i] = (char *)malloc(20 * sizeof(char));
    votes[i] = (int *)malloc(numVoters * sizeof(int));
  }

  printf("Enter the number of voters: ");
  scanf("%d", &numVoters);

  for (i = 0; i < numVoters; i++) {
    printf("Enter the voter's name: ");
    scanf("%s", candidatesName[i]);

    printf("Enter the voter's vote: ");
    scanf("%d", &vote);

    votes[candidateIndex][i] = vote;
  }

  for (i = 0; i < numCandidates; i++) {
    winner = votes[i][0] > winner ? i : winner;
  }

  printf("The winner is: %s", candidatesName[winner]);

  return 0;
}
