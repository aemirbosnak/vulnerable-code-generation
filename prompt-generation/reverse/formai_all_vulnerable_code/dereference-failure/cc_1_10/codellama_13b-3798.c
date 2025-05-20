//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: shocked
// unique_backup_system.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024
#define MAX_FILE_NAME_SIZE 256

// Function to copy a file
int copy_file(char *src, char *dest) {
  // Open source file
  FILE *src_file = fopen(src, "r");
  if (src_file == NULL) {
    printf("Error: Failed to open source file\n");
    return -1;
  }

  // Open destination file
  FILE *dest_file = fopen(dest, "w");
  if (dest_file == NULL) {
    printf("Error: Failed to open destination file\n");
    fclose(src_file);
    return -1;
  }

  // Copy data from source file to destination file
  char buf[MAX_BUF_SIZE];
  size_t bytes_read;
  while ((bytes_read = fread(buf, 1, MAX_BUF_SIZE, src_file)) > 0) {
    fwrite(buf, 1, bytes_read, dest_file);
  }

  // Close files
  fclose(src_file);
  fclose(dest_file);

  return 0;
}

// Function to backup a file
int backup_file(char *src, char *dest) {
  // Check if source file exists
  if (access(src, F_OK) != 0) {
    printf("Error: Source file does not exist\n");
    return -1;
  }

  // Check if destination file exists
  if (access(dest, F_OK) != 0) {
    printf("Error: Destination file does not exist\n");
    return -1;
  }

  // Copy file
  if (copy_file(src, dest) != 0) {
    printf("Error: Failed to copy file\n");
    return -1;
  }

  return 0;
}

// Function to backup a directory
int backup_dir(char *src, char *dest) {
  // Check if source directory exists
  if (access(src, F_OK) != 0) {
    printf("Error: Source directory does not exist\n");
    return -1;
  }

  // Check if destination directory exists
  if (access(dest, F_OK) != 0) {
    printf("Error: Destination directory does not exist\n");
    return -1;
  }

  // Open source directory
  DIR *src_dir = opendir(src);
  if (src_dir == NULL) {
    printf("Error: Failed to open source directory\n");
    return -1;
  }

  // Open destination directory
  DIR *dest_dir = opendir(dest);
  if (dest_dir == NULL) {
    printf("Error: Failed to open destination directory\n");
    closedir(src_dir);
    return -1;
  }

  // Loop through source directory
  struct dirent *entry;
  while ((entry = readdir(src_dir)) != NULL) {
    // Check if entry is a file
    if (entry->d_type == DT_REG) {
      // Backup file
      char src_file[MAX_FILE_NAME_SIZE];
      sprintf(src_file, "%s/%s", src, entry->d_name);
      char dest_file[MAX_FILE_NAME_SIZE];
      sprintf(dest_file, "%s/%s", dest, entry->d_name);
      if (backup_file(src_file, dest_file) != 0) {
        printf("Error: Failed to backup file\n");
        closedir(src_dir);
        closedir(dest_dir);
        return -1;
      }
    }
  }

  // Close directories
  closedir(src_dir);
  closedir(dest_dir);

  return 0;
}

int main(int argc, char *argv[]) {
  // Check number of arguments
  if (argc != 3) {
    printf("Usage: %s <src> <dest>\n", argv[0]);
    return -1;
  }

  // Backup file or directory
  if (access(argv[1], F_OK) == 0) {
    // Backup file
    if (backup_file(argv[1], argv[2]) != 0) {
      printf("Error: Failed to backup file\n");
      return -1;
    }
  } else if (access(argv[1], F_OK) == 0) {
    // Backup directory
    if (backup_dir(argv[1], argv[2]) != 0) {
      printf("Error: Failed to backup directory\n");
      return -1;
    }
  } else {
    printf("Error: Source does not exist\n");
    return -1;
  }

  return 0;
}