//FormAI DATASET v1.0 Category: Math exercise ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the post-apocalyptic C Math Exercise Program!\n\n");
  printf("You find yourself in a world scorched by nuclear war. The only hope for humanity lies in our ability to solve complex mathematical problems. Are you ready to take on the challenge?\n\n");

  int correct = 0;
  int tries = 0;

  srand(time(0)); /* Seed random number generator with current time */

  while (correct < 10) { /* Always ask for 10 correct answers */
    int num1 = rand() % 10 + 1; /* Generate random integer between 1 and 10 */
    int num2 = rand() % 10 + 1; 
    int op = rand() % 3; /* Randomly choose addition, subtraction, or multiplication */

    if (op == 0) { /* Addition */
      printf("What is %d + %d?\n", num1, num2);
      int answer;
      scanf("%d", &answer);
      tries++;
      if (answer == num1 + num2) {
        correct++;
        printf("Correct! You have answered %d out of 10 correctly.\n\n", correct);
      } else {
        printf("Incorrect. The correct answer is %d.\n\n", num1 + num2);
      }
    } else if (op == 1) { /* Subtraction */
      printf("What is %d - %d?\n", num1, num2);
      int answer;
      scanf("%d", &answer);
      tries++;
      if (answer == num1 - num2) {
        correct++;
        printf("Correct! You have answered %d out of 10 correctly.\n\n", correct);
      } else {
        printf("Incorrect. The correct answer is %d.\n\n", num1 - num2);
      }
    } else { /* Multiplication */
      printf("What is %d x %d?\n", num1, num2);
      int answer;
      scanf("%d", &answer);
      tries++;
      if (answer == num1 * num2) {
        correct++;
        printf("Correct! You have answered %d out of 10 correctly.\n\n", correct);
      } else {
        printf("Incorrect. The correct answer is %d.\n\n", num1 * num2);
      }
    }
  }

  printf("Congratulations! You have answered 10 post-apocalyptic C Math Exercises correctly.\n");
  printf("It looks like humanity has a chance after all! You answered %d questions in total.\n", tries);

  return 0;
}