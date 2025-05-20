//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the color codes
#define COLOR_BLACK   "\x1B[30m"
#define COLOR_RED     "\x1B[31m"
#define COLOR_GREEN   "\x1B[32m"
#define COLOR_YELLOW  "\x1B[33m"
#define COLOR_BLUE    "\x1B[34m"
#define COLOR_MAGENTA "\x1B[35m"
#define COLOR_CYAN    "\x1B[36m"
#define COLOR_WHITE   "\x1B[37m"

// Define the reset code
#define COLOR_RESET "\x1B[0m"

// Define the main function
int main(void) {
  // Get the input string
  char *input = NULL;
  size_t input_length = 0;
  ssize_t input_bytes = getline(&input, &input_length, stdin);
  if (input_bytes == -1) {
    fprintf(stderr, "Error: getline() failed.\n");
    return EXIT_FAILURE;
  }

  // Remove the newline character from the input string
  input[strcspn(input, "\n")] = '\0';

  // Convert the input string to all uppercase
  for (char *ptr = input; *ptr != '\0'; ptr++) {
    *ptr = toupper(*ptr);
  }

  // Check if the input string is a valid color code
  int is_valid_color_code = 0;
  for (char *ptr = input; *ptr != '\0'; ptr++) {
    if (*ptr >= 'A' && *ptr <= 'F') {
      is_valid_color_code = 1;
      break;
    }
  }

  // If the input string is a valid color code, convert it to the corresponding color code
  if (is_valid_color_code) {
    char *color_code = NULL;
    switch (input[0]) {
      case 'B':
        color_code = COLOR_BLACK;
        break;
      case 'R':
        color_code = COLOR_RED;
        break;
      case 'G':
        color_code = COLOR_GREEN;
        break;
      case 'Y':
        color_code = COLOR_YELLOW;
        break;
      case 'U':
        color_code = COLOR_BLUE;
        break;
      case 'M':
        color_code = COLOR_MAGENTA;
        break;
      case 'C':
        color_code = COLOR_CYAN;
        break;
      case 'W':
        color_code = COLOR_WHITE;
        break;
    }

    // Print the color code
    printf("%s%s%s\n", color_code, input, COLOR_RESET);
  } else {
    // Print an error message
    fprintf(stderr, "Error: invalid color code.\n");
    return EXIT_FAILURE;
  }

  // Free the input string
  free(input);

  // Return success
  return EXIT_SUCCESS;
}