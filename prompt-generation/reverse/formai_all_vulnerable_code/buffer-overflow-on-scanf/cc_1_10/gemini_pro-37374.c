//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: visionary
// Binary converter -- A journey into the realm of bits and bytes

#include <stdio.h>
#include <stdlib.h>

// Unveiling the mystery of binary representation
void BinaryExplorer(unsigned long long binaryNumber) {
  // Embarking on a bitwise odyssey
  unsigned long long bitMask = 1LLU << 63;

  // Unraveling the binary tapestry, one bit at a time
  printf("Binary Representation: ");
  while (bitMask) {
    // Peering into the binary abyss
    printf("%d", (binaryNumber & bitMask) ? 1 : 0);

    // Advancing through the intricate maze of bits
    bitMask >>= 1;
  }
  printf("\n");
}

// A lyrical guide through decimal-to-binary conversion
void DecimalToBinary(unsigned long long decimalNumber) {
  // Invoking the spirit of binary, zero by zero
  unsigned long long binaryNumber = 0;
  unsigned long long exponent = 1;

  // Traversing the decimal labyrinth
  while (decimalNumber != 0) {
    // Extracting the binary essence of the decimal digits
    if (decimalNumber % 2 != 0) {
      binaryNumber += exponent;
    }

    // Marching towards the binary horizon
    exponent <<= 1;

    // Uniting the decimal fragments
    decimalNumber /= 2;
  }

  // Unveiling the binary tapestry
  BinaryExplorer(binaryNumber);
}

// A binary symphony, flowing from digits to essence
void BinaryToDecimal(unsigned long long binaryNumber) {
  // A canvas of zeros and ones, teeming with potential
  unsigned long long decimalNumber = 0;
  unsigned long long exponent = 1;

  // Delving into the binary realm, bit by bit
  while (binaryNumber != 0) {
    // Unveiling the decimal essence of the binary fragments
    if (binaryNumber % 10 != 0) {
      decimalNumber += exponent;
    }

    // Ascending the decimal ladder
    exponent <<= 1;

    // Navigating the binary labyrinth
    binaryNumber /= 10;
  }

  // Unveiling the decimal symphony
  printf("Decimal Equivalent: %llu\n", decimalNumber);
}

// The heart of the program, where binary and decimal dance
int main() {
  // A shimmering portal to the binary realm
  unsigned long long binaryNumber;

  // An invitation to explore the decimal tapestry
  unsigned long long decimalNumber;

  // A choice that shapes the destiny of the program
  int choice;

  // A perpetual journey, unraveling the mysteries of binary and decimal
  while (1) {
    // Unveiling the options before the user
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Embarking on the chosen path
    switch (choice) {
      case 1:
        // Decimal to binary, a transformation of realms
        printf("Enter the decimal number: ");
        scanf("%llu", &decimalNumber);
        DecimalToBinary(decimalNumber);
        break;
      case 2:
        // Binary to decimal, a journey from bits to numbers
        printf("Enter the binary number: ");
        scanf("%llu", &binaryNumber);
        BinaryToDecimal(binaryNumber);
        break;
      case 3:
        // Farewell, for now
        printf("Exiting the binary wonderland!\n");
        exit(0);
        break;
      default:
        // Guidance for the bewildered traveler
        printf("Invalid choice. Please choose from 1, 2, or 3.\n");
    }
  }

  return 0;
}