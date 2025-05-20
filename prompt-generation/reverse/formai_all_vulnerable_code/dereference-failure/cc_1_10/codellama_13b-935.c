//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 100
#define MAX_BACKUP_NAME_LENGTH 50

typedef struct {
  char filename[MAX_FILENAME_LENGTH];
  char backup_name[MAX_BACKUP_NAME_LENGTH];
  time_t timestamp;
} file_info;

void create_backup(char* filename) {
  char backup_name[MAX_BACKUP_NAME_LENGTH];
  snprintf(backup_name, MAX_BACKUP_NAME_LENGTH, "%s.bak", filename);
  FILE* src = fopen(filename, "r");
  FILE* dst = fopen(backup_name, "w");
  char buffer[1024];
  while (fgets(buffer, 1024, src)) {
    fputs(buffer, dst);
  }
  fclose(src);
  fclose(dst);
}

void print_backup_info(file_info* files, int num_files) {
  for (int i = 0; i < num_files; i++) {
    printf("File: %s\n", files[i].filename);
    printf("Backup: %s\n", files[i].backup_name);
    printf("Timestamp: %s\n", ctime(&files[i].timestamp));
  }
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: %s <filename> [filename2] ...\n", argv[0]);
    return 1;
  }

  int num_files = argc - 1;
  file_info* files = malloc(num_files * sizeof(file_info));

  for (int i = 0; i < num_files; i++) {
    strcpy(files[i].filename, argv[i + 1]);
    create_backup(files[i].filename);
    files[i].timestamp = time(NULL);
  }

  print_backup_info(files, num_files);

  free(files);
  return 0;
}