//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a simple substitution cipher by shifting each letter by a fixed amount
char *encrypt(char *plaintext, int shift) {
  // Allocate memory for the ciphertext
  char *ciphertext = malloc(strlen(plaintext) + 1);

  // Encrypt each character in the plaintext
  for (int i = 0; i < strlen(plaintext); i++) {
    // Get the ASCII code of the current character
    int c = plaintext[i];

    // Check if the character is a letter
    if (isalpha(c)) {
      // Shift the character by the specified amount
      c += shift;

      // Wrap around if the character goes past 'z' or 'Z'
      if (c > 'z') {
        c -= 26;
      } else if (c > 'Z') {
        c -= 26;
      }
    }

    // Store the encrypted character in the ciphertext
    ciphertext[i] = c;
  }

  // Add the null terminator to the ciphertext
  ciphertext[strlen(plaintext)] = '\0';

  // Return the ciphertext
  return ciphertext;
}

// Decrypt a ciphertext using a simple substitution cipher with a fixed shift
char *decrypt(char *ciphertext, int shift) {
  // Allocate memory for the plaintext
  char *plaintext = malloc(strlen(ciphertext) + 1);

  // Decrypt each character in the ciphertext
  for (int i = 0; i < strlen(ciphertext); i++) {
    // Get the ASCII code of the current character
    int c = ciphertext[i];

    // Check if the character is a letter
    if (isalpha(c)) {
      // Shift the character back by the specified amount
      c -= shift;

      // Wrap around if the character goes before 'a' or 'A'
      if (c < 'a') {
        c += 26;
      } else if (c < 'A') {
        c += 26;
      }
    }

    // Store the decrypted character in the plaintext
    plaintext[i] = c;
  }

  // Add the null terminator to the plaintext
  plaintext[strlen(ciphertext)] = '\0';

  // Return the plaintext
  return plaintext;
}

int main() {
  // Get the plaintext from the user
  char plaintext[100];
  printf("Enter the plaintext: ");
  gets(plaintext);

  // Get the shift amount from the user
  int shift;
  printf("Enter the shift amount (1-25): ");
  scanf("%d", &shift);

  // Encrypt the plaintext using the shift amount
  char *ciphertext = encrypt(plaintext, shift);

  // Print the ciphertext
  printf("The ciphertext is: %s\n", ciphertext);

  // Decrypt the ciphertext using the shift amount
  char *decrypted_plaintext = decrypt(ciphertext, shift);

  // Print the decrypted plaintext
  printf("The decrypted plaintext is: %s\n", decrypted_plaintext);

  // Free the allocated memory
  free(ciphertext);
  free(decrypted_plaintext);

  return 0;
  
}