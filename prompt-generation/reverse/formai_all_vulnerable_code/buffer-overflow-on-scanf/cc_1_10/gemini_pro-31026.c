//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A secret key to encrypt and decrypt the file
const char *SECRET_KEY = "Secret Key";

// Function to encrypt a file
void encryptFile(char *inputFileName, char *outputFileName) {
  // Open the input file in read mode
  FILE *inputFile = fopen(inputFileName, "rb");
  if (inputFile == NULL) {
    perror("Error opening input file");
    return;
  }

  // Open the output file in write mode
  FILE *outputFile = fopen(outputFileName, "wb");
  if (outputFile == NULL) {
    perror("Error opening output file");
    fclose(inputFile);
    return;
  }

  // Get the file size
  fseek(inputFile, 0, SEEK_END);
  long fileSize = ftell(inputFile);
  rewind(inputFile);

  // Create a buffer to store the encrypted data
  char *buffer = (char *)malloc(fileSize);
  if (buffer == NULL) {
    perror("Error allocating memory");
    fclose(inputFile);
    fclose(outputFile);
    return;
  }

  // Read the file contents into the buffer
  size_t bytesRead = fread(buffer, 1, fileSize, inputFile);
  if (bytesRead != fileSize) {
    perror("Error reading input file");
    fclose(inputFile);
    fclose(outputFile);
    free(buffer);
    return;
  }

  // Encrypt the buffer using the secret key
  int keyLength = strlen(SECRET_KEY);
  for (long i = 0; i < fileSize; i++) {
    buffer[i] ^= SECRET_KEY[i % keyLength];
  }

  // Write the encrypted data to the output file
  size_t bytesWritten = fwrite(buffer, 1, fileSize, outputFile);
  if (bytesWritten != fileSize) {
    perror("Error writing output file");
    fclose(inputFile);
    fclose(outputFile);
    free(buffer);
    return;
  }

  // Cleanup
  fclose(inputFile);
  fclose(outputFile);
  free(buffer);

  printf("\nFile encrypted successfully!\n");
}

// Function to decrypt a file
void decryptFile(char *inputFileName, char *outputFileName) {
  // Open the input file in read mode
  FILE *inputFile = fopen(inputFileName, "rb");
  if (inputFile == NULL) {
    perror("Error opening input file");
    return;
  }

  // Open the output file in write mode
  FILE *outputFile = fopen(outputFileName, "wb");
  if (outputFile == NULL) {
    perror("Error opening output file");
    fclose(inputFile);
    return;
  }

  // Get the file size
  fseek(inputFile, 0, SEEK_END);
  long fileSize = ftell(inputFile);
  rewind(inputFile);

  // Create a buffer to store the decrypted data
  char *buffer = (char *)malloc(fileSize);
  if (buffer == NULL) {
    perror("Error allocating memory");
    fclose(inputFile);
    fclose(outputFile);
    return;
  }

  // Read the file contents into the buffer
  size_t bytesRead = fread(buffer, 1, fileSize, inputFile);
  if (bytesRead != fileSize) {
    perror("Error reading input file");
    fclose(inputFile);
    fclose(outputFile);
    free(buffer);
    return;
  }

  // Decrypt the buffer using the secret key
  int keyLength = strlen(SECRET_KEY);
  for (long i = 0; i < fileSize; i++) {
    buffer[i] ^= SECRET_KEY[i % keyLength];
  }

  // Write the decrypted data to the output file
  size_t bytesWritten = fwrite(buffer, 1, fileSize, outputFile);
  if (bytesWritten != fileSize) {
    perror("Error writing output file");
    fclose(inputFile);
    fclose(outputFile);
    free(buffer);
    return;
  }

  // Cleanup
  fclose(inputFile);
  fclose(outputFile);
  free(buffer);

  printf("\nFile decrypted successfully!\n");
}

int main() {
  // Get the input and output file names from the user
  char inputFileName[100], outputFileName[100];
  printf("Enter the input file name: ");
  scanf("%s", inputFileName);
  printf("Enter the output file name: ");
  scanf("%s", outputFileName);

  // Encrypt the file
  encryptFile(inputFileName, outputFileName);

  // Decrypt the file
  decryptFile(outputFileName, "decrypted_file.txt");

  return 0;
}