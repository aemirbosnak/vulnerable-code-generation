//FormAI DATASET v1.0 Category: Educational ; Style: surprised
#include <stdio.h>

int main() {
  int num;

  printf("Enter a number: ");
  scanf("%d", &num);

  if (num % 2 == 0) {
    printf("%d is an even number!\n", num);
  } else {
    printf("%d is an odd number!\n", num);
  }

  int sum = 0;

  printf("Enter the number of integers to add: ");
  scanf("%d", &num);

  int i;
  for (i = 0; i < num; i++) {
    int input;
    printf("Enter an integer: ");
    scanf("%d", &input);
    sum += input;
  }
  printf("The sum of your inputs is %d!\n", sum);

  char name[256];
  printf("Enter your name: ");
  scanf("%s", name);
  printf("Hello, %s!\n", name);

  printf("Enter a number to find its factorial: ");
  scanf("%d", &num);

  int factorial = 1;
  for (i = 1; i <= num; i++) {
    factorial *= i;
  }
  printf("The factorial of %d is %d!\n", num, factorial);

  int a, b;
  printf("Enter two numbers to find their product: ");
  scanf("%d %d", &a, &b);
  int product = a * b;
  printf("The product of %d and %d is %d!\n", a, b, product);

  int pins[] = {12, 45, 23, 67, 89, 34};
  int num_pins = sizeof(pins) / sizeof(pins[0]);
  int max_pin = pins[0];

  for (i = 1; i < num_pins; i++) {
    if (pins[i] > max_pin) {
      max_pin = pins[i];
    }
  }
  printf("The maximum pin number is %d!\n", max_pin);

  return 0;
}