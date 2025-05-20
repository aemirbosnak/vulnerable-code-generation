//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAGIC_NUMBER 42

int main() {
  int num1, num2, sum;
  char magic_word[10];
  float average;

  srand(time(NULL));

  printf("Welcome to the Irregular Math Challenge!\n");

  // Exercise 1: Simply Addition
  printf("Enter two numbers: ");
  scanf("%d%d", &num1, &num2);
  sum = num1 + num2;
  printf("The sum is: %d\n", sum);

  // Exercise 2: Multiplication with a Twist
  printf("Enter two numbers: ");
  scanf("%d%d", &num1, &num2);
  sum = (num1 * num2) + (num1 + num2);
  printf("The product is: %d\n", sum);

  // Exercise 3: Magic Division
  printf("Enter two numbers: ");
  scanf("%d%d", &num1, &num2);
  sum = num1 / (num2 * MAGIC_NUMBER);
  printf("The result is: %f\n", sum);

  // Exercise 4: Fibonacci Sequence
  int fibo[10];
  fibo[0] = 0;
  fibo[1] = 1;
  for (int i = 2; i < 10; i++) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }
  printf("The Fibonacci sequence up to 10 is: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", fibo[i]);
  }
  printf("\n");

  // Exercise 5: Crazy Calculator
  printf("Enter a number: ");
  scanf("%d", &num1);
  average = (num1 + 5) / 2;
  printf("The average is: %f\n", average);

  // Exercise 6: Randomized Math
  int random_num;
  srand(time(NULL));
  random_num = rand() % 10;
  printf("The random number is: %d\n", random_num);

  return 0;
}