//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10

typedef struct Color {
  char name[20];
  int red, green, blue, alpha;
} Color;

Color colors[MAX_COLORS] = {
  {"Red", 255, 0, 0, 255},
  {"Green", 0, 255, 0, 255},
  {"Blue", 0, 0, 255, 255},
  {"Yellow", 255, 255, 0, 255},
  {"Orange", 255, 165, 0, 255},
  {"Pink", 255, 192, 203, 255},
  {"Cyan", 0, 255, 255, 255},
  {"Purple", 128, 0, 128, 255},
  {"Brown", 160, 120, 0, 255},
  {"Gray", 128, 128, 128, 255}
};

int main() {
  int i;
  char color_name[20];
  int red, green, blue, alpha;

  printf("Enter the name of a color: ");
  scanf("%s", color_name);

  for (i = 0; i < MAX_COLORS; i++) {
    if (strcmp(colors[i].name, color_name) == 0) {
      red = colors[i].red;
      green = colors[i].green;
      blue = colors[i].blue;
      alpha = colors[i].alpha;
      break;
    }
  }

  if (i == MAX_COLORS) {
    printf("Error: Color not found.\n");
  } else {
    printf("Color: %s\n", colors[i].name);
    printf("Red: %d\n", red);
    printf("Green: %d\n", green);
    printf("Blue: %d\n", blue);
    printf("Alpha: %d\n", alpha);
  }

  return 0;
}