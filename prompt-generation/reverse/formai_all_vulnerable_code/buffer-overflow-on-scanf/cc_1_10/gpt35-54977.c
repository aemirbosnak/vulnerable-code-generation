//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// define constants
#define MAX_VOTERS 1000
#define MAX_CANDIDATES 10
#define MAX_NAME_LENGTH 20

// define data structures
typedef struct voter {
    char name[MAX_NAME_LENGTH];
    int age;
    int voted;
    int candidate_choice;
} Voter;

typedef struct candidate {
    char name[MAX_NAME_LENGTH];
    int vote_count;
} Candidate;

// global variables
Voter voters[MAX_VOTERS];
Candidate candidates[MAX_CANDIDATES];

int num_voters = 0;
int num_candidates = 0;

// function prototypes
void print_main_menu();
void add_voter();
void vote();
void exit_program();


// main function
int main() {
  int choice;

  // print welcome message
  printf("Welcome to the Electronic Voting System\n\n");

  // loop until user chooses to exit program
  while (1) {
    // display main menu
    print_main_menu();

    // get user choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // call the appropriate function based on user choice
    switch (choice) {
      case 1:
        add_voter();
        break;
      case 2:
        vote();
        break;
      case 3:
        exit_program();
        break;
      default:
        printf("Invalid choice, try again.\n");
        break;
    }
  }

  return 0;
}

void print_main_menu() {
  printf("Main Menu\n");
  printf("1. Add Voter\n");
  printf("2. Vote\n");
  printf("3. Exit\n");
}

void add_voter() {
  // check if there is space to add a new voter
  if (num_voters == MAX_VOTERS) {
    printf("Maximum number of voters reached. Unable to add more voters.\n");
    return;
  }

  // prompt user for voter details
  printf("Enter voter name: ");
  scanf("%s", voters[num_voters].name);

  printf("Enter voter age: ");
  scanf("%d", &voters[num_voters].age);

  // set default values for voting related fields
  voters[num_voters].voted = 0;
  voters[num_voters].candidate_choice = -1;

  // increment number of voters
  num_voters++;

  printf("Successfully added voter %s.\n", voters[num_voters-1].name);
}

void vote() {
  // check if there are any voters registered
  if (num_voters == 0) {
    printf("No voters registered. Unable to vote.\n");
    return;
  }

  // prompt user for voter name
  char name[MAX_NAME_LENGTH];
  printf("Enter your name: ");
  scanf("%s", name);

  // find the voter with the given name
  int voter_index = -1;
  for (int i = 0; i < num_voters; i++) {
    if (strcmp(voters[i].name, name) == 0) {
      voter_index = i;
      break;
    }
  }

  // check if voter was found
  if (voter_index == -1) {
    printf("Voter with name %s not found. Unable to vote.\n", name);
    return;
  }

  // check if voter has already voted
  if (voters[voter_index].voted) {
    printf("Voter with name %s has already voted. Unable to vote again.\n", name);
    return;
  }

  // print list of candidates
  printf("List of candidates:\n");
  for (int i = 0; i < num_candidates; i++) {
    printf("%d. %s\n", i+1, candidates[i].name);
  }

  // prompt user to choose candidate
  int choice;
  printf("Enter candidate number: ");
  scanf("%d", &choice);

  // validate candidate choice
  if (choice < 1 || choice > num_candidates) {
    printf("Invalid candidate choice. Try again.\n");
    return;
  }

  // set candidate choice for voter
  voters[voter_index].voted = 1;
  voters[voter_index].candidate_choice = choice-1;

  // increment vote count for candidate
  candidates[choice-1].vote_count++;

  printf("Thank you for voting.\n");
}

void exit_program() {
  printf("Thank you for using the Electronic Voting System. Goodbye.\n");
  exit(0);
}