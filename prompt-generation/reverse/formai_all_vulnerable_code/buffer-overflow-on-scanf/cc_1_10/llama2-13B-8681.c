//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: excited
// 🚀 Arithmetic Explosion 💥

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 1000000
#define MAGIC_NUMBER 42

int main() {
  int num1, num2, sum, product, difference, quotient, remainder;
  char operator;
  char magic_word[50];

  // 👽 Initialize Random Numbers 👽
  srand(time(NULL));
  num1 = rand() % MAX_NUMBER;
  num2 = rand() % MAX_NUMBER;

  // 🔍 Choose an Arithmetic Operator 🔍
  operator = '+';
  printf("🤔 Choose an Arithmetic Operator ( +, -, x, /, %): ");
  scanf(" %c", &operator);

  // 📝 Evaluate Expression 📝
  if (operator == '+') {
    sum = num1 + num2;
  } else if (operator == '-') {
    difference = num1 - num2;
  } else if (operator == '*') {
    product = num1 * num2;
  } else if (operator == '/') {
    quotient = num1 / num2;
    remainder = num1 % num2;
  } else if (operator == '%') {
    remainder = num1 % num2;
    quotient = num1 / num2;
  }

  // 🔮 Print Results 🔮
  printf("🔥 Arithmetic Explosion! 🔥\n");
  printf("Num1: %d\n", num1);
  printf("Num2: %d\n", num2);
  printf("Operator: %c\n", operator);
  printf("Sum: %d\n", sum);
  printf("Product: %d\n", product);
  printf("Quotient: %d\n", quotient);
  printf("Remainder: %d\n", remainder);

  // 🎉 Check for Magic Number 🎉
  if (sum == MAGIC_NUMBER || product == MAGIC_NUMBER || quotient == MAGIC_NUMBER || remainder == MAGIC_NUMBER) {
    printf("🔥 Magic Number Found! 🔥\n");
    strcpy(magic_word, "The magic number is: ");
    strcat(magic_word, operator);
    strcat(magic_word, " ");
    strcat(magic_word, num1);
    strcat(magic_word, " ");
    strcat(magic_word, num2);
    printf("%s\n", magic_word);
  }

  return 0;
}