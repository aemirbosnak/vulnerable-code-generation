//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10

typedef struct Color {
  char name[20];
  int r, g, b, a;
} Color;

Color colors[MAX_COLORS] = {
  {"Red", 255, 0, 0, 255},
  {"Green", 0, 255, 0, 255},
  {"Blue", 0, 0, 255, 255},
  {"Yellow", 255, 255, 0, 255},
  {"Cyan", 0, 255, 255, 255},
  {"Magenta", 255, 0, 255, 255},
  {"Black", 0, 0, 0, 255},
  {"White", 255, 255, 255, 255},
  {"Gray", 128, 128, 128, 255},
  {"Orange", 255, 165, 0, 255}
};

int main() {
  int i, color_index;
  char color_name[20];
  int red, green, blue, alpha;

  printf("Enter the name of a color: ");
  scanf("%s", color_name);

  for (i = 0; i < MAX_COLORS; i++) {
    if (strcmp(colors[i].name, color_name) == 0) {
      color_index = i;
      break;
    }
  }

  if (color_index == -1) {
    printf("Error: Color not found.\n");
  } else {
    red = colors[color_index].r;
    green = colors[color_index].g;
    blue = colors[color_index].b;
    alpha = colors[color_index].a;

    printf("Color: %s\n", colors[color_index].name);
    printf("Red: %d\n", red);
    printf("Green: %d\n", green);
    printf("Blue: %d\n", blue);
    printf("Alpha: %d\n", alpha);
  }

  return 0;
}