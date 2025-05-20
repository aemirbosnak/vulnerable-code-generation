//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() {
  // Let's play a game of "Guess the Number"!

  // First, let's get a random number:
  printf("Guess a number between 1 and 100: ");
  int guess;
  scanf("%d", &guess);

  // Now let's check if you guessed correctly:
  int secret_number = rand() % 100 + 1;

  if (guess == secret_number) {
    printf("Congratulations! You guessed correctly!\n");
  } else {
    // Oh no, you didn't guess correctly! Let's give you some feedback:

    // Did you guess too high or too low?
    int diff = guess - secret_number;
    if (diff > 0) {
      printf("Your guess was too high!\n");
    } else {
      printf("Your guess was too low!\n");
    }

    // How far off were you?
    int abs_diff = abs(diff);
    if (abs_diff < 10) {
      printf("You were pretty close!\n");
    } else if (abs_diff < 20) {
      printf("You were somewhat close.\n");
    } else {
      printf("You were far off!\n");
    }

    // Let's give you another chance to guess:
    printf("Guess again: ");
    scanf("%d", &guess);

    // Did you guess correctly this time?
    if (guess == secret_number) {
      printf("Congratulations! You guessed correctly!\n");
    } else {
      // Oh no, you still didn't guess correctly!
      diff = guess - secret_number;
      if (diff > 0) {
        printf("Your guess was still too high!\n");
      } else {
        printf("Your guess was still too low!\n");
      }
      abs_diff = abs(diff);
      if (abs_diff < 10) {
        printf("You were still pretty close!\n");
      } else if (abs_diff < 20) {
        printf("You were still somewhat close.\n");
      } else {
        printf("You were still far off!\n");
      }
    }
  }

  return 0;
}