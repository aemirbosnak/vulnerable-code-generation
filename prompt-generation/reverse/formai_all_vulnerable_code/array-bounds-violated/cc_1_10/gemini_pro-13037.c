//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: standalone
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define VERSION 1
#define ERROR_CORRECTION_LEVEL 2  // 0: Low, 1: Medium, 2: High

#define QR_CODE_SIZE 21
#define DATA_SIZE 16  // 16 bits per character

#define PATTERN1 0x77c4
#define PATTERN2 0x72d4
#define PATTERN3 0x7628
#define PATTERN4 0x76e0
#define PATTERN5 0x7a1c
#define PATTERN6 0x7cd0

uint8_t qr_code[QR_CODE_SIZE][QR_CODE_SIZE];

void init_qr_code() {
  for (int i = 0; i < QR_CODE_SIZE; i++) {
    for (int j = 0; j < QR_CODE_SIZE; j++) {
      qr_code[i][j] = 0;
    }
  }
}

void set_pattern(int x, int y, uint8_t pattern) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (pattern & (1 << (i * 8 + j))) {
        qr_code[y + i][x + j] = 1;
      }
    }
  }
}

void set_finder_patterns() {
  set_pattern(0, 0, PATTERN1);
  set_pattern(QR_CODE_SIZE - 7, 0, PATTERN2);
  set_pattern(0, QR_CODE_SIZE - 7, PATTERN3);
}

void set_alignment_patterns() {
  for (int i = 0; i < QR_CODE_SIZE; i += 7) {
    for (int j = 0; j < QR_CODE_SIZE; j += 7) {
      if (i != 0 && i != QR_CODE_SIZE - 7 && j != 0 && j != QR_CODE_SIZE - 7) {
        set_pattern(j, i, PATTERN4);
      }
    }
  }
}

void set_timing_patterns() {
  for (int i = 8; i < QR_CODE_SIZE - 8; i++) {
    qr_code[i][6] = i % 2;
    qr_code[6][i] = i % 2;
  }
}

void set_dark_module() {
  qr_code[QR_CODE_SIZE - 8][8] = 1;
}

void set_format_information() {
  uint8_t format_information = (ERROR_CORRECTION_LEVEL << 3) | VERSION;
  for (int i = 0; i < 5; i++) {
    qr_code[8][i] = format_information & (1 << i);
    qr_code[8][QR_CODE_SIZE - 1 - i] = format_information & (1 << i);
    qr_code[QR_CODE_SIZE - 1 - i][8] = format_information & (1 << i);
  }
  qr_code[QR_CODE_SIZE - 8][QR_CODE_SIZE - 8] = format_information & 1;
}

void set_version_information() {
  if (VERSION >= 7) {
    uint8_t version_information = VERSION << 3 | ERROR_CORRECTION_LEVEL;
    for (int i = 0; i < 6; i++) {
      qr_code[17][i] = version_information & (1 << i);
      qr_code[QR_CODE_SIZE - 11 + i][17] = version_information & (1 << i);
    }
  }
}

void set_data(const char *data) {
  int data_bits_index = 0;
  int data_index = 0;
  for (int y = QR_CODE_SIZE - 1; y >= 0; y -= 2) {
    for (int x = QR_CODE_SIZE - 1; x >= 0; x--) {
      if (x == 6 || y == 6 || (x >= 8 && y >= 8 && x < QR_CODE_SIZE - 8 && y < QR_CODE_SIZE - 8)) {
        continue;
      }
      if (data_bits_index < DATA_SIZE * data_index) {
        qr_code[y][x] = (data[data_index] >> (DATA_SIZE - 1 - data_bits_index % DATA_SIZE)) & 1;
        data_bits_index++;
      }
      if (data_bits_index >= DATA_SIZE * data_index && data_index < strlen(data)) {
        data_index++;
        data_bits_index = 0;
      }
    }
  }
}

void print_qr_code() {
  for (int i = 0; i < QR_CODE_SIZE; i++) {
    for (int j = 0; j < QR_CODE_SIZE; j++) {
      printf("%d ", qr_code[i][j]);
    }
    printf("\n");
  }
}

int main() {
  init_qr_code();

  set_finder_patterns();
  set_alignment_patterns();
  set_timing_patterns();
  set_dark_module();
  set_format_information();
  set_version_information();
  set_data("Hello, world!");

  print_qr_code();

  return 0;
}