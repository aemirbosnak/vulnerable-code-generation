//GEMINI-pro DATASET v1.0 Category: System administration ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char **argv) {
  // Check if the user has provided enough arguments.
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <file> <pattern>\n", argv[0]);
    exit(1);
  }

  // Open the file for reading.
  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("open");
    exit(1);
  }

  // Get the size of the file.
  struct stat st;
  if (fstat(fd, &st) == -1) {
    perror("fstat");
    exit(1);
  }

  // Allocate a buffer for the file contents.
  char *buf = malloc(st.st_size + 1);
  if (buf == NULL) {
    perror("malloc");
    exit(1);
  }

  // Read the file contents into the buffer.
  if (read(fd, buf, st.st_size) == -1) {
    perror("read");
    exit(1);
  }

  // Close the file.
  if (close(fd) == -1) {
    perror("close");
    exit(1);
  }

  // Add a null terminator to the buffer.
  buf[st.st_size] = '\0';

  // Search for the pattern in the buffer.
  char *ptr = strstr(buf, argv[2]);
  if (ptr == NULL) {
    printf("Pattern not found.\n");
  } else {
    printf("Pattern found at offset %ld.\n", ptr - buf);
  }

  // Free the buffer.
  free(buf);

  return 0;
}