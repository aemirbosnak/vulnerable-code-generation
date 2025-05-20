//FormAI DATASET v1.0 Category: Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main()
{
  printf("Welcome to the amazing calculator program!\n\n");

  int num1, num2, option, result;

  printf("Please enter the first number: ");
  scanf("%d", &num1);

  printf("\nPlease enter the second number: ");
  scanf("%d", &num2);

  printf("\nWow, two great numbers! What would you like to do with them?\n");
  printf("1. Add them.\n");
  printf("2. Subtract the second number from the first.\n");
  printf("3. Multiply them.\n");
  printf("4. Divide the first number by the second.\n");

  printf("\nPlease enter your option (1/2/3/4): ");
  scanf("%d", &option);

  switch(option)
  {
    case 1:
      result = num1 + num2;
      printf("\nCongratulations, the sum of %d and %d is %d!\n", num1, num2, result);
      break;

    case 2:
      result = num1 - num2;
      printf("\nAmazing, %d minus %d equals %d!\n", num1, num2, result);
      break;

    case 3:
      result = num1 * num2;
      printf("\nIncredible, %d times %d is %d!\n", num1, num2, result);
      break;

    case 4:
      result = num1 / num2;
      printf("\nAstounding, when you divide %d by %d, you get %d!\n", num1, num2, result);
      break;

    default:
      printf("\nOh no, you entered an invalid option! Exiting program.\n");
      exit(0);
  }

  printf("\nThank you for using the amazing calculator program. Have a fantastic day!\n");

  return 0;
}