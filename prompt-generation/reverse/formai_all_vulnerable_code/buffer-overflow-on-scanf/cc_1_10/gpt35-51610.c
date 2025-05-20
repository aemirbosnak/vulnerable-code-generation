//FormAI DATASET v1.0 Category: Educational ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num;

  printf("Enter a number: ");
  scanf("%d", &num);

  printf("The number you entered is %d\n\n", num);

  /* Check if number is positive, negative or zero */
  if(num > 0) {
    printf("%d is a positive number.\n", num);
  } else if(num < 0) {
    printf("%d is a negative number.\n", num);
  } else {
    printf("You entered zero.\n");
  }

  /* Check if number is even or odd */
  if(num % 2 == 0) {
    printf("%d is an even number.\n", num);
  } else {
    printf("%d is an odd number.\n", num);
  }

  /* Display all even numbers from 1 to entered number */
  printf("All even numbers from 1 to %d: ", num);
  for(int i = 2; i <= num; i += 2) {
    printf("%d ", i);
  }

  /* Find and display the factorial of the entered number */
  int factorial = 1;
  for(int i = 1; i <= num; i++) {
    factorial *= i;
  }
  printf("\n\nThe factorial of %d is %d.\n", num, factorial);

  /* Generate and display the Fibonacci sequence up to the entered number */
  printf("\nThe Fibonacci sequence up to %d: ", num);
  int a = 0, b = 1, c = 0;
  while(c <= num) {
    printf("%d ", c);
    a = b;
    b = c;
    c = a + b;
  }

  return 0;
}