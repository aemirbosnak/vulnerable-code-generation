//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100000

int main() {
  srand(time(NULL));  // seed the random number generator

  int num1, num2, sum, difference, product, quotient, remainder;
  int correct = 0;  // keep track of correct answers

  printf("Welcome to the Happy Math Exercise!\n");

  // 1. Addition
  printf("Let's start with some addition exercises! 🐰💡\n");
  for (int i = 0; i < 5; i++) {
    num1 = rand() % MAX_NUMBER;
    num2 = rand() % MAX_NUMBER;
    sum = num1 + num2;
    printf("What is %d + %d? 🤔\n", num1, num2);
    printf("You answered: %d\n", sum);
    if (sum == num1 + num2) {
      correct++;
      printf("Correct! 👍 You got it right! 🎉\n");
    } else {
      printf("Oops! 😔 You got it wrong. 😢 Try again! 👊\n");
    }
  }

  // 2. Subtraction
  printf("Now let's practice subtraction! 🐰🔪\n");
  for (int i = 0; i < 5; i++) {
    num1 = rand() % MAX_NUMBER;
    num2 = rand() % MAX_NUMBER;
    difference = num1 - num2;
    printf("What is %d - %d? 🤔\n", num1, num2);
    printf("You answered: %d\n", difference);
    if (difference == num1 - num2) {
      correct++;
      printf("Great job! 👍 You got it right! 🎉\n");
    } else {
      printf("Oops! 😔 You got it wrong. 😢 Try again! 👊\n");
    }
  }

  // 3. Multiplication
  printf("Next up is multiplication! 🐰🔢\n");
  for (int i = 0; i < 5; i++) {
    num1 = rand() % MAX_NUMBER;
    num2 = rand() % MAX_NUMBER;
    product = num1 * num2;
    printf("What is %d x %d? 🤔\n", num1, num2);
    printf("You answered: %d\n", product);
    if (product == num1 * num2) {
      correct++;
      printf("Well done! 👍 You got it right! 🎉\n");
    } else {
      printf("Oops! 😔 You got it wrong. 😢 Try again! 👊\n");
    }
  }

  // 4. Division
  printf("Last but not least, let's do some division! 🐰🔢\n");
  for (int i = 0; i < 5; i++) {
    num1 = rand() % MAX_NUMBER;
    num2 = rand() % MAX_NUMBER;
    quotient = num1 / num2;
    remainder = num1 % num2;
    printf("What is %d / %d? 🤔\n", num1, num2);
    printf("You answered: %d\n", quotient);
    if (quotient == num1 / num2 && remainder == num1 % num2) {
      correct++;
      printf("Yay! 👍 You got it right! 🎉\n");
    } else {
      printf("Oops! 😔 You got it wrong. 😢 Try again! 👊\n");
    }
  }

  printf("You got %d out of 5 correct! 🎉\n", correct);
  return 0;
}