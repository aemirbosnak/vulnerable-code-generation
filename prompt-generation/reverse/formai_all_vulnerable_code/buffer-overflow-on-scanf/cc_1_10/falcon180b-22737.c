//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num_candidates, num_voters, i, j;
  char **candidate_names;
  int *voter_choices;

  // Prompt user for number of candidates
  printf("Enter number of candidates: ");
  scanf("%d", &num_candidates);

  // Allocate memory for candidate names array
  candidate_names = (char **)malloc(num_candidates * sizeof(char *));

  // Prompt user for each candidate's name and store in array
  for (i = 0; i < num_candidates; i++) {
    printf("Enter candidate %d's name: ", i + 1);
    scanf("%s", candidate_names[i]);
  }

  // Prompt user for number of voters
  printf("Enter number of voters: ");
  scanf("%d", &num_voters);

  // Allocate memory for voter choices array
  voter_choices = (int *)malloc(num_voters * sizeof(int));

  // Prompt each voter for their choice and store in array
  for (i = 0; i < num_voters; i++) {
    printf("Voter %d's choice: ", i + 1);
    scanf("%d", &voter_choices[i]);
  }

  // Count votes for each candidate
  for (i = 0; i < num_candidates; i++) {
    int votes = 0;
    for (j = 0; j < num_voters; j++) {
      if (voter_choices[j] == i + 1) {
        votes++;
      }
    }
    printf("Candidate %s received %d votes.\n", candidate_names[i], votes);
  }

  // Free memory
  for (i = 0; i < num_candidates; i++) {
    free(candidate_names[i]);
  }
  free(candidate_names);
  free(voter_choices);

  return 0;
}