//Code Llama-13B DATASET v1.0 Category: File system simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

#define MAX_FILE_SIZE (1024 * 1024 * 1024)
#define MAX_FILE_NAME_SIZE 256
#define MAX_PATH_SIZE 1024

typedef struct {
  char name[MAX_FILE_NAME_SIZE];
  uint32_t size;
  bool is_dir;
} File;

typedef struct {
  char name[MAX_FILE_NAME_SIZE];
  uint32_t size;
  bool is_dir;
  File *files;
} Directory;

typedef struct {
  char name[MAX_FILE_NAME_SIZE];
  uint32_t size;
  bool is_dir;
  Directory *directories;
} FileSystem;

FileSystem *create_filesystem(char *name) {
  FileSystem *fs = malloc(sizeof(FileSystem));
  strcpy(fs->name, name);
  fs->size = 0;
  fs->is_dir = false;
  fs->directories = NULL;
  return fs;
}

void destroy_filesystem(FileSystem *fs) {
  free(fs);
}

Directory *create_directory(FileSystem *fs, char *name) {
  Directory *dir = malloc(sizeof(Directory));
  strcpy(dir->name, name);
  dir->size = 0;
  dir->is_dir = true;
  dir->files = NULL;
  fs->size += sizeof(Directory);
  return dir;
}

void destroy_directory(Directory *dir) {
  free(dir);
}

File *create_file(Directory *dir, char *name, uint32_t size) {
  File *file = malloc(sizeof(File));
  strcpy(file->name, name);
  file->size = size;
  file->is_dir = false;
  dir->size += size;
  return file;
}

void destroy_file(File *file) {
  free(file);
}

void print_filesystem(FileSystem *fs) {
  printf("Filesystem: %s\n", fs->name);
  printf("Size: %d\n", fs->size);
  printf("Directories: %d\n", fs->directories);
  for (int i = 0; i < fs->directories; i++) {
    printf("\t%s\n", fs->directories[i].name);
    printf("\tSize: %d\n", fs->directories[i].size);
    printf("\tFiles: %d\n", fs->directories[i].files);
    for (int j = 0; j < fs->directories[i].files; j++) {
      printf("\t\t%s\n", fs->directories[i].files[j].name);
      printf("\t\tSize: %d\n", fs->directories[i].files[j].size);
    }
  }
}

int main() {
  FileSystem *fs = create_filesystem("my_filesystem");
  Directory *dir1 = create_directory(fs, "dir1");
  File *file1 = create_file(dir1, "file1", 1024);
  File *file2 = create_file(dir1, "file2", 1024);
  Directory *dir2 = create_directory(fs, "dir2");
  File *file3 = create_file(dir2, "file3", 512);
  File *file4 = create_file(dir2, "file4", 512);
  print_filesystem(fs);
  destroy_filesystem(fs);
  return 0;
}