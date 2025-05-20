//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

typedef struct FileEntry {
  char *name;
  struct FileEntry *next;
} FileEntry;

FileEntry *getFileEntry(char *name) {
  FileEntry *head = NULL;
  FileEntry *curr = NULL;

  if (head == NULL) {
    head = malloc(sizeof(FileEntry));
    head->name = strdup(name);
    head->next = NULL;
    curr = head;
  } else {
    curr = head;
    while (curr->next) {
      curr = curr->next;
    }
    curr->next = malloc(sizeof(FileEntry));
    curr = curr->next;
    curr->name = strdup(name);
    curr->next = NULL;
  }

  return head;
}

int main() {
  FILE *fp;
  char buffer[BUFFER_SIZE];
  char filename[256];
  FileEntry *files = NULL;

  printf("Enter file name: ");
  scanf("%s", filename);

  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
    getFileEntry(buffer);
  }

  fclose(fp);

  printf("Files backed up: \n");
  for (FileEntry *curr = files; curr; curr = curr->next) {
    printf("%s\n", curr->name);
  }

  return 0;
}