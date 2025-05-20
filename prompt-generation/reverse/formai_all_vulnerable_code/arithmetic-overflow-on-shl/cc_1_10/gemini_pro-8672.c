//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: artistic
// Paintbrush poised, I dance across the canvas of code,
// Encrypting secrets, a symphony in binary mode.

#include <stdio.h>
#include <string.h>

// Define our magic constants, a sprinkle of mystery in code's trance
#define KEY 0xCAFEF00D
#define ROTATION_ROUNDS 13

// Our encryption function, a brushstroke of obscurity
void encrypt(char *plaintext, char *ciphertext) {
  int i, j;
  size_t len = strlen(plaintext);

  // Begin our enchanted loop, where each byte gets a twist
  for (i = 0; i < len; i++) {
    // Rotate bits, a dance of ones and zeros
    j = plaintext[i] << ROTATION_ROUNDS;
    j |= plaintext[i] >> (32 - ROTATION_ROUNDS);

    // XOR with our key, a secret shared only by you and me
    j ^= KEY;

    // Capture the transformed byte, a piece of the encrypted puzzle
    ciphertext[i] = j;
  }
}

// Unveiling the secrets, a decryption dance we now devise
void decrypt(char *ciphertext, char *plaintext) {
  int i, j;
  size_t len = strlen(ciphertext);

  // Embark on the decryption journey, a journey through time
  for (i = 0; i < len; i++) {
    // Reverse the XORing, breaking the key's hold
    j = ciphertext[i] ^ KEY;

    // Rotate the bits back, unwinding the encryption's fold
    j = j >> ROTATION_ROUNDS;
    j |= j << (32 - ROTATION_ROUNDS);

    // Reveal the plaintext message, a whisper from the encrypted past
    plaintext[i] = j;
  }
}

// Our main function, where the encryption and decryption show
int main() {
  char message[] = "A secret message, hidden from prying eyes";
  char encrypted[strlen(message) + 1];
  char decrypted[strlen(message) + 1];

  printf("Original message: %s\n", message);

  // Encrypt the message, a brushstroke of secrecy
  encrypt(message, encrypted);
  printf("Encrypted message: %s\n", encrypted);

  // Decrypt the message, unveiling the hidden story
  decrypt(encrypted, decrypted);
  printf("Decrypted message: %s\n", decrypted);

  return 0;
}