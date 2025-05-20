//Code Llama-13B DATASET v1.0 Category: File Synchronizer ; Style: multivariable
// File Synchronizer Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#define BUF_SIZE 1024
#define FILE_COUNT 5

int main(int argc, char *argv[]) {
  // Check if the number of arguments is valid
  if (argc != 2) {
    printf("Usage: %s <directory>\n", argv[0]);
    return 1;
  }

  // Open the directory
  DIR *dir = opendir(argv[1]);
  if (dir == NULL) {
    printf("Failed to open directory: %s\n", argv[1]);
    return 1;
  }

  // Read the directory entries
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    // Skip over the current and parent directories
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    // Open the file
    char *filepath = malloc(strlen(argv[1]) + strlen(entry->d_name) + 2);
    sprintf(filepath, "%s/%s", argv[1], entry->d_name);
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
      printf("Failed to open file: %s\n", filepath);
      continue;
    }

    // Read the file contents
    char buffer[BUF_SIZE];
    size_t bytes_read = read(fd, buffer, BUF_SIZE);
    if (bytes_read == -1) {
      printf("Failed to read file: %s\n", filepath);
      close(fd);
      continue;
    }

    // Print the file contents
    printf("File: %s\n", filepath);
    printf("Contents: %s\n", buffer);

    // Close the file
    close(fd);
  }

  // Close the directory
  closedir(dir);

  return 0;
}