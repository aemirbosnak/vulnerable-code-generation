//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: Alan Turing
#include <stdio.h>

void main() {
  char input_symbol, output_symbol;
  int state = 0;

  // Loop until the input symbol is not a blank
  while (input_symbol != ' ') {
    // Read the input symbol
    scanf("%c", &input_symbol);

    // Determine the output symbol based on the state and input symbol
    switch (state) {
      case 0:
        if (input_symbol == 'a') {
          output_symbol = 'b';
          state = 1;
        } else if (input_symbol == 'b') {
          output_symbol = 'c';
          state = 2;
        } else {
          output_symbol = ' ';
        }
        break;
      case 1:
        if (input_symbol == 'a') {
          output_symbol = 'c';
          state = 2;
        } else if (input_symbol == 'b') {
          output_symbol = ' ';
          state = 0;
        } else {
          output_symbol = ' ';
        }
        break;
      case 2:
        if (input_symbol == 'a') {
          output_symbol = ' ';
          state = 0;
        } else if (input_symbol == 'b') {
          output_symbol = ' ';
          state = 0;
        } else {
          output_symbol = ' ';
        }
        break;
    }

    // Print the output symbol
    printf("%c", output_symbol);
  }

  // Print a newline
  printf("\n");
}