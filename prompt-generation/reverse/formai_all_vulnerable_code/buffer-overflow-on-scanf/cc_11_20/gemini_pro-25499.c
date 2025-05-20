//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  // Read a number from the user
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);

  // Check if the number is even or odd
  if (num % 2 == 0) {
    printf("%d is even.\n", num);
  } else {
    printf("%d is odd.\n", num);
  }

  // Check if the number is negative or positive
  if (num < 0) {
    printf("%d is negative.\n", num);
  } else {
    printf("%d is positive.\n", num);
  }

  // Check if the number is a multiple of 3
  if (num % 3 == 0) {
    printf("%d is a multiple of 3.\n", num);
  } else {
    printf("%d is not a multiple of 3.\n", num);
  }

  // Check if the number is a multiple of 5
  if (num % 5 == 0) {
    printf("%d is a multiple of 5.\n", num);
  } else {
    printf("%d is not a multiple of 5.\n", num);
  }

  // Check if the number is a prime number
  int isPrime = 1;
  for (int i = 2; i <= num / 2; ++i) {
    if (num % i == 0) {
      isPrime = 0;
      break;
    }
  }

  if (isPrime == 1) {
    printf("%d is a prime number.\n", num);
  } else {
    printf("%d is not a prime number.\n", num);
  }

  // Check if the number is a palindrome
  int reversedNum = 0, remainder;
  int originalNum = num;

  while (num != 0) {
    remainder = num % 10;
    reversedNum = reversedNum * 10 + remainder;
    num /= 10;
  }

  if (originalNum == reversedNum) {
    printf("%d is a palindrome.\n", originalNum);
  } else {
    printf("%d is not a palindrome.\n", originalNum);
  }

  // Flip the bits of the number
  int flippedNum = ~num;
  printf("The flipped bits of %d is %d.\n", num, flippedNum);

  // Extract the individual bits of the number
  printf("The individual bits of %d are: ", num);
  for (int i = 31; i >= 0; i--) {
    printf("%d", (num >> i) & 1);
  }
  printf("\n");

  // Set a specific bit of the number
  int bitPosition;
  printf("Enter the bit position to set (0-31): ");
  scanf("%d", &bitPosition);

  num = num | (1 << bitPosition);
  printf("The number after setting the bit at position %d is %d.\n", bitPosition, num);

  // Clear a specific bit of the number
  printf("Enter the bit position to clear (0-31): ");
  scanf("%d", &bitPosition);

  num = num & ~(1 << bitPosition);
  printf("The number after clearing the bit at position %d is %d.\n", bitPosition, num);

  // Toggle a specific bit of the number
  printf("Enter the bit position to toggle (0-31): ");
  scanf("%d", &bitPosition);

  num = num ^ (1 << bitPosition);
  printf("The number after toggling the bit at position %d is %d.\n", bitPosition, num);

  return 0;
}