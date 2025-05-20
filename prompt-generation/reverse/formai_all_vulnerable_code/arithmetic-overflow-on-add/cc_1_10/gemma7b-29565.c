//Gemma-7B DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store file information
typedef struct FileInfo {
  char filename[256];
  int size;
  FILE *fp;
} FileInfo;

// Function to open a file
void openFile(FileInfo *file, char *filename) {
  file->fp = fopen(filename, "r");
  if (file->fp == NULL) {
    perror("Error opening file");
    exit(1);
  }
  file->size = 0;
  file->filename[0] = '\0';
  strcpy(file->filename, filename);
}

// Function to close a file
void closeFile(FileInfo *file) {
  fclose(file->fp);
  file->fp = NULL;
  file->size = 0;
  file->filename[0] = '\0';
}

// Function to read a file
void readFile(FileInfo *file) {
  char buffer[1024];
  int bytesRead;
  file->size = 0;
  while ((bytesRead = fread(buffer, 1, 1024, file->fp)) > 0) {
    file->size += bytesRead;
  }
}

// Function to write to a file
void writeFile(FileInfo *file, char *data, int bytesToWrite) {
  int bytesWritten;
  if (fwrite(data, 1, bytesToWrite, file->fp) < bytesToWrite) {
    perror("Error writing to file");
    exit(1);
  }
  file->size += bytesWritten;
}

int main() {
  FileInfo file;
  openFile(&file, "my_file.txt");
  readFile(&file);
  writeFile(&file, "Hello, world!", 13);
  closeFile(&file);
  return 0;
}