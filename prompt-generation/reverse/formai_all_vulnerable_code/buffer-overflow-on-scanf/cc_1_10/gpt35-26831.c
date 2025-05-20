//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int randomNumber, guess, attempts = 0;
  char choice;
  /* initialize random seed */
  srand(time(NULL));
  /* generate random number between 1 and 100 */
  randomNumber = rand() % 100 + 1;
  
  printf("Welcome to Guess the Number game!\n");
  printf("I am thinking of a number between 1 and 100, can you guess it?\n");
  
  do {
      printf("Enter your guess: ");
      scanf("%d", &guess);
      attempts++;
      
      if(guess > randomNumber)
      {
          printf("Too high! Try again.\n");
      }
      else if(guess < randomNumber)
      {
          printf("Too low! Try again.\n");
      }
      else
      {
          printf("Congratulations! You guessed the number in %d attempts!\n", attempts);
      }
      
      /* ask user if they want to play again */
      printf("Do you want to play again? (y/n): ");
      scanf(" %c", &choice);
      
      /* generate new random number if user wants to play again */
      if(choice == 'y' || choice == 'Y')
      {
          randomNumber = rand() % 100 + 1;
          attempts = 0;
          printf("\nNew game!\n");
      }

  } while(choice == 'y' || choice == 'Y');

  printf("Thanks for playing! Goodbye.\n");

  return 0;
}