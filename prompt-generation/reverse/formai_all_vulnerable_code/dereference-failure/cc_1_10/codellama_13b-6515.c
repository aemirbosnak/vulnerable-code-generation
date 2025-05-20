//Code Llama-13B DATASET v1.0 Category: Hexadecimal Converter ; Style: post-apocalyptic
// Hexadecimal Converter Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert hexadecimal to decimal
int hex_to_dec(char* hex) {
  int dec = 0, i;
  for (i = 0; hex[i] != '\0'; i++) {
    if (hex[i] >= '0' && hex[i] <= '9') {
      dec = dec * 16 + hex[i] - '0';
    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
      dec = dec * 16 + hex[i] - 'a' + 10;
    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
      dec = dec * 16 + hex[i] - 'A' + 10;
    } else {
      return -1;
    }
  }
  return dec;
}

// Function to convert decimal to hexadecimal
char* dec_to_hex(int dec) {
  char hex[100];
  int i = 0;
  while (dec != 0) {
    if (dec % 16 < 10) {
      hex[i++] = dec % 16 + '0';
    } else {
      hex[i++] = dec % 16 - 10 + 'a';
    }
    dec /= 16;
  }
  hex[i] = '\0';
  char* str = (char*)malloc(i * sizeof(char) + 1);
  strcpy(str, hex);
  return str;
}

// Main function
int main() {
  char hex[100];
  int dec;

  // Hexadecimal to decimal conversion
  printf("Enter hexadecimal number: ");
  scanf("%s", hex);
  dec = hex_to_dec(hex);
  if (dec == -1) {
    printf("Invalid hexadecimal number.");
  } else {
    printf("Decimal equivalent of %s is %d.", hex, dec);
  }

  // Decimal to hexadecimal conversion
  printf("\nEnter decimal number: ");
  scanf("%d", &dec);
  char* hex_str = dec_to_hex(dec);
  printf("Hexadecimal equivalent of %d is %s.", dec, hex_str);

  return 0;
}