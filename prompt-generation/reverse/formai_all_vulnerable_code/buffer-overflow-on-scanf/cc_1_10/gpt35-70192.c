//FormAI DATASET v1.0 Category: Educational ; Style: ephemeral
#include <stdio.h>

int main() {

  int num1 = 30, num2 = 12;  // declaring two variables
  char op = '+';

  switch (op) {
    case '+':
      printf("%d + %d = %d\n", num1, num2, num1 + num2);
      break;

    case '-':
      printf("%d - %d = %d\n", num1, num2, num1 - num2);
      break;

    case '*':
      printf("%d * %d = %d\n", num1, num2, num1 * num2);
      break;

    case '/':
      printf("%d / %d = %d\n", num1, num2, num1 / num2);
      break;

    default:
      printf("Invalid operator");
  }

  char name[20];
  printf("Please enter your name: ");
  scanf("%s", name); // takes user input and stores it in name array
  printf("Welcome, %s!\n", name);

  int num;
  printf("Please enter a number: ");
  scanf("%d", &num); // takes user input and stores it in num variable

  if (num % 2 == 0) {
    printf("%d is an even number.\n", num);
  } else {
    printf("%d is an odd number.\n", num);
  }

  int i;
  for (i = 1; i <= 10; i++) {
    printf("%d\n", i);
  }

  return 0;
}