//Code Llama-13B DATASET v1.0 Category: File Synchronizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_PATH_LENGTH 1024
#define MAX_NAME_LENGTH 256
#define MAX_FILES 1024

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <directory>\n", argv[0]);
    return 1;
  }

  char *directory = argv[1];

  DIR *dir = opendir(directory);
  if (dir == NULL) {
    perror("opendir");
    return 1;
  }

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    char path[MAX_PATH_LENGTH];
    snprintf(path, MAX_PATH_LENGTH, "%s/%s", directory, entry->d_name);

    struct stat file_stat;
    if (stat(path, &file_stat) == -1) {
      perror("stat");
      continue;
    }

    if (file_stat.st_ino == 0) {
      continue;
    }

    if (S_ISDIR(file_stat.st_mode)) {
      continue;
    }

    char *file_name = entry->d_name;
    char *ext = strrchr(file_name, '.');
    if (ext == NULL) {
      continue;
    }

    if (strcmp(ext, ".txt") != 0) {
      continue;
    }

    int fd = open(path, O_RDONLY);
    if (fd == -1) {
      perror("open");
      continue;
    }

    char buffer[1024];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
      perror("read");
      close(fd);
      continue;
    }

    char *line = strtok(buffer, "\n");
    while (line != NULL) {
      printf("%s\n", line);
      line = strtok(NULL, "\n");
    }

    close(fd);
  }

  closedir(dir);
  return 0;
}