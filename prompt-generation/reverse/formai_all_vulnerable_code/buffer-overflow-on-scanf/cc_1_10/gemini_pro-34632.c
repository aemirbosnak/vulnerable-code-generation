//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: futuristic
// Galactic Binary Converter: A Stellar Odyssey

#include <stdio.h>
#include <stdlib.h>

// Binary to Decimal Converter
int binaryToDecimal(char *binaryString) {
  int decimal = 0, base = 1;
  
  // Traverse the binary string from right to left
  int i = strlen(binaryString) - 1;
  while (i >= 0) {
    // Check if the current character is '0' or '1'
    if (binaryString[i] == '0') {}
    else if (binaryString[i] == '1') {
      decimal += base;
    } else {
      printf("Invalid binary string: %s\n", binaryString);
      exit(1);
    }
    
    // Shift the base to the left
    base *= 2;
    
    // Move to the next character
    i--;
  }
  
  return decimal;
}

// Decimal to Binary Converter
void decimalToBinary(int decimal) {
  int binary[32];
  int index = 0;
  
  // Convert the decimal to binary
  while (decimal > 0) {
    binary[index++] = decimal % 2;
    decimal /= 2;
  }
  
  // Print the binary representation
  for (int i = index - 1; i >= 0; i--) {
    printf("%d", binary[i]);
  }
  printf("\n");
}

// Main Function: The Nexus of Interstellar Conversion
int main(int argc, char *argv[]) {
  // Welcome Message: A Cosmic Greeting
  printf("Welcome to the Galactic Binary Converter!\n");
  printf("Prepare for an interstellar journey of numerical transcendence.\n");
  
  // Input Loop: A Galactic Portal
  while (1) {
    // Display Options: The Galactic Navigator
    printf("\nChoose your Galactic Destination:\n");
    printf("1. Binary to Decimal (Starlit Path)\n");
    printf("2. Decimal to Binary (Aetheric Gateway)\n");
    printf("3. Exit (Cosmic Farewell)\n");
    printf("Enter your choice (1/2/3): ");
    
    int choice;
    scanf("%d", &choice);
    
    // Process User Choice: The Interdimensional Nexus
    switch (choice) {
      case 1:
        // Binary to Decimal: Unraveling the Cosmic Code
        printf("Enter a binary string (0s and 1s): ");
        char binaryString[32];
        scanf("%s", binaryString);
        printf("Decimal equivalent: %d\n", binaryToDecimal(binaryString));
        break;
      
      case 2:
        // Decimal to Binary: Weaving the Stellar Tapestry
        printf("Enter a decimal integer: ");
        int decimal;
        scanf("%d", &decimal);
        printf("Binary representation: ");
        decimalToBinary(decimal);
        break;
      
      case 3:
        // Exit: A Cosmic Farewell
        printf("Cosmic Farewell. May the Binary Star guide your journey.\n");
        return 0;
      
      default:
        // Invalid Choice: A Galactic Anomaly
        printf("Invalid choice. Please choose from the available options (1/2/3).\n");
        break;
    }
  }
  
  // End of the Infinite Loop: The Cosmic Void
  return 0;
}