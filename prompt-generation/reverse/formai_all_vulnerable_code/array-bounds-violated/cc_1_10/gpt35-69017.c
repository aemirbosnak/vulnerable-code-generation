//FormAI DATASET v1.0 Category: File Backup System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100

/*
  This program is a unique file backup system written in C.
  It allows the user to backup their files to a designated folder.
  The user inputs the filename and the backup folder and the program creates a backup copy of the file in the backup folder.
*/

int main() {
  char filename[MAX_FILENAME_LENGTH];
  char backup_folder[MAX_FILENAME_LENGTH];
  char buffer[1024];
  int ch, len, i;

  printf("Enter the filename to be backed up (including extension): ");
  fgets(filename, MAX_FILENAME_LENGTH, stdin);
  len = strlen(filename);

  // Removing newline character from the input
  if (filename[len - 1] == '\n') {
    filename[--len] = 0;
  }

  printf("Enter the folder in which you want to backup the file: ");
  fgets(backup_folder, MAX_FILENAME_LENGTH, stdin);
  len = strlen(backup_folder);
    // Removing newline character from the input
  if (backup_folder[len - 1] == '\n') {
    backup_folder[--len] = 0;
  }

  // Opening the original file
  FILE *original_file_ptr = fopen(filename, "r");

  if (original_file_ptr == NULL) {
    printf("Error opening the file\n");
    exit(1);
  }

  // Creating the backup file
  char backup_filename[MAX_FILENAME_LENGTH + 5];
  strcpy(backup_filename, backup_folder);
  strcat(backup_filename, "/");
  strcat(backup_filename, filename);
  strcat(backup_filename, ".bak");

  FILE *backup_file_ptr = fopen(backup_filename, "w");

  if (backup_file_ptr == NULL) {
    printf("Error creating the backup file\n");
    exit(1);
  }

  // Copying the contents of the original file to the backup file
  while ((ch = fgetc(original_file_ptr)) != EOF) {
    fputc(ch, backup_file_ptr);
  }

  // Closing the files
  fclose(original_file_ptr);
  fclose(backup_file_ptr);

  printf("Backup created successfully!\n");

  return 0;
}