//FormAI DATASET v1.0 Category: Math exercise ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num1, num2, operation, answer, user_answer;
  int score = 0;

  srand(time(NULL));

  for (int i = 0; i < 10; i++) {
    num1 = rand() % 10 + 1;
    num2 = rand() % 10 + 1;
    operation = rand() % 4;

    switch(operation) {
      case 0:
        answer = num1 + num2;
        printf("What is %d + %d?\n", num1, num2);
        break;
      case 1:
        answer = num1 - num2;
        printf("What is %d - %d?\n", num1, num2);
        break;
      case 2:
        answer = num1 * num2;
        printf("What is %d * %d?\n", num1, num2);
        break;
      case 3:
        answer = num1 / num2;
        printf("What is %d / %d (rounded down to nearest integer)?\n", num1, num2);
        break;
      default:
        printf("Oops, something went wrong!\n");
        exit(1);
    }

    scanf("%d", &user_answer);

    if (user_answer == answer) {
      printf("Correct!\n");
      score++;
    } else {
      printf("Incorrect. The correct answer is: %d\n", answer);
    }
  }

  printf("\nYour final score is: %d/10\n", score);

  return 0;
}