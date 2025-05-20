//FormAI DATASET v1.0 Category: Color Code Converter ; Style: standalone
#include <stdio.h>

int main() {
  int r, g, b;
  printf("Enter the Red value (0-255): ");
  scanf("%d", &r);
  printf("Enter the Green value (0-255): ");
  scanf("%d", &g);
  printf("Enter the Blue value (0-255): ");
  scanf("%d", &b);

  // Convert RGB to HEX
  int hexValue = (r << 16) + (g << 8) + b;
  printf("HEX Value: #%06X\n", hexValue);

  // Convert RGB to CMYK
  double c, m, y, k;
  c = 1.0 - (double)r/255.0;
  m = 1.0 - (double)g/255.0;
  y = 1.0 - (double)b/255.0;
  k = (c < m) ? ((c < y) ? c : y) : ((m < y) ? m : y);
  c = (c-k)/(1.0-k);
  m = (m-k)/(1.0-k);
  y = (y-k)/(1.0-k);
  printf("CMYK Value: (%.2f, %.2f, %.2f, %.2f)\n", c, m, y, k);

  // Convert RGB to HSL
  double h, s, l;
  double rP = (double)r/255.0;
  double gP = (double)g/255.0;
  double bP = (double)b/255.0;
  double max, min, delta;
  max = (rP > gP) ? ((rP > bP) ? rP : bP) : ((gP > bP) ? gP : bP);
  min = (rP < gP) ? ((rP < bP) ? rP : bP) : ((gP < bP) ? gP : bP);
  delta = max - min;
  if (delta == 0) {
    h = 0;
  } else if (max == rP) {
    h = fmod((((gP-bP)/delta) + 6.0), 6);
  } else if (max == gP) {
    h = (((bP-rP)/delta) + 2.0);
  } else {
    h = (((rP-gP)/delta) + 4.0);
  }
  h *= 60;
  if (h < 0) h += 360;
  l = (max + min) / 2;
  if (delta == 0) {
    s = 0;
  } else {
    s = delta / (1 - fabs(2*l - 1));
  }
  printf("HSL Value: (%.2f, %.2f%%, %.2f%%)\n", h, s*100, l*100);

  return 0;
}