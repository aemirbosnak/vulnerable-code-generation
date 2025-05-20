//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// Simple metadata extractor for a file

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Open the file
  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("open");
    return EXIT_FAILURE;
  }

  // Get the file size
  struct stat statbuf;
  if (fstat(fd, &statbuf) == -1) {
    perror("fstat");
    return EXIT_FAILURE;
  }

  // Read the file contents
  char *buf = malloc(statbuf.st_size + 1);
  if (buf == NULL) {
    perror("malloc");
    return EXIT_FAILURE;
  }

  if (read(fd, buf, statbuf.st_size) != statbuf.st_size) {
    perror("read");
    return EXIT_FAILURE;
  }

  // Close the file
  if (close(fd) == -1) {
    perror("close");
    return EXIT_FAILURE;
  }

  // Extract the metadata

  // File size
  printf("File size: %ld bytes\n", statbuf.st_size);

  // File type
  printf("File type: ");
  switch (statbuf.st_mode & S_IFMT) {
    case S_IFREG:
      printf("regular file\n");
      break;
    case S_IFDIR:
      printf("directory\n");
      break;
    case S_IFLNK:
      printf("symbolic link\n");
      break;
    case S_IFBLK:
      printf("block device\n");
      break;
    case S_IFCHR:
      printf("character device\n");
      break;
    case S_IFIFO:
      printf("FIFO\n");
      break;
    case S_IFSOCK:
      printf("socket\n");
      break;
    default:
      printf("unknown\n");
      break;
  }

  // File permissions
  printf("File permissions: %o\n", statbuf.st_mode & 0777);

  // File owner
  printf("File owner: %d\n", statbuf.st_uid);

  // File group
  printf("File group: %d\n", statbuf.st_gid);

  // File access time
  printf("File access time: %ld\n", statbuf.st_atime);

  // File modification time
  printf("File modification time: %ld\n", statbuf.st_mtime);

  // File change time
  printf("File change time: %ld\n", statbuf.st_ctime);

  // File content

  // Print the first 100 characters of the file
  printf("File content:\n");
  fwrite(buf, 1, 100, stdout);
  putchar('\n');

  // Free the buffer
  free(buf);

  return EXIT_SUCCESS;
}