//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <openssl/evp.h>

typedef struct {
  EVP_CIPHER_CTX *ctx;
  unsigned char key[EVP_MAX_KEY_LENGTH];
  unsigned char iv[EVP_MAX_IV_LENGTH];
  int key_len;
  int iv_len;
} EVP_CTX;

EVP_CTX *EVP_CTX_new(const char *cipher, const unsigned char *key, int key_len, const unsigned char *iv, int iv_len)
{
  EVP_CTX *ctx = malloc(sizeof(*ctx));
  if (!ctx)
    return NULL;

  ctx->ctx = EVP_CIPHER_CTX_new();
  if (!ctx->ctx) {
    free(ctx);
    return NULL;
  }

  if (EVP_CipherInit_ex(ctx->ctx, EVP_get_cipherbyname(cipher), NULL, key, iv, 1) != 1) {
    EVP_CIPHER_CTX_free(ctx->ctx);
    free(ctx);
    return NULL;
  }

  ctx->key_len = key_len;
  ctx->iv_len = iv_len;

  return ctx;
}

void EVP_CTX_free(EVP_CTX *ctx)
{
  if (!ctx)
    return;

  EVP_CIPHER_CTX_free(ctx->ctx);
  free(ctx);
}

int EVP_CTX_update(EVP_CTX *ctx, const unsigned char *in, int in_len, unsigned char *out, int out_len)
{
  int out_len_actual;
  if (EVP_CipherUpdate(ctx->ctx, out, &out_len_actual, in, in_len) != 1)
    return -1;

  return out_len_actual;
}

int EVP_CTX_final(EVP_CTX *ctx, unsigned char *out, int out_len)
{
  int out_len_actual;
  if (EVP_CipherFinal_ex(ctx->ctx, out, &out_len_actual) != 1)
    return -1;

  return out_len_actual;
}

int main(int argc, char **argv)
{
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <cipher> <key> <plaintext>\n", argv[0]);
    return EXIT_FAILURE;
  }

  const char *cipher = argv[1];
  const unsigned char *key = (const unsigned char *)argv[2];
  const int key_len = strlen(argv[2]);
  const unsigned char *plaintext = (const unsigned char *)argv[3];
  const int plaintext_len = strlen(argv[3]);

  unsigned char *ciphertext = malloc(plaintext_len + EVP_MAX_BLOCK_LENGTH);
  if (!ciphertext) {
    fprintf(stderr, "malloc() failed\n");
    return EXIT_FAILURE;
  }

  int ciphertext_len;

  EVP_CTX *ctx = EVP_CTX_new(cipher, key, key_len, NULL, 0);
  if (!ctx) {
    fprintf(stderr, "EVP_CTX_new() failed\n");
    free(ciphertext);
    return EXIT_FAILURE;
  }

  ciphertext_len = EVP_CTX_update(ctx, plaintext, plaintext_len, ciphertext, plaintext_len + EVP_MAX_BLOCK_LENGTH);
  if (ciphertext_len < 0) {
    fprintf(stderr, "EVP_CTX_update() failed\n");
    EVP_CTX_free(ctx);
    free(ciphertext);
    return EXIT_FAILURE;
  }

  ciphertext_len += EVP_CTX_final(ctx, ciphertext + ciphertext_len, plaintext_len + EVP_MAX_BLOCK_LENGTH - ciphertext_len);
  if (ciphertext_len < 0) {
    fprintf(stderr, "EVP_CTX_final() failed\n");
    EVP_CTX_free(ctx);
    free(ciphertext);
    return EXIT_FAILURE;
  }

  EVP_CTX_free(ctx);

  printf("Ciphertext: ");
  for (int i = 0; i < ciphertext_len; i++)
    printf("%02x", ciphertext[i]);
  printf("\n");

  free(ciphertext);

  return EXIT_SUCCESS;
}