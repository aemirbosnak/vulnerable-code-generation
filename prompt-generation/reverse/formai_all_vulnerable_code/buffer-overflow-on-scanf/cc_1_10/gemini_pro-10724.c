//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the color codes
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[37m"
#define RESET   "\x1b[0m"

// Define the color code array
char *color_codes[] = {RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, RESET};

// Get the color code from the user
char *get_color_code(char *color) {
  for (int i = 0; i < 7; i++) {
    if (strcmp(color, color_codes[i]) == 0) {
      return color_codes[i];
    }
  }

  return NULL;
}

// Print the color code to the console
void print_color_code(char *color_code) {
  printf("%s", color_code);
}

// Main function
int main() {
  // Get the color from the user
  char color[20];
  printf("Enter a color: ");
  scanf("%s", color);

  // Get the color code
  char *color_code = get_color_code(color);

  // If the color code is valid, print it to the console
  if (color_code != NULL) {
    print_color_code(color_code);
    printf("This is the color code for %s.\n", color);
  } else {
    printf("Invalid color.\n");
  }

  return 0;
}