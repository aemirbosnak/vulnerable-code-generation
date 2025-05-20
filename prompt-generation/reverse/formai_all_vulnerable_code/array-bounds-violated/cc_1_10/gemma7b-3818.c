//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct HexadecimalConverter {
  char buffer[MAX_BUFFER_SIZE];
  int position;
  int converted_value;
  int is_negative;
} HexadecimalConverter;

HexadecimalConverter *create_converter(int initial_value) {
  HexadecimalConverter *converter = malloc(sizeof(HexadecimalConverter));
  converter->position = 0;
  converter->converted_value = initial_value;
  converter->is_negative = 0;

  return converter;
}

void convert_hexadecimal(HexadecimalConverter *converter) {
  char hex_digits[] = "0123456789abcdef";

  while (converter->converted_value) {
    int digit = converter->converted_value % 16;
    converter->buffer[converter->position++] = hex_digits[digit];

    converter->converted_value /= 16;
  }

  if (converter->is_negative) {
    converter->buffer[converter->position++] = '-';
  }
}

void print_hexadecimal(HexadecimalConverter *converter) {
  int i = converter->position - 1;

  for (; i >= 0; i--) {
    printf("%c", converter->buffer[i]);
  }

  printf("\n");
}

int main() {
  HexadecimalConverter *converter = create_converter(-12);
  convert_hexadecimal(converter);
  print_hexadecimal(converter);

  converter = create_converter(15);
  convert_hexadecimal(converter);
  print_hexadecimal(converter);

  return 0;
}