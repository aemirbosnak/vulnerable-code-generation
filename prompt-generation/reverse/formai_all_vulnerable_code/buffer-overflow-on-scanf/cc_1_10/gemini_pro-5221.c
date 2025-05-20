//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a string using the Caesar cipher
char *encrypt(char *plaintext, int key) {
  char *ciphertext = malloc(strlen(plaintext) + 1); // Allocate memory for the ciphertext

  // Loop through each character in the plaintext
  for (int i = 0; plaintext[i] != '\0'; i++) {
    // Check if the character is a letter
    if (isalpha(plaintext[i])) {
      // Encrypt the character by shifting it by the specified key
      if (isupper(plaintext[i])) {
        ciphertext[i] = 'A' + (plaintext[i] - 'A' + key) % 26;
      } else {
        ciphertext[i] = 'a' + (plaintext[i] - 'a' + key) % 26;
      }
    } else {
      // If the character is not a letter, copy it to the ciphertext
      ciphertext[i] = plaintext[i];
    }
  }

  // Add the null-terminator to the ciphertext
  ciphertext[strlen(plaintext)] = '\0';

  return ciphertext; // Return the ciphertext
}

// Function to decrypt a string using the Caesar cipher
char *decrypt(char *ciphertext, int key) {
  char *plaintext = malloc(strlen(ciphertext) + 1); // Allocate memory for the plaintext

  // Loop through each character in the ciphertext
  for (int i = 0; ciphertext[i] != '\0'; i++) {
    // Check if the character is a letter
    if (isalpha(ciphertext[i])) {
      // Decrypt the character by shifting it by the specified key
      if (isupper(ciphertext[i])) {
        plaintext[i] = 'A' + (ciphertext[i] - 'A' - key + 26) % 26;
      } else {
        plaintext[i] = 'a' + (ciphertext[i] - 'a' - key + 26) % 26;
      }
    } else {
      // If the character is not a letter, copy it to the plaintext
      plaintext[i] = ciphertext[i];
    }
  }

  // Add the null-terminator to the plaintext
  plaintext[strlen(ciphertext)] = '\0';

  return plaintext; // Return the plaintext
}

int main() {
  // Get the plaintext and key from the user
  char *plaintext = malloc(100); // Allocate memory for the plaintext
  int key; // Declare the key variable

  printf("Enter the plaintext: ");
  scanf("%s", plaintext); // Read the plaintext from the console

  printf("Enter the key (1-25): ");
  scanf("%d", &key); // Read the key from the console

  // Encrypt the plaintext using the Caesar cipher
  char *ciphertext = encrypt(plaintext, key); // Call the encrypt function

  // Print the ciphertext
  printf("Encrypted ciphertext: %s\n", ciphertext); // Print the ciphertext to the console

  // Decrypt the ciphertext using the Caesar cipher
  char *decrypted_plaintext = decrypt(ciphertext, key); // Call the decrypt function

  // Print the decrypted plaintext
  printf("Decrypted plaintext: %s\n", decrypted_plaintext); // Print the decrypted plaintext to the console

  // Free the allocated memory
  free(plaintext);
  free(ciphertext);
  free(decrypted_plaintext);

  return 0;
}