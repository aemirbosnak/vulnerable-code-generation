//Code Llama-13B DATASET v1.0 Category: File Synchronizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
  // Check if the number of arguments is correct
  if (argc != 3) {
    printf("Usage: %s <source> <destination>\n", argv[0]);
    return 1;
  }

  // Open the source directory
  DIR *dir = opendir(argv[1]);
  if (dir == NULL) {
    perror("opendir");
    return 1;
  }

  // Open the destination directory
  DIR *dest_dir = opendir(argv[2]);
  if (dest_dir == NULL) {
    perror("opendir");
    return 1;
  }

  // Read the directory entries
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    // Check if the entry is a regular file
    if (entry->d_type != DT_REG) {
      continue;
    }

    // Open the file
    int fd = openat(dir, entry->d_name, O_RDONLY);
    if (fd == -1) {
      perror("openat");
      continue;
    }

    // Create the destination file
    int dest_fd = openat(dest_dir, entry->d_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
      perror("openat");
      close(fd);
      continue;
    }

    // Copy the file
    char buf[BUF_SIZE];
    ssize_t n;
    while ((n = read(fd, buf, BUF_SIZE)) > 0) {
      write(dest_fd, buf, n);
    }
    if (n == -1) {
      perror("read");
      close(fd);
      close(dest_fd);
      continue;
    }

    // Close the file
    close(fd);
    close(dest_fd);
  }

  // Close the directories
  closedir(dir);
  closedir(dest_dir);

  return 0;
}