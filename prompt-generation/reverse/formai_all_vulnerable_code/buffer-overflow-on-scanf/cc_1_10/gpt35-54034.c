//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a candidate
typedef struct candidate {
  int id;
  char name[50];
  int votes;
} Candidate;

// Define a struct to represent a voter
typedef struct voter {
  int id;
  char name[50];
  int voted;
} Voter;

// Function to print the candidates
void print_candidates(Candidate* candidates, int num_candidates) {
  printf("\nList of candidates:\n");
  for (int i = 0; i < num_candidates; i++) {
    printf("%d. %s\n", candidates[i].id, candidates[i].name);
  }
}

// Function to print the voters
void print_voters(Voter* voters, int num_voters) {
  printf("\nList of voters:\n");
  for (int i = 0; i < num_voters; i++) {
    printf("%d. %s\n", voters[i].id, voters[i].name);
  }
}

int main() {
  // Define the candidates
  int num_candidates = 3;
  Candidate candidates[num_candidates];
  candidates[0].id = 1;
  strcpy(candidates[0].name, "John Smith");
  candidates[0].votes = 0;
  candidates[1].id = 2;
  strcpy(candidates[1].name, "Jane Doe");
  candidates[1].votes = 0;
  candidates[2].id = 3;
  strcpy(candidates[2].name, "Bob Brown");
  candidates[2].votes = 0;

  // Define the voters
  int num_voters = 5;
  Voter voters[num_voters];
  voters[0].id = 1;
  strcpy(voters[0].name, "Alice");
  voters[0].voted = 0;
  voters[1].id = 2;
  strcpy(voters[1].name, "Bob");
  voters[1].voted = 0;
  voters[2].id = 3;
  strcpy(voters[2].name, "Charlie");
  voters[2].voted = 0;
  voters[3].id = 4;
  strcpy(voters[3].name, "David");
  voters[3].voted = 0;
  voters[4].id = 5;
  strcpy(voters[4].name, "Eve");
  voters[4].voted = 0;

  // Print the candidates and voters
  print_candidates(candidates, num_candidates);
  print_voters(voters, num_voters);

  // Start the voting process
  int vote_count = 0;
  while (vote_count < num_voters) {
    printf("\nEnter ID of voter: ");
    int voter_id;
    scanf("%d", &voter_id);

    // Check if voter has already voted
    int voter_index = -1;
    for (int i = 0; i < num_voters; i++) {
      if (voters[i].id == voter_id) {
        voter_index = i;
        break;
      }
    }
    if (voter_index == -1) {
      printf("Error: Invalid voter ID\n");
      continue;
    }
    if (voters[voter_index].voted) {
      printf("Error: Voter has already voted\n");
      continue;
    }

    // Print the candidates again for the voter to see
    print_candidates(candidates, num_candidates);

    // Ask the voter to select a candidate
    printf("\nEnter ID of candidate: ");
    int candidate_id;
    scanf("%d", &candidate_id);

    // Check if the candidate is valid
    int candidate_index = -1;
    for (int i = 0; i < num_candidates; i++) {
      if (candidates[i].id == candidate_id) {
        candidate_index = i;
        break;
      }
    }
    if (candidate_index == -1) {
      printf("Error: Invalid candidate ID\n");
      continue;
    }

    // Add the vote to the candidate
    candidates[candidate_index].votes++;
    printf("Vote recorded for %s\n", candidates[candidate_index].name);

    // Mark the voter as voted
    voters[voter_index].voted = 1;

    // Increase the vote count
    vote_count++;
  }

  // Print the final results
  printf("\nFinal vote count:\n");
  for (int i = 0; i < num_candidates; i++) {
    printf("%s: %d\n", candidates[i].name, candidates[i].votes);
  }

  return 0;
}