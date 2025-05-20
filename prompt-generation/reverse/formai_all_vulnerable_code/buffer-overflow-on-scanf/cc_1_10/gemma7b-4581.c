//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main() {
  char source_path[256];
  char destination_path[256];
  char filename[256];
  int file_size;
  FILE *fp;
  struct stat sb;
  char buffer[BUFFER_SIZE];

  printf("Enter source path: ");
  scanf("%s", source_path);

  printf("Enter destination path: ");
  scanf("%s", destination_path);

  printf("Enter filename: ");
  scanf("%s", filename);

  stat(source_path, &sb);
  file_size = sb.st_size;

  fp = fopen(source_path, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  fp = fopen(destination_path, "w");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  while (!feof(fp)) {
    read(fp, buffer, BUFFER_SIZE);
    fwrite(buffer, BUFFER_SIZE, 1, fp);
  }

  fclose(fp);
  fclose(fp);

  printf("File backup complete.\n");

  return 0;
}