//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BACKUP_DIR "backup"
#define BACKUP_EXT ".bak"

void backup_file(char *file_path) {
  // Open the file for reading
  FILE *file = fopen(file_path, "r");
  if (file == NULL) {
    printf("Error opening file: %s\n", file_path);
    return;
  }

  // Create a backup file name
  char *backup_file_path = malloc(strlen(file_path) + strlen(BACKUP_EXT) + 1);
  strcpy(backup_file_path, file_path);
  strcat(backup_file_path, BACKUP_EXT);

  // Open the backup file for writing
  FILE *backup_file = fopen(backup_file_path, "w");
  if (backup_file == NULL) {
    printf("Error creating backup file: %s\n", backup_file_path);
    return;
  }

  // Copy the contents of the file to the backup file
  char buffer[1024];
  while (fgets(buffer, 1024, file) != NULL) {
    fputs(buffer, backup_file);
  }

  // Close the files
  fclose(file);
  fclose(backup_file);

  // Free the memory
  free(backup_file_path);
}

int main(int argc, char *argv[]) {
  // Check if a file path was provided
  if (argc < 2) {
    printf("Usage: %s <file_path>\n", argv[0]);
    return 1;
  }

  // Backup the file
  backup_file(argv[1]);

  return 0;
}