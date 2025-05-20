//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/stat.h>

#define SECTOR_SIZE 512
#define MAX_SECTORS 1024

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
    return 1;
  }

  // Open the input file.
  FILE *input = fopen(argv[1], "rb");
  if (input == NULL) {
    perror("fopen(input)");
    return 1;
  }

  // Get the size of the input file.
  struct stat statbuf;
  if (fstat(fileno(input), &statbuf) == -1) {
    perror("fstat(input)");
    fclose(input);
    return 1;
  }

  // Create a buffer to hold the input file's data.
  uint8_t *buffer = malloc(statbuf.st_size);
  if (buffer == NULL) {
    perror("malloc");
    fclose(input);
    return 1;
  }

  // Read the input file's data into the buffer.
  size_t bytes_read = fread(buffer, 1, statbuf.st_size, input);
  if (bytes_read != statbuf.st_size) {
    perror("fread");
    fclose(input);
    free(buffer);
    return 1;
  }

  // Close the input file.
  fclose(input);

  // Open the output file.
  FILE *output = fopen(argv[2], "wb");
  if (output == NULL) {
    perror("fopen(output)");
    free(buffer);
    return 1;
  }

  // Initialize the sector buffer.
  uint8_t sector_buffer[SECTOR_SIZE];

  // Loop through the input file's data, sector by sector.
  for (size_t i = 0; i < bytes_read; i += SECTOR_SIZE) {
    // Copy the sector's data into the sector buffer.
    memcpy(sector_buffer, buffer + i, SECTOR_SIZE);

    // Check if the sector's data is valid.
    if (sector_buffer[0] != 0x55 || sector_buffer[SECTOR_SIZE - 1] != 0xaa) {
      continue;
    }

    // Write the sector's data to the output file.
    if (fwrite(sector_buffer, 1, SECTOR_SIZE, output) != SECTOR_SIZE) {
      perror("fwrite");
      fclose(output);
      free(buffer);
      return 1;
    }
  }

  // Close the output file.
  fclose(output);

  // Free the buffer.
  free(buffer);

  return 0;
}