//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Candidate data structure
typedef struct candidate {
  char name[50];
  int votes;
} candidate;

// Voter data structure
typedef struct voter {
  char name[50];
  int hasVoted;
} voter;

// Initialize the candidates
candidate candidates[] = {
  {"Alice", 0},
  {"Bob", 0},
  {"Carol", 0}
};
const int numCandidates = sizeof(candidates) / sizeof(candidates[0]);

// Initialize the voters
voter voters[] = {
  {"John", 0},
  {"Jane", 0},
  {"Tom", 0}
};
const int numVoters = sizeof(voters) / sizeof(voters[0]);

// Function to display the candidates
void displayCandidates() {
  printf("Candidates:\n");
  for (int i = 0; i < numCandidates; i++) {
    printf("%d. %s\n", i + 1, candidates[i].name);
  }
}

// Function to get the candidate by their name
int getCandidateIndex(char *name) {
  for (int i = 0; i < numCandidates; i++) {
    if (strcmp(candidates[i].name, name) == 0) {
      return i;
    }
  }
  return -1;
}

// Function to get the voter by their name
int getVoterIndex(char *name) {
  for (int i = 0; i < numVoters; i++) {
    if (strcmp(voters[i].name, name) == 0) {
      return i;
    }
  }
  return -1;
}

// Function to cast a vote
void castVote(char *candidateName, char *voterName) {
  int candidateIndex = getCandidateIndex(candidateName);
  if (candidateIndex == -1) {
    printf("Invalid candidate name.\n");
    return;
  }

  int voterIndex = getVoterIndex(voterName);
  if (voterIndex == -1) {
    printf("Invalid voter name.\n");
    return;
  }

  if (voters[voterIndex].hasVoted) {
    printf("You have already voted.\n");
    return;
  }

  candidates[candidateIndex].votes++;
  voters[voterIndex].hasVoted = 1;
  printf("Vote cast successfully.\n");
}

// Function to display the results
void displayResults() {
  printf("Results:\n");
  for (int i = 0; i < numCandidates; i++) {
    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
  }
}

// Function to get the winner
candidate getWinner() {
  candidate winner = candidates[0];
  for (int i = 1; i < numCandidates; i++) {
    if (candidates[i].votes > winner.votes) {
      winner = candidates[i];
    }
  }
  return winner;
}

int main() {
  // Display the candidates
  displayCandidates();

  // Get the voter's name
  char voterName[50];
  printf("Enter your name: ");
  gets(voterName);

  // Get the candidate's name
  char candidateName[50];
  printf("Enter the candidate you want to vote for: ");
  gets(candidateName);

  // Cast the vote
  castVote(candidateName, voterName);

  // Display the results
  displayResults();

  // Get the winner
  candidate winner = getWinner();
  printf("The winner is: %s\n", winner.name);

  return 0;
}