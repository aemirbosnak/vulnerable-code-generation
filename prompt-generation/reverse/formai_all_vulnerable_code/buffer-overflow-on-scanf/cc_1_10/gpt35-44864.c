//FormAI DATASET v1.0 Category: File Backup System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define MAX_FILES 50
#define MAX_FILE_PATH 100
#define BUFFER_SIZE 1024

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

char **file_paths;
int num_files;
char *backup_dir_path;

void *backup_file(void *arg) {
  char *file_path = (char*) arg;
  char backup_file_path[MAX_FILE_PATH + 10];

  // Create backup file path
  snprintf(backup_file_path, sizeof(backup_file_path), "%s/%s.backup", backup_dir_path, strrchr(file_path, '/') + 1);
  
  // Open file for reading
  FILE *src_file = fopen(file_path, "r");
  if (src_file == NULL) {
      perror("Error opening file");
      return NULL;
  }

  // Create backup file for writing
  FILE *backup_file = fopen(backup_file_path, "w");
  if (backup_file == NULL) {
    perror("Error creating backup file");
    fclose(src_file);
    return NULL;
  }

  // Create buffer for reading/writing
  char buffer[BUFFER_SIZE];
  size_t read_size;

  // Copy file contents from source to backup file
  while ((read_size = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0) {
    fwrite(buffer, 1, read_size, backup_file);
  }

  // Close files
  fclose(src_file);
  fclose(backup_file);

  printf("Backup created for file: %s\n", file_path);

  return NULL;
}

int main(int argc, char **argv) {
  // Initialize file paths array
  file_paths = malloc(sizeof(char*) * MAX_FILES);
  num_files = 0;

  // Get backup directory path from command line argument
  if (argc != 2) {
    printf("Usage: %s <backup_directory_path>\n", argv[0]);
    return 1;
  }
  backup_dir_path = argv[1];

  // Create backup directory if it does not exist
  if (access(backup_dir_path, F_OK) == -1) {
    if (mkdir(backup_dir_path, 0755) == -1) {
      perror("Error creating backup directory");
      return 1;
    }
  }

  // Read input files from user and create backup files for each file
  char input_file_path[MAX_FILE_PATH];
  while (1) {
    printf("Enter file path (or q to quit): ");
    scanf("%s", input_file_path);

    if (strcmp(input_file_path, "q") == 0) {
      break;
    }

    // Add input file path to file_paths array
    file_paths[num_files++] = strdup(input_file_path);

    // Create new thread to create backup for this file
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, backup_file, file_paths[num_files - 1]);
    pthread_detach(thread_id);
  }

  // Wait for all threads to complete
  sleep(1);

  // Free allocated memory
  for (int i = 0; i < num_files; i++) {
    free(file_paths[i]);
  }
  free(file_paths);

  return 0;
}