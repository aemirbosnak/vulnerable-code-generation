//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to convert a decimal number to binary
char* dec_to_bin(int num) {
  int bin_size = 32;  // Assuming the maximum size of the binary number is 32 bits
  char* bin_num = malloc(bin_size);

  // Initialize the binary number to 0
  memset(bin_num, '0', bin_size);

  // Convert the decimal number to binary
  int i = 0;
  while (num > 0) {
    bin_num[i] = (num % 2) + '0';
    num /= 2;
    i++;
  }

  // Null-terminate the binary number
  bin_num[i] = '\0';

  // Reverse the binary number
  int j = 0;
  int k = strlen(bin_num) - 1;
  while (j < k) {
    char temp = bin_num[j];
    bin_num[j] = bin_num[k];
    bin_num[k] = temp;
    j++;
    k--;
  }

  return bin_num;
}

// Function to convert a binary number to decimal
int bin_to_dec(char* bin_num) {
  int dec_num = 0;
  int len = strlen(bin_num);

  for (int i = 0; i < len; i++) {
    dec_num += (bin_num[i] - '0') * (1 << (len - i - 1));
  }

  return dec_num;
}

// Main function
int main() {
  // Get the decimal number from the user
  printf("Enter a decimal number: ");
  int num;
  scanf("%d", &num);

  // Convert the decimal number to binary
  char* bin_num = dec_to_bin(num);

  // Print the binary number
  printf("Binary equivalent: %s\n", bin_num);

  // Convert the binary number back to decimal
  int dec_num = bin_to_dec(bin_num);

  // Print the decimal number
  printf("Decimal equivalent: %d\n", dec_num);

  // Free the allocated memory
  free(bin_num);

  return 0;
}