//FormAI DATASET v1.0 Category: File Backup System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_FILENAME_SIZE 100
#define MAX_BACKUP_FILES 10

// Structs
typedef struct {
  char filename[MAX_FILENAME_SIZE];
  int version;
} BackupFile;

// Global Variables
BackupFile backup_files[MAX_BACKUP_FILES];
int num_backup_files = 0;

// Function Prototypes
void backup_file(char filename[]);
void list_backup_files();
void delete_backup_file(char filename[]);
void restore_backup_file(char filename[], int version);

// Main Function
int main() {
  int option;
  char filename[MAX_FILENAME_SIZE];

  while (1) {
    printf("\nBackup System Menu:\n");
    printf("1. Backup a File\n");
    printf("2. List Backup Files\n");
    printf("3. Delete a Backup File\n");
    printf("4. Restore a Backup File\n");
    printf("0. Exit\n");

    printf("\nEnter an option: ");
    scanf("%d", &option);

    switch(option) {
      case 0:
        printf("Exiting...\n");
        exit(0);

      case 1:
        printf("\nEnter filename to backup: ");
        scanf("%s", filename);
        backup_file(filename);
        break;

      case 2:
        list_backup_files();
        break;

      case 3:
        printf("\nEnter filename to delete: ");
        scanf("%s", filename);
        delete_backup_file(filename);
        break;

      case 4:
        printf("\nEnter filename to restore: ");
        scanf("%s", filename);
        printf("Enter version to restore: ");
        int version;
        scanf("%d", &version);
        restore_backup_file(filename, version);
        break;

      default:
        printf("Invalid option\n");
    }
  }

  return 0;
}

// Function to backup a file
void backup_file(char filename[]) {
  // Check if filename already exists in backup_files array
  for (int i = 0; i < num_backup_files; i++) {
    BackupFile bf = backup_files[i];
    if (strcmp(bf.filename, filename) == 0) {
      // Increment file version
      bf.version++;
      printf("\nBacking up %s version %d\n", bf.filename, bf.version);
      return;
    }
  }

  // Create a new backup file
  BackupFile new_backup;
  strcpy(new_backup.filename, filename);
  new_backup.version = 1;

  // Add new backup file to backup_files array
  backup_files[num_backup_files] = new_backup;
  num_backup_files++;

  printf("\nBacking up %s version %d\n", new_backup.filename, new_backup.version);
}

// Function to list all backup files
void list_backup_files() {
  if (num_backup_files == 0) {
    printf("\nNo backup files found.\n");
    return;
  }

  printf("\nBackup Files:\n");
  for (int i = 0; i < num_backup_files; i++) {
    BackupFile bf = backup_files[i];
    printf("%d. %s version %d\n", i+1, bf.filename, bf.version);
  }
}

// Function to delete a backup file
void delete_backup_file(char filename[]) {
  int index = -1;

  // Find index of backup file in backup_files array
  for (int i = 0; i < num_backup_files; i++) {
    BackupFile bf = backup_files[i];
    if (strcmp(bf.filename, filename) == 0) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    printf("\nBackup file %s not found.\n", filename);
    return;
  }

  // Shift all backup files to the right of the deleted file to the left
  for (int i = index; i < num_backup_files-1; i++) {
    backup_files[i] = backup_files[i+1];
  }

  num_backup_files--;

  printf("\nDeleted backup file %s\n", filename);
}

// Function to restore a backup file
void restore_backup_file(char filename[], int version) {
  int index = -1;

  // Find index of backup file in backup_files array
  for (int i = 0; i < num_backup_files; i++) {
    BackupFile bf = backup_files[i];
    if (strcmp(bf.filename, filename) == 0 && bf.version == version) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    printf("\nBackup file %s version %d not found.\n", filename, version);
    return;
  }

  printf("\nRestoring %s version %d\n", filename, version);
  // Restore backup file from storage device
  // Note: This is a demonstration program and does not implement actual backup/restore functionality
}