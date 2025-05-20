//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Color code converter
// Takes a string as input and converts it to a color code
// Returns a string containing the color code
char *color_code_converter(char *input) {
  // Check if the input is valid
  if (strlen(input) != 6) {
    return "Invalid input";
  }

  // Convert the input to uppercase
  for (int i = 0; i < strlen(input); i++) {
    input[i] = toupper(input[i]);
  }

  // Check if the input is a valid color code
  if (strcmp(input, "FFFFFF") != 0 && strcmp(input, "000000") != 0 &&
      strcmp(input, "FF0000") != 0 && strcmp(input, "00FF00") != 0 &&
      strcmp(input, "0000FF") != 0 && strcmp(input, "FFFF00") != 0 &&
      strcmp(input, "00FFFF") != 0 && strcmp(input, "FF00FF") != 0) {
    return "Invalid color code";
  }

  // Convert the input to a color code
  char *color_code = malloc(7 * sizeof(char));
  strcpy(color_code, "#");
  strcat(color_code, input);

  // Return the color code
  return color_code;
}

// Print the color code
void print_color_code(char *color_code) {
  // Print the color code
  printf("The color code is: %s\n", color_code);
}

// Main function
int main() {
  // Get the input from the user
  char *input = malloc(7 * sizeof(char));
  printf("Enter a color code: ");
  scanf("%s", input);

  // Convert the input to a color code
  char *color_code = color_code_converter(input);

  // Print the color code
  print_color_code(color_code);

  // Free the memory allocated for the color code
  free(color_code);

  // Return 0
  return 0;
}