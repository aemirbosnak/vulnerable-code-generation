//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 10

typedef struct Color {
  char name[20];
  int red, green, blue, alpha;
} Color;

Color colors[MAX_COLORS];

void convert_color(Color *color) {
  int i, r, g, b, a;
  printf("Enter the color name: ");
  scanf("%s", color->name);

  printf("Enter the red value (0-255): ");
  scanf("%d", &r);
  color->red = r;

  printf("Enter the green value (0-255): ");
  scanf("%d", &g);
  color->green = g;

  printf("Enter the blue value (0-255): ");
  scanf("%d", &b);
  color->blue = b;

  printf("Enter the alpha value (0-255): ");
  scanf("%d", &a);
  color->alpha = a;
}

int main() {
  int i;
  for (i = 0; i < MAX_COLORS; i++) {
    colors[i].name[0] = '\0';
    colors[i].red = colors[i].green = colors[i].blue = colors[i].alpha = 0;
  }

  convert_color(colors);

  printf("Color converted:\n");
  printf("Name: %s\n", colors[0].name);
  printf("Red: %d\n", colors[0].red);
  printf("Green: %d\n", colors[0].green);
  printf("Blue: %d\n", colors[0].blue);
  printf("Alpha: %d\n", colors[0].alpha);

  return 0;
}