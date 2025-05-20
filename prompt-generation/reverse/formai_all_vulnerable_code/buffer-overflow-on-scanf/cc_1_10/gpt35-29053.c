//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: inquisitive
#include <stdio.h>

int main() {
  int vote_count[3] = {0, 0, 0}; // Initializing vote count for three candidates to zero

  printf("Welcome to the Electronic Voting System!\n");
  printf("Candidate 1: John Doe\n");
  printf("Candidate 2: Jane Smith\n");
  printf("Candidate 3: Jack Black\n\n");

  while (1) { // An infinite loop, exit condition defined inside
    printf("Enter your choice (1/2/3) or press 0 to end voting: ");
    int choice;
    scanf("%d", &choice); // Reading user's choice

    if (choice == 0) {
      printf("\nThank you for voting!\n\n");
      break;
    } else if (choice >= 1 && choice <= 3) {
      vote_count[choice-1]++; // Incrementing vote count for the candidate chosen by the user
      printf("Thank you for voting for Candidate %d!\n\n", choice);
    } else {
      printf("Invalid choice. Please enter a valid choice (1/2/3).\n\n");
    }
  }

  // Printing final result
  printf("Voting has ended. Here is the final result:\n");
  printf("Candidate 1 (John Doe): %d votes\n", vote_count[0]);
  printf("Candidate 2 (Jane Smith): %d votes\n", vote_count[1]);
  printf("Candidate 3 (Jack Black): %d votes\n", vote_count[2]);

  // Finding the winner
  int winner = 1;
  for (int i = 1; i < 3; i++) {
    if (vote_count[i] > vote_count[winner-1]) {
      winner = i+1;
    }
  }

  printf("\nAnd the winner is... Candidate %d (", winner);
  switch (winner) {
    case 1:
      printf("John Doe");
      break;
    case 2:
      printf("Jane Smith");
      break;
    case 3:
      printf("Jack Black");
      break;
  }
  printf(")!\n");

  return 0;
}