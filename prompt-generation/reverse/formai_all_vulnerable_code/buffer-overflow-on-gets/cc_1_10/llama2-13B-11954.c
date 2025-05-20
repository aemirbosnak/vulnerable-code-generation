//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_SIZE 1024 * 1024 * 50
#define MAX_BUFFER_SIZE 1024 * 1024

// Function to read a file and print its contents
void read_file(const char *filename) {
  int fd = open(filename, O_RDONLY);
  if (fd == -1) {
    perror("Error opening file");
    return;
  }

  char buffer[MAX_BUFFER_SIZE];
  size_t bytes_read = read(fd, buffer, MAX_BUFFER_SIZE);
  if (bytes_read == -1) {
    perror("Error reading file");
    close(fd);
    return;
  }

  printf("File contents:\n%s", buffer);

  close(fd);
}

// Function to write a file and print its contents
void write_file(const char *filename) {
  int fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
  if (fd == -1) {
    perror("Error creating file");
    return;
  }

  char buffer[MAX_BUFFER_SIZE];
  gets(buffer); // Get the input from the user
  write(fd, buffer, strlen(buffer));

  close(fd);
}

int main() {
  // Example usage of read_file and write_file functions
  read_file("example.txt");
  write_file("new_file.txt");

  return 0;
}