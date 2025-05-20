//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct candidate {
  char name[20];
  int id;
  int votes;
} candidate;

void display_menu() {
  printf("Welcome to our cryptic electronic voting system!\n");
  printf("1. View Candidates\n");
  printf("2. Vote for a Candidate\n");
  printf("3. View Results\n");
  printf("4. Exit\n");
}

int main() {
  int choice = 0;
  int num_candidates = 0;
  candidate *candidates = NULL;

  while(choice != 4) {
    display_menu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Listing candidates:\n");
        for(int i = 0; i < num_candidates; i++) {
          printf("%d. %s\n", candidates[i].id, candidates[i].name);
        }
        break;

      case 2:
        printf("Enter the id of the candidate you want to vote for: ");
        int vote_id;
        scanf("%d", &vote_id);

        for(int i = 0; i < num_candidates; i++) {
          if(candidates[i].id == vote_id) {
            candidates[i].votes++;
            printf("You have successfully voted for %s!\n", candidates[i].name);
            break;
          }
        }
        break;

      case 3:
        printf("Results are in:\n");
        for(int i = 0; i < num_candidates; i++) {
          printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
        }
        break;

      case 4:
        printf("Thank you for using our cryptic electronic voting system!\n");
        break;

      default:
        printf("Invalid choice.\n");
        break;
    }

    printf("\n");
  }

  return 0;
}