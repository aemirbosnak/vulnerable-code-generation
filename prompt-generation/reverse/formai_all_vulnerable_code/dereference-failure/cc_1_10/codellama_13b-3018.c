//Code Llama-13B DATASET v1.0 Category: File system simulation ; Style: funny
/*
 * Unique C File System Simulation Example Program
 *
 * In a funny style
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LEN 32
#define MAX_FILE_SIZE 1024

typedef struct {
  char name[MAX_FILE_NAME_LEN];
  int size;
  int last_modified;
} File;

typedef struct {
  char name[MAX_FILE_NAME_LEN];
  int num_files;
  File* files;
} Directory;

void create_file(File* file, char* name, int size) {
  strcpy(file->name, name);
  file->size = size;
  file->last_modified = time(NULL);
}

void create_directory(Directory* dir, char* name) {
  strcpy(dir->name, name);
  dir->num_files = 0;
  dir->files = NULL;
}

void add_file_to_directory(Directory* dir, File* file) {
  dir->files = realloc(dir->files, (dir->num_files + 1) * sizeof(File));
  dir->files[dir->num_files] = *file;
  dir->num_files++;
}

void list_directory(Directory* dir) {
  printf("Directory %s:\n", dir->name);
  for (int i = 0; i < dir->num_files; i++) {
    printf("  %s (%d bytes, last modified %s)\n", dir->files[i].name, dir->files[i].size, ctime(&dir->files[i].last_modified));
  }
}

int main() {
  File file1, file2, file3;
  Directory dir1, dir2;

  create_file(&file1, "file1.txt", 100);
  create_file(&file2, "file2.txt", 200);
  create_file(&file3, "file3.txt", 300);

  create_directory(&dir1, "dir1");
  create_directory(&dir2, "dir2");

  add_file_to_directory(&dir1, &file1);
  add_file_to_directory(&dir1, &file2);
  add_file_to_directory(&dir2, &file3);

  list_directory(&dir1);
  list_directory(&dir2);

  return 0;
}