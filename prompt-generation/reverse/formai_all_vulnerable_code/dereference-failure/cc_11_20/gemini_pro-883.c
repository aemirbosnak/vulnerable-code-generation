//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

// Maximum length of file paths
#define MAX_PATH_LEN 255

// Define file synchronization modes
#define SYNC_MODE_NONE 0
#define SYNC_MODE_COPY  1
#define SYNC_MODE_DELETE 2

// Main function
int main(int argc, char *argv[]) {
  // Check if the correct number of arguments is provided
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <source_path> <target_path> <mode>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the source file path
  char *source_path = argv[1];

  // Get the target file path
  char *target_path = argv[2];

  // Get the synchronization mode
  int sync_mode = atoi(argv[3]);

  // Validate the synchronization mode
  if (sync_mode != SYNC_MODE_NONE && sync_mode != SYNC_MODE_COPY && sync_mode != SYNC_MODE_DELETE) {
    fprintf(stderr, "Invalid synchronization mode: %d\n", sync_mode);
    return EXIT_FAILURE;
  }

  // Get the file stats of the source file
  struct stat source_stat;
  if (stat(source_path, &source_stat) == -1) {
    perror("Failed to get file stats");
    return EXIT_FAILURE;
  }

  // Get the file stats of the target file
  struct stat target_stat;
  if (stat(target_path, &target_stat) == -1) {
    // If the target file does not exist, create it if the synchronization mode is COPY
    if (sync_mode == SYNC_MODE_COPY) {
      if (copy_file(source_path, target_path) == -1) {
        perror("Failed to copy file");
        return EXIT_FAILURE;
      }

      printf("File copied: %s -> %s\n", source_path, target_path);

      // Update the target file stats
      if (stat(target_path, &target_stat) == -1) {
        perror("Failed to get file stats");
        return EXIT_FAILURE;
      }
    } else {
      printf("Target file does not exist: %s\n", target_path);
      return EXIT_SUCCESS;
    }
  } else {
    // Check if the source file is newer than the target file

    if (source_stat.st_mtime > target_stat.st_mtime) {
      // The source file is newer, so update the target file if the synchronization mode is COPY
      if (sync_mode == SYNC_MODE_COPY) {
        if (copy_file(source_path, target_path) == -1) {
          perror("Failed to copy file");
          return EXIT_FAILURE;
        }

        printf("File updated: %s -> %s\n", source_path, target_path);
      }
    } else if (source_stat.st_mtime < target_stat.st_mtime) {
      // The target file is newer, so update the source file if the synchronization mode is COPY
      if (sync_mode == SYNC_MODE_COPY) {
        if (copy_file(target_path, source_path) == -1) {
          perror("Failed to copy file");
          return EXIT_FAILURE;
        }

        printf("File updated: %s -> %s\n", target_path, source_path);
      }
    } else {
      // The files have the same modification time, so no action is required
      printf("Files are up-to-date: %s and %s\n", source_path, target_path);
    }
  }

  // If the synchronization mode is DELETE, delete the target file
  if (sync_mode == SYNC_MODE_DELETE) {
    if (remove(target_path) == -1) {
      perror("Failed to delete file");
      return EXIT_FAILURE;
    }

    printf("File deleted: %s\n", target_path);
  }

  return EXIT_SUCCESS;
}

// Copy a file from one location to another
int copy_file(const char *source_path, const char *target_path) {
  // Open the source file
  FILE *source_file = fopen(source_path, "rb");
  if (source_file == NULL) {
    perror("Failed to open source file");
    return -1;
  }

  // Open the target file
  FILE *target_file = fopen(target_path, "wb");
  if (target_file == NULL) {
    perror("Failed to open target file");
    return -1;
  }

  // Copy the file data
  char buffer[BUFSIZ];
  size_t bytes_read;
  while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
    if (fwrite(buffer, 1, bytes_read, target_file) != bytes_read) {
      perror("Failed to write to target file");
      return -1;
    }
  }

  // Close the files
  if (fclose(source_file) == EOF) {
    perror("Failed to close source file");
    return -1;
  }
  if (fclose(target_file) == EOF) {
    perror("Failed to close target file");
    return -1;
  }

  return 0;
}