//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
  char *path = "/proc";
  struct stat statbuf;
  int fd;
  char buf[1024];
  int n;

  // Open the /proc directory
  fd = open(path, O_RDONLY);
  if (fd == -1) {
    perror("open");
    exit(EXIT_FAILURE);
  }

  // Get the stat structure for the /proc directory
  if (fstat(fd, &statbuf) == -1) {
    perror("fstat");
    exit(EXIT_FAILURE);
  }

  // Check if the /proc directory is a directory
  if (!S_ISDIR(statbuf.st_mode)) {
    fprintf(stderr, "%s is not a directory\n", path);
    exit(EXIT_FAILURE);
  }

  // Read the /proc directory
  while ((n = readdir(fd, buf)) > 0) {
    // Check if the entry is a directory
    if (buf[n - 1] == '/') {
      // Open the process directory
      char *procpath = malloc(strlen(path) + n + 1);
      strcpy(procpath, path);
      strcat(procpath, buf);
      int procfd = open(procpath, O_RDONLY);
      if (procfd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
      }

      // Get the stat structure for the process directory
      if (fstat(procfd, &statbuf) == -1) {
        perror("fstat");
        exit(EXIT_FAILURE);
      }

      // Check if the process directory is a directory
      if (!S_ISDIR(statbuf.st_mode)) {
        fprintf(stderr, "%s is not a directory\n", procpath);
        exit(EXIT_FAILURE);
      }

      // Read the process directory
      while ((n = readdir(procfd, buf)) > 0) {
        // Check if the entry is a file
        if (buf[n - 1] != '/') {
          // Open the file
          char *filepath = malloc(strlen(procpath) + n + 1);
          strcpy(filepath, procpath);
          strcat(filepath, buf);
          int filefd = open(filepath, O_RDONLY);
          if (filefd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
          }

          // Read the file
          char *filebuf = malloc(1024);
          int m;
          while ((m = read(filefd, filebuf, 1024)) > 0) {
            // Process the file
            printf("%s", filebuf);
          }

          // Close the file
          close(filefd);
          free(filepath);
        }
      }

      // Close the process directory
      close(procfd);
      free(procpath);
    }
  }

  // Close the /proc directory
  close(fd);

  return EXIT_SUCCESS;
}