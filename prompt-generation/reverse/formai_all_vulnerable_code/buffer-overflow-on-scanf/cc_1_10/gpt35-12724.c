//FormAI DATASET v1.0 Category: QR code generator ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to generate QR code
void generateQrCode(char* input) {
  // Remove any non-alphanumeric characters from the string
  char* ptr1 = input;
  char* ptr2 = input;
  while (*ptr2) {
    if (isalnum(*ptr2)) {
      *ptr1 = *ptr2;
      ptr1++;
    }
    ptr2++;
  }
  *ptr1 = '\0';

  // Allocate memory for the QR code and initialize it with 0s
  int size = (strlen(input) + 2) / 3 * 2;
  int* qrCode = calloc(size, sizeof(int));

  // Loop through the input string and convert it to base64
  int i, j;
  for (i = 0, j = 0; i < strlen(input); i += 3, j += 2) {
    int b1 = input[i];
    int b2 = (i+1 < strlen(input)) ? input[i+1] : 0;
    int b3 = (i+2 < strlen(input)) ? input[i+2] : 0;
    int d1 = b1 >> 2;
    int d2 = ((b1 & 3) << 4) | (b2 >> 4);
    int d3 = ((b2 & 15) << 2) | (b3 >> 6);
    int d4 = b3 & 63;
    qrCode[j] = d1;
    qrCode[j+1] = d2;
    if (i+1 < strlen(input)) {
      qrCode[j+2] = d3;
    }
    if (i+2 < strlen(input)) {
      qrCode[j+3] = d4;
    }
  }

  // Print the QR code
  printf("QR Code:\n");
  for (i = 0; i < size; i++) {
    printf("%d ", qrCode[i]);
  }
  printf("\n");

  // Free memory
  free(qrCode);
}

int main() {
  // Prompt user for input string
  char input[100];
  printf("Enter input string: ");
  scanf("%s", input);

  // Call generateQrCode function and pass user input as argument
  generateQrCode(input);

  return 0;
}