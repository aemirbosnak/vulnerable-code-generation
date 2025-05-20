//FormAI DATASET v1.0 Category: Math exercise ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Display a cheerful message to the user
  printf("Welcome to the Math Exercise Program! Let's have some fun with math!\n");

  // Seed the random number generator
  srand(time(0));

  // Randomly generate two numbers
  int num1 = rand() % 100 + 1;
  int num2 = rand() % 100 + 1;

  // Display the two numbers to the user
  printf("What is %d + %d?\n", num1, num2);

  // Get the user's answer
  int answer1;
  scanf("%d", &answer1);

  // Check the user's answer and give feedback
  if (answer1 == num1 + num2) {
    printf("Great job! You got it right!\n");
  } else {
    printf("Oops, that's not quite right. The correct answer is %d.\n", num1 + num2);
  }

  // Randomly generate two more numbers
  int num3 = rand() % 50 + 1;
  int num4 = rand() % 50 + 1;

  // Display the second math problem to the user
  printf("What is %d - %d?\n", num3, num4);

  // Get the user's answer
  int answer2;
  scanf("%d", &answer2);

  // Check the user's answer and give feedback
  if (answer2 == num3 - num4) {
    printf("Awesome! You're on a roll!\n");
  } else {
    printf("Oops, that one was a bit trickier. The correct answer is %d.\n", num3 - num4);
  }

  // Randomly generate two more numbers
  int num5 = rand() % 10 + 1;
  int num6 = rand() % 10 + 1;

  // Display the third math problem to the user
  printf("What is %d x %d?\n", num5, num6);

  // Get the user's answer
  int answer3;
  scanf("%d", &answer3);

  // Check the user's answer and give feedback
  if (answer3 == num5*num6) {
    printf("You are a math wizard! Well done!\n");
  } else {
    printf("Don't worry, that one was tough. The correct answer is %d.\n", num5*num6);
  }

  // Display a cheerful message to the user to conclude the program
  printf("Thank you for playing the Math Exercise Program! Come back soon!\n");

  return 0;
}