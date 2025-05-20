//FormAI DATASET v1.0 Category: Color Code Converter ; Style: invasive
#include <stdio.h>

/*
  This program is a C color code converter!
*/

int main() {
  // prompt user for input
  printf("Welcome to the C Color Code Converter! Please enter a color code in HEX format: ");

  char colorCode[8];
  scanf("%s", &colorCode);

  // ensure input is in valid format
  if (colorCode[0] != '#' || strlen(colorCode) != 7) {
    printf("Invalid color code format. Please try again.\n");
    return 0;
  }
  
  // convert to RGB values
  int red = (int)strtol(colorCode+1, NULL, 16);
  int green = (int)strtol(colorCode+3, NULL, 16);
  int blue = (int)strtol(colorCode+5, NULL, 16);
  
  // output RGB values
  printf("R: %d\n", red);
  printf("G: %d\n", green);
  printf("B: %d\n", blue);

  // prompt user for conversion type
  printf("Would you like to convert to HSL or CMYK? Enter 'h' for HSL or 'c' for CMYK: ");

  char conversionType;
  scanf(" %c", &conversionType);

  if (conversionType == 'h') {
    // convert to HSL values

    float r = (float)red / 255.0;
    float g = (float)green / 255.0;
    float b = (float)blue / 255.0;

    float cmax = fmaxf(r, fmaxf(g, b));
    float cmin = fminf(r, fminf(g, b));
    float delta = cmax - cmin;

    float hue = 0;
    if (delta == 0) {
      hue = 0;
    } else if (cmax == r) {
      hue = fmodf((g - b) / delta, 6.0) * 60.0;
    } else if (cmax == g) {
      hue = ((b - r) / delta + 2) * 60.0;
    } else if (cmax == b) {
      hue = ((r - g) / delta + 4) * 60.0;
    }

    float lightness = (cmax + cmin) / 2.0;

    float saturation = 0;
    if (delta == 0) {
      saturation = 0;
    } else {
      saturation = delta / (1 - fabsf(2*lightness - 1));
    }

    // output HSL values
    printf("H: %.2f\n", hue);
    printf("S: %.2f\n", saturation);
    printf("L: %.2f\n", lightness);

  } else if (conversionType == 'c') {
    // convert to CMYK values

    float r = (float)red / 255.0;
    float g = (float)green / 255.0;
    float b = (float)blue / 255.0;

    float k = 1 - fmaxf(r, fmaxf(g, b));

    float c = (1 - r - k) / (1 - k);
    float m = (1 - g - k) / (1 - k);
    float y = (1 - b - k) / (1 - k);

    // output CMYK values
    printf("C: %.2f%%\n", c*100);
    printf("M: %.2f%%\n", m*100);
    printf("Y: %.2f%%\n", y*100);
    printf("K: %.2f%%\n", k*100);

  } else {
    printf("Invalid conversion type. Please try again.\n");
  }

  return 0;
}