//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encrypt a string using the Caesar cipher
char* encrypt(char* plaintext, int key) {
  // Allocate memory for the ciphertext
  char* ciphertext = malloc(strlen(plaintext) + 1);

  // Encrypt each character in the plaintext
  for (int i = 0; i < strlen(plaintext); i++) {
    // Get the ASCII value of the current character
    int ascii = (int)plaintext[i];

    // Apply the Caesar cipher
    ascii += key;

    // Wrap around the ASCII range if necessary
    if (ascii > 126) {
      ascii -= 94;
    } else if (ascii < 32) {
      ascii += 94;
    }

    // Convert the encrypted ASCII value back to a character
    ciphertext[i] = (char)ascii;
  }

  // Terminate the ciphertext with a null character
  ciphertext[strlen(plaintext)] = '\0';

  // Return the ciphertext
  return ciphertext;
}

// Decrypt a string using the Caesar cipher
char* decrypt(char* ciphertext, int key) {
  // Allocate memory for the plaintext
  char* plaintext = malloc(strlen(ciphertext) + 1);

  // Decrypt each character in the ciphertext
  for (int i = 0; i < strlen(ciphertext); i++) {
    // Get the ASCII value of the current character
    int ascii = (int)ciphertext[i];

    // Apply the Caesar cipher
    ascii -= key;

    // Wrap around the ASCII range if necessary
    if (ascii > 126) {
      ascii -= 94;
    } else if (ascii < 32) {
      ascii += 94;
    }

    // Convert the decrypted ASCII value back to a character
    plaintext[i] = (char)ascii;
  }

  // Terminate the plaintext with a null character
  plaintext[strlen(ciphertext)] = '\0';

  // Return the plaintext
  return plaintext;
}

int main() {
  // Get the plaintext from the user
  char plaintext[100];
  printf("Enter the plaintext: ");
  gets(plaintext);

  // Get the encryption key from the user
  int key;
  printf("Enter the encryption key (1-25): ");
  scanf("%d", &key);

  // Encrypt the plaintext
  char* ciphertext = encrypt(plaintext, key);

  // Print the ciphertext
  printf("Ciphertext: %s\n", ciphertext);

  // Decrypt the ciphertext
  char* decrypted_plaintext = decrypt(ciphertext, key);

  // Print the decrypted plaintext
  printf("Decrypted plaintext: %s\n", decrypted_plaintext);

  // Free the allocated memory
  free(ciphertext);
  free(decrypted_plaintext);

  return 0;
}