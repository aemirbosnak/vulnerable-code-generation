//FormAI DATASET v1.0 Category: File Backup System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_BACKUPS_PER_FILE 10
#define MAX_FILES 100

typedef struct backup_data {
  char timestamp[MAX_FILENAME_LENGTH];
  char filename[MAX_FILENAME_LENGTH];
} BackupData;

int main() {
  BackupData backups[MAX_FILES * MAX_BACKUPS_PER_FILE];
  int num_backups = 0;

  while(1) {
    printf("Enter file name to backup (or q to quit): ");
    char filename[MAX_FILENAME_LENGTH];
    scanf("%s", filename);

    if(strcmp(filename, "q") == 0) {
      break;
    }

    FILE* file_pointer = fopen(filename, "r");

    if(file_pointer == NULL) {
      printf("Error: Could not open file.\n");
      continue;
    }

    // Create backup data
    BackupData backup;
    time_t now = time(NULL);
    strftime(backup.timestamp, MAX_FILENAME_LENGTH, "%Y-%m-%d_%H-%M-%S", localtime(&now));
    strcpy(backup.filename, filename);

    // Create backup file name
    char backup_filename[MAX_FILENAME_LENGTH];
    snprintf(backup_filename, MAX_FILENAME_LENGTH, "%s-%s", filename, backup.timestamp);

    // Open backup file
    FILE* backup_file_pointer = fopen(backup_filename, "w");

    if(backup_file_pointer == NULL) {
      printf("Error: Could not create backup file.\n");
      fclose(file_pointer);
      continue;
    }

    // Copy content from original file to backup file
    char buffer[1024];
    size_t num_read_bytes;

    while((num_read_bytes = fread(buffer, 1, 1024, file_pointer)) > 0) {
      fwrite(buffer, 1, num_read_bytes, backup_file_pointer);
    }

    // Close files
    fclose(file_pointer);
    fclose(backup_file_pointer);

    // Add backup data to backups array
    backups[num_backups++] = backup;

    // Limit number of backups per file
    int count = 0;

    for(int i = 0; i < num_backups; i++) {
      if(strcmp(backups[i].filename, filename) == 0) {
        count++;
      }

      if(count > MAX_BACKUPS_PER_FILE) {
        remove(backups[i].timestamp);
        count--;
      }
    }

    // Limit total number of files
    if(num_backups >= MAX_FILES * MAX_BACKUPS_PER_FILE) {
      // Delete oldest backup
      remove(backups[0].timestamp);
      // Remove backup from backups array
      for(int i = 0; i < num_backups-1; i++) {
        backups[i] = backups[i+1];
      }
      num_backups--;
    }

    printf("Backup created successfully.\n\n");

    // Sleep to simulate backups being created over time
    usleep(1000000);
  }

  return 0;
}