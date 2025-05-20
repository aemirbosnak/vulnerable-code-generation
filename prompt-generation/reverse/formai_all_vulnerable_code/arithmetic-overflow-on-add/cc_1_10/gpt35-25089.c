//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/evp.h>

#define MAX_KEY_LENGTH 32

void handleErrors(void)
{
  printf("An error occurred.\n");
  exit(1);
}

void encryptKey(char *key, char *plaintext, char *ciphertext)
{
  EVP_CIPHER_CTX *ctx;

  int key_len = strlen(key);
  unsigned char iv[EVP_MAX_IV_LENGTH];
  int ciphertext_len, len;

  if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

  unsigned char key_final[MAX_KEY_LENGTH] = {0};
  if (key_len > MAX_KEY_LENGTH) key_len = MAX_KEY_LENGTH;
  memcpy(key_final, key, key_len);

  if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key_final, iv))
    handleErrors();

  if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, strlen(plaintext)))
    handleErrors();
  ciphertext_len = len;

  if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
  ciphertext_len += len;

  EVP_CIPHER_CTX_free(ctx);
}

void decryptKey(char *key, char *ciphertext, int ciphertext_len, char *plaintext)
{
  EVP_CIPHER_CTX *ctx;

  int key_len = strlen(key);
  unsigned char iv[EVP_MAX_IV_LENGTH];
  int plaintext_len, len;

  if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

  unsigned char key_final[MAX_KEY_LENGTH] = {0};
  if (key_len > MAX_KEY_LENGTH) key_len = MAX_KEY_LENGTH;
  memcpy(key_final, key, key_len);

  if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key_final, iv))
    handleErrors();

  if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
    handleErrors();
  plaintext_len = len;

  if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleErrors();
  plaintext_len += len;

  EVP_CIPHER_CTX_free(ctx);
}

int main()
{
  char key[MAX_KEY_LENGTH] = "my secret key";
  char ciphertext[1024];
  char plaintext[1024] = "Here is a secret message!";

  encryptKey(key, plaintext, ciphertext);
  printf("Encrypted message: %s\n", ciphertext);

  memset(plaintext, 0, sizeof(plaintext));
  decryptKey(key, ciphertext, strlen(ciphertext), plaintext);
  printf("Decrypted message: %s\n", plaintext);

  return 0;
}