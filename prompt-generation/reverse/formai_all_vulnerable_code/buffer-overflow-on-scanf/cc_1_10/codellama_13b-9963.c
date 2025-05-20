//Code Llama-13B DATASET v1.0 Category: File system simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_FILE_LEN 100
#define MAX_DIR_LEN 100

// Structure to store file system information
typedef struct {
  char name[MAX_NAME_LEN];
  char type;
  int size;
} FileInfo;

// Function to create a new file
void createFile(FileInfo *file) {
  // Get file name
  printf("Enter file name: ");
  scanf("%s", file->name);

  // Get file type
  printf("Enter file type (f/d): ");
  char type;
  scanf(" %c", &type);
  file->type = type;

  // Get file size
  printf("Enter file size: ");
  scanf("%d", &file->size);
}

// Function to display file information
void displayFile(FileInfo file) {
  printf("File name: %s\n", file.name);
  printf("File type: %c\n", file.type);
  printf("File size: %d\n", file.size);
}

// Function to list all files
void listFiles(FileInfo *files, int numFiles) {
  for (int i = 0; i < numFiles; i++) {
    displayFile(files[i]);
  }
}

// Function to search for a file by name
void searchFile(FileInfo *files, int numFiles, char *name) {
  for (int i = 0; i < numFiles; i++) {
    if (strcmp(files[i].name, name) == 0) {
      displayFile(files[i]);
      return;
    }
  }
  printf("File not found\n");
}

// Function to delete a file
void deleteFile(FileInfo *files, int numFiles, char *name) {
  for (int i = 0; i < numFiles; i++) {
    if (strcmp(files[i].name, name) == 0) {
      for (int j = i; j < numFiles - 1; j++) {
        files[j] = files[j + 1];
      }
      numFiles--;
      return;
    }
  }
  printf("File not found\n");
}

int main() {
  FileInfo files[100];
  int numFiles = 0;

  // Create files
  for (int i = 0; i < 10; i++) {
    createFile(&files[i]);
    numFiles++;
  }

  // Display files
  listFiles(files, numFiles);

  // Search for file
  char name[MAX_NAME_LEN];
  printf("Enter file name to search: ");
  scanf("%s", name);
  searchFile(files, numFiles, name);

  // Delete file
  printf("Enter file name to delete: ");
  scanf("%s", name);
  deleteFile(files, numFiles, name);

  // Display files again
  listFiles(files, numFiles);

  return 0;
}