//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define BINARY_LEN 16

// Function to convert decimal to binary
void dec2bin(int dec, char bin[]) {
  int i = 0;
  while (dec != 0) {
    bin[i] = dec % 2 + '0';
    dec /= 2;
    i++;
  }
  bin[i] = '\0';
}

// Function to convert binary to decimal
int bin2dec(char bin[]) {
  int dec = 0;
  for (int i = 0; bin[i] != '\0'; i++) {
    dec *= 2;
    dec += (bin[i] - '0');
  }
  return dec;
}

// Function to generate random numbers
int random_number(int min, int max) {
  srand(time(NULL));
  return min + (rand() % (max - min));
}

int main() {
  // Declare variables
  int dec, bin_len, i, j;
  char bin[BINARY_LEN];

  // Ask user for decimal number
  printf("Enter a decimal number: ");
  scanf("%d", &dec);

  // Generate random binary number
  int random_bin_len = random_number(1, BINARY_LEN);
  char random_bin[BINARY_LEN];
  for (i = 0; i < random_bin_len; i++) {
    random_bin[i] = '0' + (rand() % 2);
  }

  // Convert decimal to binary
  dec2bin(dec, bin);

  // Print binary number
  printf("Binary: ");
  for (i = 0; i < BINARY_LEN; i++) {
    printf("%c", bin[i]);
  }

  // Convert binary to decimal
  int dec_result = bin2dec(random_bin);

  // Print decimal number
  printf("\nDecimal: %d", dec_result);

  return 0;
}