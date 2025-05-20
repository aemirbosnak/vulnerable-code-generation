//Code Llama-13B DATASET v1.0 Category: Color Code Converter ; Style: creative
/*
 * Color Code Converter
 * -------------------
 *
 * This program converts a given color code from one format to another.
 *
 * Usage:
 *  color_code_converter <color_code> <format>
 *
 * Examples:
 *  color_code_converter #FF0000 hex
 *  color_code_converter 255 0 0 rgb
 *
 * Output:
 *  The converted color code in the specified format.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED_OFFSET 0
#define GREEN_OFFSET 8
#define BLUE_OFFSET 16
#define COLOR_MAX 255

typedef struct {
  unsigned int red;
  unsigned int green;
  unsigned int blue;
} color_t;

typedef enum {
  HEX,
  RGB
} color_format_t;

color_t color_from_hex(const char *hex_code) {
  color_t color;
  color.red = strtol(hex_code + RED_OFFSET, NULL, 16);
  color.green = strtol(hex_code + GREEN_OFFSET, NULL, 16);
  color.blue = strtol(hex_code + BLUE_OFFSET, NULL, 16);
  return color;
}

char *color_to_hex(const color_t *color) {
  char *hex_code = malloc(sizeof(char) * 8);
  sprintf(hex_code, "#%02X%02X%02X", color->red, color->green, color->blue);
  return hex_code;
}

char *color_to_rgb(const color_t *color) {
  char *rgb_code = malloc(sizeof(char) * 10);
  sprintf(rgb_code, "%u %u %u", color->red, color->green, color->blue);
  return rgb_code;
}

void convert_color_code(const char *input, color_format_t input_format, color_format_t output_format) {
  color_t color;
  char *output;

  switch (input_format) {
    case HEX:
      color = color_from_hex(input);
      break;
    case RGB:
      color.red = atoi(input);
      color.green = atoi(input + 1);
      color.blue = atoi(input + 2);
      break;
    default:
      fprintf(stderr, "Invalid input format: %d\n", input_format);
      exit(1);
  }

  switch (output_format) {
    case HEX:
      output = color_to_hex(&color);
      break;
    case RGB:
      output = color_to_rgb(&color);
      break;
    default:
      fprintf(stderr, "Invalid output format: %d\n", output_format);
      exit(1);
  }

  printf("%s\n", output);
  free(output);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <color_code> <format>\n", argv[0]);
    exit(1);
  }

  color_format_t input_format = strcmp(argv[2], "hex") == 0 ? HEX : RGB;
  color_format_t output_format = strcmp(argv[2], "hex") == 0 ? RGB : HEX;

  convert_color_code(argv[1], input_format, output_format);

  return 0;
}