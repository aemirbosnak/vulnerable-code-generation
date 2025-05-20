//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <plaintext> <passphrase>\n", argv[0]);
    exit(1);
  }

  int plaintext_len = strlen(argv[1]);
  int key_len = strlen(argv[2]);

  // Setup the key and the IV
  unsigned char key[EVP_MAX_KEY_LENGTH], iv[EVP_MAX_IV_LENGTH];
  EVP_BytesToKey(EVP_aes_256_cbc(), EVP_sha256(), NULL,
                 (unsigned char *) argv[2], key_len, 1, key, iv);

  // Initialize the encryption context
  EVP_CIPHER_CTX *ctx;
  if (!(ctx = EVP_CIPHER_CTX_new())) {
    printf("EVP_CIPHER_CTX_new() failed\n");
    exit(1);
  }

  // Initialize the encryption operation
  if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
    printf("EVP_EncryptInit_ex() failed\n");
    exit(1);
  }

  // Allocate space for the ciphertext
  int ciphertext_len = plaintext_len + EVP_MAX_BLOCK_LENGTH;
  unsigned char *ciphertext = malloc(ciphertext_len);

  int len;
  if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, (unsigned char *) argv[1], plaintext_len)) {
    printf("EVP_EncryptUpdate() failed\n");
    exit(1);
  }
  ciphertext_len = len;

  if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) {
    printf("EVP_EncryptFinal_ex() failed\n");
    exit(1);
  }
  ciphertext_len += len;

  // Print the ciphertext
  printf("Ciphertext:\n");
  for (int i = 0; i < ciphertext_len; i++) {
    printf("%02x ", ciphertext[i]);
  }
  printf("\n");

  // Cleanup
  free(ciphertext);
  EVP_CIPHER_CTX_free(ctx);

  return 0;
}