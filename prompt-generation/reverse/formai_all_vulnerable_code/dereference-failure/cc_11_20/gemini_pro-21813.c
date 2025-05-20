//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_FILE_SIZE 1024 * 1024

int main(int argc, char **argv) {
  if (argc < 4) {
    fprintf(stderr, "Usage: %s <source-file> <target-file> <block-size>\n", argv[0]);
    return 1;
  }

  char *source_file = argv[1];
  char *target_file = argv[2];
  int block_size = atoi(argv[3]);

  if (block_size <= 0 || block_size > MAX_FILE_SIZE) {
    fprintf(stderr, "Invalid block size: %d\n", block_size);
    return 1;
  }

  struct stat source_stat, target_stat;
  if (stat(source_file, &source_stat) < 0) {
    perror("stat");
    return 1;
  }

  if (stat(target_file, &target_stat) < 0) {
    perror("stat");
    return 1;
  }

  if (source_stat.st_size != target_stat.st_size) {
    fprintf(stderr, "Files have different sizes\n");
    return 1;
  }

  int source_fd = open(source_file, O_RDONLY);
  if (source_fd < 0) {
    perror("open");
    return 1;
  }

  int target_fd = open(target_file, O_WRONLY | O_TRUNC);
  if (target_fd < 0) {
    perror("open");
    return 1;
  }

  char buffer[block_size];
  int bytes_read;

  while ((bytes_read = read(source_fd, buffer, block_size)) > 0) {
    if (write(target_fd, buffer, bytes_read) < 0) {
      perror("write");
      return 1;
    }
  }

  if (bytes_read < 0) {
    perror("read");
    return 1;
  }

  close(source_fd);
  close(target_fd);

  return 0;
}