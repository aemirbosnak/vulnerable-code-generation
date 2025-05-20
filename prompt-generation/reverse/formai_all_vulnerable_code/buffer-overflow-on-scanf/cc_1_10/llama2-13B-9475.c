//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BINARY_LEFT_SHIFT   (1 << 24)
#define BINARY_RIGHT_SHIFT  (1 << 24)
#define BINARY_AND         (1 << 24)
#define BINARY_OR          (1 << 24)
#define BINARY_XOR         (1 << 24)

#define HEX_LEFT_SHIFT   (1 << 4)
#define HEX_RIGHT_SHIFT  (1 << 4)
#define HEX_AND         (1 << 4)
#define HEX_OR          (1 << 4)
#define HEX_XOR         (1 << 4)

#define DEC_LEFT_SHIFT   (1 << 24)
#define DEC_RIGHT_SHIFT  (1 << 24)
#define DEC_AND         (1 << 24)
#define DEC_OR          (1 << 24)
#define DEC_XOR         (1 << 24)

#define BINARY_TO_HEX(n)   (((n) & BINARY_LEFT_SHIFT) >> HEX_LEFT_SHIFT)
#define BINARY_TO_DEC(n)  (((n) & BINARY_LEFT_SHIFT) >> DEC_LEFT_SHIFT)

int main() {
  int binary, hex, dec;

  printf("Enter a binary number: ");
  scanf("%d", &binary);

  hex = BINARY_TO_HEX(binary);
  dec = BINARY_TO_DEC(binary);

  printf("Binary: %d\n", binary);
  printf("Hex: %x\n", hex);
  printf("Dec: %d\n", dec);

  printf("Enter a hexadecimal number: ");
  scanf("%x", &hex);

  binary = HEX_TO_BINARY(hex);
  dec = HEX_TO_DEC(hex);

  printf("Hex: %x\n", hex);
  printf("Binary: %d\n", binary);
  printf("Dec: %d\n", dec);

  return 0;
}

int HEX_TO_BINARY(int hex) {
  int binary = 0;

  if (hex & HEX_LEFT_SHIFT) {
    binary |= BINARY_LEFT_SHIFT;
  }

  if (hex & HEX_RIGHT_SHIFT) {
    binary |= BINARY_RIGHT_SHIFT;
  }

  if (hex & HEX_AND) {
    binary |= BINARY_AND;
  }

  if (hex & HEX_OR) {
    binary |= BINARY_OR;
  }

  if (hex & HEX_XOR) {
    binary |= BINARY_XOR;
  }

  return binary;
}

int HEX_TO_DEC(int hex) {
  int dec = 0;

  if (hex & HEX_LEFT_SHIFT) {
    dec |= DEC_LEFT_SHIFT;
  }

  if (hex & HEX_RIGHT_SHIFT) {
    dec |= DEC_RIGHT_SHIFT;
  }

  if (hex & HEX_AND) {
    dec |= DEC_AND;
  }

  if (hex & HEX_OR) {
    dec |= DEC_OR;
  }

  if (hex & HEX_XOR) {
    dec |= DEC_XOR;
  }

  return dec;
}