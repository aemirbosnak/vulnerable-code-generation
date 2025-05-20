//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: futuristic
#include <stdio.h>
#include <stdbool.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000

// Define the candidate struct
typedef struct {
  char name[50];
  int votes;
} candidate_t;

// Define the voter struct
typedef struct {
  char name[50];
  int vote;
  bool hasVoted;
} voter_t;

// Helper functions
void print_candidates(candidate_t candidates[], int num_candidates) {
  printf("Candidates:\n");
  for (int i = 0; i < num_candidates; i++) {
    printf("%s\n", candidates[i].name);
  }
}

void print_voter(voter_t voter) {
  printf("Name: %s\n", voter.name);
  printf("Vote: %d\n", voter.vote);
}

void print_voters(voter_t voters[], int num_voters) {
  printf("Voters:\n");
  for (int i = 0; i < num_voters; i++) {
    printf("%s\n", voters[i].name);
  }
}

void print_results(candidate_t candidates[], int num_candidates) {
  printf("Results:\n");
  for (int i = 0; i < num_candidates; i++) {
    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
  }
}

int main() {
  // Initialize candidates
  candidate_t candidates[MAX_CANDIDATES];
  int num_candidates = 0;
  
  // Initialize voters
  voter_t voters[MAX_VOTERS];
  int num_voters = 0;

  // Get the number of candidates
  printf("Enter the number of candidates: ");
  scanf("%d", &num_candidates);

  // Get the details of each candidate
  for (int i = 0; i < num_candidates; i++) {
    printf("Enter the name of candidate %d: ", i + 1);
    scanf("%s", candidates[i].name);
    candidates[i].votes = 0;
  }

  // Get the number of voters
  printf("Enter the number of voters: ");
  scanf("%d", &num_voters);

  // Get the details of each voter
  for (int i = 0; i < num_voters; i++) {
    printf("Enter the name of voter %d: ", i + 1);
    scanf("%s", voters[i].name);
    voters[i].vote = -1; // Set their vote to -1 (i.e. they haven't voted yet)
    voters[i].hasVoted = false;
  }

  // Let the voting begin!
  int round = 1;
  while (true) {
    printf("\nRound %d:\n", round);

    // Print the candidates
    print_candidates(candidates, num_candidates);

    // Ask each voter to cast their vote
    for (int i = 0; i < num_voters; i++) {
      if (voters[i].hasVoted) {
        continue; // Skip this voter
      }
      printf("\n%s, please cast your vote:\n", voters[i].name);
      for (int j = 0; j < num_candidates; j++) {
        printf("%d: %s\n", j + 1, candidates[j].name);
      }

      // Take their vote
      int vote = 0;
      scanf("%d", &vote);
      if (vote < 1 || vote > num_candidates) {
        printf("Invalid vote!\n");
        continue;
      }
      voters[i].vote = vote - 1; // Store their vote (minus 1 to convert to zero-based indexing)
      candidates[voters[i].vote].votes++; // Add a vote to the candidate they voted for
      voters[i].hasVoted = true; // Mark them as having voted
    }

    // Check if all voters have voted
    bool allVoted = true;
    for (int i = 0; i < num_voters; i++) {
      if (!voters[i].hasVoted) {
        allVoted = false;
        break;
      }
    }

    // If all voters have voted, end the election
    if (allVoted) {
      printf("\nAll voters have cast their votes!\n");

      // Print the final results
      print_results(candidates, num_candidates);
      break;
    }

    // Otherwise, continue to the next round
    round++;
  }

  return 0;
}