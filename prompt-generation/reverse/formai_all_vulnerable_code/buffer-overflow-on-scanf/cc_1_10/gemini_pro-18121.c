//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_CODE_LENGTH 6

// Function to convert a hexadecimal color code to an RGB color code
void hex_to_rgb(const char *hex_code, unsigned char *rgb) {
  int i;
  char *endptr;

  // Convert the hexadecimal color code to an integer
  long int hex_value = strtol(hex_code, &endptr, 16);

  // Check if the hexadecimal color code is valid
  if (*endptr != '\0') {
    printf("Invalid hexadecimal color code: %s\n", hex_code);
    exit(EXIT_FAILURE);
  }

  // Extract the RGB components from the integer
  for (i = 0; i < 3; i++) {
    rgb[i] = (hex_value >> (8 * (2 - i))) & 0xFF;
  }
}

// Function to convert an RGB color code to a hexadecimal color code
void rgb_to_hex(const unsigned char *rgb, char *hex_code) {
  int i;

  // Convert each RGB component to a hexadecimal digit
  for (i = 0; i < 3; i++) {
    char hex_digit = rgb[i] / 16;
    hex_digit += (hex_digit <= 9) ? '0' : 'A' - 10;
    hex_code[i * 2] = hex_digit;

    hex_digit = rgb[i] % 16;
    hex_digit += (hex_digit <= 9) ? '0' : 'A' - 10;
    hex_code[i * 2 + 1] = hex_digit;
  }

  // Terminate the hexadecimal color code with a null character
  hex_code[COLOR_CODE_LENGTH] = '\0';
}

// Function to print a color code in both hexadecimal and RGB formats
void print_color_code(const char *hex_code, const unsigned char *rgb) {
  printf("Hexadecimal color code: %s\n", hex_code);
  printf("RGB color code: (%u, %u, %u)\n", rgb[0], rgb[1], rgb[2]);
}

int main() {
  // Declare the hexadecimal and RGB color codes
  char hex_code[COLOR_CODE_LENGTH + 1]; // +1 for the null terminator
  unsigned char rgb[3];

  // Prompt the user to enter a hexadecimal color code
  printf("Enter a hexadecimal color code: ");
  scanf("%s", hex_code);

  // Convert the hexadecimal color code to an RGB color code
  hex_to_rgb(hex_code, rgb);

  // Print the color code in both hexadecimal and RGB formats
  print_color_code(hex_code, rgb);

  // Convert the RGB color code to a hexadecimal color code
  rgb_to_hex(rgb, hex_code);

  // Print the color code in both hexadecimal and RGB formats
  print_color_code(hex_code, rgb);

  return EXIT_SUCCESS;
}