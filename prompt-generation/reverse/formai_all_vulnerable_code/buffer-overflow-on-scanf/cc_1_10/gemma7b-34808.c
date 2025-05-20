//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 10
#define MAX_FILE_SIZE 1024

typedef struct File {
  char name[MAX_FILE_SIZE];
  int size;
  time_t timestamp;
} File;

File files[MAX_FILES];

void backup_file() {
  FILE *fp;
  char filename[MAX_FILE_SIZE];
  int file_size;
  time_t timestamp;

  printf("Enter file name: ");
  scanf("%s", filename);

  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    return;
  }

  file_size = fread(files[0].name, 1, MAX_FILE_SIZE, fp);
  files[0].size = file_size;
  files[0].timestamp = time(NULL);

  fclose(fp);
}

void list_files() {
  int i;
  for (i = 0; i < MAX_FILES; i++) {
    if (files[i].name[0] != '\0') {
      printf("%s, %d bytes, %ld\n", files[i].name, files[i].size, files[i].timestamp);
    }
  }
}

int main() {
  int choice;

  printf("Enter 1 to back up a file, 2 to list files: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      backup_file();
      break;
    case 2:
      list_files();
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}