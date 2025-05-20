//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 10

typedef struct Voter {
  char name[20];
  int vote;
} Voter;

typedef struct Candidate {
  char name[20];
  int votes;
} Candidate;

void vote(Voter *v, Candidate *c) {
  v->vote = c->votes++;
}

int main() {
  Voter voters[MAX_VOTES];
  Candidate candidates[MAX_CANDIDATES];

  // Initialize voters and candidates
  for (int i = 0; i < MAX_VOTES; i++) {
    voters[i].name[0] = '\0';
    voters[i].vote = 0;
  }

  for (int i = 0; i < MAX_CANDIDATES; i++) {
    candidates[i].name[0] = '\0';
    candidates[i].votes = 0;
  }

  // Register voters and candidates
  int num_voters = 0;
  int num_candidates = 0;

  // Vote
  while (1) {
    char voter_name[20];
    char candidate_name[20];

    printf("Enter voter name: ");
    scanf("%s", voter_name);

    printf("Enter candidate name: ");
    scanf("%s", candidate_name);

    // Validate voter and candidate
    for (int i = 0; i < num_voters; i++) {
      if (strcmp(voter_name, voters[i].name) == 0) {
        for (int j = 0; j < num_candidates; j++) {
          if (strcmp(candidate_name, candidates[j].name) == 0) {
            vote(&voters[i], &candidates[j]);
            printf("Vote cast.\n");
            break;
          }
        }
      }
    }

    // Check if voter or candidate is invalid
    if (strcmp(voter_name, "INVALID") == 0) {
      printf("Error: invalid voter.\n");
    } else if (strcmp(candidate_name, "INVALID") == 0) {
      printf("Error: invalid candidate.\n");
    }

    // Ask if voter wants to continue voting
    char continue_voting;
    printf("Do you want to continue voting? (Y/N): ");
    scanf("%c", &continue_voting);

    if (continue_voting == 'N') {
      break;
    }
  }

  // Print results
  for (int i = 0; i < num_candidates; i++) {
    printf("%s has %d votes.\n", candidates[i].name, candidates[i].votes);
  }

  return 0;
}