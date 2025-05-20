//Code Llama-13B DATASET v1.0 Category: Color Code Converter ; Style: multiplayer
/*
* Color Code Converter
* -------------------
* This program allows users to enter a color code in a specific format
* and converts it to a different format.
*
* Author: [Your Name]
* Date: [Today's Date]
*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure to store color information
typedef struct {
  int red;
  int green;
  int blue;
} Color;

// Function to convert color code to hexadecimal
void convertToHex(Color color) {
  int red = color.red;
  int green = color.green;
  int blue = color.blue;
  printf("%02x%02x%02x", red, green, blue);
}

// Function to convert color code to RGB
void convertToRGB(Color color) {
  int red = color.red;
  int green = color.green;
  int blue = color.blue;
  printf("%d,%d,%d", red, green, blue);
}

// Main function
int main() {
  // Get user input for color code
  printf("Enter a color code in the format R,G,B: ");
  int red, green, blue;
  scanf("%d,%d,%d", &red, &green, &blue);

  // Create a new color structure
  Color color = {red, green, blue};

  // Convert color code to hexadecimal
  convertToHex(color);
  printf("\n");

  // Convert color code to RGB
  convertToRGB(color);

  return 0;
}