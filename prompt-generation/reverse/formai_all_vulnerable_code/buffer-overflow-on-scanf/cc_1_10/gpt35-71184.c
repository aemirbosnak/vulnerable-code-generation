//FormAI DATASET v1.0 Category: Math exercise ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed the random number generator

  // Generate two random numbers between 1 and 10
  int num1 = rand() % 10 + 1;
  int num2 = rand() % 10 + 1;

  // Display the problem to the user
  printf("What is %d + %d?\n", num1, num2);

  // Get the user's answer
  int answer;
  scanf("%d", &answer);

  // Check if the user's answer is correct
  if (answer == num1 + num2) {
    printf("You are correct!\n");
  } else {
    printf("Sorry, the correct answer is %d.\n", num1 + num2);
  }

  // Generate two more random numbers and repeat the process for subtraction
  num1 = rand() % 10 + 1;
  num2 = rand() % 10 + 1;

  printf("What is %d - %d?\n", num1, num2);

  scanf("%d", &answer);

  if (answer == num1 - num2) {
    printf("You are correct!\n");
  } else {
    printf("Sorry, the correct answer is %d.\n", num1 - num2);
  }

  // Generate two more random numbers and repeat the process for multiplication
  num1 = rand() % 5 + 1;
  num2 = rand() % 5 + 1;
  
  printf("What is %d * %d?\n", num1, num2);

  scanf("%d", &answer);

  if (answer == num1 * num2) {
    printf("You are correct!\n");
  } else {
    printf("Sorry, the correct answer is %d.\n", num1 * num2);
  }

  // Generate two more random numbers and repeat the process for division
  num1 = rand() % 5 + 1;
  num2 = rand() % 5 + 1;
  
  float realAnswer = (float)num1 / (float)num2;
  
  printf("What is %.2f / %d?\n", realAnswer, num2);

  float userAnswer;
  scanf("%f", &userAnswer);

  if (userAnswer == realAnswer) {
    printf("You are correct!\n");
  } else {
    printf("Sorry, the correct answer is %.2f.\n", realAnswer);
  }

  return 0;
}