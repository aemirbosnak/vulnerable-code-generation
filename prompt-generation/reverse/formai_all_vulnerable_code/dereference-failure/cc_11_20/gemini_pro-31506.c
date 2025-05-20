//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define PAGE_SIZE 4096

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Open the files
  int fd1 = open(argv[1], O_RDONLY);
  if (fd1 == -1) {
    perror("open");
    return EXIT_FAILURE;
  }
  int fd2 = open(argv[2], O_RDWR);
  if (fd2 == -1) {
    perror("open");
    return EXIT_FAILURE;
  }

  // Get the file sizes
  struct stat stat1;
  if (fstat(fd1, &stat1) == -1) {
    perror("fstat");
    return EXIT_FAILURE;
  }
  struct stat stat2;
  if (fstat(fd2, &stat2) == -1) {
    perror("fstat");
    return EXIT_FAILURE;
  }

  // Memory map the files
  char *map1 = mmap(NULL, stat1.st_size, PROT_READ, MAP_PRIVATE, fd1, 0);
  if (map1 == MAP_FAILED) {
    perror("mmap");
    return EXIT_FAILURE;
  }
  char *map2 = mmap(NULL, stat2.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd2, 0);
  if (map2 == MAP_FAILED) {
    perror("mmap");
    return EXIT_FAILURE;
  }

  // Compare the files
  int diff = memcmp(map1, map2, stat1.st_size);

  // Unmap the files
  if (munmap(map1, stat1.st_size) == -1) {
    perror("munmap");
    return EXIT_FAILURE;
  }
  if (munmap(map2, stat2.st_size) == -1) {
    perror("munmap");
    return EXIT_FAILURE;
  }

  // Close the files
  if (close(fd1) == -1) {
    perror("close");
    return EXIT_FAILURE;
  }
  if (close(fd2) == -1) {
    perror("close");
    return EXIT_FAILURE;
  }

  // Print the result
  if (diff == 0) {
    printf("The files are identical.\n");
  } else {
    printf("The files are different.\n");
  }

  return EXIT_SUCCESS;
}