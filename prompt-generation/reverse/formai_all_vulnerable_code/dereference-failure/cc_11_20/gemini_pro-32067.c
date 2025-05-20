//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <source file> <destination file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Open source file
  int fd_src = open(argv[1], O_RDONLY);
  if (fd_src == -1) {
    perror("open");
    exit(EXIT_FAILURE);
  }

  // Get source file size
  struct stat stat_src;
  if (fstat(fd_src, &stat_src) == -1) {
    perror("fstat");
    exit(EXIT_FAILURE);
  }

  // Memory map source file
  char *src_map = mmap(NULL, stat_src.st_size, PROT_READ, MAP_PRIVATE, fd_src, 0);
  if (src_map == MAP_FAILED) {
    perror("mmap");
    exit(EXIT_FAILURE);
  }

  // Open destination file
  int fd_dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd_dst == -1) {
    perror("open");
    exit(EXIT_FAILURE);
  }

  // Memory map destination file
  char *dst_map = mmap(NULL, stat_src.st_size, PROT_WRITE, MAP_SHARED, fd_dst, 0);
  if (dst_map == MAP_FAILED) {
    perror("mmap");
    exit(EXIT_FAILURE);
  }

  // Copy data from source file to destination file
  memcpy(dst_map, src_map, stat_src.st_size);

  // Flush destination file
  if (msync(dst_map, stat_src.st_size, MS_SYNC) == -1) {
    perror("msync");
    exit(EXIT_FAILURE);
  }

  // Unmap destination file
  if (munmap(dst_map, stat_src.st_size) == -1) {
    perror("munmap");
    exit(EXIT_FAILURE);
  }

  // Unmap source file
  if (munmap(src_map, stat_src.st_size) == -1) {
    perror("munmap");
    exit(EXIT_FAILURE);
  }

  // Close destination file
  if (close(fd_dst) == -1) {
    perror("close");
    exit(EXIT_FAILURE);
  }

  // Close source file
  if (close(fd_src) == -1) {
    perror("close");
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}