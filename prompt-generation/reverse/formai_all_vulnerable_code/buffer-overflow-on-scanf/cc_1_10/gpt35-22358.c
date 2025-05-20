//FormAI DATASET v1.0 Category: Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearScreen() {
#ifdef WINDOWS
  system("cls");
#else
  system("clear");
#endif
}

int main() {
  int score = 0;
  int lives = 3;
  int level = 1;

  srand(time(NULL)); // seed the random number generator

  while (lives > 0) // game loop
  {
    clearScreen();

    printf("Score: %d | Lives: %d | Level: %d\n\n", score, lives, level);

    // generate random numbers for the two operands
    int operand1 = rand() % 10 + 1;
    int operand2 = rand() % 10 + 1;

    int result = operand1 + operand2; // calculate the correct answer

    printf("What is %d + %d? ", operand1, operand2);

    int guess;
    scanf("%d", &guess);

    if (guess == result) {
      // correct answer!
      score += 10;
      printf("You got it! :)\n");
    }
    else {
      // incorrect answer :(
      lives--;
      printf("Sorry, the correct answer was %d. You lose a life!\n", result);
    }

    if (score >= level * 50) {
      // level up!
      level++;
      printf("\n*** LEVEL UP! You are now on level %d! ***\n\n", level);
    }

    printf("Press enter to continue...\n");
    getchar(); getchar(); // wait for user to press enter
  }

  printf("\n\nGame over! Your final score was: %d\n", score);

  return 0;
}