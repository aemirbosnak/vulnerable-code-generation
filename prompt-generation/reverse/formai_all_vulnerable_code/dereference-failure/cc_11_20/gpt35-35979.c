//FormAI DATASET v1.0 Category: Color Code Converter ; Style: invasive
#include <stdio.h>

int main() {
  printf("Welcome to the C Color Code Converter\n");

  // Prompt user for input color code
  printf("Please enter a color code in the format of RRGGBB (e.g. FF0000 for red): ");
  char input[7];
  scanf("%s", input);

  // Convert input color code to integers
  int red = strtol(strncpy(malloc(3), input, 2), NULL, 16);
  int green = strtol(strncpy(malloc(3), &input[2], 2), NULL, 16);
  int blue = strtol(strncpy(malloc(3), &input[4], 2), NULL, 16);

  // Check if input color code is valid
  if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
    printf("Invalid color code. Please enter a valid code.\n");
    return 1;
  }

  // Convert RGB values to the nearest named color
  const char* colors[] = {
    "black", "white", "red", "green", "blue", "yellow", "cyan", "magenta", "gray"
  };
  const int redValues[] = { 0, 255, 255, 0, 0, 255, 0, 255, 128 };
  const int greenValues[] = { 0, 255, 0, 255, 0, 255, 255, 0, 128 };
  const int blueValues[] = { 0, 255, 0, 0, 255, 0, 255, 255, 128 };

  const char* nearestColor = colors[0];
  int minDistance = 1000000;
  for (int i = 0; i < sizeof(colors) / sizeof(colors[0]); ++i) {
    int distance = (red - redValues[i]) * (red - redValues[i]) +
      (green - greenValues[i]) * (green - greenValues[i]) +
      (blue - blueValues[i]) * (blue - blueValues[i]);
    if (distance < minDistance) {
      minDistance = distance;
      nearestColor = colors[i];
    }
  }

  // Prompt user for output color format
  printf("Would you like the output in RGB values or hexadecimal format (R,G,B or RRGGBB)? ");
  char format[3];
  scanf("%s", format);

  // Convert RGB values to the requested format
  if (strcmp(format, "RGB") == 0) {
    printf("In RGB format, the nearest named color to %s is %s(%d,%d,%d)\n", input,
           nearestColor, red, green, blue);
  } else if (strcmp(format, "HEX") == 0) {
    printf("In hexadecimal format, the nearest named color to %s is %s(%02X%02X%02X)\n", input,
           nearestColor, red, green, blue);
  } else {
    printf("Invalid output format. Please enter RGB or HEX.\n");
    return 1;
  }

  return 0;
}