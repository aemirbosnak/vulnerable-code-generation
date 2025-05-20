//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define KEY_SIZE 16
#define IV_SIZE 16

/* Encrypts the input string using AES-128 CBC encryption */
unsigned char *encrypt(const char *plaintext, const unsigned char *key, const unsigned char *iv){
  unsigned char *ciphertext = NULL;
  
  // Step 1: Get the length of the input string
  int plaintext_len = strlen(plaintext);

  // Step 2: Initialize the cipher context
  EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
  if(!ctx){
    fprintf(stderr, "Error creating cipher context\n");
    exit(-1);
  }

  // Step 3: Initialize the encryption operation
  if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv)){
    fprintf(stderr, "Error initializing encryption operation\n");
    exit(-1);
  }

  // Step 4: Disable padding to ensure that plaintext is a multiple of the block size
  if(1 != EVP_CIPHER_CTX_set_padding(ctx, 0)){
    fprintf(stderr, "Error disabling padding\n");
    exit(-1);
  }

  // Step 5: Allocate memory for the ciphertext buffer
  ciphertext = (unsigned char *)malloc(plaintext_len + EVP_CIPHER_CTX_block_size(ctx));

  // Step 6: Encrypt the plaintext
  int ciphertext_len;
  if(1 != EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, (unsigned char *)plaintext, plaintext_len)){
    fprintf(stderr, "Error encrypting plaintext\n");
    exit(-1);
  }

  // Step 7: Finalize the encryption
  int final_len;
  if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &final_len)){
    fprintf(stderr, "Error finalizing encryption\n");
    exit(-1);
  }
  ciphertext_len += final_len;

  // Step 8: Clean up the cipher context
  EVP_CIPHER_CTX_free(ctx);

  return ciphertext;
}

/* Decrypts the input string using AES-128 CBC decryption */
char *decrypt(const unsigned char *ciphertext, const unsigned char *key, const unsigned char *iv, int ciphertext_len){
  char *plaintext = NULL;

  // Step 1: Initialize the cipher context
  EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
  if(!ctx){
    fprintf(stderr, "Error creating cipher context\n");
    exit(-1);
  }

  // Step 2: Initialize the decryption operation
  if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv)){
    fprintf(stderr, "Error initializing decryption operation\n");
    exit(-1);
  }

  // Step 3: Disable padding to ensure that plaintext is a multiple of the block size
  if(1 != EVP_CIPHER_CTX_set_padding(ctx, 0)){
    fprintf(stderr, "Error disabling padding\n");
    exit(-1);
  }

  // Step 4: Allocate memory for the plaintext buffer
  plaintext = (char *)malloc(ciphertext_len);

  // Step 5: Decrypt the ciphertext
  int plaintext_len;
  if(1 != EVP_DecryptUpdate(ctx, (unsigned char *)plaintext, &plaintext_len, ciphertext, ciphertext_len)){
    fprintf(stderr, "Error decrypting ciphertext\n");
    exit(-1);
  }

  // Step 6: Finalize the decryption
  int final_len;
  if(1 != EVP_DecryptFinal_ex(ctx, (unsigned char *)plaintext + plaintext_len, &final_len)){
    fprintf(stderr, "Error finalizing decryption\n");
    exit(-1);
  }
  plaintext_len += final_len;

  // Step 7: Clean up the cipher context
  EVP_CIPHER_CTX_free(ctx);

  return plaintext;
}

int main(){
  const char *plaintext = "This is a test string";
  const unsigned char key[KEY_SIZE] = {0x3a, 0x1b, 0x16, 0x44, 0x1e, 0x24, 0xdf, 0x71, 0x2c, 0xcc, 0xaf, 0x4b, 0xcb, 0xd1, 0x37, 0x77};
  const unsigned char iv[IV_SIZE] = {0x3e, 0xbb, 0x7c, 0xb5, 0xef, 0x22, 0xac, 0xd9, 0xbf, 0x45, 0xf9, 0x5f, 0x01, 0x6e, 0x39, 0xa4};

  // Encrypt the plaintext
  unsigned char *ciphertext = encrypt(plaintext, key, iv);

  // Print the ciphertext
  printf("Ciphertext: ");
  for(int i = 0; i < strlen(plaintext) + EVP_CIPHER_CTX_block_size(EVP_CIPHER_CTX_new()); i++){
    printf("%02x", ciphertext[i]);
  }
  printf("\n");

  // Decrypt the ciphertext
  char *decrypted = decrypt(ciphertext, key, iv, strlen(plaintext) + EVP_CIPHER_CTX_block_size(EVP_CIPHER_CTX_new()));
  
  // Print the decrypted plaintext
  printf("Decrypted plaintext: %s\n", decrypted);

  // Free memory
  free(ciphertext);
  free(decrypted);

  return 0;
}