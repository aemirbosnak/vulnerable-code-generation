//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char binary[1024], hex[1024];
  int i, j, len, dec;

  // Receive binary number from user.
  printf("Enter the binary number: ");
  scanf("%s", binary);

  // Calculate the length of the binary number.
  len = strlen(binary);

  // Convert binary to decimal.
  dec = 0;
  for (i = 0; i < len; i++) {
    if (binary[i] == '1') {
      dec += pow(2, len - i - 1);
    }
  }

  // Convert decimal to hexadecimal.
  i = 0;
  while (dec != 0) {
    hex[i++] = dec % 16;
    dec /= 16;
  }

  // Convert hexadecimal digits to characters.
  for (j = 0; j < i; j++) {
    if (hex[j] >= 0 && hex[j] <= 9) {
      hex[j] += '0';
    } else {
      hex[j] += 'A' - 10;
    }
  }

  // Reverse the hexadecimal string.
  for (j = 0, i--; j < i; j++, i--) {
    hex[j] ^= hex[i];
    hex[i] ^= hex[j];
    hex[j] ^= hex[i];
  }

  // Display the hexadecimal result.
  printf("The hexadecimal equivalent is: %s\n", hex);

  return 0;
}