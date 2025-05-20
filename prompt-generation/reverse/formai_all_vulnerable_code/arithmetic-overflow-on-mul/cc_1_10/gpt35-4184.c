//FormAI DATASET v1.0 Category: QR code generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 101

void generateQRCode(char *qrCode, int size) {
  int i, j;
  srand(time(NULL));
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      *(qrCode + i * size + j) = (rand() % 2) ? '1' : '0';
    }
  }
  *(qrCode + size * size) = '\0';
}

void printQRCode(char *qrCode, int size) {
  int i, j;
  printf("\nQR Code:\n");
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      printf("%c ", *(qrCode + i * size + j));
    }
    printf("\n");
  }
}

void saveQRCodeToFile(char *qrCode, int size) {
  FILE *file = fopen("qrcode.txt", "w");
  int i, j;
  fprintf(file, "\nQR Code:\n");
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      fprintf(file, "%c ", *(qrCode + i * size + j));
    }
    fprintf(file, "\n");
  }
  fclose(file);
}

void printInstructions() {
  printf("Welcome to the hilarious QR Code Generator!\n");
  printf("I will generate a random QR code for you, because you're too lazy to do it yourself.\n");
  printf("Please enter the size of the QR code that you want me to create (max size is %d): ", MAX_SIZE - 1);
}

int main() {
  char qrCode[MAX_SIZE * MAX_SIZE + 1];
  int size;
  printInstructions();
  scanf("%d", &size);
  if (size > MAX_SIZE - 1) {
    printf("Sorry, the maximum size is %d. You're too ambitious for your own good.\n", MAX_SIZE - 1);
    return 1;
  }
  generateQRCode(qrCode, size);
  printQRCode(qrCode, size);
  saveQRCodeToFile(qrCode, size);
  printf("\nEnjoy your QR code!\n");
  return 0;
}