//Code Llama-13B DATASET v1.0 Category: File Synchronizer ; Style: thoughtful
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <errno.h>
  #include <unistd.h>
  #include <sys/types.h>
  #include <sys/stat.h>
  #include <fcntl.h>
  #include <sys/mman.h>

  #define BUF_SIZE 4096

  int main(int argc, char *argv[]) {
      if (argc != 3) {
          fprintf(stderr, "Usage: %s <src> <dst>\n", argv[0]);
          return 1;
      }

      char *src = argv[1];
      char *dst = argv[2];

      int src_fd = open(src, O_RDONLY);
      if (src_fd < 0) {
          perror("open");
          return 1;
      }

      int dst_fd = open(dst, O_WRONLY | O_CREAT, 0644);
      if (dst_fd < 0) {
          perror("open");
          return 1;
      }

      char *src_buf = mmap(NULL, BUF_SIZE, PROT_READ, MAP_PRIVATE, src_fd, 0);
      if (src_buf == MAP_FAILED) {
          perror("mmap");
          return 1;
      }

      char *dst_buf = mmap(NULL, BUF_SIZE, PROT_WRITE, MAP_PRIVATE, dst_fd, 0);
      if (dst_buf == MAP_FAILED) {
          perror("mmap");
          return 1;
      }

      off_t src_size = lseek(src_fd, 0, SEEK_END);
      if (src_size < 0) {
          perror("lseek");
          return 1;
      }

      lseek(dst_fd, 0, SEEK_SET);

      while (src_size > 0) {
          size_t size = src_size > BUF_SIZE ? BUF_SIZE : src_size;
          memcpy(dst_buf, src_buf, size);
          src_size -= size;
      }

      munmap(src_buf, BUF_SIZE);
      munmap(dst_buf, BUF_SIZE);

      close(src_fd);
      close(dst_fd);

      return 0;
  }