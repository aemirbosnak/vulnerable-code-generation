//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int voteCount = 0;
  int candidateOne = 0;
  int candidateTwo = 0;
  int candidateThree = 0;
  int candidateFour = 0;
  int candidateFive = 0;
  int voterID;

  printf("Welcome to the Paranoid Electronic Voting System\n");
  printf("Please enter your voter ID: ");
  scanf("%d", &voterID);
  if(voterID < 100000 || voterID > 999999) {
    printf("Invalid voter ID\n");
    return 0;
  }

  srand(time(0));
  int pin = rand() % 10000;
  printf("Please enter your PIN: ");
  int enteredPin;
  scanf("%d", &enteredPin);
  if(enteredPin != pin) {
    printf("Unauthorized voter detected.\n");
    return 0;
  }

  printf("Welcome to the voting booth!\n");
  printf("Please choose a candidate by entering their number:\n");
  printf("1. Candidate One\n");
  printf("2. Candidate Two\n");
  printf("3. Candidate Three\n");
  printf("4. Candidate Four\n");
  printf("5. Candidate Five\n");
  int candidateChoice;
  scanf("%d", &candidateChoice);

  if(candidateChoice < 1 || candidateChoice > 5) {
    printf("Invalid candidate choice.\n");
    return 0;
  }

  voteCount++;
  switch(candidateChoice) {
    case 1:
      candidateOne++;
      break;

    case 2:
      candidateTwo++;
      break;

    case 3:
      candidateThree++;
      break;

    case 4:
      candidateFour++;
      break;

    case 5:
      candidateFive++;
      break;
  }

  printf("Thank you for voting!\n");
  printf("Your vote has been recorded and will be counted.\n");

  return 1;
}