//FormAI DATASET v1.0 Category: Modern Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Asynchronous encryption function to encrypt the data.
void async_encryption(char *data, int size, char *key) {
    for(int i=0; i<size; i++) {
        data[i] = data[i]^key[i%16];
    }
}

// Main function for encrypting a file.
int main() {
  FILE *fIn;
  FILE *fOut;

  char fname[100];
  char key[16];
  char buffer[1024]; // buffer to hold the data to be encrypted
  int bytes_read;
  
  printf("Enter the input file name: ");
  scanf("%s", fname);
  printf("Enter the encryption key (16 bytes): ");
  scanf("%s", key);

  fIn = fopen(fname, "r");
  if(fIn == NULL) {
    printf("Error: Cannot open input file\n");
    return 1;
  }

  // Create a unique output file name
  char fOutName[100];
  sprintf(fOutName, "encrypted_%d.txt", (int)time(NULL));
  
  fOut = fopen(fOutName, "w");
  if(fOut == NULL) {
    fclose(fIn);
    printf("Error: Cannot create output file\n");
    return 1;
  }

  // Read from the input file in blocks of 1024 bytes, and encrypt the data
  while((bytes_read = fread(buffer, 1, 1024, fIn)) > 0) {
    async_encryption(buffer, bytes_read, key);
    fwrite(buffer, 1, bytes_read, fOut);
  }

  // Close the files and return success
  fclose(fIn);
  fclose(fOut);

  printf("File encrypted successfully!\nOutput file name: %s\n", fOutName);

  return 0;
}