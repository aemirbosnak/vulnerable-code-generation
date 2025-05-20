//FormAI DATASET v1.0 Category: Educational ; Style: excited
#include<stdio.h>

int main()
{
  printf("Wohoo! Welcome to the amazing world of C Programming!!\n");

  // Declaring 3 integer variables
  int x, y, z;

  // Taking input of 3 integers
  printf("Enter 3 integers separated by a space: ");
  scanf("%d %d %d", &x, &y, &z);

  // Performing some arithmetic operations
  int sum = x + y + z;
  int product = x * y * z;
  int average = sum / 3;

  // Printing the results of arithmetic operations
  printf("The sum of entered integers is: %d\n", sum);
  printf("The product of entered integers is: %d\n", product);
  printf("The average of entered integers is: %d\n", average);

  // Checking if the sum is greater than 100 or not 
  if (sum > 100) {
    printf("Sum is greater than 100. Hurray!!\n");
  } else {
    printf("Sum is not greater than 100. Keep trying!\n");
  }

  // Using a loop to print the numbers from 1 to entered integer
  printf("Enter an integer to print numbers from 1 to that number: ");
  int num;
  scanf("%d", &num);

  printf("Printing numbers from 1 to %d: ", num);
  for (int i = 1; i <= num; i++) {
    printf("%d ", i);
  }
  printf("\n");

  // Using switch case
  printf("Enter a number from 1 to 5: ");
  int choice;
  scanf("%d", &choice);

  switch (choice) {
    case 1: printf("You entered 1\n"); break;
    case 2: printf("You entered 2\n"); break;
    case 3: printf("You entered 3\n"); break;
    case 4: printf("You entered 4\n"); break;
    case 5: printf("You entered 5\n"); break;
    default: printf("Invalid choice\n");
  }

  // Saying goodbye
  printf("That's all folks! Bye Bye!!\n");

  return 0;
}