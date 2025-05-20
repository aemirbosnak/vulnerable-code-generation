//Code Llama-13B DATASET v1.0 Category: Color Code Converter ; Style: visionary
// C Color Code Converter Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_LENGTH 20

struct color_t {
  char name[MAX_COLOR_LENGTH];
  int r;
  int g;
  int b;
};

struct color_t color_code_to_name(int r, int g, int b) {
  struct color_t color;
  memset(&color, 0, sizeof(struct color_t));

  // Set the RGB values
  color.r = r;
  color.g = g;
  color.b = b;

  // Convert the RGB values to a hexadecimal string
  char hex_code[MAX_COLOR_LENGTH];
  sprintf(hex_code, "%02x%02x%02x", color.r, color.g, color.b);

  // Check if the hexadecimal code is a valid color
  if (strlen(hex_code) != 6) {
    return color;
  }

  // Convert the hexadecimal code to a color name
  char color_name[MAX_COLOR_LENGTH];
  if (strcmp(hex_code, "ff0000") == 0) {
    strcpy(color_name, "Red");
  } else if (strcmp(hex_code, "00ff00") == 0) {
    strcpy(color_name, "Green");
  } else if (strcmp(hex_code, "0000ff") == 0) {
    strcpy(color_name, "Blue");
  } else if (strcmp(hex_code, "ffff00") == 0) {
    strcpy(color_name, "Yellow");
  } else if (strcmp(hex_code, "00ffff") == 0) {
    strcpy(color_name, "Cyan");
  } else if (strcmp(hex_code, "ff00ff") == 0) {
    strcpy(color_name, "Magenta");
  } else if (strcmp(hex_code, "000000") == 0) {
    strcpy(color_name, "Black");
  } else if (strcmp(hex_code, "ffffff") == 0) {
    strcpy(color_name, "White");
  } else {
    strcpy(color_name, "Unknown");
  }

  // Set the color name
  strcpy(color.name, color_name);

  return color;
}

int main() {
  struct color_t color;
  memset(&color, 0, sizeof(struct color_t));

  // Get the color code from the user
  int r, g, b;
  printf("Enter the RGB values separated by spaces: ");
  scanf("%d %d %d", &r, &g, &b);

  // Convert the color code to a color name
  color = color_code_to_name(r, g, b);

  // Print the color name
  printf("The color is: %s\n", color.name);

  return 0;
}