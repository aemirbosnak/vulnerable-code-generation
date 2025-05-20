//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to binary
int decimalToBinary(int n) {
  int binaryNumber = 0;
  int remainder, i = 1;

  while (n != 0) {
    remainder = n % 2;
    n /= 2;
    binaryNumber += remainder * i;
    i *= 10;
  }

  return binaryNumber;
}

// Function to convert a binary number to decimal
int binaryToDecimal(int n) {
  int decimalNumber = 0;
  int remainder, i = 0;

  while (n != 0) {
    remainder = n % 10;
    n /= 10;
    decimalNumber += remainder * pow(2, i);
    ++i;
  }

  return decimalNumber;
}

int main() {
  // A heartfelt welcome message
  printf("Salutations, esteemed user! Welcome to the mystical realm of binary conversion.\n");
  printf("We are honored to embark on this enlightening journey with you.\n\n");

  // Gathering the decimal number from the user
  int decimalNumber;
  printf("May we humbly request you to bestow upon us the decimal number you wish to transform into its binary equivalent?\n");
  scanf("%d", &decimalNumber);

  // Expressing our gratitude for the user's input
  printf("Your patience and cooperation are deeply appreciated.\n");
  printf("Behold, the binary representation of %d is %d.\n\n", decimalNumber, decimalToBinary(decimalNumber));

  // Extending an invitation for further conversions
  printf("Feeling a surge of gratitude, we invite you to explore the wonders of converting binary numbers back to their decimal counterparts.\n");
  printf("Would you honor us by providing a binary number that we may illuminate its decimal brilliance?\n");
  int binaryNumber;
  scanf("%d", &binaryNumber);

  // Expressing our joy at the opportunity to assist
  printf("Ecstasy fills our hearts as we witness your enthusiasm for knowledge.\n");
  printf("Allow us to unveil the decimal counterpart of %d, which is %d.\n\n", binaryNumber, binaryToDecimal(binaryNumber));

  // A graceful farewell
  printf("Our gratitude knows no bounds for the opportunity to share this binary adventure with you.\n");
  printf("May you forever cherish the wisdom you have acquired. Farewell, dear user, and until our paths cross again.\n");

  return 0;
}