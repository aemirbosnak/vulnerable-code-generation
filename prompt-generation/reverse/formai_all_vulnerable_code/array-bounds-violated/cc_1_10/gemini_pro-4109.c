//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main()
{
  // Key and IV must be 16 bytes each for AES-128
  unsigned char key[] = "0123456789012345";
  unsigned char iv[] = "0123456789012345";

  // Plaintext and ciphertext buffers
  unsigned char plaintext[] = "Hello, world!";
  unsigned char ciphertext[128];

  // Create an encryption context
  EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
  if (ctx == NULL)
  {
    perror("EVP_CIPHER_CTX_new");
    return EXIT_FAILURE;
  }

  // Initialize the encryption context
  if (EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv) != 1)
  {
    perror("EVP_EncryptInit_ex");
    EVP_CIPHER_CTX_free(ctx);
    return EXIT_FAILURE;
  }

  // Encrypt the plaintext
  int ciphertext_len;
  if (EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintext, strlen(plaintext)) != 1)
  {
    perror("EVP_EncryptUpdate");
    EVP_CIPHER_CTX_free(ctx);
    return EXIT_FAILURE;
  }

  // Finalize the encryption
  if (EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len) != 1)
  {
    perror("EVP_EncryptFinal_ex");
    EVP_CIPHER_CTX_free(ctx);
    return EXIT_FAILURE;
  }

  // Print the ciphertext
  printf("Ciphertext: ");
  for (int i = 0; i < ciphertext_len; i++)
  {
    printf("%02x", ciphertext[i]);
  }
  printf("\n");

  // Decrypt the ciphertext
  if (EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv) != 1)
  {
    perror("EVP_DecryptInit_ex");
    EVP_CIPHER_CTX_free(ctx);
    return EXIT_FAILURE;
  }

  // Decrypt the ciphertext
  unsigned char decryptedtext[128];
  int decryptedtext_len;
  if (EVP_DecryptUpdate(ctx, decryptedtext, &decryptedtext_len, ciphertext, ciphertext_len) != 1)
  {
    perror("EVP_DecryptUpdate");
    EVP_CIPHER_CTX_free(ctx);
    return EXIT_FAILURE;
  }

  // Finalize the decryption
  if (EVP_DecryptFinal_ex(ctx, decryptedtext + decryptedtext_len, &decryptedtext_len) != 1)
  {
    perror("EVP_DecryptFinal_ex");
    EVP_CIPHER_CTX_free(ctx);
    return EXIT_FAILURE;
  }

  // Print the decrypted text
  printf("Decrypted text: %s\n", decryptedtext);

  // Clean up
  EVP_CIPHER_CTX_free(ctx);

  return EXIT_SUCCESS;
}