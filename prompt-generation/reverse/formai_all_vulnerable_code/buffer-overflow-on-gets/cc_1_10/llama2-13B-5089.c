//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_SIZE 1024
#define MAX_BUFFER_SIZE 512

// Function to read a file line by line
void read_file(char *filename) {
  int fd = open(filename, O_RDONLY);
  char buffer[MAX_BUFFER_SIZE];
  char *line = NULL;

  if (fd == -1) {
    perror("Error opening file");
    return;
  }

  while ((read(fd, buffer, MAX_BUFFER_SIZE)) > 0) {
    line = strtok(buffer, "\n");
    if (line != NULL) {
      printf("%s", line);
    }
  }

  close(fd);
}

// Function to write a file line by line
void write_file(char *filename) {
  int fd = open(filename, O_WRONLY | O_CREAT, 0666);
  char buffer[MAX_BUFFER_SIZE];
  char *line = NULL;

  if (fd == -1) {
    perror("Error creating file");
    return;
  }

  while ((line = gets(buffer)) != NULL) {
    write(fd, line, strlen(line));
    printf("%s", line);
  }

  close(fd);
}

int main() {
  char *filename = "example.txt";

  // Read the file line by line
  read_file(filename);

  // Write a new line to the file
  write_file(filename);

  return 0;
}