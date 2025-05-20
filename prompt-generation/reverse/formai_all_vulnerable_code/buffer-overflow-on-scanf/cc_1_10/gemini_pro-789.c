//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: futuristic
#include <stdio.h>

// Define the hexadecimal digits
char hexDigits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

// Convert a decimal number to hexadecimal
void decToHex(int dec, char *hex) {
  // Initialize the hexadecimal string
  hex[0] = '\0';

  // Convert the decimal number to hexadecimal
  while (dec > 0) {
    // Get the hexadecimal digit
    int digit = dec % 16;
    dec /= 16;

    // Append the hexadecimal digit to the string
    hex[0] = hexDigits[digit];
    hex++;
  }

  // Reverse the hexadecimal string
  int len = strlen(hex);
  for (int i = 0; i < len / 2; i++) {
    char temp = hex[i];
    hex[i] = hex[len - i - 1];
    hex[len - i - 1] = temp;
  }
}

// Convert a hexadecimal number to decimal
int hexToDec(char *hex) {
  // Initialize the decimal number
  int dec = 0;

  // Convert the hexadecimal number to decimal
  while (*hex != '\0') {
    // Get the hexadecimal digit
    int digit = 0;
    if (*hex >= '0' && *hex <= '9') {
      digit = *hex - '0';
    } else if (*hex >= 'A' && *hex <= 'F') {
      digit = *hex - 'A' + 10;
    } else if (*hex >= 'a' && *hex <= 'f') {
      digit = *hex - 'a' + 10;
    }

    // Multiply the decimal number by 16
    dec *= 16;

    // Add the hexadecimal digit to the decimal number
    dec += digit;

    // Increment the hexadecimal number
    hex++;
  }

  // Return the decimal number
  return dec;
}

// Main function
int main() {
  // Declare the variables
  int dec;
  char hex[100];

  // Get the decimal number from the user
  printf("Enter a decimal number: ");
  scanf("%d", &dec);

  // Convert the decimal number to hexadecimal
  decToHex(dec, hex);

  // Print the hexadecimal number
  printf("The hexadecimal number is: %s\n", hex);

  // Get the hexadecimal number from the user
  printf("Enter a hexadecimal number: ");
  scanf("%s", hex);

  // Convert the hexadecimal number to decimal
  dec = hexToDec(hex);

  // Print the decimal number
  printf("The decimal number is: %d\n", dec);

  return 0;
}