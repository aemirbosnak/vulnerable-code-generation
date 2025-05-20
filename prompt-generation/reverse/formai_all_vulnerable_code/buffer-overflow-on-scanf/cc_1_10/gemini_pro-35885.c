//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get the current system time
char *get_time() {
  time_t rawtime;
  struct tm *timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  return asctime(timeinfo);
}

// Function to copy a file
int copy_file(char *source, char *destination) {
  // Open the source file
  FILE *source_file = fopen(source, "r");
  if (source_file == NULL) {
    printf("Error opening the source file: %s\n", source);
    return -1;
  }

  // Open the destination file
  FILE *destination_file = fopen(destination, "w");
  if (destination_file == NULL) {
    printf("Error opening the destination file: %s\n", destination);
    return -1;
  }

  // Copy the contents of the source file to the destination file
  char buffer[1024];
  while (fread(buffer, 1, sizeof(buffer), source_file) != 0) {
    fwrite(buffer, 1, sizeof(buffer), destination_file);
  }

  // Close the files
  fclose(source_file);
  fclose(destination_file);

  return 0;
}

// Function to create a backup of a file
int backup_file(char *filename) {
  // Create the backup file name
  char backup_file[1024];
  sprintf(backup_file, "%s.%s.bak", filename, get_time());

  // Copy the file to the backup file
  int result = copy_file(filename, backup_file);
  if (result != 0) {
    printf("Error backing up the file: %s\n", filename);
    return -1;
  }

  return 0;
}

int main() {
  // Get the name of the file to back up
  char filename[1024];
  printf("Enter the name of the file to back up: ");
  scanf("%s", filename);

  // Create a backup of the file
  int result = backup_file(filename);
  if (result != 0) {
    printf("Error backing up the file: %s\n", filename);
    return -1;
  }

  printf("The file %s has been backed up to %s\n", filename, backup_file);

  return 0;
}