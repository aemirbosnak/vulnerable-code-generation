//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/hmac.h>

// Key and IV should be 16 bytes each
unsigned char key[AES_BLOCK_SIZE];
unsigned char iv[AES_BLOCK_SIZE];

// Function to generate a random key and IV
void generate_key_and_iv() {
  RAND_bytes(key, AES_BLOCK_SIZE);
  RAND_bytes(iv, AES_BLOCK_SIZE);
}

// Function to encrypt data using AES-256-CBC
int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *ciphertext) {
  EVP_CIPHER_CTX *ctx;

  // Create and initialize the cipher context
  ctx = EVP_CIPHER_CTX_new();
  if (ctx == NULL) {
    return -1;
  }

  // Initialize the cipher for encryption
  if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
    EVP_CIPHER_CTX_free(ctx);
    return -1;
  }

  // Encrypt the data
  if (EVP_EncryptUpdate(ctx, ciphertext, &plaintext_len, plaintext, plaintext_len) != 1) {
    EVP_CIPHER_CTX_free(ctx);
    return -1;
  }

  // Finalize the encryption
  if (EVP_EncryptFinal_ex(ctx, ciphertext + plaintext_len, &plaintext_len) != 1) {
    EVP_CIPHER_CTX_free(ctx);
    return -1;
  }

  // Free the cipher context
  EVP_CIPHER_CTX_free(ctx);

  return plaintext_len;
}

// Function to decrypt data using AES-256-CBC
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *plaintext) {
  EVP_CIPHER_CTX *ctx;

  // Create and initialize the cipher context
  ctx = EVP_CIPHER_CTX_new();
  if (ctx == NULL) {
    return -1;
  }

  // Initialize the cipher for decryption
  if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
    EVP_CIPHER_CTX_free(ctx);
    return -1;
  }

  // Decrypt the data
  if (EVP_DecryptUpdate(ctx, plaintext, &ciphertext_len, ciphertext, ciphertext_len) != 1) {
    EVP_CIPHER_CTX_free(ctx);
    return -1;
  }

  // Finalize the decryption
  if (EVP_DecryptFinal_ex(ctx, plaintext + ciphertext_len, &ciphertext_len) != 1) {
    EVP_CIPHER_CTX_free(ctx);
    return -1;
  }

  // Free the cipher context
  EVP_CIPHER_CTX_free(ctx);

  return ciphertext_len;
}

// Function to generate a HMAC-SHA256 signature
int generate_hmac(unsigned char *message, int message_len, unsigned char *signature) {
  HMAC_CTX *ctx;
  unsigned int signature_len;

  // Create and initialize the HMAC context
  ctx = HMAC_CTX_new();
  if (ctx == NULL) {
    return -1;
  }

  // Initialize the HMAC for signing
  if (HMAC_Init_ex(ctx, key, AES_BLOCK_SIZE, EVP_sha256(), NULL) != 1) {
    HMAC_CTX_free(ctx);
    return -1;
  }

  // Sign the message
  if (HMAC_Update(ctx, message, message_len) != 1) {
    HMAC_CTX_free(ctx);
    return -1;
  }

  // Finalize the signature
  if (HMAC_Final(ctx, signature, &signature_len) != 1) {
    HMAC_CTX_free(ctx);
    return -1;
  }

  // Free the HMAC context
  HMAC_CTX_free(ctx);

  return signature_len;
}

int main() {
  // Generate a random key and IV
  generate_key_and_iv();

  // Plaintext to be encrypted
  unsigned char plaintext[] = "This is a secret message.";
  int plaintext_len = strlen(plaintext);

  // Ciphertext buffer
  unsigned char ciphertext[plaintext_len + AES_BLOCK_SIZE];

  // Encrypt the plaintext
  int ciphertext_len = encrypt(plaintext, plaintext_len, ciphertext);
  if (ciphertext_len < 0) {
    perror("Encryption failed");
    return EXIT_FAILURE;
  }

  // Decrypt the ciphertext
  plaintext_len = decrypt(ciphertext, ciphertext_len, plaintext);
  if (plaintext_len < 0) {
    perror("Decryption failed");
    return EXIT_FAILURE;
  }

  // Print the decrypted plaintext
  printf("Decrypted plaintext: %s\n", plaintext);

  // Signature buffer
  unsigned char signature[EVP_MAX_MD_SIZE];

  // Generate a HMAC-SHA256 signature
  int signature_len = generate_hmac(plaintext, plaintext_len, signature);
  if (signature_len < 0) {
    perror("HMAC generation failed");
    return EXIT_FAILURE;
  }

  // Print the signature
  printf("HMAC-SHA256 signature: ");
  for (int i = 0; i < signature_len; i++) {
    printf("%02x", signature[i]);
  }
  printf("\n");

  return EXIT_SUCCESS;
}