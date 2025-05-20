//FormAI DATASET v1.0 Category: Educational ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num1, num2, result;

  printf("Enter the first number: ");
  scanf("%d", &num1);

  printf("Enter the second number: ");
  scanf("%d", &num2);

  result = num1 + num2;

  if (result > 1000) {
    printf("Wow, the result is greater than 1000! I didn't expect that.\n");
  } else {
    printf("Okay, the result is %d. Nothing too exciting.\n", result);
  }

  printf("\n");

  char name[50];

  printf("What is your name? ");
  scanf("%s", name);

  printf("Hello, %s! Thanks for using my program.\n", name);

  printf("\n");

  int i;

  printf("Now let's count to 10:\n");
  for (i = 1; i <= 10; i++) {
    printf("%d\n", i);
  }

  printf("\n");

  int age;

  printf("How old are you? ");
  scanf("%d", &age);

  if (age >= 18) {
    printf("Congratulations, you are an adult!\n");
  } else {
    printf("Sorry, you are not old enough to use this program.\n");
    exit(0);
  }

  printf("\n");

  printf("Thanks again for using my program, %s.\n", name);
  printf("Goodbye!\n");

  return 0;
}