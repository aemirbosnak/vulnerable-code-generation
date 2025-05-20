//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the color code structure
typedef struct color_code {
  char *name;
  int red;
  int green;
  int blue;
} color_code;

// Create an array of color codes
color_code colors[] = {
  { "Black", 0, 0, 0 },
  { "White", 255, 255, 255 },
  { "Red", 255, 0, 0 },
  { "Green", 0, 255, 0 },
  { "Blue", 0, 0, 255 },
  { "Yellow", 255, 255, 0 },
  { "Cyan", 0, 255, 255 },
  { "Magenta", 255, 0, 255 },
  { "Gray", 128, 128, 128 },
  { "Maroon", 128, 0, 0 },
  { "Olive", 128, 128, 0 },
  { "Purple", 128, 0, 128 },
  { "Teal", 0, 128, 128 },
  { "Navy", 0, 0, 128 },
  { "Aqua", 0, 255, 255 },
  { "Fuchsia", 255, 0, 255 },
  { "Lime", 0, 255, 0 },
  { "Silver", 192, 192, 192 },
  { "Gold", 255, 215, 0 },
  { "Orange", 255, 165, 0 },
  { "Brown", 165, 42, 42 },
  { "Pink", 255, 192, 203 },
  { "Violet", 238, 130, 238 }
};

// Get the number of colors
int num_colors = sizeof(colors) / sizeof(color_code);

// Convert a color code to a string
char *color_code_to_string(color_code color) {
  char *buffer = malloc(100);
  sprintf(buffer, "%s (%d, %d, %d)", color.name, color.red, color.green, color.blue);
  return buffer;
}

// Convert a string to a color code
color_code string_to_color_code(char *string) {
  for (int i = 0; i < num_colors; i++) {
    if (strcmp(string, colors[i].name) == 0) {
      return colors[i];
    }
  }

  // If the color code is not found, return black
  return colors[0];
}

// Print the color codes
void print_color_codes() {
  for (int i = 0; i < num_colors; i++) {
    printf("%s\n", color_code_to_string(colors[i]));
  }
}

int main() {
  // Get the user input
  char *input = malloc(100);
  printf("Enter a color code (e.g. \"Red\"): ");
  scanf("%s", input);

  // Convert the input to a color code
  color_code color = string_to_color_code(input);

  // Print the color code
  printf("The color code is: %s\n", color_code_to_string(color));

  // Free the allocated memory
  free(input);

  return 0;
}