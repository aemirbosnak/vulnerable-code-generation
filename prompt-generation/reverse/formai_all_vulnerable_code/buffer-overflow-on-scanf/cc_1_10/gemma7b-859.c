//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct FileEntry {
  char file_name[MAX_FILE_NAME_LENGTH];
  struct FileEntry* next;
} FileEntry;

int main() {
  FILE* backup_file = NULL;
  FileEntry* file_head = NULL;

  // Create a new file entry
  FileEntry* new_file_entry = malloc(sizeof(FileEntry));
  new_file_entry->next = NULL;

  // Get the file name from the user
  char file_name[MAX_FILE_NAME_LENGTH];
  printf("Enter the file name: ");
  scanf("%s", file_name);

  // Copy the file name into the new file entry
  strcpy(new_file_entry->file_name, file_name);

  // If the file head is NULL, make it the first file entry
  if (file_head == NULL) {
    file_head = new_file_entry;
  } else {
    // Otherwise, add the new file entry to the end of the linked list
    file_head->next = new_file_entry;
    file_head = new_file_entry;
  }

  // Open a file for writing
  backup_file = fopen("backup.txt", "a");

  // Write the file name to the backup file
  fprintf(backup_file, "%s\n", new_file_entry->file_name);

  // Close the file
  fclose(backup_file);

  // Print the file name
  printf("File name: %s\n", new_file_entry->file_name);

  return 0;
}