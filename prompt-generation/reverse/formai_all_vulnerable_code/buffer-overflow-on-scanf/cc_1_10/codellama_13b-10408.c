//Code Llama-13B DATASET v1.0 Category: Math exercise ; Style: decentralized
// Decentralized Math Exercise Program

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define constants
const int MIN_NUM = 1;
const int MAX_NUM = 100;
const int MIN_OP = 0;
const int MAX_OP = 5;
const int OPERATIONS[5] = { '+', '-', '*', '/', '%' };

// Function to generate a random number between a min and max value
int random_num(int min, int max) {
  return min + rand() % (max - min + 1);
}

// Function to generate a random operation between a min and max value
char random_op(int min, int max) {
  return OPERATIONS[rand() % (max - min + 1)];
}

// Function to perform a math operation on two numbers
int perform_operation(int num1, int num2, char op) {
  switch (op) {
    case '+':
      return num1 + num2;
    case '-':
      return num1 - num2;
    case '*':
      return num1 * num2;
    case '/':
      return num1 / num2;
    case '%':
      return num1 % num2;
    default:
      return 0;
  }
}

// Function to validate the user's answer
int validate_answer(int num1, int num2, char op, int answer) {
  return perform_operation(num1, num2, op) == answer;
}

// Main function
int main() {
  // Initialize random seed
  srand(time(NULL));

  // Generate random numbers and operation
  int num1 = random_num(MIN_NUM, MAX_NUM);
  int num2 = random_num(MIN_NUM, MAX_NUM);
  char op = random_op(MIN_OP, MAX_OP);

  // Print the problem
  printf("%d %c %d = ", num1, op, num2);

  // Get the user's answer
  int answer;
  scanf("%d", &answer);

  // Validate the user's answer
  if (validate_answer(num1, num2, op, answer)) {
    printf("Correct!\n");
  } else {
    printf("Incorrect, the answer is %d\n", perform_operation(num1, num2, op));
  }

  return 0;
}