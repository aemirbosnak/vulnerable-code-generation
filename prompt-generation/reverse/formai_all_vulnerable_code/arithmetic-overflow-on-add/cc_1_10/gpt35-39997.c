//FormAI DATASET v1.0 Category: Educational ; Style: cheerful
#include <stdio.h>

/* This program is a fun way to practice math skills! */

int main(void) {
  
  int num1, num2, operator, answer, user_answer;
  char name[20];

  printf("Hello! What's your name? ");
  scanf("%s", name);

  printf("Hi, %s!\n", name);
  
  printf("Let's practice some math skills!\n\n");

  while (1) {
    printf("Choose an operator:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");

    scanf("%d", &operator);

    if (operator == 5) {
      printf("Goodbye, %s!\n", name);
      break;
    }

    printf("Enter a number: ");
    scanf("%d", &num1);

    printf("Enter another number: ");
    scanf("%d", &num2);

    if (operator == 1) {
      answer = num1 + num2;
      printf("What is %d + %d? ", num1, num2);
    } else if (operator == 2) {
      answer = num1 - num2;
      printf("What is %d - %d? ", num1, num2);
    } else if (operator == 3) {
      answer = num1 * num2;
      printf("What is %d * %d? ", num1, num2);
    } else {
      answer = num1 / num2;
      printf("What is %d / %d? ", num1, num2);
    }

    scanf("%d", &user_answer);

    if (user_answer == answer) {
      printf("Nice job, %s! That's correct!\n\n", name);
    } else {
      printf("Sorry, %s. The correct answer is %d\n\n" , name, answer);
    }

  }

  return 0;
}