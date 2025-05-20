//FormAI DATASET v1.0 Category: Educational ; Style: active
#include <stdio.h>

int main() {

  int num1, num2, sum;

  printf("Enter the first number: ");
  scanf("%d", &num1);

  printf("Enter the second number: ");
  scanf("%d", &num2);

  sum = num1 + num2;

  printf("The sum of %d and %d is: %d\n", num1, num2, sum);

  if (sum >= 50) {
    printf("The sum is greater than or equal to 50.\n");
  }
  else {
    printf("The sum is less than 50.\n");
  }

  int i; // counter for loop
  printf("Printing the numbers from 1 to 10 using a for loop: \n");
  for (i = 1; i <= 10; i++) {
    printf("%d\n", i);
  }

  // Using a switch statement to determine a grade based on a percentage
  int percentage;
  printf("Enter your percentage: ");
  scanf("%d", &percentage);

  switch (percentage / 10) {
    case 10:
    case 9:
      printf("Your grade is A.\n");
      break;
    case 8:
      printf("Your grade is B.\n");
      break;
    case 7:
      printf("Your grade is C.\n");
      break;
    case 6:
      printf("Your grade is D.\n");
      break;
    default:
      printf("Your grade is F.\n");
  }

  return 0;
}