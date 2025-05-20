//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the candidate structure
typedef struct candidate {
  int id;
  char name[20];
  int votes;
} Candidate;

// Define the voter structure
typedef struct voter {
  int id;
  char name[20];
  int voted;
} Voter;

// Define a function to reset the votes of all candidates
void resetVotes(Candidate candidates[], int numCandidates) {
  int i;
  for (i = 0; i < numCandidates; i++) {
    candidates[i].votes = 0;
  }
}

// Define a function to display all candidates and their votes
void displayResults(Candidate candidates[], int numCandidates) {
  int i;
  printf("Candidate\tVotes\n");
  for (i = 0; i < numCandidates; i++) {
    printf("%s\t\t%d\n", candidates[i].name, candidates[i].votes);
  }
}

// Define the main function
int main() {
  int numCandidates, numVoters, i, j, choice, candidateID, voterID;

  // Declare arrays of candidates and voters
  Candidate candidates[MAX_CANDIDATES];
  Voter voters[MAX_VOTERS];

  // Seed the random number generator
  srand(time(NULL));

  // Get the number of candidates from the user
  printf("Enter the number of candidates: ");
  scanf("%d", &numCandidates);

  // Get the names of all candidates
  for (i = 0; i < numCandidates; i++) {
    printf("Enter the name of candidate %d: ", i + 1);
    scanf("%s", candidates[i].name);
    candidates[i].id = i + 1;
    candidates[i].votes = 0;
  }

  // Reset the candidate votes
  resetVotes(candidates, numCandidates);

  // Get the number of voters from the user
  printf("Enter the number of voters: ");
  scanf("%d", &numVoters);

  // Get the names of all voters
  for (i = 0; i < numVoters; i++) {
    printf("Enter the name of voter %d: ", i + 1);
    scanf("%s", voters[i].name);
    voters[i].id = i + 1;
    voters[i].voted = 0;
  }

  // Loop through all voters and let them vote
  for (i = 0; i < numVoters; i++) {
    // Generate a random candidate ID for the voter to vote for
    candidateID = rand() % numCandidates + 1;

    // Check if the voter has already voted
    if (voters[i].voted) {
      printf("%s has already voted.\n", voters[i].name);
      continue;
    }

    // Let the voter vote for the chosen candidate
    printf("%s, please select a candidate: \n", voters[i].name);
    for (j = 0; j < numCandidates; j++) {
      printf("%d - %s\n", candidates[j].id, candidates[j].name);
    }
    scanf("%d", &choice);

    // Validate the choice and store the vote
    if (choice >= 1 && choice <= numCandidates && candidates[choice - 1].id == candidateID) {
      candidates[choice - 1].votes++;
      voters[i].voted = 1;
      printf("%s has voted for %s.\n", voters[i].name, candidates[choice - 1].name);
    } else {
      printf("Invalid choice!\n");
    }
  }

  // Display the results of the election
  printf("\nElection Results\n");
  displayResults(candidates, numCandidates);

  return 0;
}