//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define VOTER_PWD_LENGTH 6

struct voter {
  int id;
  char name[30];
  char password[VOTER_PWD_LENGTH + 1];
};

struct candidate {
  int id;
  char name[30];
  int votes;
};

int main() {
  srand(time(NULL));

  int option;
  struct candidate candidates[MAX_CANDIDATES];
  int num_candidates = 0;
  struct voter voters[MAX_CANDIDATES];
  int num_voters = 0;

  do {
    printf("Electronic Voting System\n");
    printf("========================\n");
    printf("1. Register candidate\n");
    printf("2. Register voter\n");
    printf("3. Login as voter\n");
    printf("4. View results\n");
    printf("5. Exit\n");

    printf("Choose an option: ");
    scanf("%d", &option);

    switch(option) {
      case 1:
        if (num_candidates >= MAX_CANDIDATES) {
          printf("Reached maximum number of candidates.\n");
          break;
        }

        struct candidate c;
        printf("Enter candidate name: ");
        scanf("%s", c.name);
        c.id = rand() % 10000;
        c.votes = 0;
        candidates[num_candidates++] = c;

        printf("Candidate registered with ID %d.\n", c.id);
        break;

      case 2:
        if (num_voters >= MAX_CANDIDATES) {
          printf("Reached maximum number of voters.\n");
          break;
        }

        struct voter v;
        printf("Enter voter name: ");
        scanf("%s", v.name);
        v.id = rand() % 10000;
        printf("Enter voter password (6 characters): ");
        scanf("%s", v.password);
        voters[num_voters++] = v;

        printf("Voter registered with ID %d.\n", v.id);
        break;

      case 3:
        printf("Enter voter ID: ");
        int voter_id;
        scanf("%d", &voter_id);

        struct voter* v_ptr = NULL;
        for (int i = 0; i < num_voters; i++) {
          if (voters[i].id == voter_id) {
            v_ptr = &voters[i];
            break;
          }
        }

        if (v_ptr == NULL) {
          printf("Invalid voter ID.\n");
          break;
        }

        printf("Enter voter password: ");
        char password[VOTER_PWD_LENGTH + 1];
        scanf("%s", password);

        if (strcmp(password, v_ptr->password) != 0) {
          printf("Invalid password.\n");
          break;
        }

        printf("Welcome, %s!\n", v_ptr->name);

        int vote;
        printf("Candidates:\n");
        for (int i = 0; i < num_candidates; i++) {
          printf("%d. %s\n", candidates[i].id, candidates[i].name);
        }
        printf("Choose a candidate ID to vote for (0 to cancel): ");
        scanf("%d", &vote);

        if (vote == 0) {
          break;
        }

        struct candidate* c_ptr = NULL;
        for (int i = 0; i < num_candidates; i++) {
          if (candidates[i].id == vote) {
            c_ptr = &candidates[i];
            break;
          }
        }

        if (c_ptr == NULL) {
          printf("Invalid candidate ID.\n");
          break;
        }

        c_ptr->votes++;
        printf("Thanks for voting!\n");
        break;

      case 4:
        if (num_candidates == 0) {
          printf("No candidates registered yet.\n");
          break;
        }

        printf("Results:\n");
        for (int i = 0; i < num_candidates; i++) {
          printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        }
        break;

      case 5:
        printf("Goodbye!\n");
        break;

      default:
        printf("Invalid option.\n");
    }

    printf("\n");
  } while(option != 5);

  return 0;
}