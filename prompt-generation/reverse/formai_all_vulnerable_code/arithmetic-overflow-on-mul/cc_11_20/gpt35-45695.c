//FormAI DATASET v1.0 Category: Arithmetic ; Style: shape shifting
#include <stdio.h>

int main() {
  int number = 0;

  printf("Enter a number: ");
  scanf("%d", &number);

  if (number < 0) {
    printf("%d is negative\n", number);
  } else if (number > 0) {
    printf("%d is positive\n", number);
  } else {
    printf("%d is neither negative nor positive\n", number);
  }

  printf("Do you want to square the number? (y/n): ");
  char choice = getchar();

  if (choice == 'y' || choice == 'Y') {
    int squared = number * number;
    printf("The square of %d is %d\n", number, squared);
  }

  printf("Do you want to convert the number to binary? (y/n): ");
  choice = getchar();

  if (choice == 'y' || choice == 'Y') {
    int binary[32];
    int index = 0;

    while (number > 0) {
      binary[index] = number % 2;
      number = number / 2;
      index++;
    }

    printf("The binary representation of the number is: ");

    for (int i = index - 1; i >= 0; i--) {
      printf("%d", binary[i]);
    }

    printf("\n");
  }

  printf("Do you want to find the factorial of the number? (y/n): ");
  choice = getchar();

  if (choice == 'y' || choice == 'Y') {
    unsigned long long int factorial = 1;

    for (int i = 1; i <= number; i++) {
      factorial *= i;
    }

    printf("The factorial of %d is %llu\n", number, factorial);
  }

  return 0;
}