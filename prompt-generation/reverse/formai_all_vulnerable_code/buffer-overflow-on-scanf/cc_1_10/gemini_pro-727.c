//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to its binary representation
void decimalToBinary(int n)
{
  // Array to store the binary digits
  int binary[100];
  
  // Initialize the array with zeros
  for (int i = 0; i < 100; i++)
    binary[i] = 0;

  // Index of the array
  int index = 0;

  // Convert the decimal number to binary by dividing it by 2 and storing the remainder in the array
  while (n > 0) {
    binary[index++] = n % 2;
    n /= 2;
  }

  // Print the binary representation
  printf("Binary representation: ");
  for (int i = index - 1; i >= 0; i--)
    printf("%d", binary[i]);
  printf("\n");
}

// Function to convert a binary number to its decimal representation
int binaryToDecimal(char *binary)
{
  // Length of the binary string
  int len = strlen(binary);

  // Decimal value of the binary number
  int decimal = 0;

  // Convert the binary digits to decimal by multiplying each digit by the corresponding power of 2 and adding the results
  for (int i = 0; i < len; i++) {
    decimal += (binary[i] - '0') * (1 << (len - i - 1));
  }

  return decimal;
}

int main()
{
  // User input
  int choice;
  int number;
  char binary[100];

  // Display the menu
  printf("Binary Converter\n");
  printf("1. Decimal to Binary\n");
  printf("2. Binary to Decimal\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  // Perform the selected operation
  switch (choice) {
    case 1:
      printf("Enter a decimal number: ");
      scanf("%d", &number);
      decimalToBinary(number);
      break;
    case 2:
      printf("Enter a binary number: ");
      scanf("%s", binary);
      printf("Decimal representation: %d\n", binaryToDecimal(binary));
      break;
    default:
      printf("Invalid choice\n");
  }

  return 0;
}