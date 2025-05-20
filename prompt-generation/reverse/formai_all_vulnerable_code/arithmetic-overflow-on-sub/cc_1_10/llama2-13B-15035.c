//LLAMA2-13B DATASET v1.0 Category: Data recovery tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void recover_file(char *filename) {
  int fd, i, j;
  off_t start, end;
  char buffer[BUFFER_SIZE];
  struct stat stat_info;

  if (stat(filename, &stat_info) == -1) {
    perror("stat");
    return;
  }

  start = stat_info.st_size;
  end = start - BUFFER_SIZE;

  if (end < 0) {
    end = 0;
  }

  for (i = end; i <= start; i += BUFFER_SIZE) {
    if (read(fd, buffer, BUFFER_SIZE) == -1) {
      perror("read");
      return;
    }

    for (j = 0; j < BUFFER_SIZE; j++) {
      if (buffer[j] == 0x0A) { // 0x0A is the newline character
        break;
      }
    }

    if (j != 0) {
      // Found a newline character, so this is the end of the file
      break;
    }

    // Append the buffer to the recovered file
    if (write(fd, buffer, BUFFER_SIZE) == -1) {
      perror("write");
      return;
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
    return 1;
  }

  // Open the file in read-write mode
  int fd = open(argv[1], O_RDWR | O_NONBLOCK);
  if (fd == -1) {
    perror("open");
    return 1;
  }

  // Recover the file
  recover_file(argv[1]);

  // Close the file
  close(fd);

  return 0;
}