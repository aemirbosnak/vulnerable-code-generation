//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

typedef struct { uint8_t r; uint8_t g; uint8_t b; } RGB;
typedef struct { float h; float s; float v; } HSV;

bool validRGB(RGB rgb) {
  return rgb.r >= 0 && rgb.r <= 255 &&
         rgb.g >= 0 && rgb.g <= 255 &&
         rgb.b >= 0 && rgb.b <= 255;
}

void RGBtoHSV(RGB rgb, HSV* hsv) {
  float min, max, deltaH;

  max = (rgb.r > rgb.g) ? rgb.r : rgb.g;
  max = (max > rgb.b) ? max : rgb.b;

  min = (rgb.r <= rgb.g) ? rgb.r : rgb.g;
  min = (min <= rgb.b) ? min : rgb.b;

  hsv->v = max;
  hsv->s = (max > 0) ? (1.0 - (min / max)) : 0.0;

  if (max > 0) {
    deltaH = (rgb.g - rgb.b) + (rgb.r - rgb.g) * 6.0;
    hsv->h = (deltaH < 0) ? (deltaH + 6.0) : deltaH;
    hsv->h /= 6.0;
  } else {
    hsv->h = NAN;
  }
}

void printHSV(HSV hsv) {
  printf("(H, S, V): (%f, %f, %f)\n", hsv.h, hsv.s, hsv.v);
}

int main(void) {
  RGB rgb;
  HSV hsv;

  scanf("%d %d %d", &rgb.r, &rgb.g, &rgb.b);

  if (validRGB(rgb)) {
    RGBtoHSV(rgb, &hsv);
    printHSV(hsv);
  } else {
    fprintf(stderr, "Invalid RGB values.\n");
  }

  return 0;
}