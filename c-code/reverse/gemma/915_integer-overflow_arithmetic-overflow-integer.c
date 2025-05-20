#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_FILES 1000
#define MAX_FILE_SIZE 1000000

typedef struct FileEntry {
  char *name;
  long size;
  struct FileEntry *next;
} FileEntry;

FileEntry *getFileEntry(char *name, long size) {
  FileEntry *newEntry = malloc(sizeof(FileEntry));
  newEntry->name = strdup(name);
  newEntry->size = size;
  newEntry->next = NULL;

  return newEntry;
}

int main() {
  FileEntry *files = NULL;

  // Handle multiple backups
  for (int i = 0; i < MAX_FILES; i++) {
    char *name = "file_" + i;
    long size = rand() % MAX_FILE_SIZE;
    getFileEntry(name, size);
  }

  // Check if file size limit is exceeded
  for (FileEntry *file = files; file; file = file->next) {
    if (file->size > MAX_FILE_SIZE) {
      printf("Error: File size limit exceeded for file %s.\n", file->name);
    }
  }

  return 0;
}
