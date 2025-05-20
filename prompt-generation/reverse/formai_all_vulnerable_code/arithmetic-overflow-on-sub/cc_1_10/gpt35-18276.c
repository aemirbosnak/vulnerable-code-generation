//FormAI DATASET v1.0 Category: Color Code Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void rgbToHex(int red, int green, int blue);
void hexToRgb(char *hex);

int main() {
  // menu
  int choice;
  printf("Choose an option:\n");
  printf("1. Convert RGB to Hex\n");
  printf("2. Convert Hex to RGB\n");
  scanf("%d", &choice);

  // variables for RGB to Hex conversion
  int red, green, blue;

  // variables for Hex to RGB conversion
  char *hex = malloc(sizeof(char) * 7);

  switch(choice) {
    case 1:
      // ask for RGB values
      printf("Enter red value (0-255): ");
      scanf("%d", &red);
      printf("Enter green value (0-255): ");
      scanf("%d", &green);
      printf("Enter blue value (0-255): ");
      scanf("%d", &blue);

      // call RGB to Hex function
      rgbToHex(red, green, blue);
      break;
    case 2:
      // ask for Hex value
      printf("Enter hex value (include # symbol): ");
      scanf("%s", hex);

      // call Hex to RGB function
      hexToRgb(hex);
      break;
    default:
      printf("Invalid choice. Please choose 1 or 2.\n");
  }

  free(hex);

  return 0;
}

// function to convert RGB to Hex
void rgbToHex(int red, int green, int blue) {
  int r1, r2, g1, g2, b1, b2;
  int sum = 0;

  // convert each RGB value to two hexadecimal digits
  r1 = red / 16;
  r2 = red % 16;
  g1 = green / 16;
  g2 = green % 16;
  b1 = blue / 16;
  b2 = blue % 16;

  // add up the values and output HEX code
  sum = r1 * 16 + r2;
  printf("#%X", sum);
  sum = g1 * 16 + g2;
  printf("%X", sum);
  sum = b1 * 16 + b2;
  printf("%X\n", sum);
}

// function to convert Hex to RGB
void hexToRgb(char *hex) {
  int r, g, b;
  char *ptr;

  // use strtol() to convert the hexadecimal string to an integer
  r = strtol(hex + 1, &ptr, 16);
  g = strtol(ptr + 1, &ptr, 16);
  b = strtol(ptr + 1, NULL, 16);

  // output RGB values
  printf("Red: %d\n", r);
  printf("Green: %d\n", g);
  printf("Blue: %d\n", b);
}