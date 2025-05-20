//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/err.h>

#define KEY_SIZE 32
#define IV_SIZE 16

int main() {
  // Generate a random key and IV
  unsigned char key[KEY_SIZE];
  unsigned char iv[IV_SIZE];
  RAND_bytes(key, KEY_SIZE);
  RAND_bytes(iv, IV_SIZE);

  // Create a new cipher context
  EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
  if (ctx == NULL) {
    ERR_print_errors_fp(stderr);
    exit(1);
  }

  // Initialize the cipher context with the key, IV, and cipher algorithm
  if (EVP_CipherInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv, 1) != 1) {
    ERR_print_errors_fp(stderr);
    exit(1);
  }

  // Get the plaintext from the user
  char plaintext[1024];
  printf("Enter the plaintext: ");
  fgets(plaintext, sizeof(plaintext), stdin);

  // Encrypt the plaintext using the cipher context
  int plaintext_len = strlen(plaintext);
  unsigned char ciphertext[plaintext_len + EVP_CIPHER_CTX_block_size(ctx)];
  int ciphertext_len = 0;
  if (EVP_CipherUpdate(ctx, ciphertext, &ciphertext_len, (unsigned char *)plaintext, plaintext_len) != 1) {
    ERR_print_errors_fp(stderr);
    exit(1);
  }

  // Finalize the encryption process
  if (EVP_CipherFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len) != 1) {
    ERR_print_errors_fp(stderr);
    exit(1);
  }

  // Print the ciphertext
  printf("Ciphertext: ");
  for (int i = 0; i < ciphertext_len; i++) {
    printf("%02x", ciphertext[i]);
  }
  printf("\n");

  // Decrypt the ciphertext using the cipher context
  unsigned char decryptedtext[plaintext_len];
  int decryptedtext_len = 0;
  if (EVP_CipherInit_ex(ctx, NULL, NULL, NULL, NULL, 0) != 1) {
    ERR_print_errors_fp(stderr);
    exit(1);
  }

  if (EVP_CipherUpdate(ctx, decryptedtext, &decryptedtext_len, ciphertext, ciphertext_len) != 1) {
    ERR_print_errors_fp(stderr);
    exit(1);
  }

  if (EVP_CipherFinal_ex(ctx, decryptedtext + decryptedtext_len, &decryptedtext_len) != 1) {
    ERR_print_errors_fp(stderr);
    exit(1);
  }

  // Print the decrypted text
  printf("Decrypted text: %s\n", decryptedtext);

  // Clean up
  EVP_CIPHER_CTX_free(ctx);
  return 0;
}