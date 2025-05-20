//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

// Define the maximum number of files to backup
#define MAX_FILES 100

// Define the maximum size of a file to backup
#define MAX_FILE_SIZE 1024 * 1024 * 1024

// Define the backup directory
#define BACKUP_DIR "/backup"

// Define the file extension to backup
#define FILE_EXTENSION ".txt"

// Main function
int main() {
  // Get the current time
  time_t now = time(NULL);

  // Create the backup directory if it doesn't exist
  if (mkdir(BACKUP_DIR, 0755) != 0) {
    perror("mkdir");
    return EXIT_FAILURE;
  }

  // Open the backup directory
  DIR *dir = opendir(BACKUP_DIR);
  if (dir == NULL) {
    perror("opendir");
    return EXIT_FAILURE;
  }

  // Get a list of all the files in the backup directory
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    // Check if the file is a regular file
    if (entry->d_type != DT_REG) {
      continue;
    }

    // Check if the file is a .txt file
    if (strcmp(entry->d_name + strlen(entry->d_name) - strlen(FILE_EXTENSION), FILE_EXTENSION) != 0) {
      continue;
    }

    // Get the file size
    struct stat statbuf;
    if (stat(entry->d_name, &statbuf) != 0) {
      perror("stat");
      return EXIT_FAILURE;
    }

    // Check if the file is too large
    if (statbuf.st_size > MAX_FILE_SIZE) {
      continue;
    }

    // Open the file
    FILE *file = fopen(entry->d_name, "r");
    if (file == NULL) {
      perror("fopen");
      return EXIT_FAILURE;
    }

    // Read the file contents into a buffer
    char *buffer = malloc(statbuf.st_size);
    if (buffer == NULL) {
      perror("malloc");
      return EXIT_FAILURE;
    }
    fread(buffer, 1, statbuf.st_size, file);

    // Close the file
    fclose(file);

    // Write the file contents to a new file in the backup directory
    char *filename = malloc(strlen(entry->d_name) + 1 + sizeof(now));
    sprintf(filename, "%s.%ld", entry->d_name, now);
    file = fopen(filename, "w");
    if (file == NULL) {
      perror("fopen");
      return EXIT_FAILURE;
    }
    fwrite(buffer, 1, statbuf.st_size, file);

    // Close the file
    fclose(file);

    // Free the buffer
    free(buffer);

    // Free the filename
    free(filename);
  }

  // Close the backup directory
  closedir(dir);

  return EXIT_SUCCESS;
}