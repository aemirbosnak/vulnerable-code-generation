//FormAI DATASET v1.0 Category: Math exercise ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Retro Math Exercise Program */

int main() {
  int num1, num2, answer, response, correctAnswers = 0, totalQuestions = 0, menuSelection;

  // Seed the random number generator with current time
  srand(time(NULL));

  printf("*** Retro Math Exercise Program ***\n");

  // Main menu
  do {
    printf("\nSelect an option:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Quit\n\n");
    scanf("%d", &menuSelection);

    if (menuSelection == 1) {
      // Addition
      printf("\nYou have selected addition. Press 0 to quit.\n");

      do {
        num1 = rand() % 100;
        num2 = rand() % 100;
        answer = num1 + num2;

        printf("\n%d + %d = ", num1, num2);
        scanf("%d", &response);

        if (response == 0) {
          // End exercise
          break;
        }

        totalQuestions++;

        if (response == answer) {
          printf("Right!\n");
          correctAnswers++;
        } else {
          printf("Wrong. The correct answer is %d.\n", answer);
        }
      } while (1);

    } else if (menuSelection == 2) {
      // Subtraction
      printf("\nYou have selected subtraction. Press 0 to quit.\n");

      do {
        num1 = rand() % 100;
        num2 = rand() % 100;
        answer = num1 - num2;

        printf("\n%d - %d = ", num1, num2);
        scanf("%d", &response);

        if (response == 0) {
          // End exercise
          break;
        }

        totalQuestions++;

        if (response == answer) {
          printf("Right!\n");
          correctAnswers++;
        } else {
          printf("Wrong. The correct answer is %d.\n", answer);
        }
      } while (1);

    } else if (menuSelection == 3) {
      // Multiplication
      printf("\nYou have selected multiplication. Press 0 to quit.\n");

      do {
        num1 = rand() % 10;
        num2 = rand() % 10;
        answer = num1 * num2;

        printf("\n%d x %d = ", num1, num2);
        scanf("%d", &response);

        if (response == 0) {
          // End exercise
          break;
        }

        totalQuestions++;

        if (response == answer) {
          printf("Right!\n");
          correctAnswers++;
        } else {
          printf("Wrong. The correct answer is %d.\n", answer);
        }
      } while (1);

    } else if (menuSelection == 4) {
      // Division
      printf("\nYou have selected division. Press 0 to quit.\n");

      do {
        num1 = rand() % 100;
        num2 = rand() % 9 + 1;   // Ensure second number is not 0
        answer = num1 / num2;

        printf("\n%d / %d = ", num1, num2);
        scanf("%d", &response);

        if (response == 0) {
          // End exercise
          break;
        }

        totalQuestions++;

        if (response == answer) {
          printf("Right!\n");
          correctAnswers++;
        } else {
          printf("Wrong. The correct answer is %d.\n", answer);
        }
      } while (1);

    } else if (menuSelection == 5) {
      // Quit
      break;
    }

  } while (1);

  printf("\nYou answered %d questions correctly out of %d total questions.\n", correctAnswers, totalQuestions);

  return 0;
}