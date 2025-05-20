//FormAI DATASET v1.0 Category: QR code generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define QR_VERSION 1     // Define the QR version
#define QR_SIZE 21       // Define the QR size

uint32_t generator(uint32_t message, uint32_t polynomial, uint32_t n); // Define the generator function

int main() {
  uint32_t message, polynomial, n, crc; // Define the variables
  char qr_code[QR_SIZE][QR_SIZE]; // Define the QR code array
  memset(qr_code, 0, sizeof(qr_code)); // Initialize the QR code array to all zeroes
  
  printf("Enter the message: ");
  scanf("%u", &message); // Read the message from user input

  printf("Enter the polynomial: ");
  scanf("%u", &polynomial); // Read the polynomial from user input

  n = (1 << QR_VERSION) - 1; // Calculate the number of bits available for the given QR version
  crc = generator(message << n, polynomial << n, n); // Calculate the CRC value for the message and polynomial
  
  // Convert the message and CRC value to binary format and store them in the QR code array
  for (int i = 0; i < n; i++) {
    qr_code[0][n-i-1] = ((message >> i) & 1) + '0'; // Convert the message to binary
    qr_code[QR_SIZE-1][n-i-1] = ((crc >> i) & 1) + '0'; // Convert the CRC value to binary
  }

  // Print the QR code
  for (int i = 0; i < QR_SIZE; i++) {
    for (int j = 0; j < QR_SIZE; j++) {
      printf("%c", qr_code[i][j] ? qr_code[i][j] : ' '); // Print the QR code
    }
    printf("\n");
  }
  
  return 0;
}

// Generator function to calculate the CRC value
uint32_t generator(uint32_t message, uint32_t polynomial, uint32_t n) {
  uint32_t crc = message;
  uint32_t msb = 1 << (2*n - 1); // Calculate the most significant bit

  while (msb > 1) {
    if (crc & msb) crc ^= polynomial; // XOR the polynomial with the message if the most significant bit is set
    msb >>= 1; // Shift the most significant bit to the right by one
    if (crc & msb) crc ^= polynomial; // XOR the polynomial with the message if the shifted most significant bit is set
  }

  return crc;
}