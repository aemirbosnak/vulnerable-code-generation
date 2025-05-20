//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Declaring a function to encrypt the file
int encryptFile(char *fileName) {
  // Opening the input file in read mode
  FILE *inputFile = fopen(fileName, "r");
  if (inputFile == NULL) {
    printf("Error opening the input file!\n");
    return -1;
  }

  // Opening the output file in write mode
  FILE *outputFile = fopen("encrypted.txt", "w");
  if (outputFile == NULL) {
    printf("Error opening the output file!\n");
    fclose(inputFile);
    return -1;
  }

  // Reading the input file character by character
  char ch;
  while ((ch = fgetc(inputFile)) != EOF) {
    // Encrypting the character
    ch = ch + 5;

    // Writing the encrypted character to the output file
    fputc(ch, outputFile);
  }

  // Closing the input and output files
  fclose(inputFile);
  fclose(outputFile);

  printf("File encrypted successfully!\n");
  return 0;
}

// Declaring a function to decrypt the file
int decryptFile(char *fileName) {
  // Opening the input file in read mode
  FILE *inputFile = fopen(fileName, "r");
  if (inputFile == NULL) {
    printf("Error opening the input file!\n");
    return -1;
  }

  // Opening the output file in write mode
  FILE *outputFile = fopen("decrypted.txt", "w");
  if (outputFile == NULL) {
    printf("Error opening the output file!\n");
    fclose(inputFile);
    return -1;
  }

  // Reading the input file character by character
  char ch;
  while ((ch = fgetc(inputFile)) != EOF) {
    // Decrypting the character
    ch = ch - 5;

    // Writing the decrypted character to the output file
    fputc(ch, outputFile);
  }

  // Closing the input and output files
  fclose(inputFile);
  fclose(outputFile);

  printf("File decrypted successfully!\n");
  return 0;
}

int main() {
  // Getting the input file name from the user
  char fileName[50];
  printf("Enter the name of the file to be encrypted: ");
  scanf("%s", fileName);

  // Encrypting the file
  if (encryptFile(fileName) == -1) {
    printf("Error encrypting the file!\n");
    return -1;
  }

  // Decrypting the file
  if (decryptFile("encrypted.txt") == -1) {
    printf("Error decrypting the file!\n");
    return -1;
  }

  return 0;
}