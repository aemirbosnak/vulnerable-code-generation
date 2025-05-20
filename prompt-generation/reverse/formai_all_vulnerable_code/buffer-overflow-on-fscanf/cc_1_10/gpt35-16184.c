//FormAI DATASET v1.0 Category: QR code reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the QR code
#define MAX_SIZE 100

// Define the structure for the QR code
typedef struct {
  int size;
  char code[MAX_SIZE][MAX_SIZE];
} QRcode;

// Define a function to read the QR code from file
QRcode readQRCode(char filename[]) {
  QRcode qrcode;
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error: Unable to open file\n");
    exit(1);
  }
  // Read the size of the QR code
  fscanf(file, "%d", &qrcode.size);
  // Read the QR code
  for (int i = 0; i < qrcode.size; i++) {
    for (int j = 0; j < qrcode.size; j++) {
      fscanf(file, " %c", &qrcode.code[i][j]);
    }
  }
  fclose(file);
  return qrcode;
}

// Define a function to print the QR code
void printQRCode(QRcode qrcode) {
  for (int i = 0; i < qrcode.size; i++) {
    for (int j = 0; j < qrcode.size; j++) {
      printf("%c", qrcode.code[i][j]);
    }
    printf("\n");
  }
}

// Define a function to check if the QR code is valid
bool isQRCodeValid(QRcode qrcode) {
  for (int i = 0; i < qrcode.size; i++) {
    for (int j = 0; j < qrcode.size; j++) {
      if (qrcode.code[i][j] != '0' && qrcode.code[i][j] != '1') {
        return false;
      }
    }
  }
  return true;
}

// Define the main function
int main() {
  // Read the QR code from file
  QRcode qrcode = readQRCode("qrcode.txt");
  // Print the QR code
  printf("QR Code:\n");
  printQRCode(qrcode);
  // Check if the QR code is valid
  if (isQRCodeValid(qrcode)) {
    printf("Valid QR Code\n");
  } else {
    printf("Invalid QR Code\n");
  }
  return 0;
}