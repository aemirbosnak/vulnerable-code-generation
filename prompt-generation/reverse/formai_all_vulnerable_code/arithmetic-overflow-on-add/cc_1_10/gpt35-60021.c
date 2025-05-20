//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define KEY_SIZE  32
#define IV_SIZE  16
#define MAX_DATA_SIZE 1024

int main(void) {
  unsigned char *data = "Hello, World!";
  unsigned char *key = (unsigned char *)"supersecretkey123";
  unsigned char *iv = (unsigned char *)"1234567890123456";

  int data_len = strlen(data);
  int out_len, dec_len;

  // initialize the cipher context
  EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();

  // set the cipher for encryption
  EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

  // allocate memory for the encrypted data
  unsigned char *encrypted = malloc(MAX_DATA_SIZE);

  // encrypt the data
  if(!EVP_EncryptUpdate(ctx, encrypted, &out_len, data, data_len)) {
    // handle error
    printf("Encryption failed\n");
    return 1;
  }

  // finalize the encryption
  if(!EVP_EncryptFinal_ex(ctx, encrypted + out_len, &dec_len)) {
    // handle error
    printf("Encryption failed\n");
    return 1;
  }

  // print the encrypted data
  printf("Encrypted data: ");
  for(int i = 0; i < out_len + dec_len; i++) {
    printf("%02x", encrypted[i]);
  }
  printf("\n");

  // set the cipher for decryption
  EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

  // allocate memory for the decrypted data
  unsigned char *decrypted = malloc(MAX_DATA_SIZE);

  // decrypt the data
  if(!EVP_DecryptUpdate(ctx, decrypted, &out_len, encrypted, out_len + dec_len)) {
    // handle error
    printf("Decryption failed\n");
    return 1;
  }

  // finalize the decryption
  if(!EVP_DecryptFinal_ex(ctx, decrypted + out_len, &dec_len)) {
    // handle error
    printf("Decryption failed\n");
    return 1;
  }

  // print the decrypted data
  printf("Decrypted data: %s\n", decrypted);

  // clean up the cipher context
  EVP_CIPHER_CTX_free(ctx);

  // free the allocated memory
  free(encrypted);
  free(decrypted);

  return 0;
}