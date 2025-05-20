//Code Llama-13B DATASET v1.0 Category: Color Code Converter ; Style: Romeo and Juliet
// Romeo and Juliet Color Code Converter
// By: Your Name

#include <stdio.h>
#include <stdlib.h>

// Function to convert a color code to a color name
char* convertColorCode(int colorCode) {
  char* colorName;
  switch (colorCode) {
    case 1:
      colorName = "RED";
      break;
    case 2:
      colorName = "GREEN";
      break;
    case 3:
      colorName = "BLUE";
      break;
    case 4:
      colorName = "YELLOW";
      break;
    case 5:
      colorName = "PURPLE";
      break;
    case 6:
      colorName = "ORANGE";
      break;
    case 7:
      colorName = "PINK";
      break;
    case 8:
      colorName = "GRAY";
      break;
    case 9:
      colorName = "BROWN";
      break;
    case 10:
      colorName = "CYAN";
      break;
    default:
      colorName = "INVALID";
      break;
  }
  return colorName;
}

// Function to convert a color name to a color code
int convertColorName(char* colorName) {
  int colorCode;
  if (strcmp(colorName, "RED") == 0) {
    colorCode = 1;
  } else if (strcmp(colorName, "GREEN") == 0) {
    colorCode = 2;
  } else if (strcmp(colorName, "BLUE") == 0) {
    colorCode = 3;
  } else if (strcmp(colorName, "YELLOW") == 0) {
    colorCode = 4;
  } else if (strcmp(colorName, "PURPLE") == 0) {
    colorCode = 5;
  } else if (strcmp(colorName, "ORANGE") == 0) {
    colorCode = 6;
  } else if (strcmp(colorName, "PINK") == 0) {
    colorCode = 7;
  } else if (strcmp(colorName, "GRAY") == 0) {
    colorCode = 8;
  } else if (strcmp(colorName, "BROWN") == 0) {
    colorCode = 9;
  } else if (strcmp(colorName, "CYAN") == 0) {
    colorCode = 10;
  } else {
    colorCode = -1;
  }
  return colorCode;
}

// Main function
int main() {
  // Declare variables
  int colorCode;
  char colorName[20];

  // Take input from user
  printf("Enter a color code: ");
  scanf("%d", &colorCode);

  // Convert color code to color name
  convertColorCode(colorCode);

  // Take input from user
  printf("Enter a color name: ");
  scanf("%s", colorName);

  // Convert color name to color code
  convertColorName(colorName);

  // Print output
  printf("Color Code: %d\nColor Name: %s\n", colorCode, colorName);

  return 0;
}