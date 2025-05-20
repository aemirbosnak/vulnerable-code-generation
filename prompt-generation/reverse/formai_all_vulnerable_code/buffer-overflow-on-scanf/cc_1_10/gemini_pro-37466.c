//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alphabet
char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

// Define the key
char key[] = "IAMYOURKEY";

// Define the encryption function
char encrypt(char c) {
  // Find the index of the character in the alphabet
  int index = strchr(alphabet, c) - alphabet;

  // Shift the index by the key
  index = (index + strlen(key)) % strlen(alphabet);

  // Return the encrypted character
  return alphabet[index];
}

// Define the decryption function
char decrypt(char c) {
  // Find the index of the character in the alphabet
  int index = strchr(alphabet, c) - alphabet;

  // Shift the index by the key
  index = (index - strlen(key) + strlen(alphabet)) % strlen(alphabet);

  // Return the decrypted character
  return alphabet[index];
}

// Define the main function
int main() {
  // Get the plaintext from the user
  char plaintext[100];
  printf("Enter the plaintext: ");
  scanf("%s", plaintext);

  // Encrypt the plaintext
  char ciphertext[100];
  for (int i = 0; i < strlen(plaintext); i++) {
    ciphertext[i] = encrypt(plaintext[i]);
  }

  // Print the ciphertext
  printf("The ciphertext is: %s\n", ciphertext);

  // Decrypt the ciphertext
  char decryptedtext[100];
  for (int i = 0; i < strlen(ciphertext); i++) {
    decryptedtext[i] = decrypt(ciphertext[i]);
  }

  // Print the decryptedtext
  printf("The decryptedtext is: %s\n", decryptedtext);

  return 0;
}