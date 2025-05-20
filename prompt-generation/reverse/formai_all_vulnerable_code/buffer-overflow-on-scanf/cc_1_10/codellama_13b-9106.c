//Code Llama-13B DATASET v1.0 Category: Electronic Voting System ; Style: accurate
// Electronic Voting System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store candidate information
struct candidate {
  char name[50];
  int votes;
};

// Structure to store voter information
struct voter {
  char name[50];
  char id[10];
};

// Function to add a new candidate to the system
void addCandidate(struct candidate *candidates, int *numCandidates) {
  // Get input from user
  char name[50];
  printf("Enter the name of the candidate: ");
  scanf("%s", name);

  // Check if candidate already exists
  for (int i = 0; i < *numCandidates; i++) {
    if (strcmp(name, candidates[i].name) == 0) {
      printf("Candidate already exists.\n");
      return;
    }
  }

  // Add candidate to the system
  strcpy(candidates[*numCandidates].name, name);
  candidates[*numCandidates].votes = 0;
  (*numCandidates)++;
  printf("Candidate added successfully.\n");
}

// Function to add a new voter to the system
void addVoter(struct voter *voters, int *numVoters) {
  // Get input from user
  char name[50];
  char id[10];
  printf("Enter the name of the voter: ");
  scanf("%s", name);
  printf("Enter the voter's ID: ");
  scanf("%s", id);

  // Check if voter already exists
  for (int i = 0; i < *numVoters; i++) {
    if (strcmp(id, voters[i].id) == 0) {
      printf("Voter already exists.\n");
      return;
    }
  }

  // Add voter to the system
  strcpy(voters[*numVoters].name, name);
  strcpy(voters[*numVoters].id, id);
  (*numVoters)++;
  printf("Voter added successfully.\n");
}

// Function to cast a vote
void castVote(struct candidate *candidates, int *numCandidates, struct voter *voters, int *numVoters) {
  // Get input from user
  char id[10];
  char name[50];
  int candidateIndex;
  printf("Enter the voter's ID: ");
  scanf("%s", id);
  printf("Enter the candidate's name: ");
  scanf("%s", name);

  // Find the voter
  for (int i = 0; i < *numVoters; i++) {
    if (strcmp(id, voters[i].id) == 0) {
      candidateIndex = i;
      break;
    }
  }

  // Cast the vote
  for (int i = 0; i < *numCandidates; i++) {
    if (strcmp(name, candidates[i].name) == 0) {
      candidates[i].votes++;
      printf("Vote casted successfully.\n");
      return;
    }
  }

  printf("Invalid vote.\n");
}

// Function to print the results
void printResults(struct candidate *candidates, int *numCandidates) {
  // Print the results
  for (int i = 0; i < *numCandidates; i++) {
    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
  }
}

int main() {
  // Initialize variables
  struct candidate candidates[50];
  int numCandidates = 0;
  struct voter voters[50];
  int numVoters = 0;

  // Add candidates and voters
  addCandidate(candidates, &numCandidates);
  addVoter(voters, &numVoters);

  // Cast votes
  castVote(candidates, &numCandidates, voters, &numVoters);

  // Print results
  printResults(candidates, &numCandidates);

  return 0;
}