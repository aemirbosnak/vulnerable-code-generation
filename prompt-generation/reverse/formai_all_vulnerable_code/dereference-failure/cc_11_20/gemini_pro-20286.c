//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <source directory> <destination directory>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *source_directory = argv[1];
  char *destination_directory = argv[2];

  DIR *source_dir = opendir(source_directory);
  if (source_dir == NULL) {
    perror("opendir");
    return EXIT_FAILURE;
  }

  struct dirent *source_dirent;
  while ((source_dirent = readdir(source_dir)) != NULL) {
    if (strcmp(source_dirent->d_name, ".") == 0 || strcmp(source_dirent->d_name, "..") == 0) {
      continue;
    }

    char *source_file = malloc(strlen(source_directory) + strlen(source_dirent->d_name) + 2);
    if (source_file == NULL) {
      perror("malloc");
      closedir(source_dir);
      return EXIT_FAILURE;
    }

    sprintf(source_file, "%s/%s", source_directory, source_dirent->d_name);

    struct stat source_stat;
    if (stat(source_file, &source_stat) == -1) {
      perror("stat");
      free(source_file);
      closedir(source_dir);
      return EXIT_FAILURE;
    }

    if (S_ISDIR(source_stat.st_mode)) {
      char *destination_subdirectory = malloc(strlen(destination_directory) + strlen(source_dirent->d_name) + 2);
      if (destination_subdirectory == NULL) {
        perror("malloc");
        free(source_file);
        closedir(source_dir);
        return EXIT_FAILURE;
      }

      sprintf(destination_subdirectory, "%s/%s", destination_directory, source_dirent->d_name);

      if (mkdir(destination_subdirectory, source_stat.st_mode) == -1) {
        perror("mkdir");
        free(source_file);
        free(destination_subdirectory);
        closedir(source_dir);
        return EXIT_FAILURE;
      }

      free(destination_subdirectory);
    } else {
      char *destination_file = malloc(strlen(destination_directory) + strlen(source_dirent->d_name) + 2);
      if (destination_file == NULL) {
        perror("malloc");
        free(source_file);
        closedir(source_dir);
        return EXIT_FAILURE;
      }

      sprintf(destination_file, "%s/%s", destination_directory, source_dirent->d_name);

      int source_fd = open(source_file, O_RDONLY);
      if (source_fd == -1) {
        perror("open");
        free(source_file);
        free(destination_file);
        closedir(source_dir);
        return EXIT_FAILURE;
      }

      int destination_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, source_stat.st_mode);
      if (destination_fd == -1) {
        perror("open");
        close(source_fd);
        free(source_file);
        free(destination_file);
        closedir(source_dir);
        return EXIT_FAILURE;
      }

      char buffer[BUFFER_SIZE];
      ssize_t bytes_read;
      while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(destination_fd, buffer, bytes_read) != bytes_read) {
          perror("write");
          close(source_fd);
          close(destination_fd);
          free(source_file);
          free(destination_file);
          closedir(source_dir);
          return EXIT_FAILURE;
        }
      }

      if (bytes_read == -1) {
        perror("read");
        close(source_fd);
        close(destination_fd);
        free(source_file);
        free(destination_file);
        closedir(source_dir);
        return EXIT_FAILURE;
      }

      close(source_fd);
      close(destination_fd);
      free(source_file);
      free(destination_file);
    }
  }

  closedir(source_dir);
  return EXIT_SUCCESS;
}