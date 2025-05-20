//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTER_COUNT 1000
#define MAX_CANDIDATE_COUNT 10

typedef struct {
  char name[50];
  int votes;
} Candidate;

typedef struct {
  char name[50];
  int id;
} Voter;

int main() {
  Candidate candidates[MAX_CANDIDATE_COUNT];
  Voter voters[MAX_VOTER_COUNT];
  int candidateCount = 0, voterCount = 0;
  int i, j, choice;

  printf("Welcome to the Electronic Voting System.\n");

  while (1) {
    printf("\nPlease choose an option:\n");
    printf("1. Add Candidate\n");
    printf("2. Add Voter\n");
    printf("3. List Candidates\n");
    printf("4. List Voters\n");
    printf("5. Cast Vote\n");
    printf("6. Exit\n");
    printf("> ");

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        if (candidateCount >= MAX_CANDIDATE_COUNT) {
          printf("ERROR: Maximum candidate count reached.\n");
          break;
        }
        printf("Enter candidate name: ");
        scanf("%s", candidates[candidateCount].name);
        candidates[candidateCount].votes = 0;
        candidateCount++;
        printf("Candidate added successfully.\n");
        break;
      case 2:
        if (voterCount >= MAX_VOTER_COUNT) {
          printf("ERROR: Maximum voter count reached.\n");
          break;
        }
        printf("Enter voter name: ");
        scanf("%s", voters[voterCount].name);
        voters[voterCount].id = voterCount + 1;
        voterCount++;
        printf("Voter added successfully.\n");
        break;
      case 3:
        printf("List of candidates:\n");
        for (i = 0; i < candidateCount; i++) {
          printf("%d. %s (%d votes)\n", i + 1, candidates[i].name, candidates[i].votes);
        }
        break;
      case 4:
        printf("List of voters:\n");
        for (i = 0; i < voterCount; i++) {
          printf("%d. %s (ID: %d)\n", i + 1, voters[i].name, voters[i].id);
        }
        break;
      case 5:
        printf("Enter voter ID: ");
        int id;
        scanf("%d", &id);

        // find the voter by ID
        Voter* voter = NULL;
        for (i = 0; i < voterCount; i++) {
          if (voters[i].id == id) {
            voter = &voters[i];
            break;
          }
        }

        if (voter == NULL) {
          printf("ERROR: Voter not found.\n");
          break;
        }

        if (voter->id == 0) {
          printf("ERROR: Invalid voter ID.\n");
          break;
        }

        if (voter->id == -1) {
          printf("ERROR: This voter has already cast their vote.\n");
          break;
        }

        printf("The available candidates are:\n");
        for (i = 0; i < candidateCount; i++) {
          printf("%d. %s\n", i + 1, candidates[i].name);
        }

        printf("Enter your choice: ");
        int candidateChoice;
        scanf("%d", &candidateChoice);

        if (candidateChoice < 1 || candidateChoice > candidateCount) {
          printf("ERROR: Invalid candidate choice.\n");
          break;
        }

        // find the candidate by index
        Candidate* candidate = &candidates[candidateChoice - 1];

        candidate->votes++;
        printf("You have successfully cast your vote for %s.\n", candidate->name);

        // mark voter as voted
        voter->id = -1;
        break;
      case 6:
        printf("Exiting program...\n");
        return 0;
      default:
        printf("ERROR: Invalid option.\n");
        break;
    }
  }

  return 0;
}