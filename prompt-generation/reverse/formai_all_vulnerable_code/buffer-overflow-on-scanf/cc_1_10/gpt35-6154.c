//FormAI DATASET v1.0 Category: File Encyptor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1048576 // 1 MB

void encryptFile(char* fileName) {
  // open file
  FILE* file = fopen(fileName, "rb");
  if (file == NULL) {
    printf("Error: could not open file %s\n", fileName);
    return;
  }

  // get file size
  fseek(file, 0L, SEEK_END);
  long fileSize = ftell(file);
  fseek(file, 0L, SEEK_SET);

  // read file contents into buffer
  char* fileContents = malloc(MAX_FILE_SIZE);
  fread(fileContents, fileSize, 1, file);

  // generate random encryption key
  srand(time(NULL));
  char encryptionKey[10];
  for (int i = 0; i < 10; i++) {
    encryptionKey[i] = rand() % 256;
  }

  // encrypt file contents with encryption key
  for (int i = 0; i < fileSize; i++) {
    fileContents[i] = fileContents[i] ^ encryptionKey[i % 10];
  }

  // create new encrypted file with .enc extension
  char encryptedFileName[strlen(fileName) + 5];
  strcpy(encryptedFileName, fileName);
  strcat(encryptedFileName, ".enc");
  FILE* encryptedFile = fopen(encryptedFileName, "wb");
  if (encryptedFile == NULL) {
    printf("Error: could not create encrypted file %s\n", encryptedFileName);
    return;
  }

  // write encrypted file contents
  fwrite(fileContents, fileSize, 1, encryptedFile);

  // write encryption key to file
  fwrite(encryptionKey, sizeof(encryptionKey), 1, encryptedFile);

  // close files and free memory
  fclose(file);
  fclose(encryptedFile);
  free(fileContents);

  printf("File %s encrypted successfully with key: ", fileName);
  for (int i = 0; i < 10; i++) {
    printf("%02X", encryptionKey[i]);
  }
  printf("\n");
}

void decryptFile(char* fileName, char* key) {
  // open file
  FILE* file = fopen(fileName, "rb");
  if (file == NULL) {
    printf("Error: could not open file %s\n", fileName);
    return;
  }

  // get file size
  fseek(file, 0L, SEEK_END);
  long fileSize = ftell(file) - 10; // last 10 bytes are encryption key
  fseek(file, 0L, SEEK_SET);

  // read file contents into buffer
  char* fileContents = malloc(MAX_FILE_SIZE);
  fread(fileContents, fileSize, 1, file);

  // read encryption key from file
  char encryptionKey[10];
  fread(encryptionKey, sizeof(encryptionKey), 1, file);
  if (strcmp(key, "") != 0 && memcmp(encryptionKey, key, sizeof(encryptionKey)) != 0) {
    printf("Error: incorrect encryption key\n");
    return;
  }

  // decrypt file contents with encryption key
  for (int i = 0; i < fileSize; i++) {
    fileContents[i] = fileContents[i] ^ encryptionKey[i % 10];
  }

  // create new decrypted file with .dec extension
  char decryptedFileName[strlen(fileName) + 5];
  strcpy(decryptedFileName, fileName);
  strcat(decryptedFileName, ".dec");
  FILE* decryptedFile = fopen(decryptedFileName, "wb");
  if (decryptedFile == NULL) {
    printf("Error: could not create decrypted file %s\n", decryptedFileName);
    return;
  }

  // write decrypted file contents
  fwrite(fileContents, fileSize, 1, decryptedFile);

  // close files and free memory
  fclose(file);
  fclose(decryptedFile);
  free(fileContents);

  printf("File %s decrypted successfully\n", fileName);
}

int main() {
  printf("Welcome to the post-apocalyptic C file encryptor!\n");

  // get file name
  char fileName[256];
  printf("Enter the name of the file to encrypt/decrypt: ");
  scanf("%s", fileName);

  // get operation (encrypt/decrypt)
  char operation[10];
  printf("Enter the operation to perform (encrypt/decrypt): ");
  scanf("%s", operation);

  if (strcmp(operation, "encrypt") == 0) {
    encryptFile(fileName);
  } else if (strcmp(operation, "decrypt") == 0) {
    // get encryption key
    char key[20];
    printf("Enter the encryption key (leave blank if none): ");
    scanf("%s", key);
    decryptFile(fileName, key);
  } else {
    printf("Error: invalid operation\n");
  }

  return 0;
}