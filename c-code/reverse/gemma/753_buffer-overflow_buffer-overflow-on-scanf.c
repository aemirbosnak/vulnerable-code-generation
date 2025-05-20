#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[100];
  int input_length;
  long decimal_number;
  long hexadecimal_number;

  printf("Enter a hexadecimal number: ");
  scanf("%s", input);

  input_length = strlen(input);

  if (input_length > 0) {
    if (input_length % 2 == 0) {
      hexadecimal_number = strtol(input, NULL, 16);
      decimal_number = hexadecimal_number * 16 + strtol(input + input_length - 1, NULL, 10);
    } else {
      printf("Invalid input. Please enter a valid hexadecimal number.");
    }
  } else {
    printf("Invalid input. Please enter a valid hexadecimal number.");
  }

  if (decimal_number != hexadecimal_number) {
    printf("Error: Conversion failed.");
  } else {
    printf("Decimal equivalent: %ld", decimal_number);
  }

  return 0;
}
