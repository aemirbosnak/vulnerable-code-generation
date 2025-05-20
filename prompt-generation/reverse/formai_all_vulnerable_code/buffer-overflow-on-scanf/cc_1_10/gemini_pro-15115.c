//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int votes;
} Candidate;

int main() {
  int num_candidates, num_voters;
  scanf("%d %d", &num_candidates, &num_voters);

  Candidate *candidates = malloc(sizeof(Candidate) * num_candidates);
  for (int i = 0; i < num_candidates; i++) {
    candidates[i].name = malloc(256);
    scanf("%s", candidates[i].name);
    candidates[i].votes = 0;
  }

  char **voters = malloc(sizeof(char *) * num_voters);
  for (int i = 0; i < num_voters; i++) {
    voters[i] = malloc(256);
    scanf("%s", voters[i]);
  }

  for (int i = 0; i < num_voters; i++) {
    int vote;
    scanf("%d", &vote);
    candidates[vote - 1].votes++;
  }

  int max_votes = 0;
  int winner = -1;
  for (int i = 0; i < num_candidates; i++) {
    if (candidates[i].votes > max_votes) {
      max_votes = candidates[i].votes;
      winner = i;
    }
  }

  printf("%s\n", candidates[winner].name);

  for (int i = 0; i < num_candidates; i++) {
    free(candidates[i].name);
  }
  free(candidates);

  for (int i = 0; i < num_voters; i++) {
    free(voters[i]);
  }
  free(voters);

  return 0;
}