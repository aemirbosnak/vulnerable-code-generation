//Code Llama-13B DATASET v1.0 Category: Cryptography Implementation ; Style: real-life
/*
* Cryptography Implementation Example Program in C
*
* This program implements a simple cryptography algorithm using the Caesar Cipher.
* The Caesar Cipher is a simple encryption technique that replaces each
* character in the plaintext with a character a fixed number of positions down
* the alphabet.
*/

#include <stdio.h>
#include <string.h>

/*
* Function to encrypt the plaintext using the Caesar Cipher
*
* @param plaintext: The plaintext to be encrypted
* @param key: The encryption key
* @return: The encrypted text
*/
char *encrypt(char *plaintext, int key) {
  char *encrypted = malloc(strlen(plaintext) + 1);
  int i;

  for (i = 0; i < strlen(plaintext); i++) {
    // Encrypt each character
    encrypted[i] = plaintext[i] + key;

    // Check if the character is a letter
    if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
      // Check if the encrypted character is a letter
      if (encrypted[i] > 'z') {
        // Add the encryption key to the character to wrap it around
        encrypted[i] = encrypted[i] - 'z' + 'a' - 1;
      }
    }
  }

  return encrypted;
}

/*
* Function to decrypt the ciphertext using the Caesar Cipher
*
* @param ciphertext: The ciphertext to be decrypted
* @param key: The decryption key
* @return: The decrypted text
*/
char *decrypt(char *ciphertext, int key) {
  char *decrypted = malloc(strlen(ciphertext) + 1);
  int i;

  for (i = 0; i < strlen(ciphertext); i++) {
    // Decrypt each character
    decrypted[i] = ciphertext[i] - key;

    // Check if the character is a letter
    if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
      // Check if the decrypted character is a letter
      if (decrypted[i] < 'a') {
        // Subtract the encryption key from the character to wrap it around
        decrypted[i] = decrypted[i] + 'z' - 'a' + 1;
      }
    }
  }

  return decrypted;
}

/*
* Main function
*
* This function demonstrates the use of the Caesar Cipher
*/
int main() {
  // Encrypt the plaintext
  char *plaintext = "Hello, World!";
  int key = 3;
  char *encrypted = encrypt(plaintext, key);

  // Print the encrypted text
  printf("Encrypted text: %s\n", encrypted);

  // Decrypt the ciphertext
  char *ciphertext = "Khoor, Zruog!";
  char *decrypted = decrypt(ciphertext, key);

  // Print the decrypted text
  printf("Decrypted text: %s\n", decrypted);

  return 0;
}