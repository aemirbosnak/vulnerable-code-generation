//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: minimalist
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION 1
#define ERROR_CORRECTION_LEVEL 0
#define DATA_TYPE 0
#define DATA_LENGTH 4
#define DATA "TEST"

static uint8_t qr_code[VERSION][VERSION];

static void init_qr_code(void) {
  for (int i = 0; i < VERSION; i++) {
    for (int j = 0; j < VERSION; j++) {
      qr_code[i][j] = 0;
    }
  }
}

static void set_bit(int x, int y, bool bit) {
  if (bit) {
    qr_code[x][y] |= 1 << (7 - y % 8);
  } else {
    qr_code[x][y] &= ~(1 << (7 - y % 8));
  }
}

static void encode_format_information(void) {
  // Format information is a 5-bit sequence that encodes the version and error correction level.
  uint8_t format_information = (ERROR_CORRECTION_LEVEL << 3) | VERSION;

  // Interleave the format information bits and store them in the qr code.
  int x = VERSION - 1;
  int y = VERSION - 1;
  for (int i = 0; i < 5; i++) {
    set_bit(x, y, format_information & (1 << i));
    x -= 2;
    if (x < 0) {
      x = VERSION - 1;
      y -= 1;
    }
  }

  // Mask the format information bits using the formula x^y where x is the format information bit
  // and y is the mask pattern.
  for (int i = 0; i < VERSION; i++) {
    for (int j = 0; j < VERSION; j++) {
      if ((i + j) % 2 == 0) {
        qr_code[i][j] ^= format_information;
      }
    }
  }
}

static void encode_data(void) {
  // Data is encoded using the Reed-Solomon error correction code.
  uint8_t data_codewords[] = {
      0x49, 0x43, 0x45, 0x53, 0x54, 0x31, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00
  };

  // Interleave the data codewords and store them in the qr code.
  int x = VERSION - 1;
  int y = VERSION - 1;
  int direction = -1;
  for (int i = 0; i < DATA_LENGTH + 4; i++) {
    set_bit(x, y, data_codewords[i] & (1 << 7));

    if (direction == 1) {
      x += 2;
      if (x >= VERSION) {
        x = VERSION - 1;
        y -= 1;
      }
    } else {
      x -= 2;
      if (x < 0) {
        x = 0;
        y -= 1;
      }
    }

    direction *= -1;
  }
}

static void print_qr_code(void) {
  for (int i = 0; i < VERSION; i++) {
    for (int j = 0; j < VERSION; j++) {
      printf("%d ", qr_code[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  init_qr_code();
  encode_format_information();
  encode_data();
  print_qr_code();

  return 0;
}