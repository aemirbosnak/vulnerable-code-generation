//FormAI DATASET v1.0 Category: QR code generator ; Style: medieval
/*
* This program generates a QR code based on user input in a medieval style.
* It uses the libqrencode library for QR code generation.
* Written by [Your Name] in the year of our Lord [Current Year].
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

// Function declarations
void printMedievalBorder(int length);

int main(void) {
  char data[256];
  int level = QR_ECLEVEL_Q;
  QRcode *qr;

  // Get input from user
  printf("Enter data to encode: ");
  scanf("%s", data);

  // Generate QR code
  qr = QRcode_encodeString(data, 0, level, QR_MODE_8, 1);

  // Print QR code in medieval style
  int width = qr->width;
  int length = width * 3 + 2;

  printMedievalBorder(length);

  for (int i = 0; i < width; i++) {
    printf("%c ", 178); // Print vertical border
    for (int j = 0; j < width; j++) {
      if (qr->data[i * width + j] & 1) {
        printf("%c%c%c", 255, 219, 255); // Print black
      } else {
        printf("%c%c%c", 255, 255, 255); // Print white
      }
    }
    printf("%c\n", 178); // Print vertical border
  }

  printMedievalBorder(length);

  // Free memory allocated by libqrencode
  QRcode_free(qr);

  return 0;
}

// Function to print border in medieval style
void printMedievalBorder(int length) {
  printf("%c", 201); // Top left corner

  for (int i = 0; i < length - 2; i++) {
    printf("%c", 205); // Top border
  }

  printf("%c\n", 187); // Top right corner

  for (int i = 0; i < length - 2; i++) {
    printf("%c ", 186); // Left border
    printf("%c", 32); // Empty space
  }

  printf("%c%c\n", 186, 186); // Right border

  printf("%c", 200); // Bottom left corner

  for (int i = 0; i < length - 2; i++) {
    printf("%c", 205); // Bottom border
  }

  printf("%c\n", 188); // Bottom right corner
}