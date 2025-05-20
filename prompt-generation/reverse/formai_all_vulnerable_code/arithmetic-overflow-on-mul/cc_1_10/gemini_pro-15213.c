//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Declare variables
  int num1, num2, result, choice;
  float num3, num4, resultf;

  // Display the menu
  printf("1. Add two integers\n");
  printf("2. Subtract two integers\n");
  printf("3. Multiply two integers\n");
  printf("4. Divide two integers\n");
  printf("5. Add two floats\n");
  printf("6. Subtract two floats\n");
  printf("7. Multiply two floats\n");
  printf("8. Divide two floats\n");
  printf("9. Exit\n");

  // Get the user's choice
  printf("Enter your choice: ");
  scanf("%d", &choice);

  // Perform the selected operation
  switch (choice) {
    case 1:
      // Get the two integers
      printf("Enter the first integer: ");
      scanf("%d", &num1);
      printf("Enter the second integer: ");
      scanf("%d", &num2);

      // Add the two integers
      result = num1 + num2;

      // Display the result
      printf("The sum of %d and %d is: %d\n", num1, num2, result);
      break;
    case 2:
      // Get the two integers
      printf("Enter the first integer: ");
      scanf("%d", &num1);
      printf("Enter the second integer: ");
      scanf("%d", &num2);

      // Subtract the two integers
      result = num1 - num2;

      // Display the result
      printf("The difference of %d and %d is: %d\n", num1, num2, result);
      break;
    case 3:
      // Get the two integers
      printf("Enter the first integer: ");
      scanf("%d", &num1);
      printf("Enter the second integer: ");
      scanf("%d", &num2);

      // Multiply the two integers
      result = num1 * num2;

      // Display the result
      printf("The product of %d and %d is: %d\n", num1, num2, result);
      break;
    case 4:
      // Get the two integers
      printf("Enter the first integer: ");
      scanf("%d", &num1);
      printf("Enter the second integer: ");
      scanf("%d", &num2);

      // Divide the two integers
      result = num1 / num2;

      // Display the result
      printf("The quotient of %d and %d is: %d\n", num1, num2, result);
      break;
    case 5:
      // Get the two floats
      printf("Enter the first float: ");
      scanf("%f", &num3);
      printf("Enter the second float: ");
      scanf("%f", &num4);

      // Add the two floats
      resultf = num3 + num4;

      // Display the result
      printf("The sum of %f and %f is: %f\n", num3, num4, resultf);
      break;
    case 6:
      // Get the two floats
      printf("Enter the first float: ");
      scanf("%f", &num3);
      printf("Enter the second float: ");
      scanf("%f", &num4);

      // Subtract the two floats
      resultf = num3 - num4;

      // Display the result
      printf("The difference of %f and %f is: %f\n", num3, num4, resultf);
      break;
    case 7:
      // Get the two floats
      printf("Enter the first float: ");
      scanf("%f", &num3);
      printf("Enter the second float: ");
      scanf("%f", &num4);

      // Multiply the two floats
      resultf = num3 * num4;

      // Display the result
      printf("The product of %f and %f is: %f\n", num3, num4, resultf);
      break;
    case 8:
      // Get the two floats
      printf("Enter the first float: ");
      scanf("%f", &num3);
      printf("Enter the second float: ");
      scanf("%f", &num4);

      // Divide the two floats
      resultf = num3 / num4;

      // Display the result
      printf("The quotient of %f and %f is: %f\n", num3, num4, resultf);
      break;
    case 9:
      // Exit the program
      exit(0);
      break;
    default:
      // Invalid choice
      printf("Invalid choice\n");
  }

  return 0;
}