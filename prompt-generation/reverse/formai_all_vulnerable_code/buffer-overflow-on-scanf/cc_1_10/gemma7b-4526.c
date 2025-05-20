//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct FileEntry {
  char file_name[MAX_FILE_NAME_LENGTH];
  struct FileEntry* next;
} FileEntry;

void insert_file_entry(FileEntry* head, char* file_name) {
  FileEntry* new_entry = malloc(sizeof(FileEntry));
  strcpy(new_entry->file_name, file_name);
  new_entry->next = NULL;

  if (head == NULL) {
    head = new_entry;
  } else {
    new_entry->next = head;
    head = new_entry;
  }
}

void backup_files(FileEntry* head) {
  FILE* file_ptr;
  char backup_dir[MAX_FILE_NAME_LENGTH];
  char file_path[MAX_FILE_NAME_LENGTH];

  printf("Enter the backup directory: ");
  scanf("%s", backup_dir);

  printf("Enter the file path: ");
  scanf("%s", file_path);

  file_ptr = fopen(file_path, "r");

  if (file_ptr == NULL) {
    printf("Error opening file: %s\n", file_path);
    return;
  }

  insert_file_entry(head, file_path);

  fprintf(file_ptr, "Backed up on: %s\n", backup_dir);
  fclose(file_ptr);
}

int main() {
  FileEntry* head = NULL;

  backup_files(head);

  return 0;
}