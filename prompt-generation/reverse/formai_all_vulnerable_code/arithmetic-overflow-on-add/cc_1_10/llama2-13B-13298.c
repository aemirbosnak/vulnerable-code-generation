//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
  int number1, number2, sum, difference, product, quotient, remainder;
  char operation;

  printf("Welcome to the Arithmetic Adventure! \n");

  // Initialize the variables
  printf("Enter the first number: ");
  scanf("%d", &number1);
  printf("Enter the second number: ");
  scanf("%d", &number2);
  printf("Enter the operation (+, -, x, /): ");
  scanf(" %c", &operation);

  // Perform the operation
  switch (operation) {
    case '+':
      sum = number1 + number2;
      break;
    case '-':
      difference = number1 - number2;
      break;
    case '*':
      product = number1 * number2;
      break;
    case '/':
      quotient = number1 / number2;
      remainder = number1 % number2;
      break;
    default:
      printf("Invalid operation. Please try again.\n");
      return 1;
  }

  // Print the results
  printf("The result of %d %c %d is %d\n", number1, operation, number2, sum);
  printf("The result of %d %c %d is %d\n", number1, operation, number2, product);
  printf("The result of %d %c %d is %d\n", number1, operation, number2, quotient);
  printf("The result of %d %c %d is %d\n", number1, operation, number2, remainder);

  // Play a game of arithmetic roulette
  srand(time(NULL));
  int roulette_number = (rand() % 10) + 1;
  switch (roulette_number) {
    case 1:
      printf("Congratulations, you won a magic bean! \n");
      break;
    case 2:
      printf("Better luck next time. You lost a magic bean. \n");
      break;
    default:
      printf("You rolled a %d. Keep playing to see if you win or lose. \n", roulette_number);
      break;
  }

  return 0;
}