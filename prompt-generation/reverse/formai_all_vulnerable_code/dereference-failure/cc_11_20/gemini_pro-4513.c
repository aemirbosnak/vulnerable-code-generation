//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

// Define the maximum path length
#define MAX_PATH_LEN 256

// Define the maximum file size
#define MAX_FILE_SIZE 1024 * 1024

// Define the buffer size
#define BUFFER_SIZE 1024

// Recursively synchronize two directories
void sync_dirs(char *dir1, char *dir2) {
  // Get the directory entries
  DIR *dp1 = opendir(dir1);
  DIR *dp2 = opendir(dir2);
  if (dp1 == NULL || dp2 == NULL) {
    perror("opendir");
    return;
  }

  // Loop through the directory entries
  struct dirent *entry1;
  struct dirent *entry2;
  while ((entry1 = readdir(dp1)) != NULL && (entry2 = readdir(dp2)) != NULL) {
    // Skip the current and parent directories
    if (strcmp(entry1->d_name, ".") == 0 || strcmp(entry1->d_name, "..") == 0) {
      continue;
    }
    if (strcmp(entry2->d_name, ".") == 0 || strcmp(entry2->d_name, "..") == 0) {
      continue;
    }

    // Check if the entries are directories
    char path1[MAX_PATH_LEN];
    char path2[MAX_PATH_LEN];
    snprintf(path1, MAX_PATH_LEN, "%s/%s", dir1, entry1->d_name);
    snprintf(path2, MAX_PATH_LEN, "%s/%s", dir2, entry2->d_name);
    struct stat stat1;
    struct stat stat2;
    if (lstat(path1, &stat1) == -1 || lstat(path2, &stat2) == -1) {
      perror("lstat");
      continue;
    }
    if (S_ISDIR(stat1.st_mode) && S_ISDIR(stat2.st_mode)) {
      // Recursively synchronize the directories
      sync_dirs(path1, path2);
    } else {
      // Check if the entries are files
      if (S_ISREG(stat1.st_mode) && S_ISREG(stat2.st_mode)) {
        // Check if the files are the same size
        if (stat1.st_size != stat2.st_size) {
          // Copy the file from dir1 to dir2
          int fd1 = open(path1, O_RDONLY);
          int fd2 = open(path2, O_WRONLY | O_CREAT | O_TRUNC, stat1.st_mode);
          if (fd1 == -1 || fd2 == -1) {
            perror("open");
            continue;
          }
          char buffer[BUFFER_SIZE];
          ssize_t nread;
          while ((nread = read(fd1, buffer, BUFFER_SIZE)) > 0) {
            if (write(fd2, buffer, nread) == -1) {
              perror("write");
              break;
            }
          }
          if (nread == -1) {
            perror("read");
          }
          close(fd1);
          close(fd2);
        }
      } else {
        // The entries are not the same type
        // TODO: Handle this case
      }
    }
  }

  // Close the directory entries
  closedir(dp1);
  closedir(dp2);
}

// Main function
int main(int argc, char *argv[]) {
  // Check the arguments
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <dir1> <dir2>\n", argv[0]);
    return 1;
  }

  // Synchronize the directories
  sync_dirs(argv[1], argv[2]);

  return 0;
}