//Code Llama-13B DATASET v1.0 Category: Color Code Converter ; Style: romantic
// Color Code Converter
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the color code struct
typedef struct {
  char *name;
  int r;
  int g;
  int b;
} color_code_t;

// Define the color code array
color_code_t color_codes[] = {
  {"Red", 255, 0, 0},
  {"Green", 0, 255, 0},
  {"Blue", 0, 0, 255},
  {"Yellow", 255, 255, 0},
  {"Cyan", 0, 255, 255},
  {"Magenta", 255, 0, 255},
  {"White", 255, 255, 255},
  {"Black", 0, 0, 0},
  {NULL, 0, 0, 0}
};

// Define the color code conversion function
void convert_color_code(int r, int g, int b, char *name) {
  for (int i = 0; color_codes[i].name != NULL; i++) {
    if (color_codes[i].r == r && color_codes[i].g == g && color_codes[i].b == b) {
      strcpy(name, color_codes[i].name);
      return;
    }
  }
  strcpy(name, "Unknown");
}

// Define the main function
int main(int argc, char **argv) {
  char name[10];
  int r, g, b;

  // Get the input values
  printf("Enter the RGB values: ");
  scanf("%d %d %d", &r, &g, &b);

  // Convert the color code
  convert_color_code(r, g, b, name);

  // Print the output
  printf("The color code is: %s\n", name);

  return 0;
}