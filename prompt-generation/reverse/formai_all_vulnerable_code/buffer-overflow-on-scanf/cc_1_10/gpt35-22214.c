//FormAI DATASET v1.0 Category: Table Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int min = 1;
  int max = 100;
  int guess;
  int attempts = 0;
  char choice;
  
  // generate random number
  srand(time(NULL));
  int number = rand() % 100 + 1;
  
  printf("\nWelcome to the C Table Game!\n");
  printf("I'm thinking of a number between %d and %d\n", min, max);
  
  // game loop
  do {
    printf("\nEnter your guess: ");
    scanf("%d", &guess);
    attempts++;
    
    // check if guess is within range
    if (guess < min || guess > max) {
      printf("Incorrect input! Guess between %d and %d\n", min, max);
    }
    else if (guess < number) {
      printf("My number is higher!\n");
    }
    else if (guess > number) {
      printf("My number is lower!\n");
    }
    else {
      printf("\nCongratulations! You guessed my number in %d attempts!\n", attempts);
      printf("Play again? (Y/N): ");
      scanf(" %c", &choice);
      
      // reset game if player wants to play again
      if (choice == 'Y' || choice == 'y') {
        attempts = 0;
        number = rand() % 100 + 1;
        printf("\nWelcome to the C Table Game!\n");
        printf("I'm thinking of a number between %d and %d\n", min, max);
      }
    }
  } while (choice != 'N' && choice != 'n');

  printf("\nThank you for playing! Goodbye.\n");
  return 0;
}