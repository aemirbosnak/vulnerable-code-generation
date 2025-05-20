//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int candidates = 0, voters = 0;

  printf("Welcome to Electronic Voting System\n\n");

  printf("Enter the number of candidates: ");
  scanf("%d", &candidates);

  printf("\nEnter the number of voters: ");
  scanf("%d", &voters);

  char candidate_name[candidates][50]; // Array to store candidate names
  int candidate_votes[candidates]; // Array to store candidate votes

  for (int i = 0; i < candidates; i++) {
    printf("\nEnter candidate %d name: ", i+1);
    scanf("%s", candidate_name[i]); // reading candidate name with space

    candidate_votes[i] = 0; // initializing all candidate votes as 0
  }

  printf("\nElectronic Voting Machine is ready for use.\nPlease cast your vote.\n");

  for (int i = 0; i < voters; i++) {
    printf("\nVote %d", i+1);

    printf("\nSelect candidate from the following:\n");
    for (int j = 0; j < candidates; j++) {
      printf("%d. %s\n", j+1, candidate_name[j]);
    }

    int vote;
    printf("\nEnter candidate number to vote: ");
    scanf("%d", &vote);

    // validating candidate number
    if (vote < 1 || vote > candidates) {
      printf("\nInvalid candidate number. Please try again.\n");
      i--; // reducing vote count as vote is not valid
      continue; // continue to next iteration
    }

    candidate_votes[vote-1]++; // increase vote count for the candidate
  }

  printf("\nVotes summary:\n");
  for (int i = 0; i < candidates; i++) {
    printf("%d votes - %s\n", candidate_votes[i], candidate_name[i]);
  }

  int max_votes = candidate_votes[0]; // Assume candidate 1 has highest votes
  int max_index = 0; // index of candidate 1

  for (int i = 1; i < candidates; i++) {
    if (candidate_votes[i] > max_votes) {
      max_votes = candidate_votes[i];
      max_index = i;
    }
  }

  printf("\n*** Results ***\n");
  printf("Winner: %s with %d votes.\n", candidate_name[max_index], max_votes);

  return EXIT_SUCCESS;
}