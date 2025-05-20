//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SORRY_NOT_SORRY 1

int main() {
  int sorry = SORRY_NOT_SORRY;
  int num1 = 42;
  int num2 = 13;
  int result = 0;
  char op = '+';

  // Let's get this party started!
  printf("Welcome to the most epic C arithmetic program ever created! \n");
  printf("We're gonna party like it's 1999! \n");

  // Ask the user for the first number.
  printf("Gimme that first number, yo! ");
  scanf("%d", &num1);
  printf("Okay, that's cool. Now give me the second number...\n");

  // Ask the user for the second number.
  scanf("%d", &num2);

  // Let's get this arithmetic party started!
  switch (op) {
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num1 - num2;
      break;
    case '*':
      result = num1 * num2;
      break;
    case '/':
      result = num1 / num2;
      break;
    case '%':
      result = num1 % num2;
      break;
    default:
      sorry = SORRY_NOT_SORRY;
      break;
  }

  // Display the result.
  printf("The result of %d + %d is %d. \n", num1, num2, result);

  // Time for a little breakdancing!
  printf("Yo, yo, yo! Look ma, I'm a C programmer and I can do some sick moves! \n");
  printf("I can do the cha cha slide, the Macarena, and even the Sprinkler! \n");
  printf("But don't worry, I won't do any of that here. I'm too cool for that. \n");

  // Ask the user if they want to play again.
  printf("Do you want to play again? (y/n) ");
  char playAgain = getchar();

  if (playAgain == 'y') {
    printf("Alright, let's do this again! \n");
    // Do it again!
  } else {
    printf("It was fun, but I think I'll stop here. \n");
  }

  return sorry;
}