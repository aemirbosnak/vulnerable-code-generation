//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

#define BUF_SIZE 4096
#define MAX_FILENAME_SIZE 256

typedef struct {
  char name[MAX_FILENAME_SIZE];
  char extension[MAX_FILENAME_SIZE];
} filename_t;

typedef struct {
  char name[MAX_FILENAME_SIZE];
  char extension[MAX_FILENAME_SIZE];
  time_t last_modified;
  int file_size;
} file_info_t;

int main(int argc, char *argv[]) {
  char source_path[MAX_FILENAME_SIZE];
  char dest_path[MAX_FILENAME_SIZE];
  int backup_interval;
  int num_files;
  int i;
  DIR *dir;
  struct dirent *entry;
  struct stat statbuf;
  char file_path[MAX_FILENAME_SIZE];
  char backup_path[MAX_FILENAME_SIZE];
  filename_t filename;
  file_info_t file_info;
  FILE *source_file;
  FILE *backup_file;
  char buf[BUF_SIZE];
  int bytes_read;
  int bytes_written;

  // Parse command line arguments
  if (argc < 4) {
    printf("Usage: %s <source_path> <dest_path> <backup_interval>\n", argv[0]);
    return 1;
  }
  strcpy(source_path, argv[1]);
  strcpy(dest_path, argv[2]);
  backup_interval = atoi(argv[3]);

  // Open source directory
  dir = opendir(source_path);
  if (dir == NULL) {
    printf("Error opening source directory: %s\n", strerror(errno));
    return 1;
  }

  // Loop through all files in source directory
  while ((entry = readdir(dir)) != NULL) {
    // Ignore directories and files that start with '.'
    if (entry->d_type != DT_REG || entry->d_name[0] == '.') {
      continue;
    }

    // Build file path and open source file
    strcpy(file_path, source_path);
    strcat(file_path, entry->d_name);
    source_file = fopen(file_path, "r");
    if (source_file == NULL) {
      printf("Error opening source file: %s\n", strerror(errno));
      continue;
    }

    // Get file information
    stat(file_path, &statbuf);
    strcpy(file_info.name, entry->d_name);
    strcpy(file_info.extension, ".txt");
    file_info.last_modified = statbuf.st_mtime;
    file_info.file_size = statbuf.st_size;

    // Build backup file path and open backup file
    strcpy(backup_path, dest_path);
    strcat(backup_path, file_info.name);
    strcat(backup_path, file_info.extension);
    backup_file = fopen(backup_path, "w");
    if (backup_file == NULL) {
      printf("Error opening backup file: %s\n", strerror(errno));
      fclose(source_file);
      continue;
    }

    // Copy file contents to backup file
    while ((bytes_read = fread(buf, sizeof(char), BUF_SIZE, source_file)) > 0) {
      bytes_written = fwrite(buf, sizeof(char), bytes_read, backup_file);
      if (bytes_written < bytes_read) {
        printf("Error writing to backup file: %s\n", strerror(errno));
        fclose(source_file);
        fclose(backup_file);
        return 1;
      }
    }

    // Close source and backup files
    fclose(source_file);
    fclose(backup_file);
  }

  // Close source directory
  closedir(dir);

  return 0;
}