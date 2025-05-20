//FormAI DATASET v1.0 Category: File Encyptor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define DATA_BLOCK_SIZE 8

// Function to encrypt the given data
void encryptData(unsigned char *dataBlock, unsigned char *key) {
  // Applying XOR operation on each byte of the data block using the key
  for(int i = 0; i < DATA_BLOCK_SIZE; i++) {
    dataBlock[i] ^= key[i];
  }
}

// Function to generate a random key
void generateKey(unsigned char *key) {
  for(int i = 0; i < DATA_BLOCK_SIZE; i++) {
    key[i] = rand() % 256;
  }
}

int main() {
  char fileName[MAX_LENGTH];

  printf("Enter the name of the file to encrypt: ");
  scanf("%s", fileName);

  FILE *fp = fopen(fileName, "rb");
  if(fp == NULL) {
    printf("Error: Could not open file %s", fileName);
    exit(1);
  }

  unsigned char key[DATA_BLOCK_SIZE];
  generateKey(key);

  // Creating a new file with the .enc extension
  char encryptedFileName[MAX_LENGTH];
  strcpy(encryptedFileName, fileName);
  strcat(encryptedFileName, ".enc");

  FILE *fpEncrypted = fopen(encryptedFileName, "wb");
  if(fpEncrypted == NULL) {
    printf("Error: Could not create encrypted file");
    exit(1);
  }

  unsigned char dataBlock[DATA_BLOCK_SIZE];
  int bytesRead = 0;

  // Reading in data blocks of size DATA_BLOCK_SIZE from the file
  while((bytesRead = fread(dataBlock, sizeof(unsigned char), DATA_BLOCK_SIZE, fp)) > 0) {
    // If the last block read was not of size DATA_BLOCK_SIZE, padding it with zeroes
    if(bytesRead < DATA_BLOCK_SIZE) {
      for(int i = bytesRead; i < DATA_BLOCK_SIZE; i++) {
        dataBlock[i] = 0;
      }
    }

    encryptData(dataBlock, key);

    // Writing the encrypted data block to the new file
    fwrite(dataBlock, sizeof(unsigned char), DATA_BLOCK_SIZE, fpEncrypted);
  }

  fclose(fp);
  fclose(fpEncrypted);

  printf("File %s encrypted successfully\n", fileName);

  return 0;
}