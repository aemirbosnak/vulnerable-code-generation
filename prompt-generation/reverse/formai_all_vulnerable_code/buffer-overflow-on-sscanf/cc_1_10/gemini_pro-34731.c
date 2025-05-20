//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the colors
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

// Print a string in a specific color
void print_color(const char *color, const char *string) {
  printf("%s%s%s", color, string, "\033[0m");
}

// Convert a hex color code to an RGB color code
void hex_to_rgb(const char *hex, char *rgb) {
  int r, g, b;
  sscanf(hex, "%02x%02x%02x", &r, &g, &b);
  sprintf(rgb, "%d,%d,%d", r, g, b);
}

// Convert an RGB color code to a hex color code
void rgb_to_hex(const char *rgb, char *hex) {
  int r, g, b;
  sscanf(rgb, "%d,%d,%d", &r, &g, &b);
  sprintf(hex, "#%02x%02x%02x", r, g, b);
}

// Print a color palette
void print_palette() {
  printf("Available colors:\n");
  printf("  - Black: %s\n", BLACK);
  printf("  - Red: %s\n", RED);
  printf("  - Green: %s\n", GREEN);
  printf("  - Yellow: %s\n", YELLOW);
  printf("  - Blue: %s\n", BLUE);
  printf("  - Magenta: %s\n", MAGENTA);
  printf("  - Cyan: %s\n", CYAN);
  printf("  - White: %s\n", WHITE);
}

// Main function
int main() {
  // Print a welcome message
  print_color(GREEN, "Welcome to the Color Code Converter!\n");

  // Get the user's input
  char input[100];
  printf("Enter a color code (hex or rgb): ");
  scanf("%s", input);

  // Convert the color code to the other format
  char output[100];
  if (input[0] == '#') {
    hex_to_rgb(input, output);
    print_color(CYAN, "RGB: ");
    printf("%s\n", output);
  } else {
    rgb_to_hex(input, output);
    print_color(YELLOW, "Hex: ");
    printf("%s\n", output);
  }

  // Print a palette of available colors
  print_palette();

  return 0;
}