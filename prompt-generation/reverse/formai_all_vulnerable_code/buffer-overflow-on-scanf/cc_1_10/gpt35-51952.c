//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define structures
struct Candidate {
  char name[20];
  int votes;
};

struct Voter {
  char name[20];
  int voted_for;
};

// Declare global variables
struct Candidate candidates[MAX_CANDIDATES];
struct Voter voters[MAX_VOTERS];
int num_candidates = 0;
int num_voters = 0;
int election_over = 0;

// Declare functions
void add_candidate();
void cast_vote();
void display_results();

int main() {
  char choice = '0';
  while (choice != '4') {
    printf("Election Menu:\n");
    printf("1. Add Candidate\n");
    printf("2. Cast Vote\n");
    printf("3. Display Results\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);
    switch (choice) {
      case '1':
        add_candidate();
        break;
      case '2':
        cast_vote();
        break;
      case '3':
        display_results();
        break;
      case '4':
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
  }
  return 0;
}

void add_candidate() {
  if (num_candidates < MAX_CANDIDATES) {
    printf("Enter candidate name: ");
    scanf(" %s", candidates[num_candidates].name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
    printf("Candidate added!\n");
  } else {
    printf("Maximum number of candidates reached. Cannot add more.\n");
  }
}

void cast_vote() {
  if (election_over) {
    printf("Election is over. Cannot cast vote.\n");
    return;
  }
  if (num_voters < MAX_VOTERS) {
    printf("Enter your name: ");
    scanf(" %s", voters[num_voters].name);
    printf("Choose your candidate:\n");
    for (int i = 0; i < num_candidates; i++) {
      printf("%d. %s\n", i + 1, candidates[i].name);
    }
    int choice = 0;
    scanf(" %d", &choice);
    if (choice >= 1 && choice <= num_candidates) {
      voters[num_voters].voted_for = choice - 1;
      candidates[choice - 1].votes++;
      num_voters++;
      printf("Vote cast successfully!\n");
    } else {
      printf("Invalid candidate choice. Vote not recorded.\n");
    }
  } else {
    printf("Maximum number of voters reached. Cannot cast vote.\n");
  }
}

void display_results() {
  printf("Election Results:\n");
  for (int i = 0; i < num_candidates; i++) {
    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
  }
  election_over = 1;
}