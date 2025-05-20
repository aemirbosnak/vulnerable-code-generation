//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 4096

int main(void) {
  // Get the name of the file to be backed up.
  char *filename;
  printf("Enter the name of the file to be backed up: ");
  scanf("%s", filename);

  // Get the name of the destination file.
  char *destFilename;
  printf("Enter the name of the destination file: ");
  scanf("%s", destFilename);

  // Open the source file.
  int fd = open(filename, O_RDONLY);
  if (fd < 0) {
    perror("Could not open the source file.");
    return EXIT_FAILURE;
  }

  // Open the destination file.
  int fd2 = open(destFilename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd2 < 0) {
    perror("Could not open the destination file.");
    return EXIT_FAILURE;
  }

  // Read from the source file and write to the destination file.
  char buf[BUF_SIZE];
  int bytesRead;
  while ((bytesRead = read(fd, buf, BUF_SIZE)) > 0) {
    if (write(fd2, buf, bytesRead) < 0) {
      perror("Could not write to the destination file.");
      return EXIT_FAILURE;
    }
  }

  // Close the files.
  close(fd);
  close(fd2);

  // Tell the user that the file was successfully backed up.
  printf("The file was successfully backed up.\n");

  return EXIT_SUCCESS;
}