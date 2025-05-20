//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the function to convert a decimal number to binary
void decimalToBinary(int n) {
  // Create an array to store the binary representation of the number
  int binaryNum[1000];

  // Initialize the index of the array to 0
  int i = 0;

  // While the number is greater than 0, continue the loop
  while (n > 0) {
    // Store the remainder of the number divided by 2 in the array
    binaryNum[i] = n % 2;

    // Divide the number by 2
    n /= 2;

    // Increment the index of the array
    i++;
  }

  // Print the binary representation of the number
  for (int j = i - 1; j >= 0; j--) {
    printf("%d", binaryNum[j]);
  }
}

// Declare the function to convert a binary number to decimal
int binaryToDecimal(char *binary) {
  // Initialize the decimal number to 0
  int decimalNum = 0;

  // Get the length of the binary string
  int length = strlen(binary);

  // For each character in the binary string, multiply the decimal number by 2 and add the value of the character to the decimal number
  for (int i = 0; i < length; i++) {
    decimalNum *= 2;
    decimalNum += binary[i] - '0';
  }

  // Return the decimal number
  return decimalNum;
}

// Declare the main function
int main() {
  // Get the input from the user
  int choice;
  printf("Enter 1 to convert decimal to binary or 2 to convert binary to decimal: ");
  scanf("%d", &choice);

  // Convert the decimal number to binary or the binary number to decimal based on the user's choice
  if (choice == 1) {
    int decimalNum;
    printf("Enter the decimal number: ");
    scanf("%d", &decimalNum);
    decimalToBinary(decimalNum);
  } else if (choice == 2) {
    char binaryNum[1000];
    printf("Enter the binary number: ");
    scanf("%s", binaryNum);
    printf("The decimal number is: %d", binaryToDecimal(binaryNum));
  } else {
    printf("Invalid choice");
  }

  return 0;
}