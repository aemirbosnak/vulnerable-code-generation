//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate {
  char name[20];
  int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(int voter_id, char candidate_name) {
  int i;
  for (i = 0; i < MAX_CANDIDATES; i++) {
    if (strcmp(candidates[i].name, candidate_name) == 0) {
      candidates[i].votes++;
      break;
    }
  }
}

int main() {
  int i, voter_id, vote_count;
  char candidate_name;

  // Initialize candidates
  for (i = 0; i < MAX_CANDIDATES; i++) {
    candidates[i].name[0] = '\0';
    candidates[i].votes = 0;
  }

  // Simulate voter registration and voting
  voter_id = 0;
  while (voter_id < MAX_VOTES) {
    printf("Enter your voter ID: ");
    scanf("%d", &voter_id);

    printf("Enter the candidate's name: ");
    scanf(" %s", candidates[voter_id].name);

    vote(voter_id, candidates[voter_id].name);
  }

  // Print vote results
  vote_count = 0;
  for (i = 0; i < MAX_CANDIDATES; i++) {
    printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
    vote_count += candidates[i].votes;
  }

  printf("Total number of votes: %d\n", vote_count);

  return 0;
}