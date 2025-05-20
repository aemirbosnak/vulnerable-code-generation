//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

struct candidate {
  char name[50];
  int votes;
};

int main() {
  int num_candidates, num_voters, i, j, is_voted = 0;
  struct candidate *candidates;
  int *voter_choices;

  printf("Welcome to the Electronic Voting System!\n\n");

  printf("Enter the number of candidates: ");
  scanf("%d", &num_candidates);

  candidates = (struct candidate*) malloc(num_candidates * sizeof(struct candidate));

  for (i = 0; i < num_candidates; i++) {
    printf("Enter the name of candidate %d: ", i+1);
    scanf("%s", candidates[i].name);
    candidates[i].votes = 0;
  }

  printf("\nEnter the number of voters: ");
  scanf("%d", &num_voters);

  voter_choices = (int*) malloc(num_voters * sizeof(int));

  printf("\nPlease enter your %d choices in order of preference:\n", num_candidates);

  for (i = 0; i < num_voters; i++) {
    printf("\nVoter %d:\n", i+1);
    for (j = 0; j < num_candidates; j++) {
      printf("Rank %d: ", j+1);
      scanf("%d", &voter_choices[i*num_candidates+j]);
    }
  }

  printf("\nThank you for voting!\n\n");

  while (!is_voted) {
    printf("Do you want to view the current vote tally? (y/n) ");
    char response;
    scanf(" %c", &response);
    if (response == 'y') {
      printf("\nCurrent Vote Tally:\n");
      for (i = 0; i < num_candidates; i++) {
        printf("%s: %d\n", candidates[i].name, candidates[i].votes);
      }
    }
    else if (response == 'n') {
      printf("\nThank you for using the Electronic Voting System!\n");
      is_voted = 1;
    }
    else {
      printf("\nInvalid Response.\n");
    }
  }

  free(candidates);
  free(voter_choices);

  return 0;
}