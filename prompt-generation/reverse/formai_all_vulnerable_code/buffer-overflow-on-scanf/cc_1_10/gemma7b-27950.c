//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILE_NAME_LENGTH 255
#define BUFFER_SIZE 4096

int main() {
  char filename[FILE_NAME_LENGTH];
  char buffer[BUFFER_SIZE];
  time_t timestamp;
  int file_size;

  printf("Enter file name: ");
  scanf("%s", filename);

  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }

  fseek(file, 0, SEEK_END);
  file_size = ftell(file);

  rewind(file);

  timestamp = time(NULL);
  sprintf(buffer, "backup_%d_%d_%d_%s.bak", timestamp, file_size, file_size, filename);

  FILE *backup = fopen(buffer, "w");
  if (backup == NULL) {
    printf("Error creating backup file.\n");
    fclose(file);
    exit(1);
  }

  int read_size;
  while ((read_size = read(file, buffer, BUFFER_SIZE)) > 0) {
    fwrite(buffer, read_size, 1, backup);
  }

  fclose(file);
  fclose(backup);

  printf("File backup complete.\n");

  return 0;
}