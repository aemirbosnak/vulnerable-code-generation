//Code Llama-13B DATASET v1.0 Category: Hexadecimal Converter ; Style: dynamic
// Hexadecimal Converter

#include <stdio.h>
#include <string.h>

// Function to convert decimal to hexadecimal
char* dec_to_hex(int dec) {
  char hex[10];
  int i = 0;

  while (dec > 0) {
    hex[i++] = (dec % 16) + 48;
    dec /= 16;
  }

  hex[i] = '\0';

  return hex;
}

// Function to convert hexadecimal to decimal
int hex_to_dec(char* hex) {
  int dec = 0;
  int i = 0;

  while (hex[i] != '\0') {
    dec = (dec * 16) + (hex[i] - 48);
    i++;
  }

  return dec;
}

int main() {
  int dec;
  char hex[10];

  printf("Enter a decimal number: ");
  scanf("%d", &dec);

  // Convert decimal to hexadecimal
  char* hex_str = dec_to_hex(dec);

  // Print the hexadecimal number
  printf("Hexadecimal number: %s\n", hex_str);

  // Convert hexadecimal to decimal
  int dec_num = hex_to_dec(hex_str);

  // Print the decimal number
  printf("Decimal number: %d\n", dec_num);

  return 0;
}