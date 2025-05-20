//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Get ready to witness the ultimate encryption extravaganza!
int main() {
  char plaintext[100], ciphertext[100], key[50];
  int key_length, choice, i;

  // Kick off the encryption party by selecting an encryption method!
  printf("1. Encrypt\t2. Decrypt\n");
  printf("Make your choice, valiant encryption warrior: ");
  scanf("%d", &choice);

  // Welcome the plaintext, the protagonist of our encryption saga!
  printf("Enter the plaintext, the secret message you wish to encrypt: ");
  scanf(" %[^\n]", plaintext);

  // Introducing the key, the secret ingredient that will lock away the plaintext!
  printf("Enter the key, the password that will unlock the secrets: ");
  scanf(" %[^\n]", key);

  // Calculate the length of the key, the gatekeeper of encryption!
  key_length = strlen(key);

  // Time for the grand finale! Let's encrypt!
  if (choice == 1) {
    for (i = 0; i < strlen(plaintext); i++) {
      // To the encryption chamber we go, where plaintext transforms into ciphertext!
      ciphertext[i] = plaintext[i] ^ key[i % key_length];
    }
    printf("Congratulations! Your plaintext has been encrypted and locked away. Behold, the ciphertext: %s\n", ciphertext);
  }

  // Now, let's break the code! Time to decrypt!
  else if (choice == 2) {
    for (i = 0; i < strlen(ciphertext); i++) {
      // Decryption, the reverse journey, where ciphertext returns to its plaintext form!
      plaintext[i] = ciphertext[i] ^ key[i % key_length];
    }
    printf("Huzzah! Your ciphertext has been decrypted and the secret message revealed: %s\n", plaintext);
  }

  // Uh oh, invalid input! Time to wave goodbye to encryption!
  else {
    printf("Oops! Invalid choice. Time to bid farewell to encryption adventures!");
  }

  // The encryption saga ends, but the secrets remain safeguarded!
  return 0;
}