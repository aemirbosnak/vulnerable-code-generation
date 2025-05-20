//FormAI DATASET v1.0 Category: Math exercise ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num1, num2, guess, correctAns, opr; // declare variables
  srand(time(NULL)); // seed random number generator
  
  printf("Welcome to the Math Exercise Program!\n\n");
  printf("Choose an operation:\n");
  printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");

  scanf("%d", &opr); // take user input for operation

  switch(opr) {
    case 1:
      printf("You have chosen addition!\n\n");
      break;
    case 2:
      printf("You have chosen subtraction!\n\n");
      break;
    case 3:
      printf("You have chosen multiplication!\n\n");
      break;
    case 4:
      printf("You have chosen division!\n\n");
      break;
    default:
      printf("Invalid operation choice!\n");
      return 0;
  }
  
  num1 = rand() % 100; // generate random numbers
  num2 = rand() % 100;
  
  switch(opr) {
    case 1:
      correctAns = num1 + num2;
      printf("What is %d + %d?\n", num1, num2);
      break;
    case 2:
      correctAns = num1 - num2;
      printf("What is %d - %d?\n", num1, num2);
      break;
    case 3:
      correctAns = num1 * num2;
      printf("What is %d * %d?\n", num1, num2);
      break;
    case 4:
      correctAns = num1 / num2;
      printf("What is %d / %d (rounded to the nearest whole number)?\n", num1, num2);
      break;
  }

  scanf("%d", &guess); // take user input for answer

  if(guess == correctAns) {
    printf("You are correct! Great job.\n");
  } else {
    printf("Sorry, the correct answer was %d.\n", correctAns);
  }

  return 0;
}