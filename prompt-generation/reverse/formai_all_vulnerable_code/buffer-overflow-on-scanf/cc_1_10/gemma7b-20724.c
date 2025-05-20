//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

int main() {
  char buffer[MAX_BUFFER_SIZE];
  int i = 0;
  char input[MAX_BUFFER_SIZE];
  char output[MAX_BUFFER_SIZE];
  int input_length = 0;
  int output_length = 0;

  // Get the input from the user
  printf("Enter the binary number: ");
  scanf("%s", input);

  // Calculate the length of the input
  input_length = strlen(input);

  // Convert the input to uppercase
  for (i = 0; i < input_length; i++) {
    input[i] = toupper(input[i]);
  }

  // Convert the input to binary
  for (i = 0; i < input_length; i++) {
    switch (input[i]) {
      case '0':
        output[output_length++] = '0';
        break;
      case '1':
        output[output_length++] = '1';
        break;
      default:
        printf("Error: invalid input.\n");
        return 1;
    }
  }

  // Print the output
  printf("The binary number in decimal is: ");
  for (i = 0; i < output_length; i++) {
    printf("%c", output[i]);
  }

  printf("\n");

  return 0;
}