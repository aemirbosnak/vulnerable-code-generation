//FormAI DATASET v1.0 Category: Data recovery tool ; Style: random
#include <stdio.h>
#include <stdlib.h>

// function to recover data from corrupted file
void recoverData(char* filename) {
  FILE* fp;
  int num_bytes, bytes_read;
  char* buffer;

  // opening file in binary read mode
  fp = fopen(filename, "rb");

  // checking if file is successfully opened
  if (fp == NULL) {
    printf("Error: File cannot be opened!");
    exit(1);
  }

  // getting file size
  fseek(fp, 0, SEEK_END);
  num_bytes = ftell(fp);

  // allocating memory for buffer
  buffer = (char*) malloc(num_bytes * sizeof(char));

  // checking if memory is successfully allocated
  if (buffer == NULL) {
    printf("Error: Memory cannot be allocated!");
    fclose(fp);
    exit(1);
  }

  // moving file pointer to start of file
  fseek(fp, 0, SEEK_SET);

  // reading data from file to buffer
  bytes_read = fread(buffer, sizeof(char), num_bytes, fp);

  // checking if data is successfully read
  if (bytes_read != num_bytes) {
    printf("Error: Data cannot be read!");
    free(buffer);
    fclose(fp);
    exit(1);
  }

  // printing recovered data
  printf("\nRecovered Data:\n");
  printf("%s", buffer);

  // freeing memory and closing file
  free(buffer);
  fclose(fp);
}

int main() {
  char filename[100];

  printf("Enter filename: ");
  scanf("%s", &filename);

  // recovering data from file
  recoverData(filename);

  return 0;
}