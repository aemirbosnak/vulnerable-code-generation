//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VOTERS 1000
#define MAX_CANDIDATES 10

int main() {

  int voters[MAX_VOTERS];
  int candidates[MAX_CANDIDATES];
  int num_voters, num_candidates;
  int i, j;
  int max_votes = 0, winner = 0;

  srand(time(NULL));

  printf("Welcome to the Electronic Voting System\n");
  printf("Please enter the number of voters: ");
  scanf("%d", &num_voters);
  printf("Please enter the number of candidates: ");
  scanf("%d", &num_candidates);

  for (i = 0; i < num_voters; i++) {
    // surrealistic voter ID generation
    voters[i] = rand() % 10000000000 + 1;
  }

  for (i = 0; i < num_candidates; i++) {
    printf("Please enter the name of candidate %d: ", i+1);
    // surrealistic candidate name
    char candidate_name[20];
    scanf("%s", candidate_name);
    candidates[i] = 0;
  }

  printf("\nLet the voting begin!\n");

  for (i = 0; i < num_voters; i++) {
    int vote = rand() % num_candidates;
    candidates[vote]++;
    printf("Voter %d voted for candidate %d\n", voters[i], vote+1);
  }

  printf("\nVoting has ended!\n");

  for (i = 0; i < num_candidates; i++) {
    printf("Candidate %d received %d votes.\n", i+1, candidates[i]);
    if (candidates[i] > max_votes) {
      max_votes = candidates[i];
      winner = i+1;
    }
  }

  // surrealistic winner announcement
  printf("\nThe winner of the election is... candidate %d with %d votes!", winner, max_votes);

  return 0;
}