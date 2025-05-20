//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to copy a file
int copyFile(char *src, char *dest) {
  // Open the source file
  FILE *fptr1 = fopen(src, "r");
  if (fptr1 == NULL) {
    printf("Error opening source file!\n");
    return -1;
  }

  // Open the destination file
  FILE *fptr2 = fopen(dest, "w");
  if (fptr2 == NULL) {
    printf("Error opening destination file!\n");
    fclose(fptr1);
    return -1;
  }

  // Copy the contents of the source file to the destination file
  char ch;
  while ((ch = fgetc(fptr1)) != EOF) {
    fputc(ch, fptr2);
  }

  // Close the files
  fclose(fptr1);
  fclose(fptr2);

  return 0;
}

// Function to create a backup of a file
int createBackup(char *filename) {
  // Create a backup filename
  char backupFilename[strlen(filename) + 5];
  strcpy(backupFilename, filename);
  strcat(backupFilename, ".bak");

  // Copy the file to the backup filename
  if (copyFile(filename, backupFilename) == -1) {
    return -1;
  }

  return 0;
}

// Main function
int main() {
  // Get the filename from the user
  char filename[50];
  printf("Enter the filename: ");
  scanf("%s", filename);

  // Create a backup of the file
  if (createBackup(filename) == -1) {
    printf("Error creating backup!\n");
    return -1;
  }

  printf("Backup created successfully!\n");

  return 0;
}