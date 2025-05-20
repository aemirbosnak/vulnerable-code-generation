//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Custom hash function using SHA-256 and a salt value
unsigned char* custom_hash(const char* input, const char* salt) {
  unsigned char* hash = malloc(SHA256_DIGEST_LENGTH);
  if (hash == NULL) {
    return NULL;
  }
  
  // Create a SHA-256 context
  SHA256_CTX ctx;
  SHA256_Init(&ctx);

  // Update the context with the input and salt
  SHA256_Update(&ctx, input, strlen(input));
  SHA256_Update(&ctx, salt, strlen(salt));

  // Finalize the context and get the hash
  SHA256_Final(hash, &ctx);
  
  return hash;
}

int main() {
  // Get the input string from the user
  char input[1024];
  printf("Enter the string to hash: ");
  scanf("%s", input);

  // Get the salt value from the user
  char salt[1024];
  printf("Enter the salt value: ");
  scanf("%s", salt);

  // Compute the hash using the custom function
  unsigned char* hash = custom_hash(input, salt);
  if (hash == NULL) {
    printf("Error computing hash.\n");
    return EXIT_FAILURE;
  }

  // Print the hash
  printf("Hash: ");
  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    printf("%02x", hash[i]);
  }
  printf("\n");

  // Free the allocated memory
  free(hash);

  return EXIT_SUCCESS;
}