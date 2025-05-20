//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A secret key for XOR encryption
#define KEY 0x42

// A function to encrypt a file
void encrypt(char *filename) {
  // Open the file
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    perror("Error opening file");
    return;
  }

  // Get the file size
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  rewind(file);

  // Allocate a buffer to hold the encrypted data
  char *buffer = malloc(size);
  if (buffer == NULL) {
    perror("Error allocating buffer");
    return;
  }

  // Read the file into the buffer
  fread(buffer, 1, size, file);

  // Encrypt the buffer
  for (int i = 0; i < size; i++) {
    buffer[i] ^= KEY;
  }

  // Write the encrypted data to a new file
  FILE *outfile = fopen("encrypted.txt", "wb");
  if (outfile == NULL) {
    perror("Error opening output file");
    return;
  }

  fwrite(buffer, 1, size, outfile);

  // Close the files
  fclose(file);
  fclose(outfile);

  // Free the buffer
  free(buffer);
}

// A function to decrypt a file
void decrypt(char *filename) {
  // Open the file
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    perror("Error opening file");
    return;
  }

  // Get the file size
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  rewind(file);

  // Allocate a buffer to hold the decrypted data
  char *buffer = malloc(size);
  if (buffer == NULL) {
    perror("Error allocating buffer");
    return;
  }

  // Read the file into the buffer
  fread(buffer, 1, size, file);

  // Decrypt the buffer
  for (int i = 0; i < size; i++) {
    buffer[i] ^= KEY;
  }

  // Write the decrypted data to a new file
  FILE *outfile = fopen("decrypted.txt", "wb");
  if (outfile == NULL) {
    perror("Error opening output file");
    return;
  }

  fwrite(buffer, 1, size, outfile);

  // Close the files
  fclose(file);
  fclose(outfile);

  // Free the buffer
  free(buffer);
}

int main() {
  // Get the filename from the user
  char filename[100];
  printf("Enter the filename to encrypt: ");
  scanf("%s", filename);

  // Encrypt the file
  encrypt(filename);

  // Decrypt the file
  decrypt("encrypted.txt");

  return 0;
}