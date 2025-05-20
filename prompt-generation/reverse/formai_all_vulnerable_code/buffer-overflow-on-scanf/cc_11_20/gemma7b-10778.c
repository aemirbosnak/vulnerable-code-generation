//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main() {
  char input_buffer[MAX_BUFFER_SIZE];
  char output_buffer[MAX_BUFFER_SIZE];
  int input_length = 0;
  int output_length = 0;

  // Get the input from the user
  printf("Enter a hexadecimal number: ");
  scanf("%s", input_buffer);

  // Calculate the length of the input
  input_length = strlen(input_buffer);

  // Convert the input to uppercase
  for (int i = 0; i < input_length; i++) {
    input_buffer[i] = toupper(input_buffer[i]);
  }

  // Convert the input to hexadecimal
  for (int i = 0; i < input_length; i++) {
    switch (input_buffer[i]) {
      case '0':
        output_buffer[output_length++] = '0';
        break;
      case '1':
        output_buffer[output_length++] = '1';
        break;
      case '2':
        output_buffer[output_length++] = '2';
        break;
      case '3':
        output_buffer[output_length++] = '3';
        break;
      case '4':
        output_buffer[output_length++] = '4';
        break;
      case '5':
        output_buffer[output_length++] = '5';
        break;
      case '6':
        output_buffer[output_length++] = '6';
        break;
      case '7':
        output_buffer[output_length++] = '7';
        break;
      case '8':
        output_buffer[output_length++] = '8';
        break;
      case '9':
        output_buffer[output_length++] = '9';
        break;
      default:
        printf("Error: Invalid input.\n");
        exit(1);
    }
  }

  // Print the output
  printf("Hexadecimal equivalent: ");
  for (int i = 0; i < output_length; i++) {
    printf("%c ", output_buffer[i]);
  }

  printf("\n");

  return 0;
}