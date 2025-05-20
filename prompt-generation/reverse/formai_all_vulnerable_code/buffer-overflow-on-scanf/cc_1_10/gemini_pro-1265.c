//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: random
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

// Function to encrypt a file
int encryptFile(char *fileName, char *password) {
  FILE *inputFile, *outputFile;
  int ch, i = 0;
  inputFile = fopen(fileName, "rb");
  if (inputFile == NULL) {
    printf("Error opening input file!\n");
    return 1;
  }
  outputFile = fopen("encrypted.txt", "wb");
  if (outputFile == NULL) {
    printf("Error opening output file!\n");
    return 1;
  }
  while ((ch = fgetc(inputFile)) != EOF) {
    fputc(ch ^ password[i++], outputFile);
    // Wrap around password if we reach the end
    if (i == strlen(password)) { i = 0; }
  }
  fclose(inputFile);
  fclose(outputFile);
  return 0;
}

// Function to decrypt a file
int decryptFile(char *fileName, char *password) {
  FILE *inputFile, *outputFile;
  int ch, i = 0;
  inputFile = fopen(fileName, "rb");
  if (inputFile == NULL) {
    printf("Error opening input file!\n");
    return 1;
  }
  outputFile = fopen("decrypted.txt", "wb");
  if (outputFile == NULL) {
    printf("Error opening output file!\n");
    return 1;
  }
  while ((ch = fgetc(inputFile)) != EOF) {
    fputc(ch ^ password[i++], outputFile);
    // Wrap around password if we reach the end
    if (i == strlen(password)) { i = 0; }
  }
  fclose(inputFile);
  fclose(outputFile);
  return 0;
}

// Function to get the file name and password from the user
void getInput(char *fileName, char *password) {
  printf("Enter the file name: ");
  scanf("%s", fileName);
  printf("Enter the password: ");
  scanf("%s", password);
}

// Function to print the menu
void printMenu() {
  printf("\nFile Encrypter/Decrypter\n");
  printf("-------------------------\n");
  printf("1. Encrypt a file\n");
  printf("2. Decrypt a file\n");
  printf("3. Exit\n");
  printf("Enter your choice: ");
}

// Main function
int main() {
  int choice;
  char fileName[100], password[100];
  do {
    printMenu();
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        getInput(fileName, password);
        if (encryptFile(fileName, password) == 0) {
          printf("File encrypted successfully!\n");
        }
        break;
      case 2:
        getInput(fileName, password);
        if (decryptFile(fileName, password) == 0) {
          printf("File decrypted successfully!\n");
        }
        break;
      case 3:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
    printf("\nPress any key to continue...");
    getchar();
    getchar();
    system(CLEAR);
  } while (choice != 3);
  return 0;
}