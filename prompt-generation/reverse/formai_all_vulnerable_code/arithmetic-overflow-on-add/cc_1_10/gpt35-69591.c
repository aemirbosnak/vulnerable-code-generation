//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define ERROR -1
#define SUCCESS 0

static int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
  unsigned char *iv, unsigned char *ciphertext)
{
  EVP_CIPHER_CTX *ctx;

  int len;

  int ciphertext_len;

  if(!(ctx = EVP_CIPHER_CTX_new())) {
    return ERROR;
  }

  if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
    return ERROR;
  }

  if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)) {
    return ERROR;
  }

  ciphertext_len = len;

  if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) {
    return ERROR;
  }

  ciphertext_len += len;

  EVP_CIPHER_CTX_free(ctx);

  return ciphertext_len;
}

static int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
  unsigned char *iv, unsigned char *plaintext)
{
  EVP_CIPHER_CTX *ctx;

  int len;

  int plaintext_len;

  if(!(ctx = EVP_CIPHER_CTX_new())) {
    return ERROR;
  }

  if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
    return ERROR;
  }

  if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len)) {
    return ERROR;
  }

  plaintext_len = len;

  if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) {
    return ERROR;
  }

  plaintext_len += len;

  EVP_CIPHER_CTX_free(ctx);

  return plaintext_len;
}

int main(void)
{
  unsigned char *key = (unsigned char *)"01234567890123456789012345678901";

  unsigned char *iv = (unsigned char *)"0123456789012345";

  unsigned char *plaintext =
    (unsigned char *)"Now is the time for all good men to come to the aid of the party\n";

  int plaintext_len = strlen((char *)plaintext);

  unsigned char ciphertext[128];

  int ciphertext_len = encrypt(plaintext, plaintext_len, key, iv, ciphertext);

  printf("Ciphertext is:\n");

  BIO_dump_fp(stdout, (const char *)ciphertext, ciphertext_len);

  unsigned char decryptedtext[128];

  int decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);

  decryptedtext[decryptedtext_len] = '\0';

  printf("Decrypted text is:\n");

  printf("%s\n", decryptedtext);

  return SUCCESS;
}