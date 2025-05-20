//FormAI DATASET v1.0 Category: Arithmetic ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void calculate_sum(int num1, int num2);
void calculate_difference(int num1, int num2);
void calculate_product(int num1, int num2);
void calculate_quotient(int num1, int num2);

int main() {

  int num1, num2;

  printf("Enter a value for num1: ");
  scanf("%d", &num1);
  
  printf("Enter a value for num2: ");
  scanf("%d", &num2);

  printf("Calculating the sum asynchronously...\n");
  calculate_sum(num1, num2);

  printf("Calculating the difference asynchronously...\n");
  calculate_difference(num1, num2);

  printf("Calculating the product asynchronously...\n");
  calculate_product(num1, num2);

  printf("Calculating the quotient asynchronously...\n");
  calculate_quotient(num1, num2);

  return 0;
}

void calculate_sum(int num1, int num2) {
  int result = num1 + num2;
  srand(time(NULL));
  int delay = rand() % 5 + 1;
  printf("The sum is %d (delayed by %d seconds).\n", result, delay);
  sleep(delay);
}

void calculate_difference(int num1, int num2) {
  int result = num1 - num2;
  srand(time(NULL));
  int delay = rand() % 5 + 1;
  printf("The difference is %d (delayed by %d seconds).\n", result, delay);
  sleep(delay);
}

void calculate_product(int num1, int num2) {
  int result = num1 * num2;
  srand(time(NULL));
  int delay = rand() % 5 + 1;
  printf("The product is %d (delayed by %d seconds).\n", result, delay);
  sleep(delay);
}

void calculate_quotient(int num1, int num2) {
  float result = (float) num1 / num2;
  srand(time(NULL));
  int delay = rand() % 5 + 1;
  printf("The quotient is %f (delayed by %d seconds).\n", result, delay);
  sleep(delay);
}