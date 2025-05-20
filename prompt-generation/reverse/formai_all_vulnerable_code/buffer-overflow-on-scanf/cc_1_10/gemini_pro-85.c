//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the file name
#define MAX_FILE_NAME_SIZE 256

// Define the maximum number of files to backup
#define MAX_NUM_FILES 10

// Define the maximum size of the backup file
#define MAX_BACKUP_FILE_SIZE 1024 * 1024

// Define the file types to backup
#define FILE_TYPES "txt,csv,doc,docx,xls,xlsx,ppt,pptx,pdf"

// Define the backup file name
#define BACKUP_FILE_NAME "backup.zip"

// Define the error codes
#define ERR_OPEN_FILE -1
#define ERR_READ_FILE -2
#define ERR_WRITE_FILE -3
#define ERR_CLOSE_FILE -4
#define ERR_ZIP_FILE -5
#define ERR_UNZIP_FILE -6
#define ERR_DELETE_FILE -7

// Declare the main function
int main() {
  // Declare the variables
  char file_name[MAX_FILE_NAME_SIZE];
  char backup_file_name[MAX_FILE_NAME_SIZE];
  char command[MAX_FILE_NAME_SIZE * 2];
  FILE *file;
  int i;
  int n;
  int ret;

  // Get the number of files to backup
  printf("Enter the number of files to backup: ");
  scanf("%d", &n);

  // Get the file names
  for (i = 0; i < n; i++) {
    printf("Enter the file name %d: ", i + 1);
    scanf("%s", file_name);

    // Check if the file exists
    file = fopen(file_name, "r");
    if (file == NULL) {
      printf("Error: File %s does not exist.\n", file_name);
      return ERR_OPEN_FILE;
    }

    // Close the file
    fclose(file);
  }

  // Create the backup file name
  sprintf(backup_file_name, "%s.zip", BACKUP_FILE_NAME);

  // Create the zip command
  sprintf(command, "zip -r %s %s", backup_file_name, FILE_TYPES);

  // Execute the zip command
  ret = system(command);
  if (ret != 0) {
    printf("Error: Failed to zip files.\n");
    return ERR_ZIP_FILE;
  }

  // Delete the original files
  for (i = 0; i < n; i++) {
    ret = remove(file_name);
    if (ret != 0) {
      printf("Error: Failed to delete file %s.\n", file_name);
      return ERR_DELETE_FILE;
    }
  }

  // Return success
  return 0;
}