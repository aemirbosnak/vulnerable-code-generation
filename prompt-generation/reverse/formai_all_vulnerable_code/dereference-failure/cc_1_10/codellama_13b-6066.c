//Code Llama-13B DATASET v1.0 Category: File system simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Structures for storing file system information
typedef struct {
  char name[20];
  int size;
  int type; // 0 for file, 1 for directory
} FileInfo;

typedef struct {
  FileInfo* files;
  int num_files;
  char name[20];
} Directory;

// Function to create a new file
FileInfo* create_file(char* name, int size) {
  FileInfo* file = (FileInfo*)malloc(sizeof(FileInfo));
  strcpy(file->name, name);
  file->size = size;
  file->type = 0;
  return file;
}

// Function to create a new directory
Directory* create_directory(char* name) {
  Directory* dir = (Directory*)malloc(sizeof(Directory));
  strcpy(dir->name, name);
  dir->num_files = 0;
  dir->files = NULL;
  return dir;
}

// Function to add a file to a directory
void add_file_to_directory(Directory* dir, FileInfo* file) {
  dir->files = (FileInfo*)realloc(dir->files, sizeof(FileInfo) * (dir->num_files + 1));
  dir->files[dir->num_files] = *file;
  dir->num_files++;
}

// Function to display the contents of a directory
void display_directory(Directory* dir) {
  printf("Directory: %s\n", dir->name);
  for (int i = 0; i < dir->num_files; i++) {
    if (dir->files[i].type == 0) {
      printf("  File: %s (%d bytes)\n", dir->files[i].name, dir->files[i].size);
    } else {
      printf("  Directory: %s\n", dir->files[i].name);
    }
  }
}

// Main function
int main() {
  // Create a root directory
  Directory* root = create_directory("root");

  // Create a file in the root directory
  FileInfo* file = create_file("file1.txt", 100);
  add_file_to_directory(root, file);

  // Create a directory in the root directory
  Directory* dir = create_directory("dir1");
  add_file_to_directory(root, dir);

  // Create a file in the dir1 directory
  FileInfo* file2 = create_file("file2.txt", 50);
  add_file_to_directory(dir, file2);

  // Display the contents of the root directory
  display_directory(root);

  return 0;
}