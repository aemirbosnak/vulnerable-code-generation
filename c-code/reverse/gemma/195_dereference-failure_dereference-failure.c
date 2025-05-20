#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *votes = NULL;
  int num_votes = 0;

  // Allocate memory for votes
  votes = malloc(10 * sizeof(int));
  if (votes == NULL) {
    return 1;
  }

  // Get number of votes
  printf("Enter the number of votes: ");
  scanf("%d", &num_votes);

  // Validate input and store votes
  for (int i = 0; i < num_votes; i++) {
    int vote = 0;

    printf("Enter vote: ");
    scanf("%d", &vote);

    if (vote < 1 || vote > 5) {
      printf("Invalid vote. Please try again.\n");
      i--;
    } else {
      votes[i] = vote;
    }
  }

  // Free memory
  free(votes);

  // Print results
  printf("The results are:\n");
  for (int i = 0; i < num_votes; i++) {
    printf("Vote %d: %d\n", i + 1, votes[i]);
  }

  return 0;
}
