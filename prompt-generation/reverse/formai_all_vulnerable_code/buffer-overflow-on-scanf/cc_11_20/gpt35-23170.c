//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int numCandidates, numVoters, menu, vote, i, j, k;
  char candidateNames[10][20], tempName[20];
  int candidateVotes[10] = {0};
  int voterID[100] = {0};
  char voterNames[100][20];
  char voterPasswords[100][20];

  printf("Welcome to the Electronic Voting System!\n\n");

  printf("Enter the number of candidates: ");
  scanf("%d", &numCandidates);

  // Input candidate names
  for (i = 0; i < numCandidates; i++) {
    printf("Enter candidate %d name: ", i + 1);
    scanf("%s", candidateNames[i]);
  }

  // Input number of voters
  printf("\nEnter the number of voters: ");
  scanf("%d", &numVoters);

  // Input voter information
  for (i = 0; i < numVoters; i++) {
    printf("\nEnter voter %d ID: ", i + 1);
    scanf("%d", &voterID[i]);

    printf("\nEnter voter %d name: ", i + 1);
    scanf("%s", voterNames[i]);

    printf("\nEnter voter %d password: ", i + 1);
    scanf("%s", voterPasswords[i]);
  }

  // Main menu loop
  do {
    printf("\n\n===============");
    printf("\nMain Menu");
    printf("\n===============");
    printf("\n1. Vote");
    printf("\n2. Show Results");
    printf("\n3. Exit");
    printf("\n\nEnter choice: ");
    scanf("%d", &menu);

    switch(menu) {
      case 1:
        // Login loop
        do {
          printf("\n\nEnter your voter ID and password to continue voting\n\n");
          printf("Voter ID: ");
          scanf("%d", &vote);
          printf("Password: ");
          char password[20];
          scanf("%s", password);

          // Check if voter ID and password is correct
          for (i = 0; i < numVoters; i++) {
            if (voterID[i] == vote) {
              if (strcmp(voterPasswords[i], password) == 0) {
                printf("\nLogin successful! Welcome, %s\n", voterNames[i]);
                break;
              } else {
                printf("\nInvalid password!\n");
                break;
              }
            }
          }

          // If voter ID not found
          if (i == numVoters) {
            printf("\nInvalid voter ID! Please try again.\n");
          }
        } while (i == numVoters);

        // Display candidates and input vote
        printf("\nCandidates:\n");
        for (i = 0; i < numCandidates; i++) {
          printf("%d. %s\n", i + 1, candidateNames[i]);
        }
        printf("\nPlease enter your vote: ");
        scanf("%d", &vote);

        // Add vote to candidate
        candidateVotes[vote - 1]++;
        printf("\nThank you for voting!\n");

        break;
      case 2:
        // Display results
        printf("\nResults:\n");
        for (i = 0; i < numCandidates; i++) {
          for (j = i + 1; j < numCandidates; j++) {
            if (candidateVotes[j] > candidateVotes[i]) {
              // Swap candidate positions
              strcpy(tempName, candidateNames[i]);
              strcpy(candidateNames[i], candidateNames[j]);
              strcpy(candidateNames[j], tempName);

              // Swap candidate votes
              int tempVote = candidateVotes[i];
              candidateVotes[i] = candidateVotes[j];
              candidateVotes[j] = tempVote;
            }
          }
          printf("%d. %s - %d votes\n", i + 1, candidateNames[i], candidateVotes[i]);
        }

        break;
      case 3:
        // Exit program
        printf("\nExiting program...\n");
        break;
      default:
        printf("\nInvalid choice! Please try again.\n");
    }
  } while (menu != 3);

  return 0;
}