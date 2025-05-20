//FormAI DATASET v1.0 Category: Color Code Converter ; Style: inquisitive
#include <stdio.h>

int main() {
  char color[7];
  printf("Please enter a 6-digit HEX color code (e.g. FF0000 for red):\n");
  scanf("%6s", color);
  
  // validate input
  for (int i = 0; i < 6; i++) {
    if (!((color[i] >= '0' && color[i] <= '9') || (color[i] >= 'A' && color[i] <= 'F'))) {
      printf("Invalid input, please enter a valid HEX color code (e.g. FF0000 for red):\n");
      scanf("%6s", color);
      i = -1; // reset loop
    }
  }

  // convert HEX to RGB
  int r = 0, g = 0, b = 0;
  sscanf(color, "%2x%2x%2x", &r, &g, &b);
  printf("RGB values: %d, %d, %d\n", r, g, b);

  // convert RGB to HSL
  double h, s, l;
  double r_ratio = r / 255.0, g_ratio = g / 255.0, b_ratio = b / 255.0;
  double max_color = r_ratio, min_color = r_ratio;
  int max_index = 0;
  double color_arr[3] = { r_ratio, g_ratio, b_ratio };
  
  for (int i = 1; i < 3; i++) {
    if (color_arr[i] > max_color) {
      max_color = color_arr[i];
      max_index = i;
    }
    if (color_arr[i] < min_color) {
      min_color = color_arr[i];
    }
  }
  
  if (max_index == 0) {
    h = (g_ratio - b_ratio) / (max_color - min_color);
  } else if (max_index == 1) {
    h = 2.0 + (b_ratio - r_ratio) / (max_color - min_color);
  } else {
    h = 4.0 + (r_ratio - g_ratio) / (max_color - min_color);
  }
  
  h *= 60;
  if (h < 0) h += 360;
  
  l = (max_color + min_color) / 2.0;

  if (max_color == min_color) {
    s = 0;
  } else if (l <= 0.5) {
    s = (max_color - min_color) / (max_color + min_color);
  } else {
    s = (max_color - min_color) / (2.0 - max_color - min_color);
  }
  
  printf("HSL values: %f, %f, %f\n", h, s, l);

  return 0;
}