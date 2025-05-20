//FormAI DATASET v1.0 Category: Math exercise ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Math Exercise Program!\n\n");

  int num1, num2, answer, userAnswer;
  char operator;
  int i, correctAnswers = 0;

  srand(time(NULL));

  for (i = 0; i < 10; i++) {
    num1 = rand() % 10 + 1;
    num2 = rand() % 10 + 1;

    switch(rand() % 4) {
      case 0:
        operator = '+';
        answer = num1 + num2;
        break;
      case 1:
        operator = '-';
        answer = num1 - num2;
        break;
      case 2:
        operator = '*';
        answer = num1 * num2;
        break;
      case 3:
        operator = '/';
        answer = num1 / num2;
        break;
    }

    printf("Question %d: %d %c %d = ?\n", i+1, num1, operator, num2);
    scanf("%d", &userAnswer);

    if (userAnswer == answer) {
      printf("Correct!\n\n");
      correctAnswers++;
    } else {
      printf("Incorrect, the correct answer is %d\n\n", answer);
    }
  }

  printf("You answered %d out of 10 questions correctly. Good job!\n", correctAnswers);

  return 0;
}