//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  int voters[100], candidate1 = 0, candidate2 = 0, candidate3 = 0, invalid = 0, vote;
  srand(time(NULL));             // Seed for random number generation

  // Initialize voters with random ID numbers
  for(int i = 0; i < 100; i++) {
    voters[i] = rand() % 1000;
  }

  printf("Welcome to the Electronic Voting System!\n\n");
  
  // Loop through all voters
  for(int i = 0; i < 100; i++) {
    printf("Voter %d, please input your candidate choice (1, 2, or 3): ", voters[i]);
    scanf("%d", &vote);
    switch(vote) {
      case 1:
        candidate1++;
        printf("Thank you for voting for candidate 1!\n\n");
        break;
      case 2:
        candidate2++;
        printf("Thank you for voting for candidate 2!\n\n");
        break;
      case 3:
        candidate3++;
        printf("Thank you for voting for candidate 3!\n\n");
        break;
      default:
        invalid++;
        printf("Invalid vote: please choose 1, 2, or 3.\n\n");
        break;
    }
  }

  // Print final results
  printf("Voting has ended!\nCandidate 1 received %d votes.\nCandidate 2 received %d votes.\nCandidate 3 received %d votes.\n%d invalid votes were cast.\n", candidate1, candidate2, candidate3, invalid);

  // Declare winner
  if(candidate1 > candidate2 && candidate1 > candidate3) {
    printf("Candidate 1 is the winner!\n");
  }
  else if(candidate2 > candidate1 && candidate2 > candidate3) {
    printf("Candidate 2 is the winner!\n");
  }
  else if(candidate3 > candidate1 && candidate3 > candidate2) {
    printf("Candidate 3 is the winner!\n");
  }
  else {
    printf("There is a tie!\n");
  }

  return 0;
}