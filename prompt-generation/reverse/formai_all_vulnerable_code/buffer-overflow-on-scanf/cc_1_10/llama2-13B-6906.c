//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT_SIZE 1024
#define MAX_BASES 16

// Function to convert a binary string to decimal
int binary_to_decimal(char *bin) {
  int i, j, sum = 0;
  for (i = 0; i < strlen(bin); i++) {
    sum += (bin[i] - '0') * pow(2, j);
    j++;
  }
  return sum;
}

// Function to convert a decimal number to binary
char *decimal_to_binary(int num) {
  int i, j, binary[MAX_INPUT_SIZE];
  char *result = malloc(MAX_INPUT_SIZE);
  for (i = 0; i < MAX_INPUT_SIZE; i++) {
    binary[i] = num % 2 == 0 ? '0' : '1';
    num /= 2;
  }
  for (j = MAX_INPUT_SIZE - 1; j >= 0; j--) {
    result[j] = binary[j];
  }
  return result;
}

int main() {
  int num, base;
  char bin[MAX_INPUT_SIZE], dec[MAX_INPUT_SIZE];

  // Convert decimal to binary
  printf("Enter a decimal number: ");
  scanf("%d", &num);
  dec[0] = decimal_to_binary(num);

  // Convert binary to decimal
  printf("Enter a binary string: ");
  fgets(bin, MAX_INPUT_SIZE, stdin);
  bin[strcspn(bin, "\n")] = '\0'; // Remove newline character
  num = binary_to_decimal(bin);

  // Print the results
  printf("Decimal: %d\n", num);
  printf("Binary: %s\n", dec);

  return 0;
}