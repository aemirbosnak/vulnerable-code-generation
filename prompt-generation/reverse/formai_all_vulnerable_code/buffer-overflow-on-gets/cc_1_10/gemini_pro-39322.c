//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Declare variables
  FILE *inputFile;
  FILE *outputFile;
  char inputFileName[256];
  char outputFileName[256];
  char key[256];
  int keyLength;
  int i;

  // Get input file name from user
  printf("Enter the input file name: ");
  gets(inputFileName);

  // Get output file name from user
  printf("Enter the output file name: ");
  gets(outputFileName);

  // Get encryption key from user
  printf("Enter the encryption key: ");
  gets(key);

  // Calculate key length
  keyLength = strlen(key);

  // Open input file
  inputFile = fopen(inputFileName, "rb");
  if (inputFile == NULL) {
    printf("Error: Could not open input file %s\n", inputFileName);
    return 1;
  }

  // Open output file
  outputFile = fopen(outputFileName, "wb");
  if (outputFile == NULL) {
    printf("Error: Could not open output file %s\n", outputFileName);
    fclose(inputFile);
    return 1;
  }

  // Encrypt file
  while (!feof(inputFile)) {
    // Read a character from input file
    char c = fgetc(inputFile);

    // If end of file, break loop
    if (feof(inputFile)) {
      break;
    }

    // Encrypt character
    c ^= key[i % keyLength];

    // Write encrypted character to output file
    fputc(c, outputFile);

    // Increment key index
    i++;
  }

  // Close input file
  fclose(inputFile);

  // Close output file
  fclose(outputFile);

  // Print success message
  printf("File encrypted successfully\n");

  return 0;
}