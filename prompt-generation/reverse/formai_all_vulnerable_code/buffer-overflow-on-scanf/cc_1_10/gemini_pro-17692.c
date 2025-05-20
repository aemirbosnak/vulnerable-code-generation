//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of files that can be backed up
#define MAX_FILES 10

// Define the maximum size of each file that can be backed up
#define MAX_FILE_SIZE 1024

// Define the backup file name
#define BACKUP_FILE_NAME "backup.dat"

// Define the function to backup a file
int backup_file(char *file_name) {
  // Open the file to be backed up
  FILE *file = fopen(file_name, "rb");
  if (file == NULL) {
    printf("Error opening file %s\n", file_name);
    return -1;
  }

  // Get the file size
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  rewind(file);

  // Allocate memory for the file data
  char *file_data = malloc(file_size);
  if (file_data == NULL) {
    printf("Error allocating memory for file data\n");
    fclose(file);
    return -1;
  }

  // Read the file data into memory
  fread(file_data, file_size, 1, file);
  fclose(file);

  // Open the backup file
  FILE *backup_file = fopen(BACKUP_FILE_NAME, "wb");
  if (backup_file == NULL) {
    printf("Error opening backup file %s\n", BACKUP_FILE_NAME);
    free(file_data);
    return -1;
  }

  // Write the file data to the backup file
  fwrite(file_data, file_size, 1, backup_file);
  fclose(backup_file);

  // Free the memory allocated for the file data
  free(file_data);

  // Return success
  return 0;
}

// Define the function to restore a file
int restore_file(char *file_name) {
  // Open the backup file
  FILE *backup_file = fopen(BACKUP_FILE_NAME, "rb");
  if (backup_file == NULL) {
    printf("Error opening backup file %s\n", BACKUP_FILE_NAME);
    return -1;
  }

  // Get the file size
  fseek(backup_file, 0, SEEK_END);
  long file_size = ftell(backup_file);
  rewind(backup_file);

  // Allocate memory for the file data
  char *file_data = malloc(file_size);
  if (file_data == NULL) {
    printf("Error allocating memory for file data\n");
    fclose(backup_file);
    return -1;
  }

  // Read the file data into memory
  fread(file_data, file_size, 1, backup_file);
  fclose(backup_file);

  // Open the file to be restored
  FILE *file = fopen(file_name, "wb");
  if (file == NULL) {
    printf("Error opening file %s\n", file_name);
    free(file_data);
    return -1;
  }

  // Write the file data to the file to be restored
  fwrite(file_data, file_size, 1, file);
  fclose(file);

  // Free the memory allocated for the file data
  free(file_data);

  // Return success
  return 0;
}

// Define the main function
int main() {
  // Get the number of files to be backed up
  int num_files;
  printf("Enter the number of files to be backed up: ");
  scanf("%d", &num_files);

  // Get the names of the files to be backed up
  char file_names[MAX_FILES][MAX_FILE_SIZE];
  for (int i = 0; i < num_files; i++) {
    printf("Enter the name of file %d: ", i + 1);
    scanf("%s", file_names[i]);
  }

  // Backup the files
  for (int i = 0; i < num_files; i++) {
    if (backup_file(file_names[i]) != 0) {
      printf("Error backing up file %s\n", file_names[i]);
      return -1;
    }
  }

  // Print a happy message
  printf("Files backed up successfully!\n");

  // Get the name of the file to be restored
  char file_name[MAX_FILE_SIZE];
  printf("Enter the name of the file to be restored: ");
  scanf("%s", file_name);

  // Restore the file
  if (restore_file(file_name) != 0) {
    printf("Error restoring file %s\n", file_name);
    return -1;
  }

  // Print a happy message
  printf("File restored successfully!\n");

  // Return success
  return 0;
}