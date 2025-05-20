//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 4096

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <file> <key>\n", argv[0]);
    return 1;
  }

  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("open");
    return 1;
  }

  char *key = argv[2];
  size_t key_len = strlen(key);

  char *buf = malloc(BUF_SIZE);
  if (buf == NULL) {
    perror("malloc");
    return 1;
  }

  while (1) {
    ssize_t nread = read(fd, buf, BUF_SIZE);
    if (nread == -1) {
      perror("read");
      return 1;
    }

    if (nread == 0) {
      break;
    }

    for (size_t i = 0; i < nread; i++) {
      buf[i] = buf[i] ^ key[i % key_len];
    }

    ssize_t nwritten = write(STDOUT_FILENO, buf, nread);
    if (nwritten == -1) {
      perror("write");
      return 1;
    }
  }

  free(buf);
  close(fd);

  return 0;
}