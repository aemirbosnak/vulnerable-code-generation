//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Function to encrypt a file
int encryptFile(char *fileName, char *key) {
  // Open the file to be encrypted
  FILE *file = fopen(fileName, "rb");
  if (file == NULL) {
    printf("Error opening file %s\n", fileName);
    return -1;
  }

  // Get the file size
  fseek(file, 0, SEEK_END);
  long fileSize = ftell(file);
  rewind(file);

  // Allocate memory for the encrypted file
  char *encryptedFile = malloc(fileSize);
  if (encryptedFile == NULL) {
    printf("Error allocating memory for encrypted file\n");
    fclose(file);
    return -1;
  }

  // Read the file into the memory
  fread(encryptedFile, 1, fileSize, file);
  fclose(file);

  // Encrypt the file using the key
  for (long i = 0; i < fileSize; i++) {
    encryptedFile[i] ^= key[i % strlen(key)];
  }

  // Open the encrypted file for writing
  FILE *encryptedFilePtr = fopen("encrypted.bin", "wb");
  if (encryptedFilePtr == NULL) {
    printf("Error opening encrypted file\n");
    free(encryptedFile);
    return -1;
  }

  // Write the encrypted file to disk
  fwrite(encryptedFile, 1, fileSize, encryptedFilePtr);
  fclose(encryptedFilePtr);

  // Free the memory allocated for the encrypted file
  free(encryptedFile);

  return 0;
}

// Function to decrypt a file
int decryptFile(char *fileName, char *key) {
  // Open the encrypted file
  FILE *encryptedFile = fopen(fileName, "rb");
  if (encryptedFile == NULL) {
    printf("Error opening encrypted file %s\n", fileName);
    return -1;
  }

  // Get the file size
  fseek(encryptedFile, 0, SEEK_END);
  long fileSize = ftell(encryptedFile);
  rewind(encryptedFile);

  // Allocate memory for the decrypted file
  char *decryptedFile = malloc(fileSize);
  if (decryptedFile == NULL) {
    printf("Error allocating memory for decrypted file\n");
    fclose(encryptedFile);
    return -1;
  }

  // Read the encrypted file into the memory
  fread(decryptedFile, 1, fileSize, encryptedFile);
  fclose(encryptedFile);

  // Decrypt the file using the key
  for (long i = 0; i < fileSize; i++) {
    decryptedFile[i] ^= key[i % strlen(key)];
  }

  // Open the decrypted file for writing
  FILE *decryptedFilePtr = fopen("decrypted.bin", "wb");
  if (decryptedFilePtr == NULL) {
    printf("Error opening decrypted file\n");
    free(decryptedFile);
    return -1;
  }

  // Write the decrypted file to disk
  fwrite(decryptedFile, 1, fileSize, decryptedFilePtr);
  fclose(decryptedFilePtr);

  // Free the memory allocated for the decrypted file
  free(decryptedFile);

  return 0;
}

int main() {
  // Get the file name and key from the user
  char fileName[256];
  printf("Enter the file name to be encrypted: ");
  scanf("%s", fileName);

  char key[256];
  printf("Enter the encryption key: ");
  scanf("%s", key);

  // Encrypt the file
  int result = encryptFile(fileName, key);
  if (result != 0) {
    printf("Error encrypting file\n");
    return -1;
  }

  printf("File encrypted successfully\n");

  // Decrypt the file
  result = decryptFile("encrypted.bin", key);
  if (result != 0) {
    printf("Error decrypting file\n");
    return -1;
  }

  printf("File decrypted successfully\n");

  return 0;
}