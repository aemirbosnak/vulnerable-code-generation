//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sherlock's cipher key
const char *key = "Elementary, my dear Watson!";

// Function to encrypt a string
char *encrypt(char *plaintext)
{
  // Allocate memory for the ciphertext
  char *ciphertext = malloc(strlen(plaintext) + 1);

  // Initialize the ciphertext to the null terminator
  ciphertext[0] = '\0';

  // Loop through each character in the plaintext
  for (int i = 0; i < strlen(plaintext); i++)
  {
    // Get the corresponding character from the key
    char key_char = key[i % strlen(key)];

    // Perform the XOR operation to encrypt the character
    ciphertext[i] = plaintext[i] ^ key_char;
  }

  // Return the ciphertext
  return ciphertext;
}

// Function to decrypt a string
char *decrypt(char *ciphertext)
{
  // Allocate memory for the plaintext
  char *plaintext = malloc(strlen(ciphertext) + 1);

  // Initialize the plaintext to the null terminator
  plaintext[0] = '\0';

  // Loop through each character in the ciphertext
  for (int i = 0; i < strlen(ciphertext); i++)
  {
    // Get the corresponding character from the key
    char key_char = key[i % strlen(key)];

    // Perform the XOR operation to decrypt the character
    plaintext[i] = ciphertext[i] ^ key_char;
  }

  // Return the plaintext
  return plaintext;
}

int main()
{
  // Get the plaintext from the user
  char plaintext[100];
  printf("Enter the plaintext: ");
  gets(plaintext);

  // Encrypt the plaintext
  char *ciphertext = encrypt(plaintext);
  printf("Encrypted ciphertext: %s\n", ciphertext);

  // Decrypt the ciphertext
  char *decrypted_plaintext = decrypt(ciphertext);
  printf("Decrypted plaintext: %s\n", decrypted_plaintext);

  // Free the allocated memory
  free(ciphertext);
  free(decrypted_plaintext);

  return 0;
}