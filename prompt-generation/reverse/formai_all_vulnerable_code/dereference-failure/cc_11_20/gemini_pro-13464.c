//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: systematic
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY_SIZE 32

int main(int argc, char **argv) {
  // Check if the user provided the correct number of arguments.
  if (argc != 3) {
    printf("Usage: %s <input file> <output file>\n", argv[0]);
    return 1;
  }

  // Open the input file.
  FILE *input = fopen(argv[1], "rb");
  if (!input) {
    perror("fopen");
    return 1;
  }

  // Open the output file.
  FILE *output = fopen(argv[2], "wb");
  if (!output) {
    perror("fopen");
    return 1;
  }

  // Generate a random key.
  unsigned char key[KEY_SIZE];
  if (RAND_bytes(key, KEY_SIZE) != 1) {
    perror("RAND_bytes");
    return 1;
  }

  // Create an AES-256-CBC cipher.
  AES_KEY aes;
  if (AES_set_encrypt_key(key, KEY_SIZE * 8, &aes) != 0) {
    perror("AES_set_encrypt_key");
    return 1;
  }

  // Create an initialization vector.
  unsigned char iv[AES_BLOCK_SIZE];
  if (RAND_bytes(iv, AES_BLOCK_SIZE) != 1) {
    perror("RAND_bytes");
    return 1;
  }

  // Write the initialization vector to the output file.
  if (fwrite(iv, 1, AES_BLOCK_SIZE, output) != AES_BLOCK_SIZE) {
    perror("fwrite");
    return 1;
  }

  // Encrypt the input file in chunks of AES_BLOCK_SIZE bytes.
  unsigned char buffer[AES_BLOCK_SIZE];
  while (1) {
    // Read a chunk of data from the input file.
    size_t bytes_read = fread(buffer, 1, AES_BLOCK_SIZE, input);
    if (bytes_read == 0) {
      break;
    }

    // Pad the chunk of data if it is not a multiple of AES_BLOCK_SIZE bytes.
    if (bytes_read < AES_BLOCK_SIZE) {
      memset(buffer + bytes_read, 0, AES_BLOCK_SIZE - bytes_read);
    }

    // Encrypt the chunk of data.
    AES_cbc_encrypt(buffer, buffer, bytes_read, &aes, iv, AES_ENCRYPT);

    // Write the encrypted chunk of data to the output file.
    if (fwrite(buffer, 1, bytes_read, output) != bytes_read) {
      perror("fwrite");
      return 1;
    }
  }

  // Close the input file.
  fclose(input);

  // Close the output file.
  fclose(output);

  return 0;
}