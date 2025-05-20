//Code Llama-13B DATASET v1.0 Category: File system simulation ; Style: inquisitive
// File System Simulation Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_FILE_SIZE 10000

typedef struct {
  char filename[MAX_FILENAME_LENGTH];
  char file_data[MAX_FILE_SIZE];
  int file_size;
} file_t;

file_t* files[MAX_FILENAME_LENGTH];
int num_files = 0;

void print_files() {
  for (int i = 0; i < num_files; i++) {
    printf("File: %s\n", files[i]->filename);
    printf("Size: %d\n", files[i]->file_size);
    printf("Data: %s\n", files[i]->file_data);
    printf("\n");
  }
}

void create_file(char* filename, char* data) {
  file_t* file = malloc(sizeof(file_t));
  if (file == NULL) {
    fprintf(stderr, "Error allocating memory for file\n");
    exit(1);
  }

  strcpy(file->filename, filename);
  strcpy(file->file_data, data);
  file->file_size = strlen(data);

  files[num_files++] = file;
}

void delete_file(char* filename) {
  for (int i = 0; i < num_files; i++) {
    if (strcmp(files[i]->filename, filename) == 0) {
      free(files[i]);
      files[i] = files[--num_files];
      break;
    }
  }
}

void main() {
  create_file("file1.txt", "Hello, world!");
  create_file("file2.txt", "This is a test file.");
  create_file("file3.txt", "This is a third test file.");

  print_files();

  delete_file("file2.txt");

  print_files();
}