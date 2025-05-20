//FormAI DATASET v1.0 Category: Arithmetic ; Style: brave
#include <stdio.h>

int main() {
  printf("Welcome to the ultimate arithmetic adventure!\n");

  printf("Enter a number: ");
  int num1;
  scanf("%d", &num1);

  printf("Enter another number: ");
  int num2;
  scanf("%d", &num2);

  int sum = num1 + num2;
  int difference = num1 - num2;
  int product = num1 * num2;
  float quotient = (float)num1 / num2;

  printf("------------------------\n");
  printf("Calculating...\n");
  printf("------------------------\n");

  printf("The sum of your numbers is: %d\n", sum);
  printf("The difference of your numbers is: %d\n", difference);
  printf("The product of your numbers is: %d\n", product);
  printf("The quotient of your numbers is: %.2f\n", quotient);

  printf("------------------------\n");
  printf("Now for some extra fun...\n");
  printf("------------------------\n");

  printf("This program can also determine the remainder when dividing your two numbers!\n");
  int remainder = num1 % num2;
  printf("The remainder of your numbers is: %d\n", remainder);

  printf("------------------------\n");
  printf("But wait, there's more!\n");
  printf("------------------------\n");

  printf("What about powers? Enter an integer power you want to raise your first number to: ");
  int power;
  scanf("%d", &power);

  int result = 1;
  for(int i = 0; i < power; i++) {
    result = result * num1;
  }

  printf("%d raised to the power of %d is: %d\n", num1, power, result);

  printf("------------------------\n");
  printf("Hope you enjoyed your arithmetic adventure!\n");
  printf("------------------------\n");

  return 0;
}