//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define SECRET_KEY "F0054r31!"

int main() {
  char filename[100];
  char password[100];
  int choice;

  srand(time(NULL));

  // Welcome the user to the program
  printf("\n*********************************************************************************************************");
  printf("\n*                                                                                                       *");
  printf("\n*  Welcome to the C File Encryption Program. This program will help you encrypt and decrypt your files securely. *");
  printf("\n*                                                                                                       *");
  printf("\n*********************************************************************************************************");

  // Get the user's choice
  printf("\n\nPlease choose an option:\n");
  printf("1. Encrypt a file\n");
  printf("2. Decrypt a file\n");
  printf("3. Quit\n");
  printf("\nChoice: ");
  scanf("%d", &choice);

  // Encrypt a file
  if (choice == 1) {
    printf("\nEnter the filename of the file you want to encrypt: ");
    scanf("%s", filename);
    printf("\nEnter the password for the encryption: ");
    scanf("%s", password);

    // Open the file to be encrypted
    FILE *inputFile = fopen(filename, "rb");
    if (inputFile == NULL) {
      printf("Error: Could not open the file %s", filename);
      return 1;
    }

    // Get the size of the file
    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    rewind(inputFile);

    // Allocate memory for the encrypted file
    char *encryptedFile = (char *)malloc(fileSize);
    if (encryptedFile == NULL) {
      printf("Error: Could not allocate memory for the encrypted file");
      return 1;
    }

    // Encrypt the file
    int i;
    for (i = 0; i < fileSize; i++) {
      encryptedFile[i] = fgetc(inputFile) ^ SECRET_KEY[i % strlen(SECRET_KEY)];
    }

    // Close the input file
    fclose(inputFile);

    // Open the file to be written
    FILE *outputFile = fopen("encrypted.txt", "wb");
    if (outputFile == NULL) {
      printf("Error: Could not open the file encrypted.txt");
      return 1;
    }

    // Write the encrypted file to disk
    fwrite(encryptedFile, fileSize, 1, outputFile);

    // Close the output file
    fclose(outputFile);

    // Free the memory allocated for the encrypted file
    free(encryptedFile);

    // Print a success message
    printf("\nThe file %s has been encrypted successfully.\n", filename);
  }

  // Decrypt a file
  else if (choice == 2) {
    printf("\nEnter the filename of the file you want to decrypt: ");
    scanf("%s", filename);
    printf("\nEnter the password for the decryption: ");
    scanf("%s", password);

    // Open the file to be decrypted
    FILE *inputFile = fopen(filename, "rb");
    if (inputFile == NULL) {
      printf("Error: Could not open the file %s", filename);
      return 1;
    }

    // Get the size of the file
    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    rewind(inputFile);

    // Allocate memory for the decrypted file
    char *decryptedFile = (char *)malloc(fileSize);
    if (decryptedFile == NULL) {
      printf("Error: Could not allocate memory for the decrypted file");
      return 1;
    }

    // Decrypt the file
    int i;
    for (i = 0; i < fileSize; i++) {
      decryptedFile[i] = fgetc(inputFile) ^ SECRET_KEY[i % strlen(SECRET_KEY)];
    }

    // Close the input file
    fclose(inputFile);

    // Open the file to be written
    FILE *outputFile = fopen("decrypted.txt", "wb");
    if (outputFile == NULL) {
      printf("Error: Could not open the file decrypted.txt");
      return 1;
    }

    // Write the decrypted file to disk
    fwrite(decryptedFile, fileSize, 1, outputFile);

    // Close the output file
    fclose(outputFile);

    // Free the memory allocated for the decrypted file
    free(decryptedFile);

    // Print a success message
    printf("\nThe file %s has been decrypted successfully.\n", filename);
  }

  // Quit the program
  else if (choice == 3) {
    printf("\nThank you for using the C File Encryption Program. Goodbye!\n");
    return 0;
  }

  // Invalid choice
  else {
    printf("\nInvalid choice. Please choose a valid option.\n");
  }

  return 0;
}