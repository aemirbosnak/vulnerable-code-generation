//Code Llama-13B DATASET v1.0 Category: Temperature monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define MAX_TEMP_FILE_PATH 100
#define MAX_TEMP_READ_SIZE 100

int main(int argc, char *argv[]) {
  // Check for command line arguments
  if (argc != 2) {
    printf("Usage: %s <temperature_file_path>\n", argv[0]);
    return 1;
  }

  // Open the temperature file
  char temp_file_path[MAX_TEMP_FILE_PATH];
  strcpy(temp_file_path, argv[1]);
  int temp_fd = open(temp_file_path, O_RDONLY);
  if (temp_fd < 0) {
    printf("Error opening temperature file: %s\n", strerror(errno));
    return 1;
  }

  // Read the temperature from the file
  char temp_buf[MAX_TEMP_READ_SIZE];
  int temp_read_size = read(temp_fd, temp_buf, MAX_TEMP_READ_SIZE);
  if (temp_read_size < 0) {
    printf("Error reading temperature file: %s\n", strerror(errno));
    return 1;
  }

  // Parse the temperature value from the file
  float temperature;
  if (sscanf(temp_buf, "%f", &temperature) != 1) {
    printf("Error parsing temperature value: %s\n", temp_buf);
    return 1;
  }

  // Print the temperature value
  printf("Temperature: %.2f C\n", temperature);

  // Close the temperature file
  close(temp_fd);

  return 0;
}