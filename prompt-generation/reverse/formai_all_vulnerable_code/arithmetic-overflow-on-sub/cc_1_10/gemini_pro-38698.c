//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int main() {
  // Get the current time
  struct timeval start, end;
  gettimeofday(&start, NULL);

  // Download a file of known size
  FILE *fp = fopen("http://example.com/test.bin", "rb");
  if (fp == NULL) {
    perror("fopen");
    return -1;
  }

  // Read the file into a buffer
  int buffer_size = 1024 * 1024;  // 1 MB
  char *buffer = malloc(buffer_size);
  if (buffer == NULL) {
    perror("malloc");
    fclose(fp);
    return -1;
  }

  int bytes_read = 0;
  while ((bytes_read = fread(buffer, 1, buffer_size, fp)) > 0) {
    // Do nothing with the data, just read it
  }

  // Close the file
  fclose(fp);

  // Get the current time again
  gettimeofday(&end, NULL);

  // Calculate the time taken to download the file
  double seconds = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

  // Calculate the download speed
  double speed = bytes_read / seconds;

  // Convert the speed to megabits per second
  speed /= 1024 * 1024;

  // Print the download speed
  printf("Download speed: %.2f Mbps\n", speed);

  // Free the buffer
  free(buffer);

  return 0;
}