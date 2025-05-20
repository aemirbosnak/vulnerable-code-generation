//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { FALSE, TRUE } bool_t;

bool_t validate_binary(char **binary) {
  for (size_t i = 0; binary[i] != NULL; i++) {
    if (binary[i] < '0' || binary[i] > '1') {
      return FALSE;
    }
  }
  return TRUE;
}

int main() {
  char **binary = NULL;
  size_t count = 0;

  printf("Enter a binary number (separate bits with spaces): ");

  // Dynamic memory allocation for the binary number
  binary = malloc(sizeof(char *) * 10);
  for (size_t i = 0; binary[i] = NULL; i++) {}

  // Get the binary number from the user
  char input[100];
  scanf("%s", input);

  // Split the binary number into individual bits and store them in the binary array
  char *token = strtok(input, " ");
  while (token) {
    binary[count++] = token;
    token = strtok(NULL, " ");
  }

  // Validate the binary number
  if (!validate_binary(binary)) {
    printf("Invalid binary number.\n");
    return 1;
  }

  // Convert the binary number to an integer
  int decimal = 0;
  for (size_t i = count - 1; i >= 0; i--) {
    int digit = binary[i] - '0';
    decimal += digit * pow(2, count - 1 - i);
  }

  // Print the converted decimal number
  printf("Decimal equivalent: %d\n", decimal);

  // Free the dynamically allocated memory
  free(binary);

  return 0;
}