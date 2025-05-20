//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000

// Define the structure of a candidate
typedef struct {
  char name[50];
  int votes;
} candidate_t;

// Define the structure of a voter
typedef struct {
  char name[50];
  int voted;
} voter_t;

// Define the array of candidates
candidate_t candidates[MAX_CANDIDATES];

// Define the array of voters
voter_t voters[MAX_VOTERS];

// Get the number of candidates
int get_num_candidates() {
  int num_candidates;
  printf("Enter the number of candidates: ");
  scanf("%d", &num_candidates);
  return num_candidates;
}

// Get the candidates' names
void get_candidates_names(int num_candidates) {
  for (int i = 0; i < num_candidates; i++) {
    printf("Enter the name of candidate %d: ", i + 1);
    scanf("%s", candidates[i].name);
  }
}

// Get the number of voters
int get_num_voters() {
  int num_voters;
  printf("Enter the number of voters: ");
  scanf("%d", &num_voters);
  return num_voters;
}

// Get the voters' names
void get_voters_names(int num_voters) {
  for (int i = 0; i < num_voters; i++) {
    printf("Enter the name of voter %d: ", i + 1);
    scanf("%s", voters[i].name);
  }
}

// Conduct the election
void conduct_election(int num_candidates, int num_voters) {
  // Initialize the votes of all candidates to 0
  for (int i = 0; i < num_candidates; i++) {
    candidates[i].votes = 0;
  }

  // Loop through each voter
  for (int i = 0; i < num_voters; i++) {
    // Get the voter's choice
    int choice;
    printf("Enter the number of the candidate you want to vote for (%d-%d): ", 1, num_candidates);
    scanf("%d", &choice);

    // Increment the vote count of the chosen candidate
    candidates[choice - 1].votes++;

    // Mark the voter as having voted
    voters[i].voted = 1;
  }
}

// Display the election results
void display_results(int num_candidates) {
  // Find the winner of the election
  int max_votes = 0;
  int winner_index = -1;
  for (int i = 0; i < num_candidates; i++) {
    if (candidates[i].votes > max_votes) {
      max_votes = candidates[i].votes;
      winner_index = i;
    }
  }

  // Display the winner of the election
  printf("The winner of the election is: %s\n", candidates[winner_index].name);

  // Display the vote count of each candidate
  for (int i = 0; i < num_candidates; i++) {
    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
  }
}

int main() {
  // Get the number of candidates
  int num_candidates = get_num_candidates();

  // Get the candidates' names
  get_candidates_names(num_candidates);

  // Get the number of voters
  int num_voters = get_num_voters();

  // Get the voters' names
  get_voters_names(num_voters);

  // Conduct the election
  conduct_election(num_candidates, num_voters);

  // Display the election results
  display_results(num_candidates);

  return 0;
}