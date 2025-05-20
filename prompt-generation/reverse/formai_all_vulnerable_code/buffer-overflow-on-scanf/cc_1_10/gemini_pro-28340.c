//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_SIZE 1024

struct file_info {
  char name[256];
  int size;
};

int main() {
  // Declaring variables
  char source_file[256];
  char backup_file[256];
  struct file_info files[MAX_FILES];
  int num_files = 0;
  int i;

  // Prompting the user for the source file
  printf("Enter the name of the source file: ");
  scanf("%s", source_file);

  // Prompting the user for the backup file
  printf("Enter the name of the backup file: ");
  scanf("%s", backup_file);

  // Opening the source file
  FILE *source = fopen(source_file, "rb");
  if (source == NULL) {
    printf("Error opening the source file.\n");
    return 1;
  }

  // Reading the contents of the source file
  int c;
  while ((c = fgetc(source)) != EOF) {
    files[num_files].name[num_files] = c;
    num_files++;
  }

  // Closing the source file
  fclose(source);

  // Opening the backup file
  FILE *backup = fopen(backup_file, "wb");
  if (backup == NULL) {
    printf("Error opening the backup file.\n");
    return 1;
  }

  // Writing the contents of the backup file
  for (i = 0; i < num_files; i++) {
    fwrite(files[i].name, 1, files[i].size, backup);
  }

  // Closing the backup file
  fclose(backup);

  printf("The files have been backed up successfully.\n");

  return 0;
}