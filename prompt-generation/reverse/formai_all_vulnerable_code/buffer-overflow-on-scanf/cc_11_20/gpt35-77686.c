//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Cryptic
#include <stdio.h>

int main(void) {

  // Welcome to the C Color Code Converter program!
  printf("P54d3 10 $k1l1z3 7h15 pr06r4m!\n\n");

  // Ask user for input color code
  printf("P234s3 3n73r 7h3 3n7ir3 C010r c0d3: ");
  char input[10];
  scanf("%s", input);

  // Determine the color type of the input code
  int isHexCode = 0;
  int isRgbCode = 0;
  if (input[0] == '#') {
    isHexCode = 1;
  } else if (input[0] == 'r') {
    isRgbCode = 1;
  }

  // Convert hex color code to RGB color code
  int red = 0;
  int green = 0;
  int blue = 0;
  if (isHexCode) {
    int hexCode[6];
    for (int i = 1; i < 7; i++) {
      char c = input[i];
      if (c >= '0' && c <= '9') {
        hexCode[i-1] = c - '0';
      } else if (c >= 'A' && c <= 'F') {
        hexCode[i-1] = c - 'A' + 10;
      } else if (c >= 'a' && c <= 'f') {
        hexCode[i-1] = c - 'a' + 10;
      }
    }
    red = hexCode[0] * 16 + hexCode[1];
    green = hexCode[2] * 16 + hexCode[3];
    blue = hexCode[4] * 16 + hexCode[5];
  }

  // Convert RGB color code to hex color code
  char hex[10];
  if (isRgbCode) {
    int r, g, b;
    sscanf(input, "rgb(%d,%d,%d)", &r, &g, &b);
    sprintf(hex, "#%02X%02X%02X", r, g, b);
  }

  // Print the converted color code
  if (isHexCode) {
    printf("7h3 3qu1v4l3n7 RGB c010r c0d3 15: rgb(%d,%d,%d)\n", red, green, blue);
  } else if (isRgbCode) {
    printf("7h3 3qu1v4l3n7 #H3X c010r c0d3 15: %s\n", hex);
  }

  // Goodbye message
  printf("\nG00dby3!\n");

  return 0;
}