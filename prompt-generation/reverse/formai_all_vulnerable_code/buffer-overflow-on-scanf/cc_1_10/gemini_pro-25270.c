//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a binary string to an integer
int binary_to_int(char *binary) {
  int i, len, power, num;
  len = strlen(binary);
  num = 0;
  power = 1;
  for (i = len - 1; i >= 0; i--) {
    if (binary[i] == '1') {
      num += power;
    }
    power *= 2;
  }
  return num;
}

// Function to convert an integer to a binary string
char *int_to_binary(int num) {
  int i, len, temp;
  char *binary;
  len = 0;
  temp = num;
  while (temp > 0) {
    len++;
    temp /= 2;
  }
  binary = malloc(len + 1);
  for (i = len - 1; i >= 0; i--) {
    binary[i] = (num % 2) + '0';
    num /= 2;
  }
  binary[len] = '\0';
  return binary;
}

// Main function
int main() {
  char *binary;
  int num;
  printf("Enter a binary string: ");
  scanf("%s", binary);
  num = binary_to_int(binary);
  printf("The integer equivalent of %s is %d\n", binary, num);
  printf("Enter an integer: ");
  scanf("%d", &num);
  binary = int_to_binary(num);
  printf("The binary equivalent of %d is %s\n", num, binary);
  return 0;
}