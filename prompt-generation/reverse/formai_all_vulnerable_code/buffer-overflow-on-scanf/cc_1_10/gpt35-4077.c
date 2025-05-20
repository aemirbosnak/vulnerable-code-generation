//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 20
#define MAX_VOTERS 500

// Define candidate struct
typedef struct Candidate {
  char name[20];
  int vote_count;
} Candidate;

// Define voter struct
typedef struct Voter {
  char name[20];
  int has_voted;
} Voter;

// Function to print menu options
void print_menu() {
  printf("Electronic Voting System - Main Menu\n");
  printf("-----------------------------------\n");
  printf("1. Add Candidate\n");
  printf("2. Display Candidates\n");
  printf("3. Start Voting\n");
  printf("4. Exit Program\n");
}

// Function to add candidate
void add_candidate(Candidate candidates[], int *num_candidates) {
  char name[20];
  printf("Enter candidate name: ");
  scanf("%s", name);
  Candidate new_candidate;
  strcpy(new_candidate.name, name);
  new_candidate.vote_count = 0;
  candidates[*num_candidates] = new_candidate;
  (*num_candidates)++;
  printf("Candidate added successfully!\n");
}

// Function to display candidates
void display_candidates(Candidate candidates[], int num_candidates) {
  if (num_candidates == 0) {
    printf("No candidates added yet.\n");
    return;
  }
  printf("List of Candidates:\n");
  for (int i = 0; i < num_candidates; i++) {
    printf("%d. %s\n", i+1, candidates[i].name);
  }
}

// Function to get candidate index by name
int get_candidate_index(Candidate candidates[], int num_candidates, char name[]) {
  for (int i = 0; i < num_candidates; i++) {
    if (strcmp(candidates[i].name, name) == 0) {
      return i;
    }
  }
  return -1;
}

// Function to start voting
void start_voting(Candidate candidates[], int num_candidates, Voter voters[], int *num_voters) {
  if (num_candidates == 0) {
    printf("No candidates added yet.\n");
    return;
  }
  printf("Welcome to the Voting System!\n");
  printf("Please enter your name to vote: ");
  char name[20];
  scanf("%s", name);
  int index = -1;
  for (int i = 0; i < *num_voters; i++) {
    if (strcmp(voters[i].name, name) == 0) {
      index = i;
      break;
    }
  }
  if (index != -1 && voters[index].has_voted == 1) {
    printf("You have already voted.\n");
    return;
  }
  Voter new_voter;
  strcpy(new_voter.name, name);
  new_voter.has_voted = 1;
  voters[*num_voters] = new_voter;
  (*num_voters)++;
  printf("Please choose the candidate you want to vote for:\n");
  display_candidates(candidates, num_candidates);
  printf("Enter candidate name: ");
  char candidate_name[20];
  scanf("%s", candidate_name);
  int candidate_index = get_candidate_index(candidates, num_candidates, candidate_name);
  if (candidate_index == -1) {
    printf("Invalid candidate name.\n");
    return;
  }
  candidates[candidate_index].vote_count++;
  printf("You have successfully voted for %s!\n", candidate_name);
}

int main() {
  Candidate candidates[MAX_CANDIDATES];
  Voter voters[MAX_VOTERS];
  int num_candidates = 0;
  int num_voters = 0;
  int choice = 0;
  while (choice != 4) {
    print_menu();
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        add_candidate(candidates, &num_candidates);
        break;
      case 2:
        display_candidates(candidates, num_candidates);
        break;
      case 3:
        start_voting(candidates, num_candidates, voters, &num_voters);
        break;
      case 4:
        printf("Exiting Program.\n");
        break;
      default:
        printf("Invalid choice.\n");
    }
    printf("\n");
  }
  return 0;
}