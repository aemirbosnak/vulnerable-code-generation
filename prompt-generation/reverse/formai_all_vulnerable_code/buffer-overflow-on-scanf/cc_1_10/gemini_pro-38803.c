//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a candidate
typedef struct candidate {
  char name[20];
  int votes;
} candidate;

// Structure to represent the election
typedef struct election {
  int num_candidates;
  candidate *candidates;
} election;

// Function to create a new election
election *create_election(int num_candidates) {
  election *e = (election *)malloc(sizeof(election));
  e->num_candidates = num_candidates;
  e->candidates = (candidate *)malloc(sizeof(candidate) * num_candidates);
  return e;
}

// Function to add a candidate to the election
void add_candidate(election *e, candidate *c) {
  e->candidates[e->num_candidates++] = *c;
}

// Function to get the winner of the election
candidate *get_winner(election *e) {
  candidate *winner = NULL;
  for (int i = 0; i < e->num_candidates; i++) {
    if (winner == NULL || e->candidates[i].votes > winner->votes) {
      winner = &e->candidates[i];
    }
  }
  return winner;
}

// Function to print the results of the election
void print_results(election *e) {
  printf("Election Results:\n");
  for (int i = 0; i < e->num_candidates; i++) {
    printf("%s: %d votes\n", e->candidates[i].name, e->candidates[i].votes);
  }
  printf("Winner: %s\n", get_winner(e)->name);
}

// Main function
int main() {
  // Create a new election
  election *e = create_election(3);

  // Add candidates to the election
  candidate c1 = {"Alice", 0};
  add_candidate(e, &c1);
  candidate c2 = {"Bob", 0};
  add_candidate(e, &c2);
  candidate c3 = {"Charlie", 0};
  add_candidate(e, &c3);

  // Get the votes for each candidate
  printf("Enter the number of votes for each candidate:\n");
  scanf("%d %d %d", &c1.votes, &c2.votes, &c3.votes);

  // Print the results of the election
  print_results(e);

  return 0;
}