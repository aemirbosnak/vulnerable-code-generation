//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>

// Function to read QR code
int read_qr_code(char *filename) {
  int file = open(filename, O_RDONLY);
  if (file == -1) {
    printf("Error opening file\n");
    return 1;
  }
  struct stat statbuf;
  fstat(file, &statbuf);
  int size = statbuf.st_size;
  char *buffer = mmap(NULL, size, PROT_READ, MAP_SHARED, file, 0);
  if (buffer == MAP_FAILED) {
    printf("Error mapping file\n");
    return 1;
  }
  int i, j, k, count = 0;
  for (i = 0; i < size; i++) {
    if (buffer[i] == 0xff) {
      count++;
    }
  }
  if (count!= 1) {
    printf("Invalid QR code\n");
    return 1;
  }
  for (i = 0; i < size; i++) {
    if (buffer[i] == 0xff) {
      for (j = i - 1, k = 0; j >= 0 && k < 8; j--, k++) {
        if (buffer[j] & 1) {
          printf("1");
        } else {
          printf("0");
        }
      }
      printf("\n");
    }
  }
  munmap(buffer, size);
  close(file);
  return 0;
}

// Main function
int main(int argc, char *argv[]) {
  if (argc!= 2) {
    printf("Usage:./qr_reader <filename>\n");
    return 1;
  }
  read_qr_code(argv[1]);
  return 0;
}