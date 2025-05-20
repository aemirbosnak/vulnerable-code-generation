//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>

#define PAGE_SIZE (4*1024)
#define MIN_FILE_SIZE (10*1024)

int main(int argc, char *argv[]) {
  int fd, count;
  char *addr;
  struct stat statbuf;
  int pages;
  int i;

  if (argc!= 2) {
    printf("Usage: %s filename\n", argv[0]);
    exit(1);
  }

  fd = open(argv[1], O_RDWR);
  if (fd < 0) {
    printf("Error opening file: %s\n", strerror(errno));
    exit(1);
  }

  if (fstat(fd, &statbuf) < 0) {
    printf("Error getting file status: %s\n", strerror(errno));
    exit(1);
  }

  if (statbuf.st_size < MIN_FILE_SIZE) {
    printf("File too small to optimize\n");
    exit(1);
  }

  count = statbuf.st_size / PAGE_SIZE;
  pages = count + (count % 2);
  addr = mmap(NULL, pages * PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (addr == MAP_FAILED) {
    printf("Error mapping file: %s\n", strerror(errno));
    exit(1);
  }

  for (i = 0; i < count; i++) {
    if (i % 2 == 0) {
      memcpy(addr + i * PAGE_SIZE, addr + (i + 1) * PAGE_SIZE, PAGE_SIZE);
    }
  }

  munmap(addr, pages * PAGE_SIZE);
  close(fd);

  printf("File optimized successfully\n");
  return 0;
}