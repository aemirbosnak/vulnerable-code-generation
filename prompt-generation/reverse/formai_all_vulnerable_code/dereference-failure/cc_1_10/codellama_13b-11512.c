//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: surprised
/*
 * C File Backup System
 *
 * This program will backup all files in a directory to a specified location.
 *
 * Usage:
 *  ./file_backup <source_dir> <destination_dir>
 *
 * Example:
 *  ./file_backup /home/user/Documents /media/user/USB/backup
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

int main(int argc, char **argv) {
  // Check if the number of arguments is correct
  if (argc != 3) {
    printf("Usage: %s <source_dir> <destination_dir>\n", argv[0]);
    return 1;
  }

  // Get the source and destination directories
  char *source_dir = argv[1];
  char *destination_dir = argv[2];

  // Open the source directory
  DIR *dir = opendir(source_dir);
  if (dir == NULL) {
    printf("Error opening directory: %s\n", source_dir);
    return 1;
  }

  // Create the destination directory if it doesn't exist
  if (access(destination_dir, F_OK) == -1) {
    mkdir(destination_dir, 0755);
  }

  // Iterate over the files in the source directory
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    // Ignore the "." and ".." directories
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    // Get the full path of the file
    char file_path[PATH_MAX];
    snprintf(file_path, PATH_MAX, "%s/%s", source_dir, entry->d_name);

    // Check if the file is a directory
    struct stat file_stat;
    if (stat(file_path, &file_stat) == -1) {
      printf("Error getting file status: %s\n", file_path);
      continue;
    }
    if (S_ISDIR(file_stat.st_mode)) {
      continue;
    }

    // Copy the file to the destination directory
    char destination_path[PATH_MAX];
    snprintf(destination_path, PATH_MAX, "%s/%s", destination_dir, entry->d_name);
    if (copy(file_path, destination_path) == -1) {
      printf("Error copying file: %s\n", file_path);
      continue;
    }

    printf("Copied %s to %s\n", file_path, destination_path);
  }

  // Close the source directory
  closedir(dir);

  return 0;
}

int copy(char *source, char *destination) {
  // Open the source file
  FILE *src = fopen(source, "r");
  if (src == NULL) {
    return -1;
  }

  // Open the destination file
  FILE *dst = fopen(destination, "w");
  if (dst == NULL) {
    fclose(src);
    return -1;
  }

  // Copy the file
  char buffer[BUFSIZ];
  size_t bytes_read;
  while ((bytes_read = fread(buffer, 1, BUFSIZ, src)) > 0) {
    fwrite(buffer, 1, bytes_read, dst);
  }

  // Close the files
  fclose(src);
  fclose(dst);

  return 0;
}