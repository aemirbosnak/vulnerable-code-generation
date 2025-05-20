//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define PASSWORD "password123" // set the password for admin login
#define MAX_VOTERS 100 // set the maximum number of voters
#define MAX_CANDIDATES 4 // set the maximum number of candidates

int voters_count = 0; // counter for number of registered voters
int candidates_votes[MAX_CANDIDATES] = {0}; // array to store votes for each candidate

struct Voter {
  char name[30];
  int age;
  int voted; // flag to check if the voter has already voted or not
};
struct Voter voters[MAX_VOTERS]; // array to store information for all registered voters

// function to register a new voter
void register_voter() {
  if (voters_count >= MAX_VOTERS) {
    printf("Sorry, the maximum number of voters has been reached.\n");
    return;
  }
  printf("Enter voter name: ");
  scanf("%s", voters[voters_count].name);
  printf("Enter voter age: ");
  scanf("%d", &voters[voters_count].age);
  voters[voters_count].voted = 0; // set the voted flag to 0 for new voter
  voters_count++;
}

// function to display the list of registered voters
void display_voters() {
  printf("List of registered voters:\n");
  for (int i = 0; i < voters_count; i++) {
    printf("%d. %s, Age: %d\n", i+1, voters[i].name, voters[i].age);
  }
}

// function to get admin login
int admin_login() {
  char password[15];
  printf("Enter password: ");
  scanf("%s", password);
  if (strcmp(password, PASSWORD) == 0) {
    printf("Login successful!\n");
    return 1;
  }
  else {
    printf("Incorrect password. Try again.\n");
    return 0;
  }
}

// function to start the voting process
void start_voting() {
  char choice[2];
  printf("Are you sure you want to start the voting process? (Y/N) ");
  scanf("%s", choice);
  if (strcmp(choice, "Y") == 0) {
    // reset the votes for all candidates
    for (int i = 0; i < MAX_CANDIDATES; i++) {
      candidates_votes[i] = 0;
    }
    // set the voted flag to 0 for all voters
    for (int i = 0; i < voters_count; i++) {
      voters[i].voted = 0;
    }
    printf("Voting process has started.\n");
  }
}

// function to register a vote
void vote(int candidate) {
  if (voters[candidate-1].voted == 1) {
    printf("Sorry, you have already voted.\n");
    return;
  }
  candidates_votes[candidate-1]++;
  voters[candidate-1].voted = 1;
  printf("Thank you for voting.\n");
}

// function to end the voting process and display the results
void end_voting() {
  printf("Voting process has ended. Here are the results:\n");
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    printf("Candidate %d: %d votes.\n", i+1, candidates_votes[i]);
  }
}

int main() {
  int choice, candidate;
  while (1) {
    printf("===========================\n");
    printf("Electronic Voting System\n");
    printf("===========================\n");
    printf("1. Register new voter\n");
    printf("2. Display registered voters\n");
    printf("3. Admin login\n");
    printf("4. Start voting process\n");
    printf("5. Register a vote\n");
    printf("6. End voting process\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        register_voter();
        break;
      case 2:
        display_voters();
        break;
      case 3:
        if (admin_login() == 1) {
          printf("Welcome Admin!\n");
        }
        else {
          printf("Admin login failed.\n");
        }
        break;
      case 4:
        if (admin_login() == 1) {
          start_voting();
        }
        else {
          printf("Admin login required.\n");
        }
        break;
      case 5:
        if (voters_count == 0) {
          printf("Sorry, there are no registered voters yet.\n");
        }
        else {
          printf("Enter candidate number (1 to %d): ", MAX_CANDIDATES);
          scanf("%d", &candidate);
          if (candidate < 1 || candidate > MAX_CANDIDATES) {
            printf("Invalid candidate number.\n");
          }
          else {
            vote(candidate);
          }
        }
        break;
      case 6:
        if (admin_login() == 1) {
          end_voting();
        }
        else {
          printf("Admin login required.\n");
        }
        break;
      case 7:
        printf("Exiting...\n");
        exit(0);
      default:
        printf("Invalid choice. Try again.\n");
    }
  }
  return 0;
}