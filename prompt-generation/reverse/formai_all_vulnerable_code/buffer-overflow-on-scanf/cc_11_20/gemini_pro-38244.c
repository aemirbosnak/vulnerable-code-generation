//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Declare the input and output strings
  char input[100], output[100];

  // Get the input string from the user
  printf("Enter a hexadecimal number: ");
  scanf("%s", input);

  // Check if the input string is valid
  for (int i = 0; input[i] != '\0'; i++) {
    if ((input[i] >= '0' && input[i] <= '9') || (input[i] >= 'A' && input[i] <= 'F') || (input[i] >= 'a' && input[i] <= 'f')) {
      continue;
    } else {
      printf("Invalid hexadecimal number.\n");
      return 1;
    }
  }

  // Convert the hexadecimal string to an integer
  int number = 0;
  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] >= '0' && input[i] <= '9') {
      number = number * 16 + (input[i] - '0');
    } else if (input[i] >= 'A' && input[i] <= 'F') {
      number = number * 16 + (input[i] - 'A' + 10);
    } else if (input[i] >= 'a' && input[i] <= 'f') {
      number = number * 16 + (input[i] - 'a' + 10);
    }
  }

  // Convert the integer to a binary string
  int binary[100];
  int i = 0;
  while (number > 0) {
    binary[i] = number % 2;
    number = number / 2;
    i++;
  }

  // Reverse the binary string
  for (int j = 0; j < i / 2; j++) {
    int temp = binary[j];
    binary[j] = binary[i - j - 1];
    binary[i - j - 1] = temp;
  }

  // Convert the binary string to a string
  for (int j = 0; j < i; j++) {
    output[j] = binary[j] + '0';
  }
  output[i] = '\0';

  // Print the output string
  printf("The binary representation of %s is %s.\n", input, output);

  return 0;
}