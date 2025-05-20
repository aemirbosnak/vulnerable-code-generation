//Code Llama-13B DATASET v1.0 Category: Math exercise ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 100
int getRandomNumber() {
  return rand() % 100 + 1;
}

// Function to generate a random operation (+, -, *, /)
char getRandomOperation() {
  int operation = rand() % 4;
  switch (operation) {
    case 0:
      return '+';
    case 1:
      return '-';
    case 2:
      return '*';
    case 3:
      return '/';
    default:
      return '+';
  }
}

// Function to generate a random number of decimal places
int getRandomDecimalPlaces() {
  return rand() % 4;
}

// Function to generate a random number with decimal places
double getRandomNumberWithDecimalPlaces() {
  int decimalPlaces = getRandomDecimalPlaces();
  double number = getRandomNumber();
  for (int i = 0; i < decimalPlaces; i++) {
    number += getRandomNumber() / (double)pow(10, i + 1);
  }
  return number;
}

// Function to generate a random math problem
void generateMathProblem() {
  double number1 = getRandomNumberWithDecimalPlaces();
  double number2 = getRandomNumberWithDecimalPlaces();
  char operation = getRandomOperation();
  double result = 0;
  switch (operation) {
    case '+':
      result = number1 + number2;
      break;
    case '-':
      result = number1 - number2;
      break;
    case '*':
      result = number1 * number2;
      break;
    case '/':
      result = number1 / number2;
      break;
  }
  printf("What is %f %c %f?\n", number1, operation, number2);
  printf("Answer: ");
  scanf("%lf", &result);
  if (result == number1 + number2) {
    printf("Correct!\n");
  } else {
    printf("Incorrect. The answer is %f.\n", number1 + number2);
  }
}

int main() {
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    generateMathProblem();
  }
  return 0;
}