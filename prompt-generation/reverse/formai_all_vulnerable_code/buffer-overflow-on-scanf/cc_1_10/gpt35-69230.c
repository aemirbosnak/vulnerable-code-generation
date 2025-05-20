//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000

// Define global variables
int candidate_count = 0;
int voter_count = 0;
char candidate_names[MAX_CANDIDATES][20];
int candidate_votes[MAX_CANDIDATES] = {0};
char voter_ids[MAX_VOTERS][10];

// Function prototypes
void add_candidate(char name []);
void add_voter(char id []);
void cast_vote(int candidate_index, char voter_id []);

int main() {
  int option;
  char name[20];
  char id[10];
  int candidate_index;

  // Seed random number generator
  srand(time(NULL));

  // Show menu
  do {
    printf("Electronic Voting System\n");
    printf("------------------------\n");
    printf("1. Add candidate\n");
    printf("2. Add voter\n");
    printf("3. Cast vote\n");
    printf("4. Display results\n");
    printf("0. Exit\n");
    printf("Option: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        // Add candidate
        printf("Enter candidate name: ");
        scanf("%s", name);
        add_candidate(name);
        break;

      case 2:
        // Add voter
        printf("Enter voter id: ");
        scanf("%s", id);
        add_voter(id);
        break;

      case 3:
        // Cast vote
        if (candidate_count == 0) {
          printf("No candidates found. Please add candidates first.\n");
        } else if (voter_count == 0) {
          printf("No voters found. Please add voters first.\n");
        } else {
          candidate_index = rand() % candidate_count;
          cast_vote(candidate_index, voter_ids[rand() % voter_count]);
        }
        break;

      case 4:
        // Display results
        printf("%-20s %s\n", "Candidate", "Votes");
        printf("--------------------\n");
        for (int i = 0; i < candidate_count; i++) {
          printf("%-20s %d\n", candidate_names[i], candidate_votes[i]);
        }
        break;

      case 0:
        // Exit program
        printf("Goodbye!\n");
        break;

      default:
        printf("Invalid option. Please try again.\n");
        break;
    }
  } while (option != 0);

  return 0;
}

void add_candidate(char name []) {
  // Check if candidate limit reached
  if (candidate_count == MAX_CANDIDATES) {
    printf("Maximum candidate limit reached.\n");
    return;
  }

  // Check if candidate already exists
  for (int i = 0; i < candidate_count; i++) {
    if (strcmp(candidate_names[i], name) == 0) {
      printf("Candidate already exists.\n");
      return;
    }
  }

  // Add candidate
  strcpy(candidate_names[candidate_count], name);
  candidate_count++;
  printf("Candidate added successfully.\n");
}

void add_voter(char id []) {
  // Check if voter limit reached
  if (voter_count == MAX_VOTERS) {
    printf("Maximum voter limit reached.\n");
    return;
  }

  // Check if voter already exists
  for (int i = 0; i < voter_count; i++) {
    if (strcmp(voter_ids[i], id) == 0) {
      printf("Voter already exists.\n");
      return;
    }
  }

  // Add voter
  strcpy(voter_ids[voter_count], id);
  voter_count++;
  printf("Voter added successfully.\n");
}

void cast_vote(int candidate_index, char voter_id []) {
  // Check if voter has already voted
  for (int i = 0; i < candidate_count; i++) {
    if (strcmp(candidate_names[i], voter_id) == 0) {
      printf("Voter has already voted.\n");
      return;
    }
  }

  // Cast vote
  candidate_votes[candidate_index]++;
  printf("Vote casted successfully.\n");
}