//FormAI DATASET v1.0 Category: Binary Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decimalToBinary(int n) {
  int binaryNum[32];
  int i = 0;
  while (n > 0) {
    binaryNum[i] = n % 2;
    n = n / 2;
    i++;
  }

  printf("\nBinary equivalent of decimal number is: ");
  for (int j = i - 1; j >= 0; j--)
    printf("%d", binaryNum[j]);
}

// Function to convert binary to decimal
int binaryToDecimal(long long n) {
  int decimalNumber = 0, i = 0, remainder;
  while (n != 0) {
    remainder = n % 10;
    n /= 10;
    decimalNumber += remainder * pow(2, i);
    ++i;
  }
  return decimalNumber;
}

int main() {
  int choice, decimalNumber;
  long long binaryNumber;
  printf("Welcome to Binary Converter!");
  do {
    printf("\n\nSelect an option:\n1. Decimal to binary\n2. Binary to decimal\n3. Exit");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the decimal number to convert: ");
      scanf("%d", &decimalNumber);
      decimalToBinary(decimalNumber);
      break;
    case 2:
      printf("Enter the binary number to convert: ");
      scanf("%lld", &binaryNumber);
      printf("\nDecimal equivalent of binary number is: %d", binaryToDecimal(binaryNumber));
      break;
    case 3:
      printf("\nExiting program");
      exit(0);
    default:
      printf("\nInvalid choice. Please select again.");
    }
  } while (choice != 3);
  return 0;
}