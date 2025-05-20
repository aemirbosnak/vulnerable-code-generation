//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the color codes
#define BLACK "\x1B[30m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"
#define RESET "\x1B[0m"

// Define the color code conversion function
char *color_code_converter(char *color) {
  if (strcmp(color, "black") == 0) {
    return BLACK;
  } else if (strcmp(color, "red") == 0) {
    return RED;
  } else if (strcmp(color, "green") == 0) {
    return GREEN;
  } else if (strcmp(color, "yellow") == 0) {
    return YELLOW;
  } else if (strcmp(color, "blue") == 0) {
    return BLUE;
  } else if (strcmp(color, "magenta") == 0) {
    return MAGENTA;
  } else if (strcmp(color, "cyan") == 0) {
    return CYAN;
  } else if (strcmp(color, "white") == 0) {
    return WHITE;
  } else {
    return RESET;
  }
}

// Define the main function
int main() {
  // Get the color from the user
  char color[20];
  printf("Enter a color: ");
  scanf("%s", color);

  // Convert the color code
  char *color_code = color_code_converter(color);

  // Print the color code
  printf("The color code for %s is %s\n", color, color_code);

  return 0;
}