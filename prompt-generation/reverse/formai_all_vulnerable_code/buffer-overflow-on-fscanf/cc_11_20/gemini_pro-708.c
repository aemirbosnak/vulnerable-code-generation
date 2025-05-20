//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 255
#define MAX_BACKUP_COUNT 3

typedef struct {
  char filename[MAX_FILENAME_LENGTH];
  time_t timestamp;
  int backup_count;
} file_info;

int main() {
  // Initialize the file backup system
  file_info files[MAX_FILES];
  int num_files = 0;

  // Load the file list from a file
  FILE *file_list = fopen("file_list.txt", "r");
  if (file_list == NULL) {
    fprintf(stderr, "Error opening file list file.\n");
    return EXIT_FAILURE;
  }

  while (fscanf(file_list, "%s %ld %d", files[num_files].filename, &files[num_files].timestamp, &files[num_files].backup_count) != EOF) {
    num_files++;
  }

  fclose(file_list);

  // Get the current time
  time_t current_time = time(NULL);

  // Backup all files that have not been backed up in the last 24 hours
  for (int i = 0; i < num_files; i++) {
    if (current_time - files[i].timestamp > 86400) {
      // Create a backup file
      char backup_filename[MAX_FILENAME_LENGTH];
      snprintf(backup_filename, MAX_FILENAME_LENGTH, "%s.%ld", files[i].filename, current_time);
      FILE *backup_file = fopen(backup_filename, "w");
      if (backup_file == NULL) {
        fprintf(stderr, "Error opening backup file.\n");
        return EXIT_FAILURE;
      }

      // Copy the contents of the original file to the backup file
      FILE *original_file = fopen(files[i].filename, "r");
      if (original_file == NULL) {
        fprintf(stderr, "Error opening original file.\n");
        return EXIT_FAILURE;
      }

      while (!feof(original_file)) {
        int c = fgetc(original_file);
        if (c != EOF) {
          fputc(c, backup_file);
        }
      }

      fclose(original_file);
      fclose(backup_file);

      // Update the file info
      files[i].timestamp = current_time;
      files[i].backup_count++;
    }
  }

  // Delete any backup files that are older than 3 days
  for (int i = 0; i < num_files; i++) {
    if (files[i].backup_count > MAX_BACKUP_COUNT) {
      char backup_filename[MAX_FILENAME_LENGTH];
      snprintf(backup_filename, MAX_FILENAME_LENGTH, "%s.%ld", files[i].filename, files[i].timestamp - 86400 * 3);
      remove(backup_filename);
    }
  }

  // Save the file list to a file
  file_list = fopen("file_list.txt", "w");
  if (file_list == NULL) {
    fprintf(stderr, "Error opening file list file.\n");
    return EXIT_FAILURE;
  }

  for (int i = 0; i < num_files; i++) {
    fprintf(file_list, "%s %ld %d\n", files[i].filename, files[i].timestamp, files[i].backup_count);
  }

  fclose(file_list);

  return EXIT_SUCCESS;
}