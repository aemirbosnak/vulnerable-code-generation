//FormAI DATASET v1.0 Category: Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototype
void guessNumber(int);

int main() {
  int choice;

  printf("Welcome to Grateful Guessing Game!\n\n");
  printf("Choose a difficulty level:\n");
  printf("1) Easy\n2) Medium\n3) Hard\n\n");
  printf("Choice: ");
  scanf("%d", &choice);

  srand(time(NULL)); // Seed the random number generator

  switch(choice) {
    case 1:
      guessNumber(10);
      break;
    case 2:
      guessNumber(50);
      break;
    case 3:
      guessNumber(100);
      break;
    default:
      printf("Invalid choice. Please choose 1, 2, or 3.\n");
      break;
  }

  return 0;
}

// Function definition
void guessNumber(int range) {
  int target = (rand() % range) + 1;
  int guess, count = 0;

  printf("\nI'm thinking of a number between 1 and %d.\n", range);

  do {
    printf("\nEnter your guess: ");
    scanf("%d", &guess);

    count++;

    if(guess < target) {
      printf("Too low! Try again.\n");
    } else if(guess > target) {
      printf("Too high! Try again.\n");
    }

  } while(guess != target);

  printf("\nCongratulations! You guessed the number in %d attempts.\n", count);
}