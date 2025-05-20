//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define MAX_AES_KEY_SIZE 32
#define MAX_AES_IV_SIZE 16

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext) {
  EVP_CIPHER_CTX *ctx;
  int len;
  int ciphertext_len;

  if(!(ctx = EVP_CIPHER_CTX_new())) return -1;

  if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
    return -1;

  if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
    return -1;
  ciphertext_len = len;

  if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) return -1;

  ciphertext_len += len;

  EVP_CIPHER_CTX_free(ctx);

  return ciphertext_len;
}

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext) {
  EVP_CIPHER_CTX *ctx;
  int len;
  int plaintext_len;
  int ret;

  if(!(ctx = EVP_CIPHER_CTX_new())) return -1;

  if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
    return -1;

  if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
    return -1;
  plaintext_len = len;

  ret = EVP_DecryptFinal_ex(ctx, plaintext + len, &len);
  if(ret != 1) return -1;

  plaintext_len += len;

  EVP_CIPHER_CTX_free(ctx);

  return plaintext_len;
}

int main(int argc, char *argv[]) {
  unsigned char *key = (unsigned char *)"15vPpkaeewMUMTSCEXHaG4s5QHvkYTpJ"; // Random 32-byte key
  unsigned char *iv = (unsigned char *)"HS3vYy28S62TKgvt"; // Random 16-byte IV

  unsigned char *plaintext = (unsigned char *)"Hello world!";

  int ciphertext_len;
  unsigned char ciphertext[128];

  ciphertext_len = encrypt(plaintext, strlen(plaintext), key, iv, ciphertext);

  printf("Ciphertext is:\n");
  BIO_dump_fp(stdout, (const char *)ciphertext, ciphertext_len);
  
  unsigned char decryptedtext[128];
  int decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);

  decryptedtext[decryptedtext_len] = '\0';

  printf("Decrypted text is:\n");
  printf("%s\n", decryptedtext);

  return 0;
}