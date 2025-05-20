//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main() {
  char *plaintext = "This is my secret message!";

  // Generate a random key and initialization vector
  unsigned char key[EVP_MAX_KEY_LENGTH];
  unsigned char iv[EVP_MAX_IV_LENGTH];
  if (!RAND_bytes(key, sizeof(key))) {
    fprintf(stderr, "Error generating random key.\n");
    return EXIT_FAILURE;
  }
  if (!RAND_bytes(iv, sizeof(iv))) {
    fprintf(stderr, "Error generating random IV.\n");
    return EXIT_FAILURE;
  }

  // Initialize the cipher context
  EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
  if (!ctx) {
    fprintf(stderr, "Error creating cipher context.\n");
    return EXIT_FAILURE;
  }
  if (!EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
    fprintf(stderr, "Error initializing encryption context.\n");
    EVP_CIPHER_CTX_free(ctx);
    return EXIT_FAILURE;
  }

  // Encrypt the message
  int ciphertext_length = strlen(plaintext) + EVP_MAX_BLOCK_LENGTH;
  unsigned char *ciphertext = malloc(ciphertext_length);
  int final_ciphertext_length;
  if (!EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_length, (unsigned char *) plaintext, strlen(plaintext))) {
    fprintf(stderr, "Error encrypting message.\n");
    free(ciphertext);
    EVP_CIPHER_CTX_free(ctx);
    return EXIT_FAILURE;
  }
  if (!EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_length, &final_ciphertext_length)) {
    fprintf(stderr, "Error finalizing encryption.\n");
    free(ciphertext);
    EVP_CIPHER_CTX_free(ctx);
    return EXIT_FAILURE;
  }
  ciphertext_length += final_ciphertext_length;

  // Print the encrypted message
  printf("Ciphertext:\n");
  for (int i = 0; i < ciphertext_length; i++) {
    printf("%02x", ciphertext[i]);
  }
  printf("\n");

  // Clean up
  free(ciphertext);
  EVP_CIPHER_CTX_free(ctx);

  return EXIT_SUCCESS;
}