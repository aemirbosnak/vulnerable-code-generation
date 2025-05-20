//FormAI DATASET v1.0 Category: Educational ; Style: innovative
#include <stdio.h>

// Define a function to sum two integers
int sum(int x, int y) {
  return x + y;
}

int main() {
  printf("Welcome to the C Educational Example Program!\n\n");

  // Get input from the user
  int num1, num2;
  printf("Please enter two integers to sum:\n");
  scanf("%d %d", &num1, &num2);

  // Call the sum function and print the result
  int result = sum(num1, num2);
  printf("The sum of %d and %d is %d.\n", num1, num2, result);

  // Demonstrate the ternary operator
  int ternary = (num1 > num2) ? num1 : num2;
  printf("Using the ternary operator, the larger number is %d.\n", ternary);

  // Use a loop to print out the first 10 numbers in the Fibonacci sequence
  printf("The first 10 numbers in the Fibonacci sequence are:\n");
  int first = 0;
  int second = 1;
  for (int i = 0; i < 10; i++) {
    printf("%d ", first);
    int third = first + second;
    first = second;
    second = third;
  }
  printf("\n");

  // Use a switch statement to print the name of a month based on its number
  int monthNum;
  printf("Please enter a number for a month (1-12):\n");
  scanf("%d", &monthNum);
  switch (monthNum) {
    case 1:
      printf("January\n");
      break;
    case 2:
      printf("February\n");
      break;
    case 3:
      printf("March\n");
      break;
    case 4:
      printf("April\n");
      break;
    case 5:
      printf("May\n");
      break;
    case 6:
      printf("June\n");
      break;
    case 7:
      printf("July\n");
      break;
    case 8:
      printf("August\n");
      break;
    case 9:
      printf("September\n");
      break;
    case 10:
      printf("Octover\n");
      break;
    case 11:
      printf("November\n");
      break;
    case 12:
      printf("December\n");
      break;
    default:
      printf("Invalid input!\n");
  }

  printf("\nThank you for trying the C Educational Example Program!\n");
  return 0;
}