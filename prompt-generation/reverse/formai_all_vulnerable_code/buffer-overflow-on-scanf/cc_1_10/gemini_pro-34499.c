//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the RGB color structure
typedef struct RGB {
  unsigned char r;
  unsigned char g;
  unsigned char b;
} RGB;

// Define the HSL color structure
typedef struct HSL {
  float h;
  float s;
  float l;
} HSL;

// Convert RGB to HSL
void RGBtoHSL(RGB rgb, HSL *hsl) {
  float r = rgb.r / 255.0f;
  float g = rgb.g / 255.0f;
  float b = rgb.b / 255.0f;

  float max = fmax(r, fmax(g, b));
  float min = fmin(r, fmin(g, b));

  float chroma = max - min;

  if (chroma == 0) {
    hsl->h = 0;
    hsl->s = 0;
    hsl->l = max;
    return;
  }

  if (max == r) {
    hsl->h = ((g - b) / chroma) * 60.0f;
  } else if (max == g) {
    hsl->h = (((b - r) / chroma) * 60.0f) + 120.0f;
  } else {
    hsl->h = (((r - g) / chroma) * 60.0f) + 240.0f;
  }

  hsl->s = chroma / (1 - fabsf(2 * hsl->l - 1));
  hsl->l = (max + min) / 2;
}

// Convert HSL to RGB
void HSLtoRGB(HSL hsl, RGB *rgb) {
  float h = hsl.h / 60.0f;
  float s = hsl.s;
  float l = hsl.l;

  float c = (1 - fabsf(2 * l - 1)) * s;
  float x = c * (1 - fabsf(h - 2) - fabsf(h - 4));
  float y = c * (1 - fabsf(h - 3) - fabsf(h - 5));

  float r, g, b;

  if (h < 1) {
    r = c;
    g = x;
    b = 0;
  } else if (h < 2) {
    r = x;
    g = c;
    b = 0;
  } else if (h < 3) {
    r = 0;
    g = c;
    b = y;
  } else if (h < 4) {
    r = 0;
    g = x;
    b = c;
  } else if (h < 5) {
    r = y;
    g = 0;
    b = c;
  } else {
    r = c;
    g = 0;
    b = x;
  }

  rgb->r = (int)(r * 255.0f);
  rgb->g = (int)(g * 255.0f);
  rgb->b = (int)(b * 255.0f);
}

// Print RGB values
void printRGB(RGB rgb) {
  printf("RGB: (%d, %d, %d)\n", rgb.r, rgb.g, rgb.b);
}

// Print HSL values
void printHSL(HSL hsl) {
  printf("HSL: (%.2f, %.2f%%, %.2f%%)\n", hsl.h, hsl.s * 100.0f, hsl.l * 100.0f);
}

int main() {
  // Get the original RGB color
  RGB rgb;
  printf("Enter the RGB color (r, g, b): ");
  scanf("%d, %d, %d", &rgb.r, &rgb.g, &rgb.b);

  // Convert RGB to HSL
  HSL hsl;
  RGBtoHSL(rgb, &hsl);

  // Print HSL color
  printf("\nConverted HSL color: ");
  printHSL(hsl);

  // Convert HSL back to RGB
  RGB rgb2;
  HSLtoRGB(hsl, &rgb2);

  // Print RGB color
  printf("\nConverted RGB color: ");
  printRGB(rgb2);

  return 0;
}