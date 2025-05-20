//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the color code structure
typedef struct {
  char *name;
  int red;
  int green;
  int blue;
} ColorCode;

// Define an array of color codes
ColorCode colorCodes[] = {
  { "black", 0, 0, 0 },
  { "white", 255, 255, 255 },
  { "red", 255, 0, 0 },
  { "green", 0, 255, 0 },
  { "blue", 0, 0, 255 },
  { "yellow", 255, 255, 0 },
  { "magenta", 255, 0, 255 },
  { "cyan", 0, 255, 255 },
  { "orange", 255, 165, 0 },
  { "purple", 128, 0, 128 },
  { "brown", 165, 42, 42 },
  { "gray", 128, 128, 128 },
  { "pink", 255, 192, 203 },
  { "turquoise", 64, 224, 208 },
  { "lime", 0, 255, 127 },
  { "maroon", 128, 0, 0 },
  { "navy", 0, 0, 128 },
  { "olive", 128, 128, 0 },
  { "salmon", 250, 128, 114 },
  { "silver", 192, 192, 192 },
  { "teal", 0, 128, 128 },
  { "violet", 143, 0, 255 }
};

// Define the number of color codes
const int numColorCodes = sizeof(colorCodes) / sizeof(ColorCode);

// Function to convert a color name to a color code
ColorCode *getColorCode(char *name) {
  for (int i = 0; i < numColorCodes; i++) {
    if (strcmp(name, colorCodes[i].name) == 0) {
      return &colorCodes[i];
    }
  }

  return NULL;
}

// Function to print the color code of a given color name
void printColorCode(char *name) {
  ColorCode *colorCode = getColorCode(name);

  if (colorCode == NULL) {
    printf("Invalid color name: %s\n", name);
  } else {
    printf("Color code for %s: %d, %d, %d\n", colorCode->name, colorCode->red, colorCode->green, colorCode->blue);
  }
}

int main() {
  // Get the color name from the user
  char colorName[20];
  printf("Enter a color name: ");
  scanf("%s", colorName);

  // Print the color code of the given color name
  printColorCode(colorName);

  return 0;
}