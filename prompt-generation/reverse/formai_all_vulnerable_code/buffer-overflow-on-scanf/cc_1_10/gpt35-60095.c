//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: all-encompassing
#include <stdio.h>

// defining constants for maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// defining a structure for a candidate
struct candidate {
  char name[50];
  int voteCount;
};

// function to print the candidates and their vote count
void print_result(struct candidate candidates[], int numCandidates) {
  printf("\n\nResults:\n");

  for (int i = 0; i < numCandidates; i++) {
    printf("%s: %d votes\n", candidates[i].name, candidates[i].voteCount);
  }
}

int main() {
  // initializing variables
  int numCandidates, numVoters;
  struct candidate candidates[MAX_CANDIDATES];
  int vote[MAX_VOTERS];

  // prompting user to enter number of candidates
  printf("Enter the number of candidates (max %d): ", MAX_CANDIDATES);
  scanf("%d", &numCandidates);

  // prompting user to enter the names of candidates
  for (int i = 0; i < numCandidates; i++) {
    printf("\nEnter the name of candidate %d: ", i+1);
    scanf("%s", candidates[i].name);

    // initializing vote count to 0
    candidates[i].voteCount = 0;
  }

  // prompting user to enter number of voters
  printf("\nEnter the number of voters (max %d): ", MAX_VOTERS);
  scanf("%d", &numVoters);

  // prompting user to enter the votes of each voter
  for (int i = 0; i < numVoters; i++) {
    printf("\nEnter the vote of voter %d (1 to %d): ", i+1, numCandidates);

    int v;
    scanf("%d", &v);

    // validating the vote
    if (v < 1 || v > numCandidates) {
      printf("\nInvalid vote. Try again.");
      i--;
      continue;
    }

    // adding the vote to the candidate's vote count
    candidates[v-1].voteCount++;
  }

  // printing the result
  print_result(candidates, numCandidates);

  return 0;
}