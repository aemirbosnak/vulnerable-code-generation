//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate {
  char name[20];
  int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(Candidate* candidate) {
  candidate->votes++;
}

int main() {
  int i, vote_count, candidate_index;
  char vote_choice;

  // Initialize candidates
  for (i = 0; i < MAX_CANDIDATES; i++) {
    candidates[i].name[0] = '\0';
    candidates[i].votes = 0;
  }

  // Get vote count
  printf("Enter the number of votes: ");
  scanf("%d", &vote_count);

  // Cast votes
  for (i = 0; i < vote_count; i++) {
    printf("Enter the candidate's number: ");
    scanf("%d", &candidate_index);

    // Validate vote
    if (candidate_index < 0 || candidate_index >= MAX_CANDIDATES) {
      printf("Error: invalid candidate index.\n");
    } else {
      vote(&candidates[candidate_index]);
    }
  }

  // Print results
  printf("Results:\n");
  for (i = 0; i < MAX_CANDIDATES; i++) {
    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
  }

  // Find winner
  Candidate* winner = NULL;
  for (i = 0; i < MAX_CANDIDATES; i++) {
    if (winner == NULL || candidates[i].votes > winner->votes) {
      winner = &candidates[i];
    }
  }

  // Announce winner
  if (winner) {
    printf("Winner: %s\n", winner->name);
  } else {
    printf("No winner.\n");
  }

  return 0;
}