//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: optimized
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <input file> <output file> <password>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE* input = fopen(argv[1], "rb");
  if (input == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  FILE* output = fopen(argv[2], "wb");
  if (output == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
  if (ctx == NULL) {
    EVP_CIPHER_CTX_free(ctx);
    perror("EVP_CIPHER_CTX_new");
    return EXIT_FAILURE;
  }

  int keylen = EVP_CIPHER_key_length(EVP_aes_256_cfb());
  int ivlen = EVP_CIPHER_iv_length(EVP_aes_256_cfb());
  uint8_t key[keylen];
  uint8_t iv[ivlen];

  if (RAND_bytes(key, keylen) != 1) {
    perror("RAND_bytes");
    EVP_CIPHER_CTX_free(ctx);
    return EXIT_FAILURE;
  }

  if (RAND_bytes(iv, ivlen) != 1) {
    perror("RAND_bytes");
    EVP_CIPHER_CTX_free(ctx);
    return EXIT_FAILURE;
  }

  if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cfb(), NULL, key, iv) != 1) {
    perror("EVP_EncryptInit_ex");
    EVP_CIPHER_CTX_free(ctx);
    return EXIT_FAILURE;
  }

  int outlen = 0;
  uint8_t buffer[4096];
  size_t nread;

  while ((nread = fread(buffer, 1, sizeof(buffer), input)) > 0) {
    if (EVP_EncryptUpdate(ctx, buffer, &outlen, buffer, nread) != 1) {
      perror("EVP_EncryptUpdate");
      EVP_CIPHER_CTX_free(ctx);
      return EXIT_FAILURE;
    }

    fwrite(buffer, outlen, 1, output);
    outlen = 0;
  }

  if (ferror(input)) {
    perror("fread");
    EVP_CIPHER_CTX_free(ctx);
    return EXIT_FAILURE;
  }

  if (EVP_EncryptFinal_ex(ctx, buffer, &outlen) != 1) {
    perror("EVP_EncryptFinal_ex");
    EVP_CIPHER_CTX_free(ctx);
    return EXIT_FAILURE;
  }

  fwrite(buffer, outlen, 1, output);
  outlen = 0;

  if (ferror(output)) {
    perror("fwrite");
    EVP_CIPHER_CTX_free(ctx);
    return EXIT_FAILURE;
  }

  EVP_CIPHER_CTX_free(ctx);
  fclose(input);
  fclose(output);

  return EXIT_SUCCESS;
}