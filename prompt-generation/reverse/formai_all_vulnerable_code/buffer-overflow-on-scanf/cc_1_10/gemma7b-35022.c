//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {

  system("/bin/clear");

  char filename[256];
  printf("Enter filename: ");
  scanf("%s", filename);

  FILE* file_ptr = fopen(filename, "r");
  if (file_ptr == NULL) {
    perror("Error opening file");
    exit(1);
  }

  long file_size = 0;
  while (!feof(file_ptr)) {
    file_size += read(fileno(file_ptr), NULL, 0);
  }

  fclose(file_ptr);

  char* buffer = malloc(file_size);
  if (buffer == NULL) {
    perror("Error allocating memory");
    exit(1);
  }

  file_ptr = fopen(filename, "r");
  if (file_ptr == NULL) {
    perror("Error opening file");
    exit(1);
  }

  read(fileno(file_ptr), buffer, file_size);
  fclose(file_ptr);

  char destination[256];
  printf("Enter destination: ");
  scanf("%s", destination);

  FILE* destination_ptr = fopen(destination, "w");
  if (destination_ptr == NULL) {
    perror("Error opening file");
    exit(1);
  }

  fwrite(buffer, file_size, 1, destination_ptr);
  fclose(destination_ptr);

  printf("File successfully backed up.\n");

  return 0;
}