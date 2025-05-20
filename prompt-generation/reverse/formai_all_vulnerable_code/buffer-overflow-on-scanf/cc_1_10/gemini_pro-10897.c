//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the encryption key.
const char *key = "Ye olde secrete keye";

// Function to encrypt a file.
int encrypt_file(char *inputFile, char *outputFile) {
  // Open the input file.
  FILE *in = fopen(inputFile, "rb");
  if (in == NULL) {
    perror("Error opening input file");
    return -1;
  }

  // Open the output file.
  FILE *out = fopen(outputFile, "wb");
  if (out == NULL) {
    perror("Error opening output file");
    fclose(in);
    return -1;
  }

  // Read the input file one character at a time.
  int c;
  while ((c = fgetc(in)) != EOF) {
    // Apply the encryption key to the character.
    c ^= key[c % strlen(key)];

    // Write the encrypted character to the output file.
    fputc(c, out);
  }

  // Close the input and output files.
  fclose(in);
  fclose(out);

  return 0;
}

// Function to decrypt a file.
int decrypt_file(char *inputFile, char *outputFile) {
  // Open the input file.
  FILE *in = fopen(inputFile, "rb");
  if (in == NULL) {
    perror("Error opening input file");
    return -1;
  }

  // Open the output file.
  FILE *out = fopen(outputFile, "wb");
  if (out == NULL) {
    perror("Error opening output file");
    fclose(in);
    return -1;
  }

  // Read the input file one character at a time.
  int c;
  while ((c = fgetc(in)) != EOF) {
    // Apply the decryption key to the character.
    c ^= key[c % strlen(key)];

    // Write the decrypted character to the output file.
    fputc(c, out);
  }

  // Close the input and output files.
  fclose(in);
  fclose(out);

  return 0;
}

int main() {
  // Get the input and output file names from the user.
  char inputFile[100];
  char outputFile[100];
  printf("Enter the name of the input file: ");
  scanf("%s", inputFile);
  printf("Enter the name of the output file: ");
  scanf("%s", outputFile);

  // Encrypt the file.
  int err = encrypt_file(inputFile, outputFile);
  if (err != 0) {
    printf("Error encrypting file: %d\n", err);
    return err;
  }

  // Decrypt the file.
  err = decrypt_file(outputFile, inputFile);
  if (err != 0) {
    printf("Error decrypting file: %d\n", err);
    return err;
  }

  return 0;
}