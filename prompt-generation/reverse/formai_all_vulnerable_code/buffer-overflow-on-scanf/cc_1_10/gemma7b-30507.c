//Gemma-7B DATASET v1.0 Category: File handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 255

void file_handler(char *file_name) {
  FILE *fp;
  int file_size, read_size, write_size;
  char *file_data;

  // Open file
  fp = fopen(file_name, "r");
  if (fp == NULL) {
    printf("Error opening file: %s", file_name);
    exit(1);
  }

  // Get file size
  fseek(fp, 0L, SEEK_END);
  file_size = ftell(fp);
  rewind(fp);

  // Allocate memory for file data
  file_data = malloc(file_size);
  if (file_data == NULL) {
    printf("Error allocating memory: %s", file_name);
    exit(1);
  }

  // Read file data
  read_size = fread(file_data, 1, file_size, fp);
  if (read_size != file_size) {
    printf("Error reading file: %s", file_name);
    exit(1);
  }

  // Write file data
  write_size = fwrite(file_data, 1, file_size, fp);
  if (write_size != file_size) {
    printf("Error writing file: %s", file_name);
    exit(1);
  }

  // Close file
  fclose(fp);

  // Free memory
  free(file_data);
}

int main() {
  char file_name[MAX_FILE_NAME_LENGTH];

  // Get file name from user
  printf("Enter file name: ");
  scanf("%s", file_name);

  // File handler function
  file_handler(file_name);

  return 0;
}