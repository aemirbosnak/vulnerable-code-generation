//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: optimized
#include <stdio.h>

#define WIDTH 80
#define HEIGHT 80
#define MAX_COLOR 255

typedef struct {
  unsigned char r, g, b;
} Color;

typedef struct {
  char ascii_char;
  int color_flag;
} AsciiChar;

// Returns a character based on color intensity values
char getAsciiChar(int r, int g, int b) {
  static AsciiChar ascii_chars[8] = {
    {'@', 1},
    {'#', 1},
    {'&', 1},
    {'*', 1},
    {'o', 1},
    {':', 0},
    {'-', 0},
    {' ', 0}
  };
  int gray = (r + g + b) / 3;
  int index = (gray * 8) / MAX_COLOR;
  return ascii_chars[index].color_flag ? ascii_chars[index].ascii_char : ' ';
}

// Converts an image to ASCII art and prints the output
void imageToAscii(Color image[WIDTH][HEIGHT]) {
  char ascii_image[WIDTH][HEIGHT];
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      Color color = image[i][j];
      ascii_image[i][j] = getAsciiChar(color.r, color.g, color.b);
    }
  }
  for (int j = 0; j < HEIGHT; j++) {
    for (int i = 0; i < WIDTH; i++) {
      printf("%c", ascii_image[i][j]);
    }
    printf("\n");
  }
}

int main() {
  Color image[WIDTH][HEIGHT];
  // read the image and store it in the `image` array
  imageToAscii(image);
  return 0;
}