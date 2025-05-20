//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption and decryption keys
#define ENCRYPT_KEY 0x12345678
#define DECRYPT_KEY 0x87654321

// Define the encryption and decryption functions
unsigned int encrypt(unsigned int data) {
  return data ^ ENCRYPT_KEY;
}

unsigned int decrypt(unsigned int data) {
  return data ^ DECRYPT_KEY;
}

// Define the main function
int main() {
  // Get the input data from the user
  char input[100];
  printf("Enter the data to be encrypted: ");
  scanf("%s", input);

  // Convert the input data to an integer array
  unsigned int data[strlen(input)];
  for (int i = 0; i < strlen(input); i++) {
    data[i] = (unsigned int)input[i];
  }

  // Encrypt the data using the encryption function
  for (int i = 0; i < strlen(input); i++) {
    data[i] = encrypt(data[i]);
  }

  // Print the encrypted data
  printf("Encrypted data: ");
  for (int i = 0; i < strlen(input); i++) {
    printf("%02X ", data[i]);
  }
  printf("\n");

  // Decrypt the data using the decryption function
  for (int i = 0; i < strlen(input); i++) {
    data[i] = decrypt(data[i]);
  }

  // Convert the decrypted data to a character array
  char output[100];
  for (int i = 0; i < strlen(input); i++) {
    output[i] = (char)data[i];
  }

  // Print the decrypted data
  printf("Decrypted data: %s\n", output);

  return 0;
}