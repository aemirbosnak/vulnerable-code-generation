//FormAI DATASET v1.0 Category: Math exercise ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
  int num1, num2, answer, guess, attempts = 0;
  char operator[4] = "+-*/";
  srand(time(NULL)); // seed the random number generator

  printf("Welcome to the Math Exercise Program!\n\n");

  // loop until the user decides to quit
  while (1)
  {
    printf("Choose the difficulty level:\n");
    printf("1: Easy\n");
    printf("2: Medium\n");
    printf("3: Hard\n");
    printf("4: Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &guess);

    // check if the user wants to quit
    if (guess == 4)
    {
      printf("\nGoodbye!\n");
      break; // exit the program
    }

    // generate two random numbers and an operator
    num1 = rand() % 10 + 1; // number between 1 and 10
    num2 = rand() % 10 + 1; // number between 1 and 10
    char op = operator[rand() % 4];

    switch (guess)
    {
      case 1:
        printf("\nYou have chosen the Easy level.\n");
        printf("What is %d %c %d?\n", num1, op, num2);
        answer = (op == '+') ? num1 + num2 : num1 - num2; // calculate the correct answer
        break;

      case 2:
        printf("\nYou have chosen the Medium level.\n");
        printf("What is %d %c %d %c %d?\n", num1, op, num2, op, num1*num2);
        answer = (op == '+') ? num1 + num2 + num1*num2 : num1 - num2 - num1*num2; // calculate the correct answer
        break;

      case 3:
        printf("\nYou have chosen the Hard level.\n");
        printf("What is %d %c %d %c %d %c %d?\n", num1, op, num2, op, num1*num2, op, num1*num2 + num2);
        answer = (op == '+') ? num1 + num2 + num1*num2 + num1*num2 + num2 : num1 - num2 - num1*num2 - num1*num2 - num2; // calculate the correct answer
        break;

      default:
        printf("\nInvalid choice. Try again.\n");
        continue; // jump to the beginning of the loop
    }

    // prompt the user to guess the answer
    printf("\nEnter your answer: ");
    scanf("%d", &guess);

    // check if the answer is correct
    if (guess == answer)
    {
      attempts++;
      printf("\nCongratulations! Your answer is correct.\n");
      printf("You have made %d attempt(s).\n\n", attempts);
    }
    else
    {
      printf("\nSorry, your answer is incorrect.\n\n");
      attempts++;
    }
  }

  return 0; // exit the program
}