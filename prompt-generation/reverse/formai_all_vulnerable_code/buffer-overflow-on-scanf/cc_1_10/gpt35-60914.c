//FormAI DATASET v1.0 Category: Arithmetic ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int a = 5, b = 10, result, guess, attempts = 0;
  srand(time(0));

  while (1) {
    printf("Choose a random number between 1 and 100: ");
    scanf("%d", &guess);

    if (guess < 1 || guess > 100) {
      printf("Invalid number!\n");
      continue;
    }

    attempts++;
    result = a * guess + b;

    if (result % 2 == 0) {
      printf("Your result is even.\n");

      if (rand() % 100 < 25) {
        result += 10;
        printf("You got a bonus of 10 added to your result!\n");
      }
    }
    else {
      printf("Your result is odd.\n");

      if (rand() % 100 < 25) {
        result -= 5;
        printf("You got a penalty of 5 subtracted from your result!\n");
      }
    }

    printf("Your final result is: %d\n", result);

    if (result == 42) {
      printf("Congratulations! You have found the answer to the ultimate question of life, the universe, and everything!\n");
      printf("It took you %d attempts.\n", attempts);
      break;
    }
    else {
      printf("Sorry, that was not the answer. Try again!\n");
    }
  }

  return 0;
}