//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: standalone
// File Backup System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_PATH_LENGTH 512

// Function to check if file exists
int file_exists(char *filename) {
  struct stat buffer;
  return (stat(filename, &buffer) == 0);
}

// Function to get the current time
char* get_current_time() {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  char *time_str = malloc(20);
  strftime(time_str, 20, "%Y-%m-%d-%H-%M-%S", tm);
  return time_str;
}

// Function to copy a file
void copy_file(char *src_filename, char *dest_filename) {
  FILE *src_file = fopen(src_filename, "r");
  FILE *dest_file = fopen(dest_filename, "w");
  char *buffer = malloc(1024);
  while (fgets(buffer, 1024, src_file) != NULL) {
    fputs(buffer, dest_file);
  }
  fclose(src_file);
  fclose(dest_file);
  free(buffer);
}

// Function to backup a file
void backup_file(char *filename) {
  char *backup_filename = malloc(MAX_PATH_LENGTH);
  char *current_time = get_current_time();
  strcpy(backup_filename, filename);
  strcat(backup_filename, "_");
  strcat(backup_filename, current_time);
  strcat(backup_filename, ".bak");
  copy_file(filename, backup_filename);
  free(backup_filename);
  free(current_time);
}

// Function to backup a directory
void backup_dir(char *dirname) {
  DIR *dir = opendir(dirname);
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (entry->d_type == DT_REG) {
      char *filename = malloc(MAX_PATH_LENGTH);
      strcpy(filename, dirname);
      strcat(filename, "/");
      strcat(filename, entry->d_name);
      backup_file(filename);
      free(filename);
    }
  }
  closedir(dir);
}

// Function to backup a file system
void backup_filesystem(char *root_dir) {
  DIR *dir = opendir(root_dir);
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (entry->d_type == DT_DIR) {
      char *dirname = malloc(MAX_PATH_LENGTH);
      strcpy(dirname, root_dir);
      strcat(dirname, "/");
      strcat(dirname, entry->d_name);
      backup_dir(dirname);
      free(dirname);
    }
  }
  closedir(dir);
}

// Main function
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <root_dir>\n", argv[0]);
    return 1;
  }
  char *root_dir = argv[1];
  backup_filesystem(root_dir);
  return 0;
}