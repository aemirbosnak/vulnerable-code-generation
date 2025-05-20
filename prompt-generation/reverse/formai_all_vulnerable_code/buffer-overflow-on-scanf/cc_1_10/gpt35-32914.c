//FormAI DATASET v1.0 Category: File Encyptor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY 25

int main() {
  FILE *fp1; // Pointer to original file
  FILE *fp2; // Pointer to encrypted file

  char original_file[100]; // For input file name
  char encrypted_file[100]; // For output file name

  printf("Enter the name of the file you want to encrypt: ");
  scanf("%s", original_file);

  // Open the original file for reading in binary mode
  fp1 = fopen(original_file, "rb");

  if (fp1 == NULL) {
    printf("Error: Unable to open file\n");
    exit(1);
  }

  // Create the name for the encrypted file
  strcpy(encrypted_file, "encrypted_");
  strcat(encrypted_file, original_file);

  // Open the encrypted file for writing in binary mode
  fp2 = fopen(encrypted_file, "wb");

  if (fp2 == NULL) {
    printf("Error: Unable to create encrypted file\n");
    exit(1);
  }

  // Loop through every character in the file
  char ch;
  while (!feof(fp1)) {
    ch = fgetc(fp1);

    // Encrypt uppercase letters
    if (ch >= 'A' && ch <= 'Z') {
      ch = ((ch - 'A') + KEY) % 26 + 'A';
    }
    // Encrypt lowercase letters
    else if (ch >= 'a' && ch <= 'z') {
      ch = ((ch - 'a') + KEY) % 26 + 'a';
    }
    // Leave spaces and special characters untouched
    else {
      ch = ch;
    }

    // Write the encrypted character to the encrypted file
    fputc(ch, fp2);
  }

  // Close the files
  fclose(fp1);
  fclose(fp2);

  printf("File has been encrypted and saved as %s\n", encrypted_file);

  return 0;
}