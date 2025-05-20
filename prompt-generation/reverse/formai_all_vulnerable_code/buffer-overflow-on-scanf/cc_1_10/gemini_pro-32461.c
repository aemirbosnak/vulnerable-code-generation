//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the encryption key
#define KEY "X8264hjh89mMk8923q"

// Define the alphabet
char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

// Define the encryption function
char *encrypt(char *plaintext) {
  // Get the length of the plaintext
  int length = strlen(plaintext);

  // Allocate memory for the ciphertext
  char *ciphertext = malloc(length + 1);

  // Encrypt the plaintext
  for (int i = 0; i < length; i++) {
    // Get the index of the plaintext character in the alphabet
    int index = strchr(alphabet, plaintext[i]) - alphabet;

    // Shift the index by the key
    index += KEY[i % strlen(KEY)];

    // Wrap the index around if necessary
    index %= strlen(alphabet);

    // Get the ciphertext character from the alphabet
    ciphertext[i] = alphabet[index];
  }

  // Terminate the ciphertext with a null character
  ciphertext[length] = '\0';

  // Return the ciphertext
  return ciphertext;
}

// Define the decryption function
char *decrypt(char *ciphertext) {
  // Get the length of the ciphertext
  int length = strlen(ciphertext);

  // Allocate memory for the plaintext
  char *plaintext = malloc(length + 1);

  // Decrypt the ciphertext
  for (int i = 0; i < length; i++) {
    // Get the index of the ciphertext character in the alphabet
    int index = strchr(alphabet, ciphertext[i]) - alphabet;

    // Shift the index by the key
    index -= KEY[i % strlen(KEY)];

    // Wrap the index around if necessary
    index %= strlen(alphabet);

    // Get the plaintext character from the alphabet
    plaintext[i] = alphabet[index];
  }

  // Terminate the plaintext with a null character
  plaintext[length] = '\0';

  // Return the plaintext
  return plaintext;
}

// Define the main function
int main() {
  // Get the plaintext from the user
  char plaintext[100];
  printf("Enter the plaintext: ");
  scanf("%s", plaintext);

  // Encrypt the plaintext
  char *ciphertext = encrypt(plaintext);

  // Print the ciphertext
  printf("Ciphertext: %s\n", ciphertext);

  // Decrypt the ciphertext
  char *decryptedText = decrypt(ciphertext);

  // Print the decrypted text
  printf("Decrypted text: %s\n", decryptedText);

  // Free the allocated memory
  free(ciphertext);
  free(decryptedText);

  return 0;
}