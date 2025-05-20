//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: mathematical
// C File Backup System Example

// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

// Mathematical Constants
#define PI 3.141592653589793
#define E 2.718281828459045

// Function Prototypes
void backupFile(char *fileName, char *backupFileName);
void restoreFile(char *backupFileName, char *fileName);
void generateChecksum(char *fileName, unsigned long *checksum);
int compareChecksums(unsigned long checksum1, unsigned long checksum2);

// Main Function
int main() {
  // Initialize Variables
  char fileName[100], backupFileName[100];
  unsigned long checksum1, checksum2;
  int choice;

  // Get User Input
  printf("Enter the name of the file to be backed up: ");
  scanf("%s", fileName);
  printf("Enter the name of the backup file: ");
  scanf("%s", backupFileName);

  // Get User Choice
  printf("1. Backup File\n2. Restore File\n");
  scanf("%d", &choice);

  // Perform Action Based on User Choice
  switch (choice) {
    case 1:
      // Backup File
      printf("Backing up file...\n");
      backupFile(fileName, backupFileName);
      printf("File backed up successfully.\n");
      break;
    case 2:
      // Restore File
      printf("Restoring file...\n");
      restoreFile(backupFileName, fileName);
      printf("File restored successfully.\n");
      break;
  }

  // Calculate Checksums
  printf("Calculating checksums...\n");
  generateChecksum(fileName, &checksum1);
  generateChecksum(backupFileName, &checksum2);

  // Compare Checksums
  printf("Comparing checksums...\n");
  if (compareChecksums(checksum1, checksum2)) {
    printf("Checksums match. Backup is valid.\n");
  } else {
    printf("Checksums do not match. Backup is corrupted.\n");
  }

  return 0;
}

// Function to Backup File
void backupFile(char *fileName, char *backupFileName) {
  // Open Input and Output Files
  FILE *inputFile = fopen(fileName, "rb");
  FILE *outputFile = fopen(backupFileName, "wb");

  // Check if Files Opened Successfully
  if (inputFile == NULL || outputFile == NULL) {
    perror("Error opening files");
    exit(1);
  }

  // Copy File Contents
  char buffer[1024];
  size_t bytesRead;
  while ((bytesRead = fread(buffer, 1, 1024, inputFile)) > 0) {
    fwrite(buffer, 1, bytesRead, outputFile);
  }

  // Close Files
  fclose(inputFile);
  fclose(outputFile);
}


// Function to Restore File
void restoreFile(char *backupFileName, char *fileName) {
  // Open Input and Output Files
  FILE *inputFile = fopen(backupFileName, "rb");
  FILE *outputFile = fopen(fileName, "wb");

  // Check if Files Opened Successfully
  if (inputFile == NULL || outputFile == NULL) {
    perror("Error opening files");
    exit(1);
  }

  // Copy File Contents
  char buffer[1024];
  size_t bytesRead;
  while ((bytesRead = fread(buffer, 1, 1024, inputFile)) > 0) {
    fwrite(buffer, 1, bytesRead, outputFile);
  }

  // Close Files
  fclose(inputFile);
  fclose(outputFile);
}

// Function to Generate Checksum
void generateChecksum(char *fileName, unsigned long *checksum) {
  // Open File
  FILE *file = fopen(fileName, "rb");

  // Check if File Opened Successfully
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Calculate Checksum
  unsigned long sum = 0;
  char buffer[1024];
  size_t bytesRead;
  while ((bytesRead = fread(buffer, 1, 1024, file)) > 0) {
    for (int i = 0; i < bytesRead; i++) {
      sum += buffer[i];
    }
  }

  // Close File
  fclose(file);

  *checksum = sum;
}

// Function to Compare Checksums
int compareChecksums(unsigned long checksum1, unsigned long checksum2) {
  return checksum1 == checksum2;
}