//GEMINI-pro DATASET v1.0 Category: Password management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Define the maximum length of a password.
#define MAX_PASSWORD_LENGTH 100

// Define the number of iterations to use when hashing the password.
#define NUM_HASH_ITERATIONS 10000

// Define the salt size in bytes.
#define SALT_SIZE 16

// Function to generate a random salt.
void generate_salt(unsigned char *salt) {
  // Seed the random number generator.
  srand(time(NULL));

  // Generate a random salt.
  for (int i = 0; i < SALT_SIZE; i++) {
    salt[i] = rand() % 256;
  }
}

// Function to hash a password using SHA-256.
void hash_password(const char *password, unsigned char *hash) {
  // Create a SHA-256 context.
  SHA256_CTX ctx;
  SHA256_Init(&ctx);

  // Add the password to the context.
  SHA256_Update(&ctx, password, strlen(password));

  // Finalize the context and get the hash.
  SHA256_Final(hash, &ctx);
}

// Function to verify a password.
int verify_password(const char *password, unsigned char *hash, unsigned char *salt) {
  // Create a SHA-256 context.
  SHA256_CTX ctx;
  SHA256_Init(&ctx);

  // Add the password and salt to the context.
  SHA256_Update(&ctx, password, strlen(password));
  SHA256_Update(&ctx, salt, SALT_SIZE);

  // Finalize the context and get the hash.
  unsigned char new_hash[SHA256_DIGEST_LENGTH];
  SHA256_Final(new_hash, &ctx);

  // Compare the new hash to the stored hash.
  return memcmp(new_hash, hash, SHA256_DIGEST_LENGTH) == 0;
}

// Main function.
int main() {
  // Get the password from the user.
  char password[MAX_PASSWORD_LENGTH];
  printf("Enter your password: ");
  scanf("%s", password);

  // Generate a random salt.
  unsigned char salt[SALT_SIZE];
  generate_salt(salt);

  // Hash the password using SHA-256.
  unsigned char hash[SHA256_DIGEST_LENGTH];
  hash_password(password, hash);

  // Store the hash and salt in a database.

  // Later, when the user wants to log in, get the password from the user.
  char login_password[MAX_PASSWORD_LENGTH];
  printf("Enter your password to log in: ");
  scanf("%s", login_password);

  // Get the hash and salt from the database.

  // Verify the password.
  int is_valid = verify_password(login_password, hash, salt);

  // If the password is valid, log the user in.
  if (is_valid) {
    printf("You have successfully logged in.\n");
  } else {
    printf("Invalid password.\n");
  }

  return 0;
}