//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL));
   int playerScore = 0;
   int computerScore = 0;
   int choice;
   int randomNum;
   char playAgain;

   do {
      printf("Welcome to the Number Guessing Game!\n");
      printf("Guess a number between 1 and 100.\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      randomNum = rand() % 100 + 1;

      if (choice == randomNum) {
         printf("Congratulations! You guessed the correct number.\n");
         playerScore++;
      } else if (choice < randomNum) {
         printf("Too low! Try again.\n");
      } else {
         printf("Too high! Try again.\n");
      }

      computerScore = rand() % 100 + 1;
      printf("The computer guessed: %d\n", computerScore);

      if (computerScore == randomNum) {
         printf("The computer wins this round.\n");
         computerScore++;
      } else if (computerScore < randomNum) {
         printf("The computer guessed too low.\n");
      } else {
         printf("The computer guessed too high.\n");
      }

      if (playerScore >= 5 || computerScore >= 5) {
         printf("Game Over!\n");
         printf("Player Score: %d\n", playerScore);
         printf("Computer Score: %d\n", computerScore);
      }

      printf("Do you want to play again? (y/n): ");
      scanf(" %c", &playAgain);
   } while (playAgain == 'y' || playAgain == 'Y');

   return 0;
}