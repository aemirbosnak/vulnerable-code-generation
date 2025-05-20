//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Color codes
#define BLACK "\x1B[30m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"

// Reset color
#define RESET "\x1B[0m"

// Function to convert a string to a color code
char *color_code(char *str) {
  if (strcmp(str, "black") == 0) {
    return BLACK;
  } else if (strcmp(str, "red") == 0) {
    return RED;
  } else if (strcmp(str, "green") == 0) {
    return GREEN;
  } else if (strcmp(str, "yellow") == 0) {
    return YELLOW;
  } else if (strcmp(str, "blue") == 0) {
    return BLUE;
  } else if (strcmp(str, "magenta") == 0) {
    return MAGENTA;
  } else if (strcmp(str, "cyan") == 0) {
    return CYAN;
  } else if (strcmp(str, "white") == 0) {
    return WHITE;
  } else {
    return RESET;
  }
}

// Function to print a string in a color
void print_color(char *str, char *color) {
  printf("%s%s%s", color, str, RESET);
}

int main() {
  // Get the input string
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);

  // Convert the string to a color code
  char *color = color_code(str);

  // Print the string in the color
  print_color(str, color);

  return 0;
}