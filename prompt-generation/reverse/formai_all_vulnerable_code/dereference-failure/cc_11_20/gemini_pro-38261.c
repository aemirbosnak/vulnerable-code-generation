//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  int fd = open(argv[1], O_RDWR);
  if (fd == -1) {
    perror("open");
    exit(EXIT_FAILURE);
  }

  struct stat st;
  if (fstat(fd, &st) == -1) {
    perror("fstat");
    exit(EXIT_FAILURE);
  }

  if (!S_ISREG(st.st_mode)) {
    fprintf(stderr, "%s is not a regular file\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  char *buf = malloc(st.st_size);
  if (buf == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  if (read(fd, buf, st.st_size) != st.st_size) {
    perror("read");
    exit(EXIT_FAILURE);
  }

  int i;
  for (i = 0; i < st.st_size; i++) {
    if (buf[i] == '\n') {
      buf[i] = '\0';
    }
  }

  int min = st.st_size;
  int start = 0;
  int end = st.st_size;

  for (i = 0; i < st.st_size; i++) {
    if (buf[i] == '\0') {
      if (i - start < min) {
        min = i - start;
        end = i;
      }
      start = i + 1;
    }
  }

  if (min == st.st_size) {
    fprintf(stderr, "No lines found in %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  int fd2 = open("optimized.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd2 == -1) {
    perror("open");
    exit(EXIT_FAILURE);
  }

  if (write(fd2, &buf[start], end - start) != end - start) {
    perror("write");
    exit(EXIT_FAILURE);
  }

  close(fd);
  close(fd2);
  free(buf);

  return EXIT_SUCCESS;
}