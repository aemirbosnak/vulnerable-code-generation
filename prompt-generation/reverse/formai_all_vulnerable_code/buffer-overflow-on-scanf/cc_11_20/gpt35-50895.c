//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Linus Torvalds
#include <stdio.h>

int main() {
  int candidate1 = 0, candidate2 = 0, candidate3 = 0, spoiled_votes = 0;
  int total_votes = 0, vote;
  
  printf("Welcome to the Electronic Voting System\n");
  
  while (1) {
    printf("Please select your candidate:\n[1] Candidate 1\n[2] Candidate 2\n[3] Candidate 3\n[0] Spoiled Vote\n");
    scanf("%d", &vote);
    
    if (vote == 1) {
      candidate1++;
      total_votes++;
    } else if (vote == 2) {
      candidate2++;
      total_votes++;
    } else if (vote == 3) {
      candidate3++;
      total_votes++;
    } else if (vote == 0) {
      spoiled_votes++;
      total_votes++;
    } else {
      printf("Invalid selection. Please try again.\n");
    }
    
    printf("Thank you for voting!\n");
    
    char choice;
    printf("Do you want to vote again? (Y/N): ");
    scanf(" %c", &choice);
    if (choice == 'n' || choice == 'N') {
      break;
    }
  }
  
  printf("\nVoting Results:\n");
  printf("Candidate 1: %d\n", candidate1);
  printf("Candidate 2: %d\n", candidate2);
  printf("Candidate 3: %d\n", candidate3);
  printf("Spoiled Votes: %d\n", spoiled_votes);
  printf("Total Votes: %d\n", total_votes);
  
  if (candidate1 > candidate2 && candidate1 > candidate3) {
    printf("Candidate 1 is the winner!\n");
  } else if (candidate2 > candidate1 && candidate2 > candidate3) {
    printf("Candidate 2 is the winner!\n");
  } else if (candidate3 > candidate1 && candidate3 > candidate2) {
    printf("Candidate 3 is the winner!\n");
  } else {
    printf("No clear winner.\n");
  }
  
  return 0;
}