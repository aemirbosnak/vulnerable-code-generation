//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: Alan Turing
#include <stdio.h>
#include <string.h>

int main() {
  char input[1024];
  char output[1024];
  int i = 0;

  printf("Enter a color code (e.g. RGB or HSV): ");
  scanf("%s", input);

  // Convert the input color code to uppercase
  for (i = 0; input[i] != '\0'; i++) {
    input[i] = toupper(input[i]);
  }

  // Check if the input color code is valid
  if (validate_color_code(input) == 0) {
    // Convert the input color code to RGB values
    int r = convert_color_code_to_rgb(input, output);

    // Print the RGB values
    printf("RGB values: %d, %d, %d\n", output[0], output[1], output[2]);
  } else {
    // Print an error message
    printf("Invalid color code.\n");
  }

  return 0;
}

int validate_color_code(char *code) {
  // Check if the code is the correct length
  if (strlen(code) < 3) {
    return 0;
  }

  // Check if the code contains invalid characters
  for (int i = 0; code[i] != '\0'; i++) {
    if (!isalnum(code[i])) {
      return 0;
    }
  }

  // Check if the code is in the correct format
  if (code[0] != 'R' || code[1] != 'G' || code[2] != 'B' || code[3] != ' ' || code[4] != 'H' || code[5] != 'S' || code[6] != '%') {
    return 0;
  }

  return 1;
}

int convert_color_code_to_rgb(char *code, char *output) {
  // Extract the RGB values from the code
  int r = atoi(&code[1]);
  int g = atoi(&code[3]);
  int b = atoi(&code[5]);

  // Convert the RGB values to uppercase
  output[0] = (r > 255) ? 255 : r;
  output[1] = (g > 255) ? 255 : g;
  output[2] = (b > 255) ? 255 : b;

  return 0;
}