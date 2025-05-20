//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>

int main(int argc, char *argv[]) {
  // Declare variables
  int fd;
  struct stat st;
  char *buf;
  int ret;
  struct timeval start, end;
  double elapsed;

  // Open the file
  fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("open");
    return EXIT_FAILURE;
  }

  // Get the file size
  if (fstat(fd, &st) == -1) {
    perror("fstat");
    return EXIT_FAILURE;
  }

  // Allocate a buffer to hold the file contents
  buf = malloc(st.st_size);
  if (buf == NULL) {
    perror("malloc");
    return EXIT_FAILURE;
  }

  // Read the file into the buffer
  ret = read(fd, buf, st.st_size);
  if (ret == -1) {
    perror("read");
    return EXIT_FAILURE;
  }

  // Close the file
  close(fd);

  // Get the start time
  gettimeofday(&start, NULL);

  // Perform some operations on the buffer
  for (int i = 0; i < st.st_size; i++) {
    buf[i] = toupper(buf[i]);
  }

  // Get the end time
  gettimeofday(&end, NULL);

  // Calculate the elapsed time
  elapsed = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;

  // Print the elapsed time
  printf("Elapsed time: %f ms\n", elapsed);

  // Free the buffer
  free(buf);

  return EXIT_SUCCESS;
}