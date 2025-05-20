//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: intelligent
/*
 * A unique C File Encryptor example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define KEY_SIZE 16

int main(int argc, char **argv) {
  char *input_file = argv[1];
  char *output_file = argv[2];
  char *key = argv[3];

  // Check if input file exists
  if (access(input_file, F_OK) != 0) {
    printf("Error: input file does not exist\n");
    return 1;
  }

  // Check if key is valid
  if (strlen(key) != KEY_SIZE) {
    printf("Error: key must be 16 characters long\n");
    return 1;
  }

  // Open input file
  int input_fd = open(input_file, O_RDONLY);
  if (input_fd < 0) {
    printf("Error: cannot open input file\n");
    return 1;
  }

  // Open output file
  int output_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
  if (output_fd < 0) {
    printf("Error: cannot open output file\n");
    return 1;
  }

  // Encrypt input file
  char buffer[BUFFER_SIZE];
  int bytes_read;
  while ((bytes_read = read(input_fd, buffer, BUFFER_SIZE)) > 0) {
    for (int i = 0; i < bytes_read; i++) {
      buffer[i] = buffer[i] ^ key[i % KEY_SIZE];
    }
    write(output_fd, buffer, bytes_read);
  }

  // Close files
  close(input_fd);
  close(output_fd);

  printf("File encrypted successfully\n");
  return 0;
}