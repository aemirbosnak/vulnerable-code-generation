//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
  int num1, num2, result;
  float average;
  char response;

  srand(time(NULL));

  printf("Welcome to the Curious Arithmetic Adventure!\n");

  do {
    printf("Choose an operation: \n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &response);

    switch (response) {
      case 1:
        printf("Enter two numbers: ");
        scanf("%d%d", &num1, &num2);
        result = num1 + num2;
        break;

      case 2:
        printf("Enter two numbers: ");
        scanf("%d%d", &num1, &num2);
        result = num1 - num2;
        break;

      case 3:
        printf("Enter two numbers: ");
        scanf("%d%d", &num1, &num2);
        result = num1 * num2;
        break;

      case 4:
        printf("Enter two numbers: ");
        scanf("%d%d", &num1, &num2);
        result = num1 / num2;
        break;

      default:
        printf("Invalid operation choice. Try again!\n");
        continue;
    }

    printf("Result: %d\n", result);

    if (result % MAGIC_NUMBER == 0) {
      printf("Congratulations, you found the Hidden Treasure! The result is a multiple of 42.\n");
    } else {
      printf("Oh no, you didn't find the Hidden Treasure. The result is not a multiple of 42.\n");
    }

  } while (1);

  return 0;
}