//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define KEY_LEN 16
#define IV_LEN 16

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, 
            unsigned char *iv, unsigned char *ciphertext){
  EVP_CIPHER_CTX *ctx;
  int len;
  int ciphertext_len;

  if(!(ctx = EVP_CIPHER_CTX_new())) return 0;

  if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) return 0;

  if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
    return 0;
  ciphertext_len = len;

  if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) return 0;
  ciphertext_len += len;

  EVP_CIPHER_CTX_free(ctx);

  return ciphertext_len;
}

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, 
            unsigned char *iv, unsigned char *plaintext){
  EVP_CIPHER_CTX *ctx;
  int len;
  int plaintext_len;

  if(!(ctx = EVP_CIPHER_CTX_new())) return 0;

  if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) return 0;

  if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
    return 0;
  plaintext_len = len;

  if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) return 0;
  plaintext_len += len;

  EVP_CIPHER_CTX_free(ctx);

  return plaintext_len;
}

int main(){
  unsigned char *key = (unsigned char *)"0123456789abcdef";
  unsigned char *iv = (unsigned char *)"fedcba9876543210";
  unsigned char *plaintext = (unsigned char *)"This is a test string.";
  unsigned char ciphertext[128];
  unsigned char decryptedtext[128];

  int decryptedtext_len, ciphertext_len;

  ciphertext_len = encrypt(plaintext, strlen(plaintext), key, iv, ciphertext);
  
  decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);

  decryptedtext[decryptedtext_len] = '\0';

  printf("Original: %s\n", plaintext);
  printf("Encrypted: ");
  for (int i=0; i<ciphertext_len; i++){
    printf("%02x", ciphertext[i]);
  }
  printf("\n");
  printf("Decrypted: %s\n", decryptedtext);
  
  return 0;
}