//FormAI DATASET v1.0 Category: Encryption ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_SIZE 100

// Encryption function
void encrypt(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] += 3;
      if (str[i] > 'z') {
        str[i] -= 26;
      }
    }
    else if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] += 3;
      if (str[i] > 'Z') {
        str[i] -= 26;
      }
    }
  }
}

// Thread function
void *encryptFile(void *filename) {
  char *file = (char*) filename;
  char input[MAX_SIZE], output[MAX_SIZE];
  FILE *fInput, *fOutput;
  
  // Open input and output files
  fInput = fopen(file, "r");
  if (fInput == NULL) {
    printf("ERROR: Unable to open input file.\n");
    pthread_exit(NULL);
  }
  
  sprintf(output, "encrypted_%s", file);
  fOutput = fopen(output, "w");
  if (fOutput == NULL) {
    printf("ERROR: Unable to create output file.\n");
    pthread_exit(NULL);
  }
  
  // Read and encrypt data
  while (fgets(input, MAX_SIZE, fInput)) {
    encrypt(input);
    fputs(input, fOutput);      
  }
  
  // Close files
  fclose(fInput);
  fclose(fOutput);
  
  pthread_exit(NULL);
}

int main() {
  char filename[MAX_SIZE];
  pthread_t encryptThread;
  int rc;
  
  printf("Enter filename to encrypt: ");
  scanf("%s", filename);
  
  // Create a new thread to encrypt the file
  rc = pthread_create(&encryptThread, NULL, encryptFile, (void*)filename);
  if (rc) {
    printf("ERROR: Unable to create thread.\n");
    exit(-1);
  }
  
  pthread_join(encryptThread, NULL);
  
  printf("File encrypted successfully.\n");
  
  return 0;
}