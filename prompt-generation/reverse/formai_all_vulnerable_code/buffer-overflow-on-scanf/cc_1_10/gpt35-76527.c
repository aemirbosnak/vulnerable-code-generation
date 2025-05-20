//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int playerScore = 0, computerScore = 0;
  char choice;

  printf("Welcome to the Dice Game!\n");
  printf("Press 'r' to roll the dice\n");
  printf("Press 'q' to quit the game\n");

  srand(time(NULL)); // Seed the random number generator
  
  while (1) {
    printf("\nYour score: %d\n", playerScore);
    printf("Computer score: %d\n", computerScore);
    printf("Type your choice: ");
    scanf(" %c", &choice);

    switch (choice) {
      case 'r': {
        int playerRoll = rand() % 6 + 1;
        int computerRoll = rand() % 6 + 1;

        printf("You rolled a %d\n", playerRoll);
        printf("Computer rolled a %d\n", computerRoll);

        if (playerRoll > computerRoll) {
          printf("You win this round!\n");
          playerScore++;
        } else if (playerRoll < computerRoll) {
          printf("Computer wins this round!\n");
          computerScore++;
        } else {
          printf("It's a tie!\n");
        }

        break;
      }
      case 'q': {
        printf("Thanks for playing!\n");
        return 0;
      }
      default: {
        printf("Invalid choice!\n");
        break;
      }
    }

    if (playerScore == 5) {
      printf("\nCongratulations, you win the game!\n");
      return 0;
    }

    if (computerScore == 5) {
      printf("\nComputer wins the game!\n");
      return 0;
    }
  }
}