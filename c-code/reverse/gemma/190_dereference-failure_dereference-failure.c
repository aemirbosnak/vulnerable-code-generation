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

  if (numCandidates == 0 || numCandidates < 0) {
    printf("Error: Invalid number of candidates.\n");
    return 1;
  }

  char **candidates = (char **)malloc(numCandidates * sizeof(char *));
  for (int i = 0; i < numCandidates; i++) {
    candidates[i] = (char *)malloc(20 * sizeof(char));
    printf("Enter the name of candidate %d: ", i + 1);
    scanf("%s", candidates[i]);
  }

  int numVotes;
  printf("Enter the number of votes you want to cast: ");
  scanf("%d", &numVotes);

  int **votes = (int *)malloc(numCandidates * sizeof(int));
  for (int i = 0; i < numCandidates; i++) {
    votes[i] = 0;
  }

  for (int i = 0; i < numVotes; i++) {
    int candidateVote;
    printf("Enter the number of the candidate you want to vote for: ");
    scanf("%d", &candidateVote);

    if (candidateVote > numCandidates || candidateVote <= 0) {
      printf("Error: Invalid vote.\n");
      continue;
    }

    votes[candidateVote - 1]++;
  }

  int winner = -1;
  int maxVotes = 0;
  for (int i = 0; i < numCandidates; i++) {
    if (votes[i] > maxVotes) {
      maxVotes = votes[i];
      winner = i;
    }
  }

  if (winner == -1) {
    printf("There is no winner.\n");
  } else {
    printf("The winner is: %s.\n", candidates[winner]);
  }

  return 0;
}
