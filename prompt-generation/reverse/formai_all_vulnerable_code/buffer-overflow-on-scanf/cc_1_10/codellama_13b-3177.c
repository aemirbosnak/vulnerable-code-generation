//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: grateful
/*
 * File Encryptor - Encrypts a file using a simple Caesar Cipher
 *
 * Usage: ./file_encryptor [input_file] [output_file]
 *
 * Note: The input_file and output_file arguments are optional.
 * If not provided, the program will prompt the user to enter the file names.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define KEY 3

int main(int argc, char *argv[]) {
  int input_fd, output_fd;
  char input_file[100], output_file[100];
  char buffer[100];
  int count;

  if (argc == 1) {
    printf("Enter the input file name: ");
    scanf("%s", input_file);
    printf("Enter the output file name: ");
    scanf("%s", output_file);
  } else if (argc == 2) {
    strcpy(input_file, argv[1]);
    strcpy(output_file, argv[2]);
  } else {
    printf("Invalid number of arguments. Exiting...\n");
    return 1;
  }

  // Open the input file
  input_fd = open(input_file, O_RDONLY);
  if (input_fd == -1) {
    printf("Failed to open input file: %s\n", strerror(errno));
    return 1;
  }

  // Open the output file
  output_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (output_fd == -1) {
    printf("Failed to open output file: %s\n", strerror(errno));
    return 1;
  }

  // Encrypt the file
  while ((count = read(input_fd, buffer, 100)) > 0) {
    for (int i = 0; i < count; i++) {
      buffer[i] = (buffer[i] + KEY) % 26 + 'A';
    }
    write(output_fd, buffer, count);
  }

  // Close the files
  close(input_fd);
  close(output_fd);

  return 0;
}