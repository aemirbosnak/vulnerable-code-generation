//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "abracadabra"

// Function to encrypt a file
void encryptFile(FILE *inputFile, FILE *outputFile) {
  char buffer[1024];
  int keyLen = strlen(KEY);
  int i, j;

  // Read the file contents into a buffer
  while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
    // Encrypt the buffer using the XOR cipher
    for (i = 0; i < strlen(buffer); i++) {
      j = i % keyLen;
      buffer[i] ^= KEY[j];
    }

    // Write the encrypted buffer to the output file
    fwrite(buffer, strlen(buffer), 1, outputFile);
  }
}

// Function to decrypt a file
void decryptFile(FILE *inputFile, FILE *outputFile) {
  char buffer[1024];
  int keyLen = strlen(KEY);
  int i, j;

  // Read the file contents into a buffer
  while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
    // Decrypt the buffer using the XOR cipher
    for (i = 0; i < strlen(buffer); i++) {
      j = i % keyLen;
      buffer[i] ^= KEY[j];
    }

    // Write the decrypted buffer to the output file
    fwrite(buffer, strlen(buffer), 1, outputFile);
  }
}

// Main function
int main(int argc, char *argv[]) {
  FILE *inputFile, *outputFile;
  char inputFileName[100], outputFileName[100];

  // Get the input and output file names from the user
  printf("Enter the name of the file to encrypt: ");
  scanf("%s", inputFileName);
  printf("Enter the name of the output file: ");
  scanf("%s", outputFileName);

  // Open the input and output files
  inputFile = fopen(inputFileName, "r");
  if (inputFile == NULL) {
    printf("Error opening the input file!\n");
    return -1;
  }
  outputFile = fopen(outputFileName, "w");
  if (outputFile == NULL) {
    printf("Error opening the output file!\n");
    return -1;
  }

  // Encrypt the file
  encryptFile(inputFile, outputFile);

  // Close the input and output files
  fclose(inputFile);
  fclose(outputFile);

  printf("File encrypted successfully!\n");

  // Open the output file again for decryption
  outputFile = fopen(outputFileName, "r");
  if (outputFile == NULL) {
    printf("Error opening the output file!\n");
    return -1;
  }

  // Decrypt the file
  decryptFile(outputFile, stdout);

  // Close the output file
  fclose(outputFile);

  printf("File decrypted successfully!\n");

  return 0;
}