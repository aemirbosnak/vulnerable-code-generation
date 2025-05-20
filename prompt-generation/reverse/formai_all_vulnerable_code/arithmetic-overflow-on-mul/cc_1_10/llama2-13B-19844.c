//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define INVASION_BEGAN 1
#define INVASION_END 2
#define SORRY_NOT_SORRY 3

int main() {
  int invasion_state = INVASION_BEGAN;
  int num1, num2, result;
  char input_string[50];

  // Invasion begins!
  printf("Welcome to the math invasion! Your brain will be invaded with calculations... muahahaha!\n");

  // First question: addition
  printf("Please enter two numbers to add: ");
  fgets(input_string, 50, stdin);
  sscanf(input_string, "%d%*c", &num1, &num2);
  result = num1 + num2;
  printf("The result of %d + %d is %d\n", num1, num2, result);

  // Increase the invasion level
  invasion_state++;

  // Second question: subtraction
  printf("Please enter a number to subtract: ");
  fgets(input_string, 50, stdin);
  sscanf(input_string, "%d%*c", &num1);
  result = num1 - num2;
  printf("The result of %d - %d is %d\n", num1, num2, result);

  // Increase the invasion level
  invasion_state++;

  // Third question: multiplication
  printf("Please enter two numbers to multiply: ");
  fgets(input_string, 50, stdin);
  sscanf(input_string, "%d%*c", &num1, &num2);
  result = num1 * num2;
  printf("The result of %d x %d is %d\n", num1, num2, result);

  // Increase the invasion level
  invasion_state++;

  // Fourth question: division
  printf("Please enter two numbers to divide: ");
  fgets(input_string, 50, stdin);
  sscanf(input_string, "%d%*c", &num1, &num2);
  result = num1 / num2;
  printf("The result of %d / %d is %d\n", num1, num2, result);

  // Invasion ends!
  printf("The invasion has ended. Your brain has been invaded with calculations... muahahaha!\n");
  return INVASION_END;
}