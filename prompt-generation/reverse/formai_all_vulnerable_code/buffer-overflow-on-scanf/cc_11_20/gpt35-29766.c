//FormAI DATASET v1.0 Category: Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int playerScore = 0;
  int computerScore = 0;
  char playerChoice;
  char computerChoice;

  srand(time(NULL)); // initialize random seed

  printf("Welcome to Rock, Paper, Scissors!\n");

  while (playerScore < 5 && computerScore < 5) {
    printf("Enter your choice (R for Rock, P for Paper, S for Scissors): ");
    scanf(" %c", &playerChoice);
    
    // randomly generate computer's choice
    int randomNum = rand() % 3;
    
    switch(randomNum) {
      case 0:
        computerChoice = 'R';
        printf("Computer chose Rock.\n");
        break;
      case 1:
        computerChoice = 'P';
        printf("Computer chose Paper.\n");
        break;
      case 2:
        computerChoice = 'S';
        printf("Computer chose Scissors.\n");
        break;
    }

    // determine winner
    if (playerChoice == computerChoice) {
      printf("It's a tie!\n");
    } else if ((playerChoice == 'R' && computerChoice == 'S') ||
               (playerChoice == 'P' && computerChoice == 'R') ||
               (playerChoice == 'S' && computerChoice == 'P')) {
      printf("You win!\n");
      playerScore++;
    } else {
      printf("Computer wins!\n");
      computerScore++;
    }
    
    printf("Your Score: %d\n", playerScore);
    printf("Computer Score: %d\n", computerScore);
  }

  if (playerScore == 5) {
    printf("Congratulations, you win!\n");
  } else {
    printf("Sorry, computer wins!\n");
  }
  
  return 0;
}