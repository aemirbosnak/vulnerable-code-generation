//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: post-apocalyptic
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Post-apocalyptic theme
#define ENCRYPT_PASS "Overseer"
#define ENCRYPTED_FILE "vault76.dat"
#define DECRYPTED_FILE "dweller.txt"

// Function to generate a random number
int rand_num() {
  srand(time(NULL));
  return rand();
}

// Function to encrypt a file
void encrypt(char *plaintext, char *key, char *ciphertext) {
  int keylen = strlen(key);
  int i, j;
  for (i = 0, j = 0; plaintext[i] != '\0'; i++, j++) {
    if (j == keylen) j = 0;
    ciphertext[i] = plaintext[i] ^ key[j];
  }
  ciphertext[i] = '\0';
}

// Function to decrypt a file
void decrypt(char *ciphertext, char *key, char *plaintext) {
  int keylen = strlen(key);
  int i, j;
  for (i = 0, j = 0; ciphertext[i] != '\0'; i++, j++) {
    if (j == keylen) j = 0;
    plaintext[i] = ciphertext[i] ^ key[j];
  }
  plaintext[i] = '\0';
}

int main() {
  // Read the plaintext from a file
  FILE *plaintext_file = fopen("plaintext.txt", "r");
  if (plaintext_file == NULL) {
    printf("Error opening plaintext file.\n");
    return 1;
  }

  fseek(plaintext_file, 0L, SEEK_END);
  int plaintext_len = ftell(plaintext_file);
  rewind(plaintext_file);

  char *plaintext = malloc(plaintext_len + 1);
  if (plaintext == NULL) {
    printf("Error allocating memory for plaintext.\n");
    return 1;
  }

  fread(plaintext, plaintext_len, 1, plaintext_file);
  fclose(plaintext_file);

  // Generate a random key
  char key[rand_num() % 100 + 1];
  for (int i = 0; i < strlen(key); i++) {
    key[i] = rand_num() % 256;
  }

  // Encrypt the plaintext
  char *ciphertext = malloc(plaintext_len + 1);
  if (ciphertext == NULL) {
    printf("Error allocating memory for ciphertext.\n");
    return 1;
  }

  encrypt(plaintext, key, ciphertext);
  free(plaintext);

  // Write the ciphertext to a file
  FILE *ciphertext_file = fopen(ENCRYPTED_FILE, "w");
  if (ciphertext_file == NULL) {
    printf("Error opening ciphertext file.\n");
    return 1;
  }

  fwrite(ciphertext, plaintext_len, 1, ciphertext_file);
  fclose(ciphertext_file);
  free(ciphertext);

  // Decrypt the ciphertext
  char *decrypted_plaintext = malloc(plaintext_len + 1);
  if (decrypted_plaintext == NULL) {
    printf("Error allocating memory for decrypted plaintext.\n");
    return 1;
  }

  decrypt(ciphertext, key, decrypted_plaintext);

  // Write the decrypted plaintext to a file
  FILE *decrypted_plaintext_file = fopen(DECRYPTED_FILE, "w");
  if (decrypted_plaintext_file == NULL) {
    printf("Error opening decrypted plaintext file.\n");
    return 1;
  }

  fwrite(decrypted_plaintext, plaintext_len, 1, decrypted_plaintext_file);
  fclose(decrypted_plaintext_file);
  free(decrypted_plaintext);

  printf("Encryption and decryption complete.\n");

  return 0;
}