//FormAI DATASET v1.0 Category: Math exercise ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Displaying greetings to the user
  printf("Hello! Let's play a math game!\n\n");

  // Random number generation
  srand(time(0));
  int num1 = rand() % 100;
  int num2 = rand() % 100;
  int answer = num1 + num2;

  // Asking the user to solve the problem
  printf("What is %d + %d?\n", num1, num2);
  int userAnswer;
  scanf("%d", &userAnswer);

  // Checking the user's answer
  if (userAnswer == answer) {
    printf("\nCorrect! You are a math genius!\n");
  } else {
    printf("\nWrong answer! The correct answer is %d!\n", answer);
  }

  // Asking the user to solve another problem
  printf("\nLet's try another one:\n");

  // Generating new random numbers and problem
  num1 = rand() % 100;
  num2 = rand() % 100;
  answer = num1 * num2;

  // Asking the user to solve the new problem
  printf("What is %d * %d?\n", num1, num2);
  scanf("%d", &userAnswer);

  // Checking the user's answer
  if (userAnswer == answer) {
    printf("\nCorrect! You are a math ninja!\n");
  } else {
    printf("\nWrong answer! The correct answer is %d!\n", answer);
  }

  // Asking the user to solve one more problem
  printf("\nOne final problem:\n");

  // Generating new random numbers and problem
  num1 = rand() % 100;
  num2 = rand() % 100;
  answer = num1 - num2;

  // Asking the user to solve the new problem
  printf("What is %d - %d?\n", num1, num2);
  scanf("%d", &userAnswer);

  // Checking the user's answer
  if (userAnswer == answer) {
    printf("\nCorrect! You are a math wizard!\n");
  } else {
    printf("\nWrong answer! The correct answer is %d!\n", answer);
  }

  // Displaying final message to the user
  printf("\nGreat job playing this math game! Come back soon for more fun!\n");

  return 0;
}