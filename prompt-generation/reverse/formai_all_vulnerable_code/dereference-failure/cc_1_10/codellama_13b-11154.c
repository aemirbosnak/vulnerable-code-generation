//Code Llama-13B DATASET v1.0 Category: System administration ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int fd;
  char buffer[BUFFER_SIZE];
  char *filepath = argv[1];
  char *output = argv[2];

  fd = open(filepath, O_RDONLY);
  if (fd < 0) {
    printf("Error opening file: %s\n", strerror(errno));
    return 1;
  }

  while (read(fd, buffer, BUFFER_SIZE) > 0) {
    if (write(STDOUT_FILENO, buffer, BUFFER_SIZE) < 0) {
      printf("Error writing to stdout: %s\n", strerror(errno));
      return 1;
    }
  }

  if (close(fd) < 0) {
    printf("Error closing file: %s\n", strerror(errno));
    return 1;
  }

  if (output != NULL) {
    fd = open(output, O_WRONLY | O_CREAT, 0644);
    if (fd < 0) {
      printf("Error opening file: %s\n", strerror(errno));
      return 1;
    }

    while (read(STDIN_FILENO, buffer, BUFFER_SIZE) > 0) {
      if (write(fd, buffer, BUFFER_SIZE) < 0) {
        printf("Error writing to file: %s\n", strerror(errno));
        return 1;
      }
    }

    if (close(fd) < 0) {
      printf("Error closing file: %s\n", strerror(errno));
      return 1;
    }
  }

  return 0;
}